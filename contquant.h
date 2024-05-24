#ifndef CONTQUANT_H
#define CONTQUANT_H

#include <QDialog>
#include "addentry.h"

namespace Ui {
class ContQuant;
}

class ContQuant : public QDialog
{
    Q_OBJECT

public:
    explicit ContQuant(QWidget *parent = nullptr, const QString &garbageType = QString());
    ~ContQuant();

private slots:

    void on_backcontquant_clicked();

    void on_nextcontquant_clicked();

    void writeQuantFile(const QString &quant_val);

private:
    Ui::ContQuant *ui;
    AddEntry *addentry;
    QString garbageType; // Variable to store garbage type

};

#endif // CONTQUANT_H
