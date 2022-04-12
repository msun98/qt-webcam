#ifndef CAMERA_H
#define CAMERA_H
#include <iostream>
#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QTimer>

using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class camera; }
QT_END_NAMESPACE

class camera : public QMainWindow
{
    Q_OBJECT

public:
    camera(QWidget *parent = nullptr);
    ~camera();
    QTimer timer; //타이머 클래스의 객체 생성
    VideoCapture cap;// cv클래스의 videocapture 함수를 사용하기 위해 cap이라는 객체를 생성.

private slots:
    void on_shooting_clicked();
    void timeloop();

private:
    Ui::camera *ui;
};
#endif // CAMERA_H
