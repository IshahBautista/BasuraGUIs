#ifndef ADDENTRY_H
#define ADDENTRY_H

#include <QDialog>
#include "review.h"

namespace Ui {
class AddEntry;
}

class AddEntry : public QDialog
{
    Q_OBJECT

public:
    explicit AddEntry(QWidget *parent = nullptr);
    ~AddEntry();

private slots:
    void on_Cancel_clicked();

    void on_Submitother_clicked();

    void on_BACK4_clicked();

    void on_Finish_clicked();

private:
    Ui::AddEntry *ui;
    Review *review;
};

#endif // ADDENTRY_H
