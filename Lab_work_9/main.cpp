#include "car.h"
#include <QTimer>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Car w;
    w.show();
    return a.exec();
}
