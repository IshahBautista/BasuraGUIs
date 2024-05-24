#ifndef NOTIFYSUCCESS_H
#define NOTIFYSUCCESS_H

#include <QDialog>

namespace Ui {
class NotifySuccess;
}

class NotifySuccess : public QDialog
{
    Q_OBJECT

public:
    explicit NotifySuccess(QWidget *parent = nullptr);
    ~NotifySuccess();

private slots:
    void on_homepage2_clicked();

private:
    Ui::NotifySuccess *ui;
};

#endif // NOTIFYSUCCESS_H
