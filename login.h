#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "register.h"
#include <sqlprocess.h>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void init();

public slots:
    void openRegisterPage();
    void openInPage();

signals:
    void getInformation();

private:
    Ui::Login *ui;
    Register *reg;
    SqlProcess *sqlProcess;
};

#endif // LOGIN_H
