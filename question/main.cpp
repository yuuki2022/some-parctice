#include "setquestion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(time(nullptr));
    SetQuestion w;
    w.show();

    return a.exec();
}
