#ifndef QCVWIDGET_H
#define QCVWIDGET_H

#include <QWidget>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class QCvWidget; }
QT_END_NAMESPACE

class QCvWidget : public QWidget
{
    Q_OBJECT

public:
    QCvWidget(QWidget *parent = nullptr);
    ~QCvWidget();

private:
    Ui::QCvWidget *ui;
    QThread *thread;

    void setup();

signals:
    void sendSetup(int device);
    void sendToggleStream();

private slots:
    void receiveFrame(QImage frame);
    void receiveToggleStream();

};
#endif // QCVWIDGET_H
