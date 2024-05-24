#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "throwwindow.h"
#include "garbagenotif.h"
#include "capacitystatus.h"
#include "loginpage.h"
#include <QScreen>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());

    //on startup show loginpage
    loginpage = new LoginPage(this);
    loginpage->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_THROW_clicked()
{
    //opens the window after button throw garbage is pressed
    this->hide(); //hide because you might want to press back and change
    throwwindow = new throwWindow(this);
    throwwindow->show();
}


void MainWindow::on_CAPACITY_clicked()
{
    this->hide();
    capacitystatus = new CapacityStatus(this);
    capacitystatus->show();
}


void MainWindow::on_NOTIFY_clicked()
{
    this->hide();
    garbagenotif = new GarbageNotif(this);
    garbagenotif->show();
}


void MainWindow::on_EXIT_clicked()
{
    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);
    datafile.remove();
    QFile temploginfile("D:/SCHOOL/2nd Semester Classes - 1st Year/CMSC 21/FINALPROJBASURAGUIS/templogin.txt");
    temploginfile.remove();
    QFile duploginfile("D:/SCHOOL/2nd Semester Classes - 1st Year/CMSC 21/FINALPROJBASURAGUIS/duplogin.txt");
    duploginfile.remove();
}

