
#pragma once

#include "CoreMinimal.h"
#include "Plants/Plant.h"
#include "PoisonousBerry.generated.h"

UCLASS()
class PVZ_API APoisonousBerry : public APlant
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbookComponent* Fruit1a;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbookComponent* Fruit2a;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbookComponent* Fruit3a;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class UMaterial* FruitNormalMaterial;

	uint8 EatenFruit;

	TArray<UPaperFlipbookComponent*> Fruits;
	TArray<float> FruitHealth{ 0, 0, 0 };
	TArray<bool> FruitStatus{ false, false, false };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float FruitRegrowthTime = 10.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float MaxFruitHealth = 100;

	void UpdateFruits();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual float Damage(float value, enum EDamageType damageType, AActor* source) override;

	virtual void Tick(float DeltaTime) override;

	APoisonousBerry();
};
