#ifndef GARBAGENOTIF_H
#define GARBAGENOTIF_H

#include <QDialog>

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

private:
    Ui::GarbageNotif *ui;
};

#endif // GARBAGENOTIF_H
