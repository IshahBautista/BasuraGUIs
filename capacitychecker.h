#ifndef CAPACITYCHECKER_H
#define CAPACITYCHECKER_H

#include <QDialog>
#include "containerchoose.h"

namespace Ui {
class CapacityChecker;
}

class CapacityChecker : public QDialog
{
    Q_OBJECT

public:
    explicit CapacityChecker(QWidget *parent = nullptr);
    ~CapacityChecker();

private slots:
    void on_BACK3_clicked();

private:
    Ui::CapacityChecker *ui;
    ContainerChoose *containerchoose;
};

#endif // CAPACITYCHECKER_H
