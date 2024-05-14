#ifndef QUANTITYCHECKER_H
#define QUANTITYCHECKER_H

#include <QDialog>
#include "addentry.h"

namespace Ui {
class QuantityChecker;
}

class QuantityChecker : public QDialog
{
    Q_OBJECT

public:
    explicit QuantityChecker(QWidget *parent = nullptr);
    ~QuantityChecker();

private slots:
    void on_BACK3_clicked();

    void on_NEXT2_clicked();

private:
    Ui::QuantityChecker *ui;
    AddEntry *addentry;
};

#endif // QUANTITYCHECKER_H
