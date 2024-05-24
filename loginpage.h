#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>

namespace Ui {
class LoginPage;
}

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
    static QString globalFolderPath;

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
