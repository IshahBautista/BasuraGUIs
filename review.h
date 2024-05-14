#ifndef REVIEW_H
#define REVIEW_H

#include <QDialog>
#include "verifypopup.h"

namespace Ui {
class Review;
}

class Review : public QDialog
{
    Q_OBJECT

public:
    explicit Review(QWidget *parent = nullptr);
    ~Review();

private slots:
    void on_BACK5_clicked();

    void on_NEXT3_clicked();

private:
    Ui::Review *ui;
    VerifyPopUp *verifypopup;
};

#endif // REVIEW_H
