#ifndef CAPACITYSTATUS_H
#define CAPACITYSTATUS_H

#include <QDialog>

namespace Ui {
class CapacityStatus;
}

class CapacityStatus : public QDialog
{
    Q_OBJECT

public:
    explicit CapacityStatus(QWidget *parent = nullptr);
    ~CapacityStatus();

private slots:
    void on_BACKcapacity_clicked();

private:
    Ui::CapacityStatus *ui;
};

#endif // CAPACITYSTATUS_H
