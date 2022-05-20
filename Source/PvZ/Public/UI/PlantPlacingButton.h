
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlantPlacingButton.generated.h"

UCLASS()
class PVZ_API UPlantPlacingButton : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	TSubclassOf<class APlantn> PlantClass;

	float Cooldown;

	void OnClicked();

public:
	void Setup(TSubclassOf<class APlantn> PlantClass, float Cooldown);

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
