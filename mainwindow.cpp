#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "throwwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_THROW_clicked()
{
    //opens the window after button throw garbage is pressed
    this->hide();
    throwwindow = new throwWindow(this);
    throwwindow->show();

}

