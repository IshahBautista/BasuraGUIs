#include "capacitystatus.h"
#include "ui_capacitystatus.h"
#include "loginpage.h"
#include <QScreen>
#include "QProgressBar"
#include <QSCreen>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

CapacityStatus::CapacityStatus(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CapacityStatus)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    updateCapacity();

    ui->WARNBIO->hide();
    ui->WARNNONBIO->hide();
    ui->WARNRECYC->hide();

    ColorProgress();
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

void CapacityStatus::updateWarnings()
{
    if (ui->bioprogress->value() == 100) {
        ui->WARNBIO->show();
    } else {
        ui->WARNBIO->hide();
    }

    if (ui->nonbioprogress->value() == 100) {
        ui->WARNNONBIO->show();
    } else {
        ui->WARNNONBIO->hide();
    }

    if (ui->recycprogress->value() == 100) {
        ui->WARNRECYC->show();
    } else {
        ui->WARNRECYC->hide();
    }
}

void CapacityStatus::ColorProgress()
{
    //for making the progress bar green if less than 50%
    if(ui->bioprogress->value() < 50) {
        ui->bioprogress->setStyleSheet(
            "QProgressBar {"
            "background-color: rgb(177, 158, 214); "
            "border-radius: 10px; "
            "text-align: center; "
            "color: black; }"

            "QProgressBar::chunk {"
            "background-color: rgb(126, 217, 87);"
            "border-radius: 10px; }"
            );
    }

    if(ui->nonbioprogress->value() < 50) {
        ui->nonbioprogress->setStyleSheet(
            "QProgressBar {"
            "background-color: rgb(177, 158, 214); "
            "border-radius: 10px; "
            "text-align: center; "
            "color: black; }"

            "QProgressBar::chunk {"
            "background-color: rgb(126, 217, 87);"
            "border-radius: 10px; }"
            );
    }

    if(ui->recycprogress->value() < 50) {
        ui->recycprogress->setStyleSheet(
            "QProgressBar {"
            "background-color: rgb(177, 158, 214); "
            "border-radius: 10px; "
            "text-align: center; "
            "color: black; }"

            "QProgressBar::chunk {"
            "background-color: rgb(126, 217, 87);"
            "border-radius: 10px; }"
            );
    }

    //for making the color of the progress bar yellow if half
    if(ui->bioprogress->value() > 50 && ui->bioprogress->value() < 90) {
        ui->bioprogress->setStyleSheet(
            "QProgressBar {"
            "background-color: rgb(177, 158, 214); "
            "border-radius: 10px; "
            "text-align: center; "
            "color: black; }"

            "QProgressBar::chunk {"
            "background-color: rgb(255, 222, 89);"
            "border-radius: 10px; }"
            );
    }

    if(ui->bioprogress->value() > 50 && ui->bioprogress->value() < 90) {
        ui->nonbioprogress->setStyleSheet(
            "QProgressBar {"
            "background-color: rgb(177, 158, 214); "
            "border-radius: 10px; "
            "text-align: center; "
            "color: black; }"

            "QProgressBar::chunk {"
            "background-color: rgb(255, 222, 89);"
            "border-radius: 10px; }"
            );
    }

    if(ui->bioprogress->value() > 50 && ui->bioprogress->value() < 90) {
        ui->recycprogress->setStyleSheet(
            "QProgressBar {"
            "background-color: rgb(177, 158, 214); "
            "border-radius: 10px; "
            "text-align: center; "
            "color: black; }"

            "QProgressBar::chunk {"
            "background-color: rgb(255, 222, 89);"
            "border-radius: 10px; }"
            );
    }

    //for making the color of the progress bar red if greater than 90
    if(ui->bioprogress->value() > 90) {
        ui->bioprogress->setStyleSheet(
            "QProgressBar {"
            "background-color: rgb(177, 158, 214); "
            "border-radius: 10px; "
            "text-align: center; "
            "color: black; }"

            "QProgressBar::chunk {"
            "background-color: rgb(255, 87, 87);"
            "border-radius: 10px; }"
            );
    }

    if(ui->bioprogress->value() > 90) {
        ui->nonbioprogress->setStyleSheet(
            "QProgressBar {"
            "background-color: rgb(177, 158, 214); "
            "border-radius: 10px; "
            "text-align: center; "
            "color: black; }"

            "QProgressBar::chunk {"
            "background-color: rgb(255, 87, 87);"
            "border-radius: 10px; }"
            );
    }

    if(ui->bioprogress->value() > 90) {
        ui->recycprogress->setStyleSheet(
            "QProgressBar {"
            "background-color: rgb(177, 158, 214); "
            "border-radius: 10px; "
            "text-align: center; "
            "color: black; }"

            "QProgressBar::chunk {"
            "background-color: rgb(255, 87, 87);"
            "border-radius: 10px; }"
            );
    }
}

void CapacityStatus::updateCapacity()
{
    // Paths to the files
    QString bioQuantFilePath = LoginPage::globalFolderPath + "/FINALbioquant.txt";
    QString nonBioQuantFilePath = LoginPage::globalFolderPath + "/FINALnonbioquant.txt";
    QString recycQuantFilePath = LoginPage::globalFolderPath + "/FINALrecycquant.txt";

    // Variables to store the total sums
    int totalBioQuant = 0;
    int totalNonBioQuant = 0;
    int totalRecycQuant = 0;

    // Helper lambda function to read and sum the values from a file
    auto readAndSumFile = [](const QString &filePath) -> int {
        int total = 0;
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString line;
            while (in.readLineInto(&line)) {
                bool ok;
                int value = line.toInt(&ok);
                if (ok) {
                    total += value;
                }
            }
            file.close();
        } else {
            qDebug() << "Failed to open file:" << filePath;
        }
        return total;
    };

    // Calculate totals for each file
    totalBioQuant = readAndSumFile(bioQuantFilePath);
    totalNonBioQuant = readAndSumFile(nonBioQuantFilePath);
    totalRecycQuant = readAndSumFile(recycQuantFilePath);

    // Now you can use the totalBioQuant, totalNonBioQuant, and totalRecycQuant variables
    qDebug() << "Total Bio Quant:" << totalBioQuant;
    qDebug() << "Total Non-Bio Quant:" << totalNonBioQuant;
    qDebug() << "Total Recyc Quant:" << totalRecycQuant;

    // Optionally, update the progress bars or other UI elements here
    // Example:
    ui->bioprogress->setValue(totalBioQuant);
    ui->nonbioprogress->setValue(totalNonBioQuant);
    ui->recycprogress->setValue(totalRecycQuant);

    // Call updateWarnings() and ColorProgress() to update UI based on new values
    updateWarnings();
    ColorProgress();
}

