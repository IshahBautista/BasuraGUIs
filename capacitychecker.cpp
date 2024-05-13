#include "capacitychecker.h"
#include "ui_capacitychecker.h"
#include "containerchoose.h"

CapacityChecker::CapacityChecker(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CapacityChecker)
{
    ui->setupUi(this);
}

CapacityChecker::~CapacityChecker()
{
    delete ui;
}



void CapacityChecker::on_BACK3_clicked()
{
    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}

