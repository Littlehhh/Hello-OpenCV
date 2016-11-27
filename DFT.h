#ifndef DFT_H_
#define	DFT_H_

#include "opencv2/opencv.hpp"

#include <iostream>
using namespace cv;
using namespace std;

class myDFT {
private:
    Mat srcImage, complexI, dst;
public:
	explicit myDFT(const String &filename);
	explicit myDFT(Mat &srcImg);
		void Transform();
		void srcImageShow();
		void resultShow();		
        Mat& getdst();
};

#endif
