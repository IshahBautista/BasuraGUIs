#include "contquant.h"
#include "ui_contquant.h"
#include "loginpage.h"
#include <QScreen>
#include <QTextStream>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

ContQuant::ContQuant(QWidget *parent, const QString &garbageType)
    : QDialog(parent)
    , ui(new Ui::ContQuant)
    , garbageType(garbageType) // Initialize the garbage type
{
    ui->setupUi(this);
    ui->otherlineedit->hide();
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

ContQuant::~ContQuant()
{
    delete ui;
}

void ContQuant::on_backcontquant_clicked()
{
    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);
    datafile.remove();

    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void ContQuant::on_nextcontquant_clicked()
{
    qDebug() << "Garbage Type:" << garbageType;

    // Trim garbageType string to remove leading and trailing spaces
    QString garbageTypeTrimmed = garbageType.trimmed();
    qDebug() << "Trimmed Garbage Type:" << garbageTypeTrimmed;

    if(!ui->container1->isChecked() && !ui->container2->isChecked() && !ui->container3->isChecked() && !ui->container4->isChecked()) {
        //do nothing
    } else {
        if((ui->spinBox1->value() == 0) && (ui->spinBox2->value() == 0) && (ui->spinBox3->value() == 0) && (ui->spinBox4->value() == 0)) {
            //do nothing
        } else {
            if(ui->container1->isChecked()) {
                QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
                QFile datafile(datafilePath);
                //store it in the file to record what they input
                if(datafile.open(QIODevice::Append | QIODevice::ReadWrite)) {
                    QTextStream output(&datafile);
                    output << "Container: Plastic Bag";

                    //get the value of the spinbox
                    QString quant1_val = QString::number(ui->spinBox1->value());
                    output << ", " << quant1_val << "pcs.\n";

                    writeQuantFile(quant1_val);
                }
            }

            //for checking which checkbox button is pressed
            if(ui->container2->isChecked()) {
                QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
                QFile datafile(datafilePath);
                //store it in the file to record what they input
                if(datafile.open(QIODevice::Append | QIODevice::ReadWrite)) {
                    QTextStream output(&datafile);
                    output << "Container: Trash Bag";

                    //get the value of the spinbox
                    QString quant2_val = QString::number(ui->spinBox2->value());
                    output << ", " << quant2_val << "pcs.\n";

                    writeQuantFile(quant2_val);
                }
            }

            //for checking which checkbox button is pressed
            if(ui->container3->isChecked()) {
                QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
                QFile datafile(datafilePath);
                //store it in the file to record what they input
                if(datafile.open(QIODevice::Append | QIODevice::ReadWrite)) {
                    QTextStream output(&datafile);
                    output << "Container: Sack";

                    //get the value of the spinbox
                    QString quant3_val = QString::number(ui->spinBox3->value());
                    output << ", " << quant3_val << "pcs.\n";

                    writeQuantFile(quant3_val);
                }
            }

            //for checking which checkbox button is pressed
            if(ui->container4->isChecked()) {
                QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
                QFile datafile(datafilePath);
                //store it in the file to record what they input
                if(datafile.open(QIODevice::Append | QIODevice::ReadWrite)) {
                    QString inputContainer = ui->otherlineedit->text();

                    QTextStream output(&datafile);
                    output << "Container: " << inputContainer;

                    //get the value of the spinbox
                    QString quant4_val = QString::number(ui->spinBox4->value());
                    output << ", " << quant4_val << "pcs.\n";

                    writeQuantFile(quant4_val);
                }
            }

            this->hide(); //hide because you might want to press back and change
            addentry = new AddEntry(this);
            addentry->show();
        }
    }

    QString datafilePath = LoginPage::globalFolderPath + "/datafile.txt";
    QFile datafile(datafilePath);
    datafile.close();
}

void ContQuant::writeQuantFile(const QString &quant_val) {
    if(garbageType == "Biodegradable") {
        QString quantDataFilePath = LoginPage::globalFolderPath + "/TEMPbioquant.txt";
        QFile quantDataFile(quantDataFilePath);
        if(quantDataFile.open(QIODevice::Append | QIODevice::ReadWrite)) {
            QTextStream quantout(&quantDataFile);
            quantout << quant_val << "\n";
        }
    } else if(garbageType == "Non-Biodegradable") {
        QString quantDataFilePath = LoginPage::globalFolderPath + "/TEMPnonbioquant.txt";
        QFile quantDataFile(quantDataFilePath);

        if(quantDataFile.open(QIODevice::Append | QIODevice::ReadWrite)) {
            QTextStream quantout(&quantDataFile);
            quantout << quant_val << "\n";
        }
    } else if(garbageType == "Recyclable") {
        QString quantDataFilePath = LoginPage::globalFolderPath + "/TEMPrecycquant.txt";
        QFile quantDataFile(quantDataFilePath);

        if(quantDataFile.open(QIODevice::Append | QIODevice::ReadWrite)) {
            QTextStream quantout(&quantDataFile);
            quantout << quant_val << "\n";
        }
    }
}
