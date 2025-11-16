#include "prog2.h"
#include "./ui_prog2.h"
#include <cmath>
#include "QMessageBox"
#include <QMainWindow>
#include <QtCharts/QChartView>


Prog2::Prog2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Prog2)
{
    ui->setupUi(this);
}

Prog2::~Prog2()
{
    delete ui;
}

void Prog2::on_pushButton_clicked()
{
    double start,end,step;
    double x,y;
    QString s1,s2,s3;
    QString str(""); // переменная-строка и ее очистка

    double A = -2;
    double B = 5;
    double C = 7;

    s1=ui->lineEdit->text();
    start=s1.toDouble();
    s2=ui->lineEdit_2->text();
    end=s2.toDouble();
    s3=ui->lineEdit_3->text();
    step=s3.toDouble();
    series = new QLineSeries();
    for(x=start;x<=end;x=x+step)
    {
        y = qAbs(cos(A + pow(B, 2))) - pow(x, 3); // создать объект - набор данныз
        series->append(x,y); // заполнения набора значений
        str=str+"x="+s1.number(x)+"\ty="+s1.number(y)+"\n";
    }
    QMessageBox::information(this,"Результат",str);
}


void Prog2::on_graph_clicked()
{
    QChart *chart = new QChart(); // создание графика
    chart->setAnimationOptions(QChart::AllAnimations); // анимированное появление
    chart->legend()->hide(); // не показывать легенду
    chart->addSeries(series); // добавить набор данных
    chart->createDefaultAxes(); // создать основные оси
    chart->setTitle("График функции");
    QChartView *chartView = new QChartView(chart); // создание объекта для показа графика
        chartView->setRenderHint(QPainter::Antialiasing); // сглаживание
    chartView->setMinimumSize(640, 480);
    QMainWindow *window = new QMainWindow(); // создание окна для вывода графика
    window->setCentralWidget(chartView); // добавить график в окно
    window->show();
}

