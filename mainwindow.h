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
//������ ����
private:
    int sizeTravel = 6;
    int arrX[6] = { 0,0,0,0,0,0 };
    int arrY[6] = { 0,0,0,0,0,0 };
    int index = 0;

    QPoint positionHorse;
    QPoint positionPoint;

    float step = 32;//���
    float updateInterval = 500;//�������� ����������

    QTimer *timer;


//...........
//�������� ����
private:
void RunHorse();//�������� ����
bool PlacementOfobjects();//������������� ��������� ���� �� �����

//.........
//������� �� �����
private slots:
    void on_ButtonStart_clicked();

private:
    Ui::MainWindow *ui;


//..........
//C������ �� ���������� ���� � timer
private slots:
    void TimerSlot();

};
#endif // MAINWINDOW_H
