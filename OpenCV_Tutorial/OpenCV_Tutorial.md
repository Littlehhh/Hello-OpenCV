OpenCV Tutorial
====
****
### Author: Hui Wang
### E-mail: 1061659563@qq.com or wanghuichn@yahoo.com
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
#### 拷贝构造函数（深拷贝）full copy
  * Mat clone() const;
  * void copyTo( OutputArray m ) const;
  * void copyTo( OutputArray m, InputArray mask ) const;
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
