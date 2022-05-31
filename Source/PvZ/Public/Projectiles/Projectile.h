
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class PVZ_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UPaperFlipbookComponent* SpriteComponent;

	class AFightingActor* Owner;
};
