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
	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString())
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const {
	int32 ViewportSizeX, ViewportSizeY;
	FVector WorldDirection, trash, LookDirection;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
 	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
	
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, trash, LookDirection)){
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
		
	 return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & OutHitLocation) const{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			StartLocation + (LookDirection * LineTraceRange),
			ECC_Visibility)
		){
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}