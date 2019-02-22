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
		
	}
}

bool ATankPlayerController::GetSightRayHitLoction(FVector &OutHitLocation) const {
	int32 ViewportSizeX, ViewportSizeY;
	FVector WorldDirection;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
 	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
	
	if(DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y,FVector(), WorldDirection))
		UE_LOG(LogTemp, Warning, TEXT("WorldDirection: %s"), *WorldDirection.ToString())
	 return true;
}