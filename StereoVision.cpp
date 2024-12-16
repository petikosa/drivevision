// Fill out your copyright notice in the Description page of Project Settings.


#include "StereoVision.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/Texture2D.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/World.h"
#include "Rendering/Texture2DResource.h"
#include "Runtime/RHI/Public/RHITypes.h"

AUStereoVision::AUStereoVision()
{
	// UE_LOG(LogTemp, Warning, TEXT("Stereo Vision Class mate"));
	// LeftCam = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("LeftCam"));
	// ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> RenderTargetAsset(
	// TEXT("/Game/RenderTargetLeftCam.RenderTargetLeftCam"));
	// RenderTargetLeft = DuplicateObject(RenderTargetAsset.Object, nullptr);
	// LeftCam->TextureTarget = RenderTargetLeft;
	//
	// RightCam = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("RightCam"));
	// DynamicTexture = UTexture2D::CreateTransient(128, 128, EPixelFormat::PF_R8G8B8A8, "DynamicTexture");
	// DynamicTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
	// DynamicTexture->SRGB = 0;
	// DynamicTexture->Filter = TextureFilter::TF_Nearest;
	// DynamicTexture->AddToRoot();
	// DynamicTexture->UpdateResource();
}

void AUStereoVision::BeginPlay()
{
	// Super::BeginPlay();
	// RenderLoop();
}

void AUStereoVision::RenderLoop()
{
	FTimerHandle handle;
	//UTexture2D* Texture;
	// UTexture2D* RightTexture;
	GetWorld()->GetTimerManager().SetTimer(handle, [=, this]() mutable
	{
		// Texture = LeftCam->TextureTarget->ConstructTexture2D(RenderTargetLeft, "CameraImage",
		//                                                      RF_NoFlags, CTF_DeferCompression);
		DynamicMaterial->SetTextureParameterValue("DynamicTexture", DynamicTexture);

			static uint8 rgbw[64 * 64];
			for (uint32 i = 0; i < 22 * 22; i++)
			{
				rgbw[i * 4] = 22;
				rgbw[i * 4 + 1] = 25;
				rgbw[i * 4 + 2] = 99;
				rgbw[i * 4 + 3] = 0.5;
			}
			auto region = FUpdateTextureRegion2D(0, 0, 0, 0, 64, 64);
			
			FTextureResource* xx = DynamicTexture->GetResource();
			UpdateTextureRegion(0, 1, region, 2 * 4, 4, rgbw);
		
	}, .1f, true, 1.0f);
}

void AUStereoVision::UpdateTextureRegion(int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D Region,
                                         uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData,
                                         TFunction<void(uint8* SrcData)> DataCleanupFunc)
{
	ENQUEUE_RENDER_COMMAND(UpdateTextureRegionsData)(
		[=, this](FRHICommandListImmediate& RHICmdList)
		{
			// FRHITextureCreateDesc TextureDesc = FRHITextureCreateDesc::Create2D(TEXT("texture"), 4, 4, PF_B8G8R8A8);
			// TextureDesc.AddFlags(TexCreate_ShaderResource | TexCreate_UAV | TexCreate_RenderTargetable);
			// FTextureRHIRef texc = RHICreateTexture(TextureDesc);
			// RightCam->TextureTarget->ConstructTexture2D(RenderTargetRight, "RightCameraImage",
			// 													  RF_NoFlags, CTF_DeferCompression);
			FTextureRHIRef xx = DynamicTexture->GetResource()->GetTexture2DRHI();
			//UE_LOG(LogTemp, Warning, TEXT("(%d,%d)"), xx->GetSizeX(), xx->GetSizeY());
			RHIUpdateTexture2D(
				xx,
				MipIndex,
				Region,
				SrcPitch,
				SrcData
				+ Region.SrcY * SrcPitch
				+ Region.SrcX * SrcBpp
				);
			DataCleanupFunc(SrcData);
		});
}
