
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "PlayerPawn.generated.h"

UCLASS()
class PVZ_API APlayerPawn : public APawn
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class UUserWidget> PlantSlotClass;

public:
	APlayerPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* Camera;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;

};