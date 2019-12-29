#include "opencvworker.h"

OpenCvWorker::OpenCvWorker(QObject *parent) : QObject(parent),
    status(false),
    toggleStream(false),
    binaryThresholdEnabled(false),
    binarryThreshold(127)
{
    cap = new cv::VideoCapture();
    cap2 = std::make_unique<cv::VideoCapture>();
}

OpenCvWorker::~OpenCvWorker()
{
    if(cap->isOpened())
        cap->release();
    delete cap;
}

void OpenCvWorker::receiveGrabFrame(){

    if(!toggleStream) return;

    *cap >> m_originalFrame;
    if(m_originalFrame.empty()) return;

    process();
    cv::resize(m_procesedFrame, m_procesedFrame, cv::Size(), 0.75, 0.75);

    QImage output(static_cast<const unsigned char*>(m_procesedFrame.data), m_procesedFrame.cols, m_procesedFrame.rows, QImage::Format_Indexed8);

    emit sendFrame(output);
}

void OpenCvWorker::checkIfDeviceOpened(const int device){

    if(cap->isOpened()){
        cap->release();
    }
    cap->open(device);

}

void OpenCvWorker::process()
{
    cv::cvtColor(m_originalFrame, m_procesedFrame, cv::COLOR_BGR2GRAY);
    if(binaryThresholdEnabled)
    {
        cv::threshold(m_originalFrame, m_procesedFrame, binarryThreshold, 255, cv::THRESH_BINARY);
    }

}

void OpenCvWorker::receiveSetup(const int device)
{
    checkIfDeviceOpened(device);
    if(!cap->isOpened())
    {
        status = false;
        return;
    }
    else
        status = true;

}

void OpenCvWorker::receiveToggleStream(){
    toggleStream = !toggleStream;
}

void OpenCvWorker::receiveEnableBinaryThreshold()
{
    binaryThresholdEnabled = !binaryThresholdEnabled;
}

void OpenCvWorker::receiveBinaryThreshold(int threshold){
    binarryThreshold = threshold;
}
