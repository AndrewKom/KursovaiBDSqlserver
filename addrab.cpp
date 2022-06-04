#include "addrab.h"
#include "ui_addrab.h"

addRab::addRab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addRab)
{
    ui->setupUi(this);


        ui->comboBox->addItem("Inzener 1K");
        ui->comboBox->addItem("Inzener 2K");
        ui->comboBox->addItem("Inzener 3K");


        ui->comboBox_2->addItem("Sklad 1");
        ui->comboBox_2->addItem("Sklad 2");
        ui->comboBox_2->addItem("Ofis");



        ui->comboBox_3->addItem("abibas");
        ui->comboBox_3->addItem("Nuke");
        ui->comboBox_3->addItem("Bershka");

    QSqlQuery* query3=new QSqlQuery();
    query3->exec("select DISTINCT name_Rabotnik from Rabotnik");
    while(query3->next()){
        ui->comboBox_4->addItem(query3->value(0).toString());
    }

        ui->comboBox_5->addItem("kitchen");
        ui->comboBox_5->addItem("bathroom");
        ui->comboBox_5->addItem("PC room");

    QSqlQuery* query5=new QSqlQuery();
    query5->exec("select DISTINCT Name_Prikaz  from Prikaz");
    while(query5->next()){
        ui->comboBox_6->addItem(query5->value(0).toString());
    }
    QSqlQuery* query6=new QSqlQuery();
    query6->exec("select DISTINCT id_shetchik  from shetchik");
    while(query6->next()){
        ui->comboBox_7->addItem(query6->value(0).toString());
    }

    QSqlQuery* query7=new QSqlQuery();
    query7->exec("select DISTINCT Name_Prikaz  from Prikaz");
    while(query7->next()){
        ui->comboBox_8->addItem(query7->value(0).toString());
    }

    QSqlQuery* query8=new QSqlQuery();
    query8->exec("select DISTINCT is_work  from Otchet");
    while(query8->next()){
        ui->comboBox_9->addItem(query8->value(0).toString());
    }


   postcombat=0;
   postcombat1=0;
   postcombat3=0;
   postcombat4=0;
   postcombat5=0;
   postcombat6=0;
   postcombat7=0;
   postcombat8=0;
   postcombat9=0;
}

addRab::~addRab()
{
    delete ui;
}

void addRab::on_pushButton_clicked()
{
    if (ui->lineEdit->displayText().isEmpty()){
        QMessageBox::warning(this, "Внимание","Вы не ввели имя");
    }
    else{
    QSqlQuery* query=new QSqlQuery();
    query->prepare("exec  addRabotnik :name,:post,:otdel;");
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


void addRab::on_comboBox_currentIndexChanged(int index)
{
    postcombat=index;

}


void addRab::on_comboBox_2_currentIndexChanged(int index)
{
    postcombat1=index;
}


void addRab::on_pushButton_2_clicked()
{
    QSqlQuery* query=new QSqlQuery();

    QSqlQuery* querynew=new QSqlQuery();
    querynew->prepare("select id_Rabotnik from Rabotnik where name_Rabotnik= :idsr ");
    querynew->bindValue(":idsr",ui->comboBox_4->itemText(postcombat4));
    QMessageBox* ms1=new QMessageBox();
    if(!querynew->exec()){
        ms1->setText("Запрос не выполнился");
        ms1->show();
    }
    querynew->first();


    query->prepare("exec  addshetchik :start,:End,:marka,:idR,:Pomeshenie;");
    query->bindValue(":start",ui->dateEdit->text());
    query->bindValue(":End",ui->dateEdit_2->text());
    query->bindValue(":marka",ui->comboBox_3->itemText(postcombat3));
    query->bindValue(":idR",querynew->value(0).toInt());
    query->bindValue(":Pomeshenie",ui->comboBox_5->itemText(postcombat5));

    QMessageBox* ms=new QMessageBox();
    if(!query->exec()){
        ms->setText("Запрос не выполнился"+query->lastError().databaseText());
        ms->show();
    }

    emit refresh();
    close();
}


void addRab::on_comboBox_3_currentIndexChanged(int index)
{
    postcombat3=index;
}


void addRab::on_comboBox_4_currentIndexChanged(int index)
{
    postcombat4=index;
}


void addRab::on_comboBox_5_currentIndexChanged(int index)
{
    postcombat5=index;
}


void addRab::on_pushButton_3_clicked()
{
    if (ui->lineEdit_2->displayText().isEmpty()){
        QMessageBox::warning(this, "Внимание","Вы не ввели название");
    }
    else{
    QSqlQuery* query=new QSqlQuery();

    QSqlQuery* querynew=new QSqlQuery();
    querynew->prepare("select id_Prikaz from Prikaz where Name_Prikaz= :idsr ");
    querynew->bindValue(":idsr",ui->comboBox_6->itemText(postcombat6));
    QMessageBox* ms1=new QMessageBox();
    if(!querynew->exec()){
        ms1->setText("Запрос не выполнился");
        ms1->show();
    }
    querynew->first();

    query->prepare("exec  addPrikaz :name,:sv,:data;");
    query->bindValue(":name",ui->lineEdit_2->text());
    query->bindValue(":sv",querynew->value(0).toInt());
    query->bindValue(":data",ui->dateEdit_3->text());

    QMessageBox* ms=new QMessageBox();
    if(!query->exec()){
        ms->setText("Запрос не выполнился"+query->lastError().databaseText());
        ms->show();
    }

    emit refresh();
    close();
   }
}


void addRab::on_comboBox_6_currentIndexChanged(int index)
{
    postcombat6=index;
}


void addRab::on_pushButton_4_clicked()
{
    QSqlQuery* query=new QSqlQuery();

    QSqlQuery* querynew=new QSqlQuery();
    querynew->prepare("select id_Prikaz from Prikaz where Name_Prikaz= :idsr ");
    querynew->bindValue(":idsr",ui->comboBox_8->itemText(postcombat8));
    QMessageBox* ms1=new QMessageBox();
    if(!querynew->exec()){
        ms1->setText("Запрос не выполнился");
        ms1->show();
    }
    querynew->first();

    query->prepare("exec  addOtchet :shetchikId,:data,:PrikazId,:work;");
    query->bindValue(":shetchikId",ui->comboBox_7->itemText(postcombat7));
     query->bindValue(":data",ui->dateEdit_4->text());
    query->bindValue(":PrikazId",querynew->value(0).toInt());
    query->bindValue(":work",ui->comboBox_9->itemText(postcombat9));

    QMessageBox* ms=new QMessageBox();
    if(!query->exec()){
        ms->setText("Запрос не выполнился"+query->lastError().databaseText());
        ms->show();
    }

    emit refresh();
    close();

}


void addRab::on_comboBox_7_currentIndexChanged(int index)
{
    postcombat7=index;
}


void addRab::on_comboBox_8_currentIndexChanged(int index)
{
    postcombat8=index;
}


void addRab::on_comboBox_9_currentIndexChanged(int index)
{
    postcombat9=index;
}

