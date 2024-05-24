#include "addentry.h"
#include "ui_addentry.h"
#include "mainwindow.h"
#include "throwwindow.h"
#include "review.h"
#include "loginpage.h"
#include <QSCreen>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

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
    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);
    datafile.remove();

    close();
    QWidget *home = this->parentWidget()->parentWidget(); //takes you to homepage, the great great great ancestor of the widget
    home->show();
}


void AddEntry::on_Submitother_clicked()
{
    close();
    QWidget *submitNew = this->parentWidget()->parentWidget();
    submitNew->show();

    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);

    if(datafile.open(QIODevice::Append | QIODevice::ReadWrite)) {
        QTextStream newline(&datafile);
        newline << "\n";
    }
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

