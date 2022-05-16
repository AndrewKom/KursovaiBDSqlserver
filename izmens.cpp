#include "izmens.h"
#include "ui_izmens.h"

izmenS::izmenS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::izmenS)
{
    ui->setupUi(this);

    postcombat=0;
    postcombat2=0;
    postcombat3=0;
}

izmenS::~izmenS()
{
    delete ui;
}

void izmenS::on_comboBox_currentIndexChanged(int index)
{
    postcombat=index;
}


void izmenS::on_comboBox_2_currentIndexChanged(int index)
{
    postcombat2=index;
}


void izmenS::on_comboBox_3_currentIndexChanged(int index)
{
    postcombat3=index;
}


void izmenS::obr_sendID(int pos){
    QSqlQuery* query = new QSqlQuery();
    query->prepare("select Start_shetchik,END_shetchik,marka_shetchik,RabotnikId_shetchik,Pomeshenie_shetchik from shetchik where id_shetchik=?");
    query->bindValue(0,pos);
    if(query->exec()){
        query->next();
        ui->dateEdit->setDate(QDate::fromString(query->value(0).toString(),"yyyy-MM-dd"));
        ui->dateEdit_2->setDate(QDate::fromString(query->value(1).toString(),"yyyy-MM-dd"));
        ui->comboBox->addItem(query->value(2).toString());
        ui->comboBox->addItem("abibas");
        ui->comboBox->addItem("Nuke");
        ui->comboBox->addItem("Bershka");

        ui->comboBox_2->addItem(query->value(3).toString());
        QSqlQuery* query3=new QSqlQuery();
        query3->exec("select DISTINCT id_Rabotnik from Rabotnik");
        while(query3->next()){
            ui->comboBox_2->addItem(query3->value(0).toString());
        }

       ui->comboBox_3->addItem(query->value(4).toString());

       ui->comboBox_3->addItem("kitchen");
       ui->comboBox_3->addItem("bathroom");
       ui->comboBox_3->addItem("PC room");


        ui->lineEdit->setText(QString::number(pos));

    }
}

void izmenS::on_pushButton_clicked()
{
    QSqlQuery* query=new QSqlQuery();
    query->prepare("exec  updateshetchik :idS,:start,:End,:marka,:idR,:Pomeshenie;");
    query->bindValue(":idS",ui->lineEdit->text().toInt());
    query->bindValue(":start",ui->dateEdit->text());
    query->bindValue(":End",ui->dateEdit_2->text());
    query->bindValue(":marka",ui->comboBox->itemText(postcombat));
    query->bindValue(":idR",ui->comboBox_2->itemText(postcombat2));
    query->bindValue(":Pomeshenie",ui->comboBox_3->itemText(postcombat3));

    QMessageBox* ms=new QMessageBox();
    if(!query->exec()){
        ms->setText("Запрос не выполнился");
        ms->show();
    }

    emit refresh();
    close();
}

