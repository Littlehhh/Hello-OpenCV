#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
void Menu()
{
	cout << "\t\t\t\t   1 ��˹��������" << endl;
	cout << "\t\t\t\t   2 ������������" << endl;
	//cout << "\t\t\t\t   1 ��˹����ԭʼͼ" << endl;
	//cout << "\t\t\t\t   2 ��������ԭʼͼ" << endl;
	//cout << "\t\t\t\t   3 ��˹������ֵ�˲�" << endl;
	//cout << "\t\t\t\t   4 ��˹������ֵ�˲�" << endl;
	//cout << "\t\t\t\t   5 ����������ֵ�˲�" << endl;
	//cout << "\t\t\t\t   6 ����������ֵ�˲�" << endl;
	//cout << "\t\t\t\t   7 ��˹������˹�˲�" << endl;
}
int main()
{	//����Mat����󲢶���ͼƬ
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
		{	//��ʾͼƬ
		case 1:	imshow("��˹����ԭͼ��", input_gaussian); 
			blur(input_gaussian, outImg_ave, Size(3, 3));
			medianBlur(input_gaussian, outImg_median, 3);
			GaussianBlur(input_gaussian, outImg_gaussian, Size(3, 3),0,0);
			imshow("��˹������ֵ�˲�����ͼ��", outImg_ave);
			imshow("��˹������ֵ�˲�����ͼ��", outImg_median);
			imshow("��˹������˹�˲�����ͼ��", outImg_ave); waitKey(0); break;
		case 2:	imshow("��������ԭͼ��", input_salt); 
			blur(input_salt, outImg_ave, Size(3, 3));
			medianBlur(input_salt, outImg_median, 3);
			imshow("����������ֵ�˲�����ͼ��", outImg_ave);
			imshow("����������ֵ�˲�����ͼ��", outImg_median);waitKey(0);break;

		default: cout << "Please Enter 1 ~ 8 ." << endl;break;
			
			//while (char(waitKey(1)) != 'q') {}
		}

		

	}
}	
//	//CV_EXPORTS_W void imshow(const String& winname, InputArray mat);
//
//	//��ֵ�˲�  �������־���
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
//	//��ֵ�˲�
//	medianBlur(input_gaussian, outImg_median, 3);
//	//CV_EXPORTS_W void medianBlur(InputArray src, OutputArray dst, int ksize);
//
//	//��˹�˲�
//	GaussianBlur(input_gaussian, outImg_median, Size(3,3), 0);
//	//CV_EXPORTS_W void GaussianBlur(InputArray src, OutputArray dst, Size ksize,
//	//	double sigmaX, double sigmaY = 0,
//	//	int borderType = BORDER_DEFAULT);
//
//	imshow("����������ֵ�˲�����ͼ��", outImg_median);
//	imshow("����������ֵ�˲�����ͼ��", outImg_ave);
//	
//	
//	//imshow("��˹����ԭͼ��", input_gaussian);
//	//���ִ��� ������˳�
//	
//	
//	waitKey(0);




