#include "sqlprocess.h"
#include <QMessageBox>

SqlProcess::SqlProcess(const QString &ip, QString dataname, const QString &username, const QString &password, int port)
{


    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(ip);
    db.setDatabaseName(dataname);
    db.setUserName(username);
    db.setPassword(password);
    db.setPort(port);

    bool connectOk=db.open();

    if(!connectOk){
        qDebug()<<"fail to open";
        QMessageBox::warning(nullptr,"错误","没有打开数据库",QMessageBox::Cancel);
        return;
    }

    qDebug()<<db.drivers();

    QSqlQuery query(db);
    QString createTable="create table Account "
                        "("
                        "accountId varchar(25) primary key,"
                        "paw varchar(25)not null"
                        ")";


    if(!query.exec(createTable)){
        qDebug()<<query.lastError().text().toUtf8();
    }else{
        qDebug()<<"Yes";
    }

   qDebug()<< query.exec(QObject::tr("insert into Account values('testone','123456')"));
   qDebug()<< query.lastError().text();
   query.exec(QObject::tr("insert into Account values('testtwo','012354')"));



}

QSqlDatabase& SqlProcess::getSqlDatabase()
{
    return db;
}
