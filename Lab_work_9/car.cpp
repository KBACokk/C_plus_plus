#include "car.h"
#include "./ui_car.h"

 #define dt 10
#define path_forward "C:/Users/alt_ma1n/Documents/Car/RIS/cari1"
#define path_back  "C:/Users/alt_ma1n/Documents/Car/RIS/cari2"
int k =0;

Car::Car(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Car)
{
    ui->setupUi(this);
}


void Car::onTimeout()
{
    if(ui->label->geometry().x()<660 && k==0)//не доехали до правого края
    {
        ui->label->setPixmap(QPixmap(path_forward));
        ui->label->setGeometry(ui->label->geometry().x()+dt,261,161,101);
    }
    else
    {
        k=1;
        ui->label->setPixmap(QPixmap(path_back));
        ui->label->setGeometry(ui->label->geometry().x()-
                                   dt,261,161,101);
        if(ui->label->geometry().x()<5)k=0; // доехали до левого края
    }
}


Car::~Car()
{
    delete ui;
}

void Car::on_actionstart_triggered()
{
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    timer->start(100);
}


void Car::on_actionstop_triggered()
{
    timer->stop();
}


void Car::on_actionexit_triggered()
{
    QApplication::exit();
}

