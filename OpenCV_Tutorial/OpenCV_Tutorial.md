OpenCV Tutorial
====
****
#### Author: Hui Wang
#### E-mail: 1061659563@qq.com or wanghuichn@yahoo.com
****
## CONTENT
* [配置 OpenCV](##配置OpenCV)
* [Mat Class](##MatClass)
## 配置 OpenCV
### Visual Studio + OpenCV (for C++)
  [Visual Studio配置OpenCV.pdf
](https://github.com/Littlehhh/Hello-OpenCV/blob/master/OpenCV_Tutorial/Visual%20Studio%E9%85%8D%E7%BD%AEOpenCV.pdf)
### Python + OpenCV (for Python)
  1. 安装 Anaconda (Python的科学计算发行版)
  [`Anaconda介绍及下载地址`](https://www.continuum.io/)
  2. 下载编译好的 OpenCV for Python 的 whl 文件  
  [选择合适的版本](http://www.lfd.uci.edu/~gohlke/pythonlibs/)
  For instance：opencv_python‑3.2.0‑cp35‑cp35m‑win_amd64.whl(version code)  
  `3.2.0` is OpenCV version  
  `cp35` 35 is Python version 3.5
  `win_amd64` is 64bit windows
  3. 打开CMD进入下载好的 whl 文件的目录，使用如下代码
  `pip install [your whl filename]`

  4. 打开 IPython 输入
  `import cv2`  
    如果没有报错就安装成功了
## Mat Class
The Basic Image Container   (核心容器 Mat)
### Basic Knowledge (from C Struct to C++ Class)
```C
struct A{//for a instance
  int a;
  char b;
  double c;
  //Some Properties
};
```
```C++
class A{//for a instance
  int a;
  char b;
  double c;
  //Some Properties
  A();
  A(int a, int b, int c);
  //Some Constructor Functions 构造函数
  void f1();
  int f2();
  //Some Functions
  ~A();
  //Destructor 析构函数
  .....
};
```
> What is Constructor
>> A aa( a, b, c); //C++ codes 初始化一个变量

### Mat Basic Properties(Mat类基本属性)
  * int flags;  
  includes several bit-fields:
    - the magic signature
    - continuity flag
    - depth
    - number of channels  
    ![](http://img.blog.csdn.net/20150210135526729?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQveWl5dWVodWFu/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
  * int dims; //矩阵维度 >=2
  * int rows, cols; //Mat的行数和列数 如果dims>2 则rows=cols=-1
  * uchar* data; //Mat的矩阵数据
### Mat Constructor (Mat类构造函数)
#### 不指定任何参数，只声明变量
  * Mat() //无参构造函数
#### 只指定尺寸和类型
  * Mat(int rows,int cols,int type)
  * Mat(Size size, int type);
  * Mat(int ndims, const int* sizes, int type);
#### 指定尺寸、类型、和内容
  * Mat(int rows, int cols, int type, const Scalar& s);
  * Mat(Size size, int type, const Scalar& s);
  * Mat(int ndims, const int* sizes, int type, const Scalar& s);
  * Mat(int rows, int cols, int type, void* data, size_t step=AUTO_STEP);
  * Mat(Size size, int type, void* data, size_t step=AUTO_STEP);
  * Mat(int ndims, const int* sizes, int type, void* data, const size_t* steps=0);
#### 拷贝构造函数（浅拷贝）
  * Mat(const Mat& m);
  * Mat(const Mat& m, const Range& rowRange, const Range& colRange=Range::all());
  * Mat(const Mat& m, const Rect& roi);
  * Mat(const Mat& m, const Range* ranges);
### Mat Common Functions
  * void resize(size_t sz);//Changes the number of matrix rows.
  * size_t elemSize() const;//返回矩阵（元素*通道）字节数
  * int type() const;//返回矩阵元素类型
  * int depth() const;//返回矩阵元素深度
  * int channels() const;//返回通道数
  * size_t total() const;//返回元素总数
  * size_t elemSize1() const;//返回矩阵元素字节数
  * void create(int rows, int cols, int type);
  * void create(Size size, int type);
  * void create(int ndims, const int* sizes, int type);
  `该函数将为存在的Mat对象重新分配空间`
  * Mat diag(int d=0) const; //返回Mat对象的对角阵
  * void convertTo( OutputArray m, int rtype, double alpha=1, double beta=0 ) const;//转换Mat的数据类型
  * void assignTo( Mat& m, int type=-1 ) const;//将Mat的类型转为与 m 相同的类型 type Desired destination array depth
  * MatExpr t() const;//转置
  * MatExpr inv(int method=DECOMP_LU) const;//逆矩阵
#### Static Function（matlab风格）
  * static Mat diag(const Mat& d);
  * static MatExpr zeros(int rows, int cols, int type);
  * static MatExpr zeros(Size size, int type);
  * static MatExpr zeros(int ndims, const int* sz, int type);
  * static MatExpr ones(int rows, int cols, int type);
  * static MatExpr ones(Size size, int type);
  * static MatExpr ones(int ndims, const int* sz, int type);
  * static MatExpr eye(int rows, int cols, int type);
  * static MatExpr eye(Size size, int type);
#### 拷贝函数（深拷贝）full copy
  * Mat clone() const;
  * void copyTo( OutputArray m ) const;
  * void copyTo( OutputArray m, InputArray mask ) const;
### Function Parameters (上述函数参数)
  * ndims – Array dimensionality.
  * rows – Number of rows in a 2D array.
  * cols – Number of columns in a 2D array.
  * roi – Region of interest.
  * size – 2D array size: Size(cols, rows) . In the Size() constructor, the number of rows
  and the number of columns go in the reverse order.
  * sizes – Array of integers specifying an n-dimensional array shape.
  * type – Array type. Use CV_8UC1, ..., CV_64FC4 to create 1-4 channel matrices, or
  CV_8UC(n), ..., CV_64FC(n) to create multi-channel (up to CV_CN_MAX channels) matrices.  

  |CV_FLAG|BITS|TYPE|RANGE|
  |-----|-----|-----------------|--------------------|  
  |CV_8U|8-bit|unsigned integers| (0..255) |
  |CV_8S|8-bit|signed integers| (-128..127) |
  |CV_16U|16-bit|unsigned integers| (0..65535) |
  |CV_16S|16-bit|signed integers| (-32768..32767) |
  |CV_32S|32-bit|signed integers| (-2147483648..2147483647) |
  |CV_32F|32-bit|floating-point numbers| (-FLOAT_MAX..FLOAT_MAX) |
  |CV_64F|64-bit|floating-point numbers| (-DOUBLE_MAX..DOUBLE_MAX) |

  * s – An optional value to initialize each matrix element with. To set all the matrix
  elements to the particular value after the construction, use the assignment operator
  Mat::operator=(const Scalar& value) .
  * data – Pointer to the user data. Matrix constructors that take data and step parameters
  do not allocate matrix data. Instead, they just initialize the matrix header that points to
  the specified data, which means that no data is copied. This operation is very efficient and
  can be used to process external data using OpenCV functions. The external data is not
  automatically deallocated, so you should take care of it.
  * step – Number of bytes each matrix row occupies. The value should include the padding
  bytes at the end of each row, if any. If the parameter is missing (set to AUTO_STEP
  ), no padding is assumed and the actual step is calculated as cols*elemSize() . See
  Mat::elemSize() .
  * steps – Array of ndims-1 steps in case of a multi-dimensional array (the last step is always
  set to the element size). If not specified, the matrix is assumed to be continuous.
  * ranges – Array of selected ranges of m along each dimensionality
### Some Instances
```C++
// OpenCV_Tutorial_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream> // for C++ I/O  stream
#include <opencv2/core/mat.hpp> // for Mat class and other Basic class
#include <opencv2/highgui.hpp>//for imshow() GUI
#include <opencv2/imgproc/imgproc.hpp>//for cvtColor()
using namespace cv;

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
	std::cout <<   std::endl;
    return 0;
}
```
## Other Basic Class
> Attention: class_ means a template class
>> Here are some useful functions, but not the all.
### Point_
* Point_ ( _Tp _x, _Tp _y)
* Point_ (const Point_ &pt)
* Point_ (const Size_< _Tp > &sz)
* Point_ (const Vec< _Tp, 2 > &v)
### Size_
* Size_ (_Tp _width, _Tp _height)
* Size_ (const Size_ &sz)
* Size_ (const Point_< _Tp > &pt)
### Range
* Range (int _start, int _end)
* static Range::all()
### Scalar_
* Scalar_ (_Tp v0, _Tp v1, _Tp v2=0, _Tp v3=0)
* Scalar_ (_Tp v0)
* Scalar_ (const Vec< _Tp2, cn > &v)
## Access to the Mat pixel
A simple color reduction method
// 将256色缩减为26色
$$I_{new} = \frac {I_{odd}} {10} * 10$$
C++ int操作会自动取整

```C++
//create the lookup table
uchar table[256];
for (int i = 0; i < 256; ++i)
   table[i] = (uchar)(divideWith * (i/divideWith));
```
### The efficient way
C语言风格的访问方法
```C++
Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);
    int channels = I.channels();
    int nRows = I.rows;
    int nCols = I.cols * channels;
    //如果Mat在内存中是连续存储的么可以直接用一个指针从头访问到尾
    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }
    int i,j;
    uchar* p;
    for ( i = 0; i < nRows; ++i)
    {
        p = I.ptr<uchar>(i);//取每一行的行指针
        for ( j = 0; j < nCols; ++j)
        {
            p[j] = table[p[j]];
        }
    }
    return I;
}
```
### The iterator (safe) method
Mat类迭代器方法，十分安全，但是影响效率
```C++
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);
    // A function for DEBUG MODE inherited from C++ standard library
    const int channels = I.channels();
    switch(channels)
    {
    case 1:
        {
            MatIterator_<uchar> it, end;
            // 取Mat的头、尾迭代器  灰度模式下
            for( it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
                *it = table[*it];
            break;
        }
    case 3:
        {
            MatIterator_<Vec3b> it, end;
            // 取Mat的头、尾迭代器  RGB模式下
            for( it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
            {
                (*it)[0] = table[(*it)[0]];
                (*it)[1] = table[(*it)[1]];
                (*it)[2] = table[(*it)[2]];
            }
        }
    }
    return I;
}
```
### On-the-fly address calculation with reference returning
动态地址计算 更慢的方法 但是可以随机访问
A Common function in Mat class
Mat.at<T>(rows,cols);
```C++
Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);
    // A function for DEBUG MODE inherited from C++ standard library
    const int channels = I.channels();
    switch(channels)
    {
    case 1:
        {
            for( int i = 0; i < I.rows; ++i)
                for( int j = 0; j < I.cols; ++j )
                    I.at<uchar>(i,j) = table[I.at<uchar>(i,j)];
            break;
        }
    case 3:
        {
            Mat_<Vec3b> _I = I;
            for( int i = 0; i < I.rows; ++i)
            for( int j = 0; j < I.cols; ++j )
               {
                   _I(i,j)[0] = table[_I(i,j)[0]];
                   _I(i,j)[1] = table[_I(i,j)[1]];
                   _I(i,j)[2] = table[_I(i,j)[2]];
            }
         I = _I;
         break;
        }
    }
    return I;
}

```
### The Core Function
void cv::LUT 	( 	InputArray  	src,
		InputArray  	lut,
		OutputArray  	dst
  ) 	
```C++
Mat lookUpTable(1, 256, CV_8U);
uchar* p = lookUpTable.ptr();
for( int i = 0; i < 256; ++i)
    p[i] = table[i];

LUT(I, lookUpTable, J);
```
### Measure Time
Some codes for Measure Time
```C++
double t = (double)getTickCount();
// do something ...
t = ((double)getTickCount() - t)/getTickFrequency();
cout << "Times passed in seconds: " << t << endl;
```
### Performance Difference
|Method|Time|
|:------:|:----:|
|Efficient Way|0.0367628s|
|Iterator|1.40072s|
|On-The-Fly RA|2.23297s|
|LUT function|0.0128981s|
