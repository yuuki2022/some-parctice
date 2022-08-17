#include "login.h"
#include "ui_login.h"
#include <page.h>
#include <QSqlRecord>
#include <QTextCodec>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    init();


    connect(ui->btnRegister,SIGNAL(clicked()),this,SLOT(openRegisterPage()));
    connect(reg,SIGNAL(mySignal()),this,SLOT(show()));
    connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->btnLogin,SIGNAL(clicked()),this,SLOT(openInPage()));
}

Login::~Login()
{
    delete ui;
}

void Login::openRegisterPage(){
    reg=new Register(sqlProcess->getSqlDatabase());
    reg->show();
}
void Login::init(){
    this->setWindowFlags(Qt::Tool);

    sqlProcess=new SqlProcess();

}
void Login::openInPage(){
    QSqlQuery query("select accountId,paw from Account",sqlProcess->getSqlDatabase());
    QString curAccount=ui->leAccount->text().toUtf8();
    QString curPassword=ui->lePassword->text();

    QSqlRecord rec=query.record();
    qDebug()<<"第0列:"<<query.isNull(0);
    qDebug()<<"列数:"<<rec.count();
    while(query.next()){
        rec=query.record();

        QString ac=query.value("accountId").toString().toUtf8();
        QString pas=query.value("paw").toString();

        qDebug()<<ac;
        qDebug()<<pas;
        if(curAccount==ac){
            //QString pas=query.value("paw").toString().toUtf8();

            if(pas==curPassword){
                Page* page=new Page(sqlProcess->getSqlDatabase());
                page->show();
                this->close();
                return;
            }else {
                ui->leWarn->setText("你的密码错误");
                ui->leAccount->clear();
                ui->lePassword->clear();
                return;
            }

        }
    }
    ui->leWarn->setText("你的账号不存在");
    ui->leAccount->clear();
    ui->lePassword->clear();
    return;

}

