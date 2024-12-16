// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestWidget.generated.h"

class UImage;

/**
 * 
 */
UCLASS()
class DRIVEVISION_API UTestWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	UMaterial* ImageMaterialTemplate;
	
	UPROPERTY(BlueprintReadWrite)
	UMaterialInstanceDynamic* ImageMaterialInstance;

	UPROPERTY(EditAnywhere)
	UTexture2D* ImageTexture;

	UPROPERTY(meta = (BindWidget))
	UImage* Image;

protected:
	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;
};
