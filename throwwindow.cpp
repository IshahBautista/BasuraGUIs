#include "throwwindow.h"
#include "ui_throwwindow.h"
#include "mainwindow.h"
#include <QScreen>

throwWindow::throwWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::throwWindow)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

throwWindow::~throwWindow()
{
    delete ui;
}

void throwWindow::on_BACK1_clicked()
{
    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void throwWindow::on_BIO_clicked()
{
    this->hide();
    containerchoose = new ContainerChoose(this);
    containerchoose->show();
}


void throwWindow::on_NONBIO_clicked()
{
    this->hide();
    containerchoose = new ContainerChoose(this);
    containerchoose->show();
}

void throwWindow::on_RECYC_clicked()
{
    this->hide();
    containerchoose = new ContainerChoose(this);
    containerchoose->show();
}
