#ifndef SQLPROCESS_H
#define SQLPROCESS_H
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

class SqlProcess
{
private:
    QSqlDatabase db;
public:
    SqlProcess(const QString& ip="localhost",QString dataname="accounts.db3",const QString& username="root",
               const QString& password="",int port=3306);//设置连接数据库的信息
    QSqlDatabase& getSqlDatabase();//获取连接数据库的信息
};

#endif // SQLPROCESS_H
