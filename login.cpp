#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{

    ui->setupUi(this);
    ui->lineEdit->setText("LAPTOP-HRJC8ACT\\SQLEXPRESS");
    ui->lineEdit_2->setText("kursovay");
    ui->lineEdit_3->setText("test");
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    mes = new QMessageBox();

}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};SERVER="+ui->lineEdit->text()+";DATABASE+"+ui->lineEdit_2->text()+";");
    db.setUserName(ui->lineEdit_3->text());
   db.setPassword(ui->lineEdit_4->text());

   if (db.open()){
       mes->setText("Соединилось");
       close();
   }
   else{
       mes->setText("Соединение НЕ установлено");
   }

   mes->show();
}

