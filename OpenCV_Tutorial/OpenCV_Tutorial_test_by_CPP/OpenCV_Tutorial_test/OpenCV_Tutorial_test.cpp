// OpenCV_Tutorial_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main()
{
	Mat M0;
	Mat M1(5,3,CV_8U);
	Mat M2(Size(3,5), CV_8U);
	int sizes[] = {5, 3};//size用于指定Mat各个维度的数目
	Mat M3(2,sizes, CV_8U);
	Mat M11(5, 3, CV_8U, Scalar(2, 1));//Scalar为一个可以最多拥有四个元素的标量
	Mat M21(Size(3, 5), CV_8UC2, Scalar(2, 1)); //注意Size的长宽指定为Size(cols,rows)
	Mat M31(2, sizes, CV_8UC3, Scalar(2, 1, 3));
	
	M0 = Mat::zeros(5, 3, CV_8U);
	Mat M7 = Mat::ones(Size(3, 5), CV_8U);
	Mat M8 = M1(Range(0,2), Range(1,3));//Range为指定的范围（不包括上界）
	
	Mat M9 = Mat::eye(5, 5, CV_8U);
	Mat M10;
	M2.convertTo(M10,CV_64F);
	
	Mat image = imread("test.jpg");
	cvtColor(image, image, CV_BGR2RGB);//读进图像的通道需要转换才符合正常RGB
	std::cout <<   std::endl;
    return 0;
}

