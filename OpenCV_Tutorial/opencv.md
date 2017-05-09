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
### Python 3.6 + OpenCV (for Python)
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
### Mat Constructor (Mat类构造函数)
  * Mat() //无参构造函数
  * Mat(int rows,int cols,int type) 	
