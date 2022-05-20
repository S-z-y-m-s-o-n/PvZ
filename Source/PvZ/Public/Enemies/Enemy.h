
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class PVZ_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	AEnemy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UPaperFlipbookComponent* Sprite;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float MaxHealth;

	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float Range;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void Damage(float value);
};
