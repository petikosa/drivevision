// Fill out your copyright notice in the Description page of Project Settings.


#include "StereoVisionOpenCv.h"

UStereoVisionOpenCv::UStereoVisionOpenCv()
{
	UE_LOG(LogTemp, Warning, TEXT("OpenCV Class"));
	TestOpenCV();
}

void UStereoVisionOpenCv::TestOpenCV()
{
	UE_LOG(LogTemp, Warning, TEXT("OpenCV TestOpenCV"));
	cv::Mat img = cv::imread("D:/path/to/your/folder/test_write.png", cv::IMREAD_COLOR); 

	if (img.empty())
	{
		UE_LOG(LogTemp, Warning, TEXT("OpenCV TestOpenCV"));
	}
	else
	{
		int image_width = img.rows;
		int image_height = img.cols;
	}
}