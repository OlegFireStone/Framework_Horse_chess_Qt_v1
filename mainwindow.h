#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QMessageBox>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//............
//Данные игры
private:
    int sizeTravel = 6;
    int arrX[6] = { 0,0,0,0,0,0 };
    int arrY[6] = { 0,0,0,0,0,0 };
    int index = 0;

    QPoint positionHorse;
    QPoint positionPoint;

    float step = 32;//шаг
    float updateInterval = 500;//Интервал обновления

    QTimer *timer;


//...........
//Действия игры
private:
void RunHorse();//Движение коня
bool PlacementOfobjects();//Устанавливает положение коня на форме

//.........
//Объекты на форме
private slots:
    void on_ButtonStart_clicked();

private:
    Ui::MainWindow *ui;


//..........
//Cобытие по обновлению игры в timer
private slots:
    void TimerSlot();

};
#endif // MAINWINDOW_H
