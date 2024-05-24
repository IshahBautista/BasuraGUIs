#include "verifypopup.h"
#include "ui_verifypopup.h"
#include "successsubmit.h"
#include "loginpage.h"
#include <QScreen>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

VerifyPopUp::VerifyPopUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VerifyPopUp)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

VerifyPopUp::~VerifyPopUp()
{
    delete ui;
}

void VerifyPopUp::on_NO_clicked()
{
    close();
}


void VerifyPopUp::on_YES_clicked()
{
    //proceed to thank you message
    QWidget *parent = this->parentWidget();
    parent->close();

    close();
    successsubmit = new SuccessSubmit(this);
    successsubmit->show();

    //open the cumulative file
    QString finalDATAPath = LoginPage::globalFolderPath + "/finalDATA.txt";
    QFile finalDATA(finalDATAPath);

    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);

    QFile temploginfile("D:/SCHOOL/2nd Semester Classes - 1st Year/CMSC 21/FINALPROJBASURAGUIS/templogin.txt");
    QFile duploginfile("D:/SCHOOL/2nd Semester Classes - 1st Year/CMSC 21/FINALPROJBASURAGUIS/duplogin.txt");

    //replace the current temploginfile with the original duploginfile
    QString linereplace;
    if(temploginfile.open(QIODevice::WriteOnly)) {
        if(duploginfile.open(QIODevice::ReadOnly)) {
            QTextStream replace(&duploginfile);
            while(!replace.atEnd()) {
                linereplace = replace.readLine();
            }
            duploginfile.close();
        }

        QTextStream replace2(&temploginfile);
        replace2 << linereplace;
        temploginfile.close();
    }

    //to add the date and time the submission button is pressed
    if(temploginfile.open(QIODevice::Append)) {
        QTextStream out(&temploginfile);

        QDateTime datetime = QDateTime::currentDateTime();
        QString stringDateTime = datetime.toString("dd.MM.yyyy hh:mm:ss");
        out << " - " << stringDateTime;
    }
    temploginfile.flush();
    temploginfile.close();

    //to assign line to be the content in the loginfile
    QString line;
    if(temploginfile.open(QIODevice::ReadOnly)) {
        QTextStream in(&temploginfile);
        while(!in.atEnd()) {
            line = in.readLine();
        }
        temploginfile.close();
    }

    if(finalDATA.open(QIODevice::Append | QIODevice::ReadWrite)) {
        QTextStream output(&finalDATA);
        output << line << "\n";

        if(datafile.open(QIODevice::ReadOnly)) {
            QTextStream in2(&datafile);
            while(!in2.atEnd()) {
                QString lineData = in2.readLine();

                if(lineData.trimmed().isEmpty()) {
                    output << "\n" << line << "\n";
                } else {
                    output << lineData << "\n";
                }
            }
            output << "\n";

            datafile.close();
        }

        finalDATA.close();
    }

    //transfers the data of quantTEMP into the quantFINAL files
    QString quantDataFilePath1 = LoginPage::globalFolderPath + "/TEMPbioquant.txt";
    QFile quantDataFile1(quantDataFilePath1);

    QString quantDataFilePath2 = LoginPage::globalFolderPath + "/TEMPnonbioquant.txt";
    QFile quantDataFile2(quantDataFilePath2);

    QString quantDataFilePath3 = LoginPage::globalFolderPath + "/TEMPrecycquant.txt";
    QFile quantDataFile3(quantDataFilePath3);

    QString quant1FINALPath = LoginPage::globalFolderPath + "/FINALbioquant.txt";
    QFile quant1FINAL(quant1FINALPath);
    if (quant1FINAL.open(QIODevice::Append | QIODevice::ReadWrite)) { // opens the final file
        if (quantDataFile1.open(QIODevice::ReadOnly)) { // opens temp file
            QTextStream quant1dataRead(&quantDataFile1);
            QTextStream quant1dataWrite(&quant1FINAL);
            while (!quant1dataRead.atEnd()) {
                QString quantfinal1 = quant1dataRead.readLine();
                quant1dataWrite << quantfinal1 << "\n";
            }
            quantDataFile1.remove();
        }
        quant1FINAL.close();
    }

    QString quant2FINALPath = LoginPage::globalFolderPath + "/FINALnonbioquant.txt";
    QFile quant2FINAL(quant2FINALPath);
    if (quant2FINAL.open(QIODevice::Append | QIODevice::ReadWrite)) { // opens the final file
        if (quantDataFile2.open(QIODevice::ReadOnly)) { // opens temp file
            QTextStream quant2dataRead(&quantDataFile2);
            QTextStream quant2dataWrite(&quant2FINAL);
            while (!quant2dataRead.atEnd()) {
                QString quantfinal2 = quant2dataRead.readLine();
                quant2dataWrite << quantfinal2 << "\n";
            }
            quantDataFile2.remove();
        }
        quant2FINAL.close();
    }

    QString quant3FINALPath = LoginPage::globalFolderPath + "/FINALrecycquant.txt";
    QFile quant3FINAL(quant3FINALPath);
    if (quant3FINAL.open(QIODevice::Append | QIODevice::ReadWrite)) { // opens the final file
        if (quantDataFile3.open(QIODevice::ReadOnly)) { // opens temp file
            QTextStream quant3dataRead(&quantDataFile3);
            QTextStream quant3dataWrite(&quant3FINAL);
            while (!quant3dataRead.atEnd()) {
                QString quantfinal3 = quant3dataRead.readLine();
                quant3dataWrite << quantfinal3 << "\n";
            }
            quantDataFile3.remove();
        }
        quant3FINAL.close();
    }
    datafile.remove();
}

