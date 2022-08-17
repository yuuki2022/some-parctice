#ifndef PAGE_H
#define PAGE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlDatabase>

namespace Ui {
class Page;
}

class Page : public QDialog
{
    Q_OBJECT

public:
    explicit Page(const QSqlDatabase& db,QWidget *parent = nullptr);
    ~Page();

private:
    Ui::Page *ui;
    QSqlTableModel* model;
};

#endif // PAGE_H
