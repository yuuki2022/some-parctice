#include "register.h"
#include "ui_register.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QMessageBox>
#include <QSqlDatabase>

Register::Register(QSqlDatabase& sql,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    connect(ui->btnRegister,&QPushButton::clicked,this,[=]{
        this->premission(sql);
    });
    connect(ui->btnExit,&QPushButton::clicked,this,[=]{
        emit mySignal();
        this->hide();
    });
}

Register::~Register()
{
    delete ui;
}

void Register::init(){
this->setWindowFlags(Qt::FramelessWindowHint);
}

void Register::premission(const QSqlDatabase& db)
{
    QString newAccount=ui->leAccount->text().toUtf8();
    QString newPassword=ui->lePassword->text();

    if(newAccount.isEmpty()){
        ui->leWarn->setText("请填写你的账号");
        return;
    }
    if(newPassword.isEmpty()){
        ui->leWarn->setText("请填写你的密码");
        return;
    }

    QSqlQuery query("select accountId from Account",db);

    QSqlRecord rec=query.record();


    while(query.next()){
        rec=query.record();
        int index=rec.indexOf("accountId");
        QString value=query.value(index).toString().toUtf8();

        if(value==newAccount){
            ui->leWarn->setText("你账号已经被人使用,请重新找输入一个账号");
            ui->leAccount->clear();
            return;
        }

    }

    if(isSame()){
        QSqlQuery query(db);
        query.prepare("insert into Account values(:accountId,:paw)");
        query.bindValue(":accountId",newAccount);
        query.bindValue(":paw",newPassword);
        if(!query.exec())
        {
            qDebug() << "Error: Fail to insert data. " << query.lastError();
        }



        ui->leWarn->clear();

        emit mySignal();
        this->hide();
        return;
    }else {
        ui->leConfirm->clear();
        ui->leWarn->setText("两次密码需要保持一致!!");
    }


}

bool Register::isSame()
{
    if(ui->lePassword->text()==ui->leConfirm->text()){
        return true;
    }
    else {
        return false;
    }
}
