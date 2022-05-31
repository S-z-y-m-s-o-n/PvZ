
#include "Player/PlayerPawn.h"

#include "Kismet/GameplayStatics.h"

#include "Plants/Plant.h"
#include "Game/GridCell.h"

#include "Game/PvZGameInstance.h"
#include "Game/PvEBaseLevelGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"

APlayerPawn::APlayerPawn()
{
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 2048.0f/1.65;
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	APawn::SetupPlayerInputComponent(PlayerInputComponent);

	APvEBaseLevelGameMode* game = Cast< APvEBaseLevelGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	PlayerInputComponent->BindAction("UnchoosePlant", IE_Pressed, game, &APvEBaseLevelGameMode::UnchoosePlant);
	PlayerInputComponent->BindAction("LMB", IE_Pressed, game, &APvEBaseLevelGameMode::LMB);
	PlayerInputComponent->BindAction("PlantOut", IE_Pressed, game, &APvEBaseLevelGameMode::PlantOut);

	PlayerInputComponent->BindAction("1", IE_Pressed, game, &APvEBaseLevelGameMode::slot1);
	PlayerInputComponent->BindAction("2", IE_Pressed, game, &APvEBaseLevelGameMode::slot2);
	PlayerInputComponent->BindAction("3", IE_Pressed, game, &APvEBaseLevelGameMode::slot3);
	PlayerInputComponent->BindAction("4", IE_Pressed, game, &APvEBaseLevelGameMode::slot4);
	PlayerInputComponent->BindAction("5", IE_Pressed, game, &APvEBaseLevelGameMode::slot5);
}