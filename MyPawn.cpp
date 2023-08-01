// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPawn::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyPawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyPawn::AddControllerPitchInput);
	*/

	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	enhancedInputComponent->BindAction(inputMove, ETriggerEvent::Triggered, this, &AMyPawn::MyEnhancedInputMove);
	enhancedInputComponent->BindAction(inputLook, ETriggerEvent::Triggered, this, & AMyPawn::MyEnhancedInputLook);

}

void AMyPawn::MyEnhancedInputMove(const FInputActionValue& Value)
{

	UE_LOG(LogTemp, Error, TEXT(" inside Look Up"));

	const FVector2D moveVector = Value.Get<FVector2D>();
	const FRotator moveRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
 

	//if movement is in the left or right direction. 
	if (moveVector.X > 0.05f || moveVector.X < -0.05f) 
	{
		const FVector directionVector = moveRotation.RotateVector(FVector::RightVector);
		AddMovementInput(directionVector, moveVector.X);
	}

	//if the movement is in the forward or backward direction.
	if (moveVector.Y > 0.05f || moveVector.Y < -0.05f) 
	{
		const FVector directionVector = moveRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(directionVector, moveVector.Y);
	}


}

void AMyPawn::MyEnhancedInputLook(const FInputActionValue& Value)
{
}



/*void AMyPawn::MoveForward(float AxisVal)
{
	AddMovementInput(GetActorForwardVector() * AxisVal);
}

void AMyPawn::MoveRight(float AxisVal)
{
	AddMovementInput(GetActorRightVector() * AxisVal);
}*/

