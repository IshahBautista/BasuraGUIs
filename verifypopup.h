#ifndef VERIFYPOPUP_H
#define VERIFYPOPUP_H

#include <QDialog>

namespace Ui {
class VerifyPopUp;
}

class VerifyPopUp : public QDialog
{
    Q_OBJECT

public:
    explicit VerifyPopUp(QWidget *parent = nullptr);
    ~VerifyPopUp();

private slots:
    void on_NO_clicked();

    void on_YES_clicked();

private:
    Ui::VerifyPopUp *ui;
};

#endif // VERIFYPOPUP_H
