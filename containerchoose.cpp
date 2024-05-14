#include "containerchoose.h"
#include "ui_containerchoose.h"
#include "throwwindow.h"
#include "quantitychecker.h"
#include <QScreen>

ContainerChoose::ContainerChoose(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ContainerChoose)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    ui->NEXT->hide();
}

ContainerChoose::~ContainerChoose()
{
    delete ui;
}

void ContainerChoose::on_BACK2_clicked()
{
    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}

void ContainerChoose::on_NEXT_clicked()
{
        this->hide(); //hide because you might want to press back and change
        quantitychecker = new QuantityChecker(this);
        quantitychecker->show();

}






