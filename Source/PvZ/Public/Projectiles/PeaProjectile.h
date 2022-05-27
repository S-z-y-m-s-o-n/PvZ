// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PeaProjectile.generated.h"

UCLASS()
class PVZ_API APeaProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	APeaProjectile();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UPaperFlipbookComponent* SpriteComponent;

protected:
	virtual void BeginPlay() override;
};
