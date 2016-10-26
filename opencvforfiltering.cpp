#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
void Menu()
{
	cout << "\t\t\t\t   1 高斯噪声处理" << endl;
	cout << "\t\t\t\t   2 椒盐噪声处理" << endl;
	//cout << "\t\t\t\t   1 高斯噪声原始图" << endl;
	//cout << "\t\t\t\t   2 椒盐噪声原始图" << endl;
	//cout << "\t\t\t\t   3 高斯噪声均值滤波" << endl;
	//cout << "\t\t\t\t   4 高斯噪声中值滤波" << endl;
	//cout << "\t\t\t\t   5 椒盐噪声均值滤波" << endl;
	//cout << "\t\t\t\t   6 椒盐噪声中值滤波" << endl;
	//cout << "\t\t\t\t   7 高斯噪声高斯滤波" << endl;
}
int main()
{	//定义Mat类对象并读入图片
	Mat input_salt = imread("circuitboardNoise-salt.tif");
	Mat input_gaussian = imread("circuitboardNoise-gaussian.tif");
	Mat outImg_ave,outImg_median,outImg_gaussian;
	//CV_EXPORTS_W Mat imread(const String& filename, int flags = IMREAD_COLOR);
	Menu();
	int select;
	
	while (1)
	{
		cin >> select;
		switch (select)
		{	//显示图片
		case 1:	imshow("高斯噪声原图像", input_gaussian); 
			blur(input_gaussian, outImg_ave, Size(3, 3));
			medianBlur(input_gaussian, outImg_median, 3);
			GaussianBlur(input_gaussian, outImg_gaussian, Size(3, 3),0,0);
			imshow("高斯噪声均值滤波处理图像", outImg_ave);
			imshow("高斯噪声中值滤波处理图像", outImg_median);
			imshow("高斯噪声高斯滤波处理图像", outImg_ave); waitKey(0); break;
		case 2:	imshow("椒盐噪声原图像", input_salt); 
			blur(input_salt, outImg_ave, Size(3, 3));
			medianBlur(input_salt, outImg_median, 3);
			imshow("椒盐噪声均值滤波处理图像", outImg_ave);
			imshow("椒盐噪声中值滤波处理图像", outImg_median);waitKey(0);break;

		default: cout << "Please Enter 1 ~ 8 ." << endl;break;
			
			//while (char(waitKey(1)) != 'q') {}
		}

		

	}
}	
//	//CV_EXPORTS_W void imshow(const String& winname, InputArray mat);
//
//	//均值滤波  以下两种均可
////	boxFilter(input_gaussian, outImg_ave, input_gaussian.depth(), Size(3,3),Point(-1,-1),true);
//	blur(input_gaussian, outImg_ave, Size(3, 3));
//	//CV_EXPORTS_W void boxFilter(InputArray src, OutputArray dst, int ddepth,
//	//	Size ksize, Point anchor = Point(-1, -1),
//	//	bool normalize = true,
//	//	int borderType = BORDER_DEFAULT);
//	//CV_EXPORTS_W void blur(InputArray src, OutputArray dst,
//	//	Size ksize, Point anchor = Point(-1, -1),
//	//	int borderType = BORDER_DEFAULT);
//
//	//中值滤波
//	medianBlur(input_gaussian, outImg_median, 3);
//	//CV_EXPORTS_W void medianBlur(InputArray src, OutputArray dst, int ksize);
//
//	//高斯滤波
//	GaussianBlur(input_gaussian, outImg_median, Size(3,3), 0);
//	//CV_EXPORTS_W void GaussianBlur(InputArray src, OutputArray dst, Size ksize,
//	//	double sigmaX, double sigmaY = 0,
//	//	int borderType = BORDER_DEFAULT);
//
//	imshow("椒盐噪声中值滤波处理图像", outImg_median);
//	imshow("椒盐噪声均值滤波处理图像", outImg_ave);
//	
//	
//	//imshow("高斯噪声原图像", input_gaussian);
//	//保持窗口 任意键退出
//	
//	
//	waitKey(0);




