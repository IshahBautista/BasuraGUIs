#ifndef SUCCESSSUBMIT_H
#define SUCCESSSUBMIT_H

#include <QDialog>

namespace Ui {
class SuccessSubmit;
}

class SuccessSubmit : public QDialog
{
    Q_OBJECT

public:
    explicit SuccessSubmit(QWidget *parent = nullptr);
    ~SuccessSubmit();

private slots:
    void on_EXIT_clicked();

private:
    Ui::SuccessSubmit *ui;
};

#endif // SUCCESSSUBMIT_H
