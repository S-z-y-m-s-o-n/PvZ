
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Equipment.generated.h"

UCLASS()
class PVZ_API AEquipment : public AActor
{
	GENERATED_BODY()

public:
	AEquipment();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UPaperFlipbookComponent* Sprite;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
