#ifndef VERIFYNOTIFICATION_H
#define VERIFYNOTIFICATION_H

#include <QDialog>
#include "notifysuccess.h"

namespace Ui {
class VerifyNotification;
}

class VerifyNotification : public QDialog
{
    Q_OBJECT

public:
    explicit VerifyNotification(QWidget *parent = nullptr);
    ~VerifyNotification();

private slots:
    void on_YESverify_clicked();

    void on_NOverify_clicked();

private:
    Ui::VerifyNotification *ui;
    NotifySuccess *notifysuccess;
};

#endif // VERIFYNOTIFICATION_H
