#include "review.h"
#include "ui_review.h"
#include "verifypopup.h"
#include <QScreen>

Review::Review(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Review)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

Review::~Review()
{
    delete ui;
}

void Review::on_BACK5_clicked()
{
    hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void Review::on_NEXT3_clicked()
{
    //a message box shows up that says are you sure?
    verifypopup = new VerifyPopUp(this);
    verifypopup->show();
}

