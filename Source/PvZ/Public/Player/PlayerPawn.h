
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "PlayerPawn.generated.h"

UCLASS()
class PVZ_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* Camera;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};