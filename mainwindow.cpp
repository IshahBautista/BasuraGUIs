#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "throwwindow.h"
#include "garbagenotif.h"
#include "capacitystatus.h"
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_THROW_clicked()
{
    //opens the window after button throw garbage is pressed
    this->hide(); //hide because you might want to press back and change
    throwwindow = new throwWindow(this);
    throwwindow->show();
}


void MainWindow::on_CAPACITY_clicked()
{
    this->hide();
    capacitystatus = new CapacityStatus(this);
    capacitystatus->show();
}


void MainWindow::on_NOTIFY_clicked()
{
    this->hide();
    garbagenotif = new GarbageNotif(this);
    garbagenotif->show();
}

