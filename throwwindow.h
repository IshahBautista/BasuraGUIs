#ifndef THROWWINDOW_H
#define THROWWINDOW_H

#include <QDialog>
#include "containerchoose.h"

namespace Ui {
class throwWindow;
}

class throwWindow : public QDialog
{
    Q_OBJECT

public:
    explicit throwWindow(QWidget *parent = nullptr);
    ~throwWindow();

private slots:
    void on_BACK1_clicked();

    void on_BIO_clicked();

    void on_NONBIO_clicked();

    void on_RECYC_clicked();

private:
    Ui::throwWindow *ui;
    ContainerChoose *containerchoose;
};

#endif // THROWWINDOW_H
