// Fill out your copyright notice in the Description page of Project Settings.


#include "TestWidget.h"

#include <opencv2/core/base.hpp>

#include "CopyTextureShaders.h"
#include "Components/Image.h"

void UTestWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UTestWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	ImageMaterialInstance = UMaterialInstanceDynamic::Create(
		ImageMaterialTemplate, this);
	Image->SetBrushFromMaterial(ImageMaterialInstance);
	
	ImageMaterialInstance->SetTextureParameterValue(TEXT("Image"), ImageTexture);
}
