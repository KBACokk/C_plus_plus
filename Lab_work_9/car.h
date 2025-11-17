#ifndef CAR_H
#define CAR_H

#include <QMainWindow>
#include "QTimer"

QT_BEGIN_NAMESPACE
namespace Ui {
class Car;
}
QT_END_NAMESPACE

class Car : public QMainWindow
{
    Q_OBJECT

public:
    Car(QWidget *parent = nullptr);
    ~Car();

private:
    Ui::Car *ui;
    QTimer *timer;

public slots:
    void onTimeout();

private slots:
    void on_actionstop_triggered();
    void on_actionstart_triggered();
    void on_actionexit_triggered();
};


#endif // CAR_H
