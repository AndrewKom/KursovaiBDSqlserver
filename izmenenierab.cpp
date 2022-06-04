#include "izmenenierab.h"
#include "ui_izmenenierab.h"

izmenenierab::izmenenierab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::izmenenierab)
{
    ui->setupUi(this);


    postcombat=0;
    postcombat1=0;
    wp=0;
}

izmenenierab::~izmenenierab()
{
    delete ui;
}

void izmenenierab::on_comboBox_currentIndexChanged(int index)
{
    postcombat=index;
}


void izmenenierab::on_comboBox_2_currentIndexChanged(int index)
{
    postcombat1=index;
}

void izmenenierab::obr_sendID(int pos){
    QSqlQuery* query = new QSqlQuery();
    query->prepare("select name_Rabotnik, Post_Rabotnik,otdelname_Rabotnik from Rabotnik where id_Rabotnik=?");
    query->bindValue(0,pos);
    wp=pos;
    if(query->exec()){
        query->next();
        ui->lineEdit->setText(query->value(0).toString());
        ui->comboBox->addItem(query->value(1).toString());
        ui->comboBox->addItem("Inzener 1K");
        ui->comboBox->addItem("Inzener 2K");
        ui->comboBox->addItem("Inzener 3K");

        ui->comboBox_2->addItem(query->value(2).toString());
        ui->comboBox_2->addItem("Sklad 1");
        ui->comboBox_2->addItem("Sklad 2");
        ui->comboBox_2->addItem("Ofis");


    }
}

void izmenenierab::on_pushButton_clicked()
{
    if (ui->lineEdit->displayText().isEmpty()){
        QMessageBox::warning(this, "Внимание","Вы не ввели имя");
    }
    else{
    QSqlQuery* query=new QSqlQuery();
    query->prepare("exec  updateRabotnik :idR, :name,:post,:otdel;");
    query->bindValue(":idR",wp);
    query->bindValue(":name",ui->lineEdit->text());
    query->bindValue(":post",ui->comboBox->itemText(postcombat));
    query->bindValue(":otdel",ui->comboBox_2->itemText(postcombat1));

    QMessageBox* ms=new QMessageBox();
    if(!query->exec()){
        ms->setText("Запрос не выполнился"+query->lastError().databaseText());
        ms->show();
    }
    emit refresh();
    close();
    }
}

