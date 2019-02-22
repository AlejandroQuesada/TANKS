// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




void ATankPlayerController::BeginPlay(){
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *ControlledTank->GetName())
	}
	
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimToCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimToCrosshair(){
	FVector HitLocation;
	if (GetSightRayHitLoction(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
	}
}

bool ATankPlayerController::GetSightRayHitLoction(FVector &OutHitLocation) const {
	return true;
	//Find first item on the direction of the HitLocation
}