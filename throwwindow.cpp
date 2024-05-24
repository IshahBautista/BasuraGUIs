#include "throwwindow.h"
#include "ui_throwwindow.h"
#include "mainwindow.h"
#include <QScreen>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

throwWindow::throwWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::throwWindow)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

throwWindow::~throwWindow()
{
    delete ui;
}

void throwWindow::on_BACK1_clicked()
{
    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);
    datafile.remove();

    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void throwWindow::on_BIO_clicked()
{
    garbageType = "Biodegradable";

    // Create a new instance of ContQuant and pass the garbageType
    contquant = new ContQuant(this, garbageType);

    this->hide();
    contquant->show();

    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);

    if(datafile.open(QIODevice::Append | QIODevice::ReadWrite)) {
        QTextStream out2(&datafile);
        out2 << "Type: Biodegradable\n";
    }
}


void throwWindow::on_NONBIO_clicked()
{
    garbageType = "Non-Biodegradable";

    // Create a new instance of ContQuant and pass the garbageType
    contquant = new ContQuant(this, garbageType);

    this->hide();
    contquant->show();

    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);

    if(datafile.open(QIODevice::Append | QIODevice::ReadWrite)) {
        QTextStream out2(&datafile);
        out2 << "Type: Non-Biodegradable\n";
    }
}

void throwWindow::on_RECYC_clicked()
{
    garbageType = "Recyclable";

    // Create a new instance of ContQuant and pass the garbageType
    contquant = new ContQuant(this, garbageType);

    this->hide();
    contquant->show();

    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);

    if(datafile.open(QIODevice::Append | QIODevice::ReadWrite)) {
        QTextStream out2(&datafile);
        out2 << "Type: Recyclable\n";
    }
}
