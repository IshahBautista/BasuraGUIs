#include "review.h"
#include "ui_review.h"
#include "verifypopup.h"
#include "loginpage.h"
#include <QScreen>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Review::Review(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Review)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());

    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);

    if(datafile.open(QIODevice::ReadOnly)) {
        QTextStream stream(&datafile);
        QString FileData;
        while(stream.atEnd() == false) {
            FileData += stream.readLine() + "\n";
        }
        ui->reviewWidget->setText(FileData);
    }
}

Review::~Review()
{
    delete ui;
}

void Review::on_NEXT3_clicked() //submit
{
    //a message box shows up that says are you sure?
    verifypopup = new VerifyPopUp(this);
    verifypopup->show();
}


void Review::on_makechanges_clicked()
{
    close();
    QWidget *Change = this->parentWidget()->parentWidget()->parentWidget();
    Change->show();
    
    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);
    datafile.remove();

    QString quantDataFilePath1 = LoginPage::globalFolderPath + "/TEMPbioquant.txt";
    QFile quantDataFile1(quantDataFilePath1);
    quantDataFile1.remove();

    QString quantDataFilePath2 = LoginPage::globalFolderPath + "/TEMPnonbioquant.txt";
    QFile quantDataFile2(quantDataFilePath2);
    quantDataFile2.remove();

    QString quantDataFilePath3 = LoginPage::globalFolderPath + "/TEMPrecycquant.txt";
    QFile quantDataFile3(quantDataFilePath3);
    quantDataFile3.remove();

}



