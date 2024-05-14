#include "addentry.h"
#include "ui_addentry.h"
#include "mainwindow.h"
#include "throwwindow.h"
#include "containerchoose.h"
#include "quantitychecker.h"
#include "review.h"
#include <QSCreen>

AddEntry::AddEntry(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddEntry)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

AddEntry::~AddEntry()
{
    delete ui;
}

void AddEntry::on_Cancel_clicked()
{
    close();
    QWidget *home = this->parentWidget()->parentWidget()->parentWidget()->parentWidget(); //takes you to homepage, the great great great ancestor of the widget
    home->show();
}


void AddEntry::on_Submitother_clicked()
{
    close();
    QWidget *submitNew = this->parentWidget()->parentWidget()->parentWidget();
    submitNew->show();
}


void AddEntry::on_BACK4_clicked()
{
    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void AddEntry::on_Finish_clicked()
{
    hide();
    review = new Review(this);
    review->show();
}

