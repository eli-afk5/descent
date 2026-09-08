// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"

#include "PawnBase.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Mesh"));
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	CollisionSphere->SetupAttachment(ItemMesh);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnBeginOverlap);
	
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();

	if (ItemDataAsset)
	{
		ItemMesh->SetStaticMesh(ItemDataAsset->StaticMesh);
	}
	
	GI = Cast<UDescentGameInstance>(UGameplayStatics::GetGameInstance(this));
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemBase::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (!ItemDataAsset) { return; } 
	//if pointer to Data Asset is valid
	ItemDataAsset->OnPickup(); //execute OnPickup action as defined in Data Asset (print string, dev only)
	ItemMesh->DestroyComponent(); //destroy SM
	CollisionSphere->DestroyComponent(); //destroy collision sphere
}
