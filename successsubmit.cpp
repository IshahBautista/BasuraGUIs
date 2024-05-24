#include "successsubmit.h"
#include "ui_successsubmit.h"
#include "mainwindow.h"

#include <QScreen>

SuccessSubmit::SuccessSubmit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SuccessSubmit)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

SuccessSubmit::~SuccessSubmit()
{
    delete ui;
}

void SuccessSubmit::on_EXIT_clicked()
{
    close();
    QWidget *home = this->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget();
    home->show();
}

