#include "setquestion.h"
#include "ui_setquestion.h"
#include <QMessageBox>
#include <QTime>
SetQuestion::SetQuestion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetQuestion)
{
    ui->setupUi(this);

    init();


   connect(this->buttonGroup,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(setNumber(QAbstractButton*)));
   connect(ui->ieResult,SIGNAL(returnPressed()),this,SLOT(checkAnswer()));
   connect(ui->pbCheck,SIGNAL(clicked()),this,SLOT(checkAnswer()));
   connect(timer,SIGNAL(timeout()),this,SLOT(timeDisplay()));
   connect(ui->pbStatics,SIGNAL(clicked()),this,SLOT(staticsDisplay()));
   connect(ui->pbExit,SIGNAL(clicked()),this,SLOT(closeDisplay()));


}

SetQuestion::~SetQuestion()
{
    delete ui;
}

int SetQuestion::generateRand(const int& max){
    return qrand()%max;
}

void SetQuestion::setNumber(QAbstractButton* btn=nullptr){
    if(btn==ui->rbDir1){
        gradeIndex=10;
    }else if(btn==ui->rbDir2){
        gradeIndex=100;
    }else if(btn==ui->rbDir3){
        gradeIndex=1000;
    }else if(btn==ui->rbDir4){
        gradeIndex=10000;
    }else if(gradeIndex==0){
        return;
    }

    number1=generateRand(gradeIndex);
    number2=generateRand(gradeIndex);

    ui->ieNumber1->setText(QString::number(number1));
    ui->ieNumber2->setText(QString::number(number2));

    switch (qrand()%4) {
    case 0: {
        rightResult=number1+number2;
        ui->ieOper->setText("+");
        break;
    }
    case 1:{
        rightResult=number1-number2;
        ui->ieOper->setText("+");
        break;
    }
    case 2:{
        rightResult=number1*number2;
        ui->ieOper->setText("×");
        break;
    }
    case 3:{
        rightResult=number1/number2;
        ui->ieOper->setText("/");
        break;
    }
    }
 }

void SetQuestion::checkAnswer(){
    total++;

    if(rightResult==ui->ieResult->text().toInt()){
        rightRecord++;
    }

    ui->ieRight->setText(QString::number(rightRecord));
    ui->ieError->setText(QString::number(total-rightRecord));
    ui->ieTotal->setText(QString::number(total));

    ui->ieResult->clear();
    setNumber();

}

void SetQuestion::init(){
    buttonGroup=new QButtonGroup(this);
    buttonGroup->addButton(ui->rbDir1);
    buttonGroup->addButton(ui->rbDir2);
    buttonGroup->addButton(ui->rbDir3);
    buttonGroup->addButton(ui->rbDir4);

    ui->rbDir1->setChecked(true);
    ui->ieRight->setText("0");
    ui->ieError->setText("0");
    ui->ieTotal->setText("0");
    ui->ieRight->setReadOnly(true);
    ui->ieError->setReadOnly(true);
    ui->ieTotal->setReadOnly(true);
    ui->ieNumber1->setReadOnly(true);
    ui->ieNumber2->setReadOnly(true);
    ui->ieIsEqual->setText("=");
    ui->ieIsEqual->setReadOnly(true);
    ui->ieResult->setPlaceholderText("answer");

    timer=new QTimer();
    timer->setInterval(1000);
    timer->start();

}

void SetQuestion::staticsDisplay(){
    QString text=QString("正确: %1\n错误: %2\n总计: %3").arg(rightRecord).arg(total-rightRecord).arg(total);
    QMessageBox::information(this,"统计对错",text);
}

void SetQuestion::timeDisplay(){
    second++;
    if(second==60){
        minute++;
        second=0;
    }

    QTime *time=new QTime(minute,second);
    QString text=time->toString("hh:mm");
    ui->ieTime->setText(text);
}

void SetQuestion::closeDisplay(){
    QMessageBox* message=new QMessageBox(QMessageBox::Warning,"退出","真的要退出吗?",QMessageBox::Yes|QMessageBox::No,this);
    int ret=message->exec();

    if(ret==QMessageBox::Yes){
        this->close();
    }else{
        message->close();
    }

}
