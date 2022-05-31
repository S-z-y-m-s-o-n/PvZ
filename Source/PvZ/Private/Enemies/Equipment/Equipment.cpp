
#include "Enemies/Equipment/Equipment.h"

#include "PaperFlipbookComponent.h"

AEquipment::AEquipment()
{
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	SetRootComponent(Sprite);
}

void AEquipment::BeginPlay()
{
	Super::BeginPlay();

}

void AEquipment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}