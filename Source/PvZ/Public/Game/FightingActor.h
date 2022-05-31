
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Game/Damage.h"
#include "FightingActor.generated.h"

UENUM()
enum ESide
{
	Plants, 
	Zombies,
	None
};

UCLASS()
class PVZ_API AFightingActor : public AActor
{
	GENERATED_BODY()
public:	
	AFightingActor();

	ESide Side = ESide::None;

	uint8 Row;

	bool bCanEatBrain = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UPaperFlipbookComponent* SpriteComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxHealth;

	float Health;

	bool bIsDamagable = true;

	virtual float Damage(float value, EDamageType damageType, AActor* source);

protected:

	virtual void BeginPlay() override;
};
