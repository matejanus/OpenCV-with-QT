#pragma once
#include <memory>
#include <QObject>
#include <QImage>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class OpenCvWorker : public QObject
{
    Q_OBJECT

private:
    cv::Mat m_originalFrame;
    cv::Mat m_procesedFrame;

    cv::VideoCapture *cap;
    std::unique_ptr<cv::VideoCapture> cap2;

    bool status;
    bool toggleStream;
    bool binaryThresholdEnabled;
    int binarryThreshold;

    void checkIfDeviceOpened(const int device);
    void process();
public:
    explicit OpenCvWorker(QObject *parent = nullptr);
    ~OpenCvWorker();

signals:
    void sendFrame(QImage frameProcessed);
    void sendStatus(QString msg, int code);

public slots:
    void receiveGrabFrame();
    void receiveSetup(const int device);
    void receiveToggleStream();

    void receiveEnableBinaryThreshold();
    void receiveBinaryThreshold(int threshold);
};


