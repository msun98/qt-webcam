#include "camera.h"
#include "ui_camera.h"

camera::camera(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::camera),cap(0)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeloop()));
}

camera::~camera()
{
    delete ui;
}


void camera::on_shooting_clicked()
{
//    Mat img = imread("1.jpg", IMREAD_COLOR);
//QFileDialog() // 이미지를 불러올 폴더를 열어주면 클릭하면 됨.
//    imshow("display window",img);

//    if (cap.isOpened())// 카메라가 열렸을 때
//    {
//        Mat img;
////        cv 클래스의 Mat함수를 리턴받을 이미지를 저장할 인자의 이름을 img라 선언.
////        OpenCV 에서 기본적으로 이미지를 로딩하면 cv::Mat 을 리턴하게 된다. cv::Mat 에 이미지의 각 픽셀에 대한 정보가 기록되어 있으며,
////        프로그래머는 값을 읽고 수정할 수 있다. 이미지는 어떤 형태로 로딩을 하느냐에 따라 cv::Mat 의 데이터 구조가 다르며,
////        값을 읽고 수정하는 방법도 여러 가지 방법이 있다.

//        cap >> img; // 카메라로 부터 받은 이미지를 img 에 저장

//        QImage qimg(img.data, img.cols, img.rows,QImage::Format_BGR888);
//        ui->load_image->setPixmap(QPixmap::fromImage(qimg));}
////        QImage로 이미지를 불러온다. -> QPixmap에 옮긴다. -> QLabel에서 QPixmap를 불러와서 화면에 출력한다.
///
///     ui -> Dialog -> setPlainText("Hello");

    timer.setInterval(33);//몇 미리세컨드마다 쓸것인가???, 타이머의 멤버 함수
    timer.start();// 타이머 켜는 함수, 타이머의 멤버 함수
}

void camera::timeloop()
{
    if (cap.isOpened())// 카메라가 열렸을 때
    {
        Mat img;
//        cv 클래스의 Mat함수를 리턴받을 이미지를 저장할 인자의 이름을 img라 선언.
//        OpenCV 에서 기본적으로 이미지를 로딩하면 cv::Mat 을 리턴하게 된다. cv::Mat 에 이미지의 각 픽셀에 대한 정보가 기록되어 있으며,
//        프로그래머는 값을 읽고 수정할 수 있다. 이미지는 어떤 형태로 로딩을 하느냐에 따라 cv::Mat 의 데이터 구조가 다르며,
//        값을 읽고 수정하는 방법도 여러 가지 방법이 있다.

        cap >> img; // 카메라로 부터 받은 이미지를 img 에 저장

        QImage qimg(img.data, img.cols, img.rows,QImage::Format_BGR888);
        ui->load_image->setPixmap(QPixmap::fromImage(qimg));}
//        QImage로 이미지를 불러온다. -> QPixmap에 옮긴다. -> QLabel에서 QPixmap를 불러와서 화면에 출력한다.
}
