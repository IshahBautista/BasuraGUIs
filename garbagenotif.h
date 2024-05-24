#ifndef GARBAGENOTIF_H
#define GARBAGENOTIF_H

#include <QDialog>
#include "verifynotification.h"

namespace Ui {
class GarbageNotif;
}

class GarbageNotif : public QDialog
{
    Q_OBJECT

public:
    explicit GarbageNotif(QWidget *parent = nullptr);
    ~GarbageNotif();

private slots:
    void on_BACKnotif_clicked();

    void on_BIOnotify_clicked();

    void on_NONBIOnotify_clicked();

    void on_RECYCnotify_clicked();

private:
    Ui::GarbageNotif *ui;
    VerifyNotification *verifynotification;
};

#endif // GARBAGENOTIF_H
