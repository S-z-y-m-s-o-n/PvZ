
#include "Game/GridCell.h"

#include "Kismet/GameplayStatics.h"

#include "Player/PlayerPawn.h"
#include "Plants/Plant.h"

#include "PaperSpriteComponent.h"
#include "Game/GridCell.h"

AGridCell::AGridCell()
{
	PrimaryActorTick.bCanEverTick = false;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));

	Sprite->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECollisionResponse::ECR_Block);
}

void AGridCell::BeginPlay()
{
	Super::BeginPlay();

}

void AGridCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}