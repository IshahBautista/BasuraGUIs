#include "loginpage.h"
#include "ui_loginpage.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDateTime>
#include <QFileDialog>

QString LoginPage::globalFolderPath = ""; // Definition of static member variable

LoginPage::LoginPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_confirm_clicked()
{
    //close the login window
    close();

    QString folderName;

    //save the login info into a file to append later
    QFile temploginfile("D:/SCHOOL/2nd Semester Classes - 1st Year/CMSC 21/FINALPROJBASURAGUIS/templogin.txt");
    QFile duploginfile("D:/SCHOOL/2nd Semester Classes - 1st Year/CMSC 21/FINALPROJBASURAGUIS/duplogin.txt"); //duplicates the login info for appending later

    if(temploginfile.open(QIODevice::ReadWrite)) {
        QTextStream out(&temploginfile);
        QString cityinput = ui->citylineedit->text();
        QString codeinput = ui->codelineedit->text();
        out << cityinput << " - " << codeinput;

        if(duploginfile.open(QIODevice::WriteOnly)) {
            QTextStream outdup(&duploginfile);
            outdup << cityinput << " - " << codeinput;
        }

        QString folderName = cityinput + " - " + codeinput;
        qDebug() << folderName;

        // Create folder under the name of the login city and code
        if (!folderName.isEmpty()) {
            QDir directory;
            QString currentPath =("D:/SCHOOL/2nd Semester Classes - 1st Year/CMSC 21/FINALPROJBASURAGUIS/LOGINS");
            QString folderPath = currentPath + "/" + folderName;
            qDebug() << "Folder path:" << folderPath; // Debug output

            if (!directory.exists(folderPath)) {
                if (!directory.mkpath(folderPath)) { // Use mkpath instead of mkdir to create nested directories if needed
                    return;
                }
            }

            globalFolderPath = folderPath;

        } else {
            qDebug() << "Folder name is empty"; // Debug output
        }
    }
    temploginfile.flush();
    temploginfile.close();
    duploginfile.close();
}

void LoginPage::on_cancel_clicked()
{
    //close the entire app
    close();
    QWidget *parent = this->parentWidget();
    parent->close();

    QFile temploginfile("D:/SCHOOL/2nd Semester Classes - 1st Year/CMSC 21/FINALPROJBASURAGUIS/templogin.txt");
    temploginfile.remove();
}

