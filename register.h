#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <sqlprocess.h>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QSqlDatabase& sql,QWidget *parent = nullptr);
    ~Register();
    void init();
    bool accountRepeat();//认证

public slots:
    void premission(const QSqlDatabase&);

signals:
    void mySignal();


private:
    Ui::Register *ui;
    bool isSame(); //密码重复检验
};

#endif // REGISTER_H
