// OpenCV_Tutorial_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//C++ standard library
#include <iostream>
#include <vector>

// OpenCV library
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{
	// accept only char type matrices
	CV_Assert(I.depth() == CV_8U);
	int channels = I.channels();
	int nRows = I.rows;
	int nCols = I.cols * channels;
	if (I.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}
	int i, j;
	uchar* p;
	for (i = 0; i < nRows; ++i)
	{
		p = I.ptr<uchar>(i);
		for (j = 0; j < nCols; ++j)
		{
			p[j] = table[p[j]];
		}
	}
	return I;
}
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table)
{
	// accept only char type matrices
	CV_Assert(I.depth() == CV_8U);
	const int channels = I.channels();
	switch (channels)
	{
	case 1:
	{
		MatIterator_<uchar> it, end;
		for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
			*it = table[*it];
		break;
	}
	case 3:
	{
		MatIterator_<Vec3b> it, end;
		for (it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
		{
			(*it)[0] = table[(*it)[0]];
			(*it)[1] = table[(*it)[1]];
			(*it)[2] = table[(*it)[2]];
		}
	}
	}
	return I;
}
Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const table)
{
	// accept only char type matrices  
	CV_Assert(I.depth() != sizeof(uchar));
	const int channels = I.channels();
	switch (channels)
	{
	case 1:
	{
		for (int i = 0; i < I.rows; ++i)
			for (int j = 0; j < I.cols; ++j)
				I.at<uchar>(i, j) = table[I.at<uchar>(i, j)];
		break;
	}
	case 3:
	{
		Mat_<Vec3b> _I = I;

		for (int i = 0; i < I.rows; ++i)
			for (int j = 0; j < I.cols; ++j)
			{
				_I(i, j)[0] = table[_I(i, j)[0]];
				_I(i, j)[1] = table[_I(i, j)[1]];
				_I(i, j)[2] = table[_I(i, j)[2]];
			}
		I = _I;
		break;
	}
	}
	return I;
}

int main()
{
	Mat M0;
	Mat M1(5,3,CV_8U);
	Mat M2(Size(3,5), CV_8U);
	int sizes[] = {5, 3};//size用于指定Mat各个维度的数目
	Mat M3(2,sizes, CV_8U);

	Mat M11(5, 3, CV_8UC1, Scalar(2, 1));//Scalar为一个可以最多拥有四个元素的标量
	Mat M21(Size(3, 5), CV_8UC2, Scalar(2, 1)); //注意Size的长宽指定为Size(cols,rows)
	Mat M31(2, sizes, CV_8UC3, Scalar(2, 1, 3));
	
	M0 = Mat::zeros(5, 3, CV_8U);
	Mat M7 = Mat::ones(Size(3, 5), CV_8U);
	Mat M8 = M1(Range(0,2), Range(1,3));//Range为指定的范围（不包括上界）
	
	Mat M9 = Mat::eye(5, 5, CV_8U);
	Mat M10;
	M2.convertTo(M10,CV_64F);
	
	Mat image = imread("test.jpg");
//	cvtColor(image, image, CV_BGR2RGB);//读进图像的通道需要转换才符合正常RGB
	

// 像素级访问测试
	uchar table[256];
	for (int i = 0; i < 256; ++i)
		table[i] = (uchar)(10 * (i / 10));
	

	double t = (double)getTickCount();
	// do something ...
	Mat cstyle = ScanImageAndReduceC(image, table);
	t = ((double)getTickCount() - t) / getTickFrequency();
	cout << "Times passed in seconds: " << t << endl;

	t = (double)getTickCount();
	// do something ...
	Mat Iteratorway = ScanImageAndReduceIterator(image, table);
	t = ((double)getTickCount() - t) / getTickFrequency();
	cout << "Times passed in seconds: " << t << endl;

	t = (double)getTickCount();
	// do something ...
	Mat RandomAccessWay = ScanImageAndReduceRandomAccess(image, table);
	t = ((double)getTickCount() - t) / getTickFrequency();
	cout << "Times passed in seconds: " << t << endl;


	t = (double)getTickCount();
	// do something ...
	Mat J;
	vector<uchar> lookUpTable(table, table+(sizeof(table)/sizeof(uchar)));
	LUT(image, lookUpTable, J);
	t = ((double)getTickCount() - t) / getTickFrequency();
	cout << "Times passed in seconds: " << t << endl;

    return 0;
}

