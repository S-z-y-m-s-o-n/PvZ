
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlantSlot.generated.h"

UCLASS()
class PVZ_API UPlantSlot : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Cooldown;

	UFUNCTION(BlueprintCallable)
		void OnClicked();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TSubclassOf<class APlant> PlantClass;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
};
