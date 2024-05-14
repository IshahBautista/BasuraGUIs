#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "throwwindow.h"
#include "garbagenotif.h"
#include "capacitystatus.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_THROW_clicked();

    void on_CAPACITY_clicked();

    void on_NOTIFY_clicked();

private:
    Ui::MainWindow *ui;
    throwWindow *throwwindow; //to open throwwindow
    GarbageNotif *garbagenotif; //to open garbage notif
    CapacityStatus *capacitystatus; //to open capacity status
};
#endif // MAINWINDOW_H
