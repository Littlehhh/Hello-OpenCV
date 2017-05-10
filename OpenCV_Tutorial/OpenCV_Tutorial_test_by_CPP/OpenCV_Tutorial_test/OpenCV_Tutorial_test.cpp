// OpenCV_Tutorial_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <opencv2/core/mat.hpp>

using namespace cv;

int main()
{
	Mat M0;
	Mat M1(5,3,CV_8U);
	Mat M2(Size(3,5), CV_8U);
	int sizes[] = {5, 3};
	Mat M3(2,sizes, CV_8U);
	Mat M11(5, 3, CV_8U, Scalar(2, 1));
	Mat M21(Size(3, 5), CV_8UC2, Scalar(2, 1));
	Mat M31(2, sizes, CV_8UC3, Scalar(2, 1, 3));
	
	M0 = Mat::zeros(5, 3, CV_8U);
	Mat M7 = Mat::ones(Size(3, 5), CV_8U);
	//Mat M8 = Mat::diag(M1);
	
	Mat M9 = Mat::eye(5, 5, CV_8U);
	Mat M10();
	
	std::cout <<   std::endl;
    return 0;
}

