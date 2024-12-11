// Fill out your copyright notice in the Description page of Project Settings.


#include "StereoVision.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/Texture2D.h"
#include "Components/SceneCaptureComponent2D.h"	
#include "Engine/World.h"
#include "Engine/GameEngine.h"

AUStereoVision::AUStereoVision()
{
	UE_LOG(LogTemp, Warning, TEXT("Stereo Vision Class mate"));
	LeftCam = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("LeftCam"));
	ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> RenderTargetAsset(
		TEXT("/Game/RenderTargetLeftCam.RenderTargetLeftCam"));
	ConstructorHelpers::FObjectFinder<UMaterial> RenderTexture(
		TEXT("/Game/RenderTargetLeftCam_Mat.RenderTargetLeftCam_Mat"));
	RenderTarget = DuplicateObject(RenderTargetAsset.Object, nullptr);
	Mat = DuplicateObject(RenderTexture.Object, nullptr);
	LeftCam->TextureTarget = RenderTarget;
}

void AUStereoVision::BeginPlay()
{
	Super::BeginPlay();
	RenderLoop();
}

// void AUStereoVision::RenderLoop()
// {
// 	UTexture2D* ResultTexture;
// 	FTimerHandle handle;
// 	FTexture2DMipMap MipMap;
// 	GetWorld()->GetTimerManager().SetTimer(handle, [=, this]() mutable 
// 	{
// 		ResultTexture = LeftCam->TextureTarget->ConstructTexture2D(RenderTarget, "CameraImage",
// 		RF_NoFlags, CTF_DeferCompression);
// 		MipMap = ResultTexture->GetPlatformData()->Mips[0];
// 		FColor* FormatedImageData = static_cast<FColor*>(MipMap.BulkData.Lock(LOCK_READ_ONLY));
// 		uint8 PixelX = 50, PixelY = 40;
// 		uint32 TextureWidth = MipMap.SizeX, TextureHeight = MipMap.SizeY;
// 		FColor PixelColor;
// 	
// 		if (PixelX < TextureWidth && PixelY < TextureHeight)
// 		{
// 			PixelColor = FormatedImageData[PixelY * TextureWidth + PixelX];
// 			UE_LOG(LogTemp, Warning, TEXT("Pixel Colors: (%d,%d,%d)"), PixelColor.R, PixelColor.G, PixelColor.B);
// 		}
// 		ResultTexture->UpdateResource();
// 		MipMap.BulkData.Unlock();
// 	 }, 0.1f, true, 1.0f);
// }

void AUStereoVision::RenderLoop()
{
	UTexture2D* ResultTexture;
	FTimerHandle handle;
	FTexture2DMipMap MipMap;
	GetWorld()->GetTimerManager().SetTimer(handle, [=, this]() mutable 
	{
		ResultTexture = LeftCam->TextureTarget->ConstructTexture2D(RenderTarget, "CameraImage",
		RF_NoFlags, CTF_DeferCompression);
		MipMap = ResultTexture->GetPlatformData()->Mips[0];
		FColor* FormatedImageData = static_cast<FColor*>(MipMap.BulkData.Lock(LOCK_READ_ONLY));
		uint8 PixelX = 50, PixelY = 40;
		uint32 TextureWidth = MipMap.SizeX, TextureHeight = MipMap.SizeY;
		FColor PixelColor;
	
		if (PixelX < TextureWidth && PixelY < TextureHeight)
		{
			PixelColor = FormatedImageData[PixelY * TextureWidth + PixelX];
			UE_LOG(LogTemp, Warning, TEXT("Pixel Colors: (%d,%d,%d)"), PixelColor.R, PixelColor.G, PixelColor.B);
		}
		ResultTexture->UpdateResource();
		MipMap.BulkData.Unlock();
	 }, 0.1f, true, 1.0f);
}