#include "quantitychecker.h"
#include "ui_quantitychecker.h"
#include "containerchoose.h"
#include "addentry.h"
#include <QScreen>

QuantityChecker::QuantityChecker(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QuantityChecker)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
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
    this->hide(); //hide because you might want to press back and change
    addentry = new AddEntry(this);
    addentry->show();
}

