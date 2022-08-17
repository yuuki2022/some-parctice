#ifndef SETQUESTION_H
#define SETQUESTION_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QTimer>

namespace Ui {
class SetQuestion;
}

class SetQuestion : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetQuestion(QWidget *parent = nullptr);
    ~SetQuestion();
    int generateRand(const int& max);
    void init();


public slots:
    void setNumber(QAbstractButton* btn);
    void checkAnswer();
    void timeDisplay();
    void staticsDisplay();
    void closeDisplay();


private:
    Ui::SetQuestion *ui;
    QButtonGroup *buttonGroup;

    int gradeIndex=0;
    int number1=0;
    int number2=0;
    int rightResult=0;

    int rightRecord=0;
    int total=0;

    QTimer *timer;
    int second=0;
    int minute=0;

};

#endif // SETQUESTION_H
