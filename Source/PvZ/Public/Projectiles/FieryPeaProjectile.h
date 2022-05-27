
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FieryPeaProjectile.generated.h"

UCLASS()
class PVZ_API AFieryPeaProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AFieryPeaProjectile();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UPaperFlipbookComponent* SpriteComponent;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
