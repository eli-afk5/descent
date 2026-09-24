// Fill out your copyright notice in the Description page of Project Settings.


#include "AutomapWireBuilder.h"
#include "AutomapWireData.h"

#include "EngineUtils.h"                 
#include "Engine/StaticMeshActor.h"
#include "Engine/StaticMesh.h"
#include "StaticMeshResources.h"

// Sets default values
AAutomapWireBuilder::AAutomapWireBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAutomapWireBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAutomapWireBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAutomapWireBuilder::ExtractFeatureEdges(const UStaticMesh* Mesh, float InAngleDeg, TArray<FVector>& OutLines)
{
    if (!Mesh || !Mesh->GetRenderData() || Mesh->GetRenderData()->LODResources.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("ExtractFeatureEdges: Mesh nulla o senza LODResources"));
        return;
    }

    const FStaticMeshLODResources& LOD = Mesh->GetRenderData()->LODResources[0];
    const FPositionVertexBuffer& Pos = LOD.VertexBuffers.PositionVertexBuffer;
    FIndexArrayView Idx = LOD.IndexBuffer.GetArrayView();

    UE_LOG(LogTemp, Log, TEXT("Mesh %s - LODResources: %d, Verts: %d, Tris: %d"),
        *Mesh->GetName(), Mesh->GetRenderData()->LODResources.Num(),
        Pos.GetNumVertices(), Idx.Num() / 3);

    TMap<FIntVector, int32> Weld;
    TArray<FVector3f> P;
    TArray<int32> Remap;
    Remap.SetNum(Pos.GetNumVertices());

    for (uint32 i = 0; i < Pos.GetNumVertices(); ++i)
    {
        const FVector3f V = Pos.VertexPosition(i);
        const FIntVector K(FMath::RoundToInt(V.X * 10.f), FMath::RoundToInt(V.Y * 10.f), FMath::RoundToInt(V.Z * 10.f));
        int32& Id = Weld.FindOrAdd(K, INDEX_NONE);
        if (Id == INDEX_NONE)
        {
            Id = P.Add(V);
        }
        Remap[i] = Id;
    }

    struct FEdge { int32 F0 = INDEX_NONE, F1 = INDEX_NONE; };
    TMap<TPair<int32, int32>, FEdge> Edges;
    TArray<FVector3f> N;

    for (int32 t = 0; t < Idx.Num(); t += 3)
    {
        const int32 I0 = Remap[Idx[t]];
        const int32 I1 = Remap[Idx[t + 1]];
        const int32 I2 = Remap[Idx[t + 2]];
        N.Add(FVector3f::CrossProduct(P[I1] - P[I0], P[I2] - P[I0]).GetSafeNormal());

        const int32 Tri[3] = { I0, I1, I2 };
        for (int32 e = 0; e < 3; ++e)
        {
            const int32 A = Tri[e];
            const int32 B = Tri[(e + 1) % 3];
            FEdge& E = Edges.FindOrAdd(TPair<int32, int32>(FMath::Min(A, B), FMath::Max(A, B)));
            if (E.F0 == INDEX_NONE) E.F0 = t / 3;
            else E.F1 = t / 3;
        }
    }

    const float CosT = FMath::Cos(FMath::DegreesToRadians(InAngleDeg));

    // --- Diagnostica ---
    int32 NumBoundary = 0, NumSharp = 0, NumCoplanar = 0;
    float MaxAngleFound = 0.f;
    for (const auto& DiagPair : Edges)
    {
        const FEdge& E = DiagPair.Value;
        if (E.F1 == INDEX_NONE) { ++NumBoundary; continue; }
        const float Dot = FVector3f::DotProduct(N[E.F0], N[E.F1]);
        const float AngleFound = FMath::RadiansToDegrees(FMath::Acos(FMath::Clamp(Dot, -1.f, 1.f)));
        MaxAngleFound = FMath::Max(MaxAngleFound, AngleFound);
        if (Dot < CosT) ++NumSharp; else ++NumCoplanar;
    }
    UE_LOG(LogTemp, Log, TEXT("Edges totali: %d | Boundary: %d | Sharp: %d | Coplanar: %d | Angolo max trovato: %.2f°"),
        Edges.Num(), NumBoundary, NumSharp, NumCoplanar, MaxAngleFound);
    // --- Fine diagnostica ---
    
    for (const auto& Pair : Edges)
    {
        const FEdge& E = Pair.Value;
        const bool bBoundary = (E.F1 == INDEX_NONE);
        const bool bSharp = !bBoundary && FVector3f::DotProduct(N[E.F0], N[E.F1]) < CosT;

        if (bBoundary || bSharp)
        {
            OutLines.Add((FVector)P[Pair.Key.Key]);
            OutLines.Add((FVector)P[Pair.Key.Value]);
        }
    }

    UE_LOG(LogTemp, Log, TEXT("OutLines popolato: %d punti (%d segmenti)"), OutLines.Num(), OutLines.Num() / 2);
}

#if WITH_EDITOR
void AAutomapWireBuilder::Bake()
{
    if (!Target)
    {
        UE_LOG(LogTemp, Warning, TEXT("AMinimapWireBuilder::Bake - Target not assigned"));
        return;
    }

    TSet<TPair<FIntVector, FIntVector>> Seen;
    TArray<FVector> Out;
    TArray<FName> OutCategories;
    auto Quantize = [](const FVector& V) {
        return FIntVector(FMath::RoundToInt(V.X), FMath::RoundToInt(V.Y), FMath::RoundToInt(V.Z));
    };

    for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
    {
        if (!It->ActorHasTag(SourceTag))
        {
            continue;
        }

        UStaticMesh* Mesh = It->GetStaticMeshComponent()->GetStaticMesh();
        if (!Mesh)
        {
            continue;
        }

        UE_LOG(LogTemp, Log, TEXT("Actor %s, tag match: %d, mesh valid: %d"),
          *It->GetName(), It->ActorHasTag(SourceTag), Mesh != nullptr);
        
        FName Category = NAME_None;
        for (const FName& Tag : It->Tags)
        {
            if (Tag != SourceTag)
            {
                Category = Tag;
                break;
            }
        }

        TArray<FVector> Local;
        ExtractFeatureEdges(Mesh, AngleDeg, Local);
        
        for (int32 i = 0; i + 1 < Local.Num(); i += 2)
        {
            const FVector A = Local[i];
            const FVector B = Local[i + 1];

            FIntVector QA = Quantize(A);
            FIntVector QB = Quantize(B);
            if (QB.X < QA.X || (QB.X == QA.X && (QB.Y < QA.Y || (QB.Y == QA.Y && QB.Z < QA.Z))))
            {
                Swap(QA, QB);
            }

            bool bAlreadyInSet = false;
            Seen.Add(TPair<FIntVector, FIntVector>(QA, QB), &bAlreadyInSet);
            if (!bAlreadyInSet)
            {
                Out.Add(A);
                Out.Add(B);
                OutCategories.Add(Category);
            }
        }
    }
    
    const int32 NumSegments = Out.Num() / 2;

    Target->Modify();
    Target->Lines = MoveTemp(Out);
    Target->Categories = MoveTemp(OutCategories);
    Target->MarkPackageDirty();

    UE_LOG(LogTemp, Log, TEXT("AAutomapWireBuilder::Bake - %d generated segments"), NumSegments);
}
#endif