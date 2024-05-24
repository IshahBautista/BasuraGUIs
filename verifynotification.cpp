#include "verifynotification.h"
#include "ui_verifynotification.h"
#include "notifysuccess.h"
#include <QScreen>

VerifyNotification::VerifyNotification(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VerifyNotification)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

VerifyNotification::~VerifyNotification()
{
    delete ui;
}

void VerifyNotification::on_YESverify_clicked()
{
    notifysuccess = new NotifySuccess(this);
    notifysuccess->show();
}


void VerifyNotification::on_NOverify_clicked()
{
    close();
}

