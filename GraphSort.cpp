#include <iostream>
#include <opencv2/opencv.hpp>
#include "myRandom.h"
//#include "mySort.h"
#define WINDOW_NAME "【啦啦啦】"
using namespace std;
using namespace cv;
//需要一个对象 有三个Point信息
void plot(Mat &m, int A[], int n, Scalar s);
void bubbleSort(Mat &m, int data[], int n);
void insertSort(Mat &m, int data[], int n);
void shellSort(Mat &m, int data[], int n);
void selectSort(Mat &m, int data[], int n);
void plotLine(Mat &m, int i, int height, bool signal);
void main()
{
	Point p1(200, 200);  //创建一个点
	int A[40];
	myRandom(0, 50, 40, A);
	Mat m = Mat::ones(600, 1000, CV_8UC3);
	Mat a = Mat::ones(2, 2, CV_8UC3);
	Point angle[3];

	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
	imshow(WINDOW_NAME, m);
	line(m, Point(20, 20), Point(80, 80), Scalar(50, 50, 50), 10);
	//bubbleSort(m, A, 20);
	//insertSort(m, A, 20);
	//shellSort(m, A, 20);
	selectSort(m, A, 40);
	waitKey(0);
	//putText(m,"hahaha",p1,3,2, Scalar(255, 129, 0),1);
}
void shellSort(Mat &m, int data[], int n)
{
	plot(m, data, n, Scalar(0, 255, 255));
	imshow(WINDOW_NAME, m);
	waitKey(50);
	int temp, i;
	for (int Increment = n / 2; Increment > 0; Increment /= 2)
	{
		for (i = Increment; i<n; i++)
		{
			circle(m, Point(20 + i * 20, 520), 5, Scalar(0, 0, 255), -1);
			temp = data[i];
			int j = 0;
			for (j = i; j >= Increment; j -= Increment)
			{
				circle(m, Point(20 + j * 20, 520), 5, Scalar(0, 0, 255), -1);
				circle(m, Point(20 + (j - Increment) * 20, 520), 5, Scalar(0, 0, 255), -1);
				imshow(WINDOW_NAME, m);
				waitKey(500);
				if (temp < data[j - Increment])
				{
					plotLine(m, j, data[j], false);
					plotLine(m, j - Increment, data[j - Increment], false);
					data[j] = data[j - Increment];
					plotLine(m, j, data[j], true);
					plotLine(m, j - Increment, data[j - Increment], true);
				}
				else
					break;
				circle(m, Point(20 + j * 20, 520), 5, Scalar(0, 0, 255), -1);
				circle(m, Point(20 + (j - Increment) * 20, 520), 5, Scalar(0, 0, 255), -1);
			}
			data[j] = temp;
			imshow(WINDOW_NAME, m);
			waitKey(500);

		}
		plot(m, data, n, Scalar(0, 255, 255));
		imshow(WINDOW_NAME, m);
		waitKey(500);
		plot(m, data, n, Scalar(0, 0, 0));
	}
}
void insertSort(Mat &m, int data[], int n)
{
	plot(m, data, n, Scalar(0, 255, 255));
	imshow(WINDOW_NAME, m);
	waitKey(50);
	for (int i = 1; i<n; i++)
	{
		circle(m, Point(20 + i * 20, 520), 5, Scalar(0, 0, 255), -1);
		imshow(WINDOW_NAME, m);
		waitKey(500);
		int temp = data[i];
		int j;
		for (j = i - 1;temp < data[j] && j >= 0;j--)
		{
			plot(m, data, n, Scalar(0, 0, 0));
			data[j + 1] = data[j];				
		}

	data[j + 1] = temp;
	circle(m, Point(20 + (j+1) * 20, 520), 5, Scalar(0, 0, 255), -1);
	circle(m, Point(20 + i * 20, 520), 5, Scalar(0, 0, 0), -1);
	plot(m, data, n, Scalar(0, 255, 255));
	imshow(WINDOW_NAME, m);	
	waitKey(500);
	circle(m, Point(20 + (j + 1) * 20, 520), 5, Scalar(0, 0, 0), -1);
	}
	imshow(WINDOW_NAME, m);
	waitKey(0);
}
void bubbleSort(Mat &m,int data[], int n)
{
	plot(m, data, n, Scalar(0, 255, 255));
	imshow(WINDOW_NAME, m);
	waitKey(50);
	for (int i = 0; i < n - 1; i++)
	{
		
		for (int j = n - 2; j >= i; j--)
		{
			circle(m, Point(20 + j * 20, 520), 5, Scalar(0, 0, 255), -1);
			circle(m, Point(20 + (j+1) * 20, 520), 5, Scalar(0, 0, 255), -1);
			imshow(WINDOW_NAME, m);
			waitKey(100);
			if (data[j] > data[j + 1])
			{
				plotLine(m, j, data[j], false);
				plotLine(m, j+1, data[j+1], false);
				data[j] = data[j] ^ data[j + 1];
				data[j + 1] = data[j] ^ data[j + 1];
				data[j] = data[j] ^ data[j + 1];
				plotLine(m, j, data[j], true);
				plotLine(m, j + 1, data[j + 1], true);
			}
			imshow(WINDOW_NAME, m);
			waitKey(100);
			circle(m, Point(20 + (j + 1) * 20, 520), 5, Scalar(0, 0, 0), -1);
		}
	}
}
void selectSort(Mat &m, int data[], int n)
{
	plot(m, data, n, Scalar(0, 255, 255));
	imshow(WINDOW_NAME, m);
	waitKey(50);
	for (int i = 0; i<n - 1; i++)
	{
		int min = i;
		circle(m, Point(20 + i * 20, 520), 5, Scalar(255, 0, 255), -1);
		for (int j = i + 1; j < n; j++)
		{
			circle(m, Point(20 + min * 20, 550), 5, Scalar(0, 0, 255), -1);
			circle(m, Point(20 + j * 20, 550), 5, Scalar(0, 0, 255), -1);
			imshow(WINDOW_NAME, m);
			waitKey(50);
			circle(m, Point(20 + j * 20, 550), 5, Scalar(0, 0, 0), -1);
			if (data[min] > data[j])
			{
				circle(m, Point(20 + min * 20, 550), 5, Scalar(0, 0, 0), -1);
				circle(m, Point(20 + j * 20, 550), 5, Scalar(0, 0, 255), -1);
				min = j;
			}
		}
		if (min != i)
		{
			plotLine(m, min,data[min] , false);
			plotLine(m, i, data[i], false);					
			data[i] = data[i] ^ data[min];
			data[min] = data[i] ^ data[min];
			data[i] = data[i] ^ data[min];
		}
		plotLine(m, min, data[min], true);
		plotLine(m, i, data[i], true);
		circle(m, Point(20 + min * 20, 550), 5, Scalar(0, 0, 0), -1);	
		imshow(WINDOW_NAME, m);
		waitKey(100);
		//plot(m, data, n, Scalar(0, 0, 0));
	}
	circle(m, Point(n * 20, 520), 5, Scalar(255, 0, 255), -1);
	imshow(WINDOW_NAME, m);
	waitKey(0);
}
void plotLine(Mat &m,int i,int height,bool signal)
{
	Scalar s;
	if (signal == true)
		s = Scalar(0, 255, 255);
	else
		s = Scalar(0, 0, 0);
	line(m, Point(20 + 20*i, 500 - height * 10), Point(20 + 20 * i, 500), s, 7);
}

void plot(Mat &m,int A[],int n,Scalar s)
{
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		//circle(m, Point(20 + x, 550), 5, Scalar(0, 255, 255), -1);
			line(m, Point(20 + x, 500 - A[i] * 10), Point(20 + x, 500), s, 7);
			x += 20;
	}
}




