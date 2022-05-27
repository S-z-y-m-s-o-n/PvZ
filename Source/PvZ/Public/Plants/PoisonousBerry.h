
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
		class UPaperFlipbookComponent* Fruit1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbookComponent* Fruit2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbookComponent* Fruit3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class UMaterial* FruitNormalMaterial;

	uint8 EatenFruit;

	TArray<UPaperFlipbookComponent*> Fruits;
	TArray<float> FruitHealth{ 0, 0, 0 };
	TArray<bool> FruitStatus{ false, false, false };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float FruitRegrowthTime = 2.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float MaxFruitHealth = 100;

	void UpdateFruits();

protected:
	virtual void BeginPlay() override;

	void a1() { Damage(500); }
	
public:
	virtual void Damage(float value) override;

	virtual void Tick(float DeltaTime) override;

	APoisonousBerry();
};
