#ifndef PROG2_H
#define PROG2_H

#include <QMainWindow>
#include <QtCharts/QLineSeries>


QT_BEGIN_NAMESPACE
namespace Ui {
class Prog2;
}
QT_END_NAMESPACE

class Prog2 : public QMainWindow
{
    Q_OBJECT

public:
    Prog2(QWidget *parent = nullptr);
    ~Prog2();

private slots:
    void on_pushButton_clicked();

    void on_graph_clicked();

private:
    Ui::Prog2 *ui;
    QLineSeries *series;
};
#endif // PROG2_H
