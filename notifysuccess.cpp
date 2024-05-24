#include "notifysuccess.h"
#include "ui_notifysuccess.h"
#include <QScreen>

NotifySuccess::NotifySuccess(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NotifySuccess)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

NotifySuccess::~NotifySuccess()
{
    delete ui;
}

void NotifySuccess::on_homepage2_clicked()
{
    QWidget *parent = this->parentWidget();
    parent->close();

    QWidget *previousparent = this->parentWidget()->parentWidget();
    previousparent->close();

    close();
    QWidget *home = this->parentWidget()->parentWidget()->parentWidget();
    home->show();
}

