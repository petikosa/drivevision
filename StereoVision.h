// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "StereoVision.generated.h"


/**
 * 
 */
UCLASS()
class DRIVEVISION_API AUStereoVision : public AActor

{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextureRenderTarget2D* RenderTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* LeftImage;
	USceneCaptureComponent2D* LeftCam;
	UMaterial* Mat;
	AUStereoVision();
	FTimerHandle LoopHandle();
	void RenderLoop(); //FTexture2DMipMap& MipMap
	void BeginPlay();
};
