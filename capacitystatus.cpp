#include "capacitystatus.h"
#include "ui_capacitystatus.h"
#include <QScreen>

CapacityStatus::CapacityStatus(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CapacityStatus)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

CapacityStatus::~CapacityStatus()
{
    delete ui;
}

void CapacityStatus::on_BACKcapacity_clicked()
{
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}

