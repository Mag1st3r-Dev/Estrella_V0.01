// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Add the Ability System Component to the character.
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("Ability System Component"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ABaseCharacter::GetHealth() const
{
	return 0.0f;
}

void ABaseCharacter::GrantAbility(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, int32 InputCode)
{
}

void ABaseCharacter::ActivateAbility(int32 InputCode)
{
}

void ABaseCharacter::CancelAbilityWithTags(const FGameplayTagContainer CancelWithTags)
{
}

bool ABaseCharacter::IsHostile(ABaseCharacter* other)
{
	return false;
}
