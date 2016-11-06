#include <iostream>
#include <opencv2/opencv.hpp>
#include "myRandom.h"
//#include "mySort.h"
#define WINDOW_NAME "【啦啦啦】"
using namespace std;
using namespace cv;

void plot(Mat &m, int A[], int n, Scalar s);
void bubbleSort(Mat &m, int data[], int n);
void insertSort(Mat &m, int data[], int n);
void shellSort(Mat &m, int data[], int n);
void selectSort(Mat &m, int data[], int n);
void plotLine(Mat &m, int i, int height, bool signal);
void Menu()
{
	cout << "********Something Interesting**********" << endl;
	cout << "***********************by WangHui******" << endl;
	cout << "          1 bubbleSort" << endl;
	cout << "          2 insertSort" << endl;
	cout << "          3 selectSort" << endl;
	cout << "          4 shellSort" << endl;
	cout << "          5 EXIT" << endl;
}
void main()
{
	int A[100],start,end,n,select;
//	cout << "请输入随机数个数" << endl;
//	cin >> n;
//	cout << "请输入随机数产生范围" << endl;
//	cin >> start >> end;
	//生成随机数 
	start = 1;
	end = 45;
	n = 20;
	
//	myRandom(0, 50, 40, A);
	Mat m;// = Mat::ones(600, (21 * n), CV_8UC3);

	while (1)
	{
		myRandom(start, end, n, A);
		m = Mat::ones(600, (21 * n), CV_8UC3);
		Menu();
		cin >> select;
		namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
		//putText(m, "bubbleSort", Point(80, 20), 3, 1, Scalar(255, 129, 0), 1);
		imshow(WINDOW_NAME, m);
		switch (select)
		{
		case 1:putText(m, "bubbleSort", Point((m.cols/2-90),570), 3, 1, Scalar(255,0,0), 1);
			bubbleSort(m, A, n); waitKey(0); break;
		case 2:putText(m, "insertSort", Point((m.cols / 2 - 90), 570), 3, 1, Scalar(255, 0, 0), 1);
			insertSort(m, A, n); waitKey(0); break;
		case 3:putText(m, "selectSort", Point((m.cols / 2 - 90), 570), 3, 1, Scalar(255, 0, 0), 1); 
			selectSort(m, A, n); waitKey(0); break;
		case 4:putText(m, "shellSort", Point((m.cols / 2 - 80), 570), 3, 1, Scalar(255, 0, 0), 1); 
			shellSort(m, A, n); waitKey(0); break;
		case 5:return;
		default:cout << "请输入1~5之间的功能" << endl;
		}

	}

	//waitKey(0);
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
			circle(m, Point(20 + (i - Increment) * 20, 520), 5, Scalar(0, 0, 255), -1);
			imshow(WINDOW_NAME, m);
			waitKey(50);
			plot(m, data, n, Scalar(0, 0, 0));		
			temp = data[i];
			int j = 0;
			for (j = i; j >= Increment; j -= Increment)
			{
				if (temp < data[j - Increment])
				{
					data[j] = data[j - Increment];
				}
				else
					break;
			}	
			data[j] = temp; 
			plot(m, data, n, Scalar(0, 255, 255));
			circle(m, Point(20 + i * 20, 520), 5, Scalar(0, 0, 0), -1);
			circle(m, Point(20 + (i - Increment) * 20, 520), 5, Scalar(0, 0, 0), -1);
			imshow(WINDOW_NAME, m);
			waitKey(50);
		}
	}
}
void insertSort(Mat &m, int data[], int n)
{
	plot(m, data, n, Scalar(0, 255, 255));
	imshow(WINDOW_NAME, m);
	waitKey(200);
	for (int i = 1; i<n; i++)
	{
		circle(m, Point(20 + i * 20, 520), 5, Scalar(0, 0, 255), -1);
		imshow(WINDOW_NAME, m);
		waitKey(200);
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
	waitKey(100);
	circle(m, Point(20 + (j + 1) * 20, 520), 5, Scalar(0, 0, 0), -1);
	}
	imshow(WINDOW_NAME, m);
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
			waitKey(50);
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
			waitKey(50);
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
			circle(m, Point(20 + min * 20, 535), 5, Scalar(0, 0, 255), -1);
			circle(m, Point(20 + j * 20, 535), 5, Scalar(0, 0, 255), -1);
			imshow(WINDOW_NAME, m);
			waitKey(50);
			circle(m, Point(20 + j * 20, 535), 5, Scalar(0, 0, 0), -1);
			if (data[min] > data[j])
			{
				circle(m, Point(20 + min * 20, 535), 5, Scalar(0, 0, 0), -1);
				circle(m, Point(20 + j * 20, 535), 5, Scalar(0, 0, 255), -1);
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
		circle(m, Point(20 + min * 20, 535), 5, Scalar(0, 0, 0), -1);	
		imshow(WINDOW_NAME, m);
		waitKey(50);
	}
	circle(m, Point(n * 20, 520), 5, Scalar(255, 0, 255), -1);
	imshow(WINDOW_NAME, m);
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




