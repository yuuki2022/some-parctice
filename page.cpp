#include "page.h"
#include "ui_page.h"

Page::Page(const QSqlDatabase& db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page)
{
    ui->setupUi(this);
    model=new QSqlTableModel(this,db);
    model->setTable("Account");

    model->setHeaderData(0,Qt::Horizontal,"账号");
    model->setHeaderData(1,Qt::Horizontal,"密码");

    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,165);
    ui->tableView->setColumnWidth(1,165);
    model->select();
    connect(ui->buttonBox,SIGNAL(clicked()),this,SLOT(close()));
}

Page::~Page()
{
    delete ui;
}
