#include <iostream>
#include <opencv2/opencv.hpp>
#define WINDOW_NAME "【啦啦啦】"
using namespace std;
using namespace cv;
 

void main()
{
	Point p1(200,200);  //创建一个点
	//Vec<Point 5> v;
	Size s1(500,500);  //尺寸
	Rect rect(1,1,100,100);
	//Mat m(1,);
	Scalar sc(1,1,1);
	Range range(1,100);
	Mat m(1000,1000,CV_8UC1);
	Mat a = Mat::zeros(10, 10, CV_8UC1);
	//m::diag();
	m = Mat::zeros(m.rows,m.cols, CV_8UC1);
	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
	circle(m,Point(500,500),50, Scalar(255, 129, 0),50,10);
	putText(m,"hahaha",p1,3,2, Scalar(255, 129, 0),1);
	//fillConvexPoly(m,p1,Scalar(255, 0, 0));
	imshow(WINDOW_NAME,m);
	waitKey();
}