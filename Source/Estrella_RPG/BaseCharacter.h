// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayEffectTypes.h"
#include "BaseCharacter.generated.h"

UCLASS()
class ESTRELLA_RPG_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	/** Ability System Component. Required to use Gameplay Attributes and Gameplay Abilities. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
		class UAbilitySystemComponent* AbilitySystemComponent;

	//Blueprint-implementable On Health Changed event. Used to send information to the UI about current health.
	UFUNCTION(BlueprintImplementableEvent, Category = "Attributes")
		void OnHealthChanged(float CurrentHP, float NewHP);

	//Function to bind to Attribute Changed delegate. Calls On Health Changed.
	void OnHealthChangedInternal(const FOnAttributeChangeData& Data);

	/** Blueprint-accessible getter for the current health value. */
	UFUNCTION(BlueprintPure, Category = "Abilities|Attributes")
		float GetHealth() const;

	/** Ability System Interface getter. */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}

	/** Grants an ability at the given level, with an input code used to pick and choose which ability should be triggered. */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
		void GrantAbility(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, int32 InputCode);

	/** Activates an ability with a matching input code */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
		void ActivateAbility(int32 InputCode);

	/** Cancels abilities with specific Gameplay Tags applied to them.*/
	UFUNCTION(BlueprintCallable, Category = "Abilities")
		void CancelAbilityWithTags(const FGameplayTagContainer CancelWithTags);

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		bool IsHostile(ABaseCharacter* other);

	//Allow enemy to attack player with a different team id
	uint8 TeamID;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
