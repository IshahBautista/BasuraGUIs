#ifndef QUANTITYCHECKER_H
#define QUANTITYCHECKER_H

#include <QDialog>

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
};

#endif // QUANTITYCHECKER_H
