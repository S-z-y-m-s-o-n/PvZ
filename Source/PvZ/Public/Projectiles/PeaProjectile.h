// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Projectiles/Projectile.h"

#include "PeaProjectile.generated.h"

UCLASS()
class PVZ_API APeaProjectile : public AProjectile
{
	GENERATED_BODY()
	
public:	
	APeaProjectile();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnSpriteBeginOverlap(UPrimitiveComponent* comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
