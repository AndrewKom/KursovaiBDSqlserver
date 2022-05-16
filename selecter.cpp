#include "selecter.h"
#include "ui_selecter.h"

Selecter::Selecter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Selecter)
{
    ui->setupUi(this);
}

Selecter::~Selecter()
{
    delete ui;
}

void Selecter::on_pushButton_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("  SELECT * FROM Rabotnik WHERE otdelname_Rabotnik = 'Sklad 1' AND Post_Rabotnik = any (SELECT Post_Rabotnik FROM Rabotnik WHERE Post_Rabotnik = 'Inzener 1K')");
    if (model->lastError().isValid())
        qDebug() << model->lastError();


    ui->tableViewS->setModel(model);
    ui->tableViewS->resizeColumnsToContents();
    ui->tableViewS->show();
}


void Selecter::on_pushButton_2_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("  select* from Rabotnik_shetchik_view ");
    if (model->lastError().isValid())
        qDebug() << model->lastError();


    ui->tableViewS->setModel(model);
    ui->tableViewS->resizeColumnsToContents();
    ui->tableViewS->show();
}


void Selecter::on_pushButton_4_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("  SELECT  marka_shetchik, id_shetchik, (SELECT name_Rabotnik FROM Rabotnik r WHERE  s.RabotnikId_shetchik= r.id_Rabotnik) AS NAME  FROM shetchik s; ");
    if (model->lastError().isValid())
        qDebug() << model->lastError();


    ui->tableViewS->setModel(model);
    ui->tableViewS->resizeColumnsToContents();
    ui->tableViewS->show();
}


void Selecter::on_pushButton_3_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("  select S_R.* from (select r.id_Rabotnik, r.name_Rabotnik,s.marka_shetchik from Rabotnik r  join shetchik s on s.RabotnikId_shetchik=r.id_Rabotnik) S_R where S_R.id_Rabotnik>4 ");
    if (model->lastError().isValid())
        qDebug() << model->lastError();


    ui->tableViewS->setModel(model);
    ui->tableViewS->resizeColumnsToContents();
    ui->tableViewS->show();
}


void Selecter::on_pushButton_5_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("  select r.* from Rabotnik r where r.id_Rabotnik = ( select s.RabotnikId_shetchik from shetchik s where s.id_shetchik=4 );  ");
    if (model->lastError().isValid())
        qDebug() << model->lastError();


    ui->tableViewS->setModel(model);
    ui->tableViewS->resizeColumnsToContents();
    ui->tableViewS->show();
}


void Selecter::on_pushButton_8_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery(" select * from Otchet o where exists(select * from Prikaz p where p.id_Prikaz=o.PrikazId_Otchet)  ");
    if (model->lastError().isValid())
        qDebug() << model->lastError();


    ui->tableViewS->setModel(model);
    ui->tableViewS->resizeColumnsToContents();
    ui->tableViewS->show();
}


void Selecter::on_pushButton_9_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery(" SELECT id_Rabotnik,name_Rabotnik,Post_Rabotnik,otdelname_Rabotnik, case Post_Rabotnik  when 'Inzener 1K' then 'Top' when 'Inzener 2K' then 'Mid' when 'Inzener 3K' then 'Bot' else 'error' end RangInKompany FROM Rabotnik r left join shetchik s  on (r.id_Rabotnik=s.RabotnikId_shetchik) WHERE s.marka_shetchik = (SELECT marka_shetchik FROM shetchik WHERE id_shetchik ="+ui->lineEdit->text()+");");
    if (model->lastError().isValid()){
        qDebug() << model->lastError();
        QMessageBox::warning(this, "Внимание","Вы ввели недопустимое значение, попробуйте другое");
    }
    else{

    ui->tableViewS->setModel(model);
    ui->tableViewS->resizeColumnsToContents();
    ui->tableViewS->show();
}
}

void Selecter::on_pushButton_7_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT PrikazId_Otchet, count(PrikazId_Otchet) as count, p.id_Prikaz,Name_Prikaz FROM Otchet o, Prikaz p GROUP BY PrikazId_Otchet,p.id_Prikaz,Name_Prikaz HAVING count(PrikazId_Otchet) > "+ui->lineEdit->text()+";");
    if (model->lastError().isValid()){
        qDebug() << model->lastError();
        QMessageBox::warning(this, "Внимание","Вы ввели недопустимое значение, попробуйте другое");
    }
    else{

    ui->tableViewS->setModel(model);
    ui->tableViewS->resizeColumnsToContents();
    ui->tableViewS->show();
}
}

