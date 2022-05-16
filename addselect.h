#ifndef ADDSELECT_H
#define ADDSELECT_H

#include <QWidget>
#include "addrab.h"
#include "ui_addrab.h"
namespace Ui {
class addselect;
}

class addselect : public QWidget
{
    Q_OBJECT

public:
    explicit addselect(QWidget *parent = nullptr);
    ~addselect();
addRab* aRab;
private slots:
    void on_pushButton_clicked();

private:
    Ui::addselect *ui;
};

#endif // ADDSELECT_H
