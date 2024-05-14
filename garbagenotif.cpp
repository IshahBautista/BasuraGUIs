#include "garbagenotif.h"
#include "ui_garbagenotif.h"
#include <QScreen>

GarbageNotif::GarbageNotif(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GarbageNotif)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

GarbageNotif::~GarbageNotif()
{
    delete ui;
}

void GarbageNotif::on_BACKnotif_clicked()
{
    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}

