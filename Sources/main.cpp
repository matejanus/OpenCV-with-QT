#include "qcvwidget.h"

#include <QApplication>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCvWidget w;
    cv::Mat image;
    w.show();
    return a.exec();
}
