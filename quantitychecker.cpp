#include "quantitychecker.h"
#include "ui_quantitychecker.h"
#include "containerchoose.h"

QuantityChecker::QuantityChecker(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QuantityChecker)
{
    ui->setupUi(this);
    ui->lineChooseAmount->hide();
    ui->NEXT2->hide();
}

QuantityChecker::~QuantityChecker()
{
    delete ui;
}

void QuantityChecker::on_BACK3_clicked()
{
    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void QuantityChecker::on_NEXT2_clicked()
{

}

