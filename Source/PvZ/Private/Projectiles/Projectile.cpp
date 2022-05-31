// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/Projectile.h"

#include "Game/FightingActor.h"

#include "PaperFlipbookComponent.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SpriteComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite Component"));
	SetRootComponent(SpriteComponent);
}

