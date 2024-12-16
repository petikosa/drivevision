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
	UTextureRenderTarget2D* RenderTargetLeft;
	UTextureRenderTarget2D* RenderTargetRight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneCaptureComponent2D* LeftCam;
	USceneCaptureComponent2D* RightCam;
	AUStereoVision();
	void RenderLoop(); //FTexture2DMipMap& MipMap
	void BeginPlay();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* DynamicTexture;

	void UpdateTextureRegion(int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D Region,
						 uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData,
						 TFunction<void(uint8* SrcData)> DataCleanupFunc = [](uint8*){});

	UPROPERTY(BlueprintReadWrite)
	UMaterialInstanceDynamic* DynamicMaterial;

	// The Name of the Texture Parameter in the Material
	UPROPERTY(EditDefaultsOnly)
	FName DynamicMaterialParamName = "DynamicTexture";
};
