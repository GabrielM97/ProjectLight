// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Components/WidgetComponent.h"
#include "Engine/DataTable.h"
#include "ProjectLightCharacter.generated.h"

USTRUCT(BlueprintType)
struct FCharacterAnimInfo : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FGameplayTag IdTag;
	
	UPROPERTY(EditAnywhere)
	UAnimSequence* IdleAnim;

	UPROPERTY(EditAnywhere)
	UAnimSequence* JumpStartAnim;

	UPROPERTY(EditAnywhere)
	UAnimSequence* JumpLoopAnim;

	UPROPERTY(EditAnywhere)
	UAnimSequence* JumpEndAnim;

	UPROPERTY(EditAnywhere)
	UBlendSpace* WalkToRunBlendSpace;
	
};

UCLASS(config=Game)
class AProjectLightCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

public:
	AProjectLightCharacter();

	UFUNCTION(BlueprintCallable)
	void UpdateAnimations(const FGameplayTag NewAnimTag);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
	FGameplayTag DefaultAnimTag;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
	UDataTable* AnimDataTable;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

private:
	
	UPROPERTY()
	UAnimSequence* IdleAnim;

	UPROPERTY()
	UAnimSequence* JumpStartAnim;

	UPROPERTY()
	UAnimSequence* JumpLoopAnim;

	UPROPERTY()
	UAnimSequence* JumpEndAnim;
	
	UPROPERTY()
	UBlendSpace* WalkToRunBlendSpace;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay() override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

