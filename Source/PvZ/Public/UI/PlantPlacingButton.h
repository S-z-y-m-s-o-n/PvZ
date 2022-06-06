
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Cooldown;

	UFUNCTION(BlueprintCallable)
	void OnClicked();

public:

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
