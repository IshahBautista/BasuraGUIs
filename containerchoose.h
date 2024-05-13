#ifndef CONTAINERCHOOSE_H
#define CONTAINERCHOOSE_H

#include <QDialog>
#include "quantitychecker.h"

namespace Ui {
class ContainerChoose;
}

class ContainerChoose : public QDialog
{
    Q_OBJECT

public:
    explicit ContainerChoose(QWidget *parent = nullptr);
    ~ContainerChoose();

private slots:
    void on_BACK2_clicked();

    void on_NEXT_clicked();

private:
    Ui::ContainerChoose *ui;
    QuantityChecker *quantitychecker;
};

#endif // CONTAINERCHOOSE_H
