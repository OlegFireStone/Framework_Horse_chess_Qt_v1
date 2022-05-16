#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FindingMoves.h"

//................
//Конструктор и деструктор
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));//Устанавливаем соединения timer с TimerSlot()
}

MainWindow::~MainWindow()
{
    delete ui;
}

//................
//Действия
void MainWindow::RunHorse(){
    ui->Horse->move(ui->Horse->x() + arrX[index] * step, ui->Horse->y() - arrY[index] * step);
    index++;
}

bool MainWindow::PlacementOfobjects(){
    int nx, ny, mx, my;

        QString str = ui->TextPositionHorse->toMarkdown();
        QString str2 = ui->TextPositionPoint->toMarkdown();

        nx = str[0].unicode() - 97;
        ny = str[1].unicode() - 49;
        mx = str2[0].unicode() - 97;
        my = str2[1].unicode() - 49;

        if (nx < 0 || nx>7 || ny < 0 || ny>7 || mx < 0 || mx>7 || my < 0 || my>7 || str.length() > 4 || str2.length() > 4) {
            QMessageBox::about(this,"Error","Wrong Coordinates!");
            return false;
        }

        positionHorse.rx() = 41 + nx*step;
        positionHorse.ry() = 261 - ny*step;
        ui->Horse->move(positionHorse.rx(),positionHorse.ry());
        return true;
}

//................
//Объекты на форме
void MainWindow::on_ButtonStart_clicked()
{
    if(PlacementOfobjects()){
        FindingMoves findingMoves;
        sizeTravel = findingMoves.knight(ui->TextPositionHorse->toMarkdown(), ui->TextPositionPoint->toMarkdown(), arrX, arrY);

        ui->ButtonStart->setEnabled(false);

        timer->start(updateInterval);
    }
}


//...............
//Cобытие по обновлению игры в timer
void MainWindow::TimerSlot()
{
    if (index < sizeTravel) {
        RunHorse();
    }
    else {
        timer->stop();
        index = 0;
        ui->ButtonStart->setEnabled(true);

    }
}
