#include "addselect.h"
#include "ui_addselect.h"

addselect::addselect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addselect)
{
    ui->setupUi(this);
}

addselect::~addselect()
{
    delete ui;
}

void addselect::on_pushButton_clicked()
{
 aRab=new  addRab();
 aRab->show();
}

