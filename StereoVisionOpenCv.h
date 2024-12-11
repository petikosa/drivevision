#pragma once

#include "CoreMinimal.h"

#if WITH_OPENCV
#include "GameFramework/Actor.h"
#include "PreOpenCVHeaders.h"
#include "OpenCVHelper.h"
#include "opencv2/unreal.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/ml.hpp"
//#include "opencv2/imsgproc.hpp"
#include "opencv2/highgui.hpp"
#include "PostOpenCVHeaders.h"
#endif

#include "StereoVisionOpenCv.generated.h"
/**
 * 
 */
UCLASS()
class DRIVEVISION_API UStereoVisionOpenCv : public UObject
{
	GENERATED_BODY()

public:
	void TestOpenCV();
	cv::Mat frame;
	cv::VideoCapture stream;
	cv::Size size;

	UStereoVisionOpenCv();
};
