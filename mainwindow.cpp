#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DFT.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"),"",tr("Image File(*.bmp *.tif *.jpg *.jpeg *.png)"));
     QTextCodec *code = QTextCodec::codecForName("gb18030");
     std::string name = code->fromUnicode(filename).data();
     //image = cv::imread(name,0);
     myDFT img(name);
     img.Transform();
     img.resultShow();
     image = img.getdst();
	 vector<int> compression_params;
	 compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
     compression_params.push_back(9);
	 imwrite("123.png",image, compression_params);
	 namedWindow("test");
	 imshow("test", image);
     waitKey(10);
     image.convertTo(image,1);

     image = image*255;
     if(!image.data)
     {
         QMessageBox msgBox;
         msgBox.setText(tr("image data is null"));
         msgBox.exec();
     }
     else
        display(image);
}

void MainWindow::display(cv::Mat mat)
{
    cv::Mat rgb;
    QImage img;
    //cv::cvtColor(mat, rgb, CV_GRAY2BGR);
    if(mat.channels()==3)
    {
        cv::cvtColor(mat,rgb,CV_BGR2RGB);
        img = QImage((const uchar*)(rgb.data),rgb.cols,rgb.rows,rgb.cols*rgb.channels(),QImage::Format_RGB888);
    }
    else
    {

                img = QImage( mat.data,
                            mat.cols, mat.rows,
                            static_cast<int>(mat.step),
                            QImage::Format_Grayscale8 );

//        static QVector<QRgb>  sColorTable( 256 );

//        // only create our color table the first time
//        if ( sColorTable.isEmpty() )
//        {
//           for ( int i = 0; i < 256; ++i )
//           {
//              sColorTable[i] = qRgb( i, i, i );
//           }
//        }
//        //img = QImage((const uchar*)(mat.data),mat.cols,mat.rows,mat.cols*mat.channels(),QImage::Format_Indexed8);

//        img = QImage( mat.data,
//                    mat.cols, mat.rows,
//                    static_cast<int>(mat.step),
//                    QImage::Format_Indexed8 );

//        img.setColorTable( sColorTable );
        //QImage img(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
//        img.setColorCount(256);
//        for(int i = 0; i < 256; i++)
//        {
//            img.setColor(i, qRgb(i, i, i));
//        }
//        // Copy input Mat
//        uchar *pSrc = mat.data;
//        for(int row = 0; row < mat.rows; row ++)
//        {
//            uchar *pDest = img.scanLine(row);
//            memcpy(pDest, pSrc, mat.cols);
//            pSrc += mat.step;
//        }
    }
  //  img.save("456.jpg", "JPG");
    qDebug()<<img.allGray()<<img.alphaChannel()<<img.isGrayscale();
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(ui->label->pixmap()->size());
    ui->label->show();
}

void MainWindow::on_fft_clicked()
{
//    myDFT fft(this->image);
//    fft.Transform();
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"),"",tr("Image File(*.bmp *.tif *.jpg *.jpeg *.png)"));
    QTextCodec *code = QTextCodec::codecForName("gb18030");
    std::string name = code->fromUnicode(filename).data();
        QImage img(filename);
//    cv::Mat rgb = fft.getdst();
//    QImage img;
//    if(rgb.channels()==3)
//    {
//        cv::cvtColor(rgb,rgb,CV_BGR2RGB);
//        img = QImage((const uchar*)(rgb.data),rgb.cols,rgb.rows,rgb.cols*rgb.channels(),QImage::Format_RGB888);
//    }
//    else
//    {
//        img = QImage((const uchar*)(rgb.data),rgb.cols,rgb.rows,rgb.cols*rgb.channels(),QImage::Format_Indexed8);
//    }
    ui->label_2->setPixmap(QPixmap::fromImage(img));
    ui->label_2->resize(ui->label_2->pixmap()->size());
    ui->label_2->show();
}

