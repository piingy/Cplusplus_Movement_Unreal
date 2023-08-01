// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputAction.h"
#include "MyPawn.generated.h"

UCLASS()
class CPLUSTESTING_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//void MoveForward(float AxisVal);
	void MyEnhancedInputMove(const FInputActionValue& Value);

	//void MoveRight(float AxisVal);
	void MyEnhancedInputLook(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputMappingContext* inputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputLook;



	


};
