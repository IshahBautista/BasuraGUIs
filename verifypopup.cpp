#include "verifypopup.h"
#include "ui_verifypopup.h"
#include <QScreen>

VerifyPopUp::VerifyPopUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VerifyPopUp)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

VerifyPopUp::~VerifyPopUp()
{
    delete ui;
}

void VerifyPopUp::on_NO_clicked()
{
    close();
}


void VerifyPopUp::on_YES_clicked()
{
    //proceed to thank you message
}

