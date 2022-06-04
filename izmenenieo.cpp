#include "izmenenieo.h"
#include "ui_izmenenieo.h"

izmenenieO::izmenenieO(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::izmenenieO)
{
    ui->setupUi(this);
    postcombat=0;
    postcombat2=0;
    postcombat3=0;
    wp=0;
}

izmenenieO::~izmenenieO()
{
    delete ui;
}


void izmenenieO::obr_sendID(int pos){

    QSqlQuery* query = new QSqlQuery();
    query->prepare("select shetchikId_Otchet,Date_Otchet,PrikazId_Otchet,is_work from Otchet where id_Otchet=?");
    query->bindValue(0,pos);
    wp=pos;
    if(query->exec()){
        query->next();

        ui->comboBox->addItem(query->value(0).toString());
        QSqlQuery* query6=new QSqlQuery();
        query6->exec("select DISTINCT id_shetchik  from shetchik");
        while(query6->next()){
            ui->comboBox->addItem(query6->value(0).toString());
        }
        ui->dateEdit->setDate(QDate::fromString(query->value(1).toString(),"yyyy-MM-dd"));

        QSqlQuery* querynew = new QSqlQuery();
        querynew->prepare("SELECT z.Name_Prikaz FROM Otchet o left join Prikaz z on z.id_Prikaz=o.PrikazId_Otchet where o.id_Otchet=?");
        querynew->bindValue(0,pos);
        QMessageBox* ms1=new QMessageBox();
        if(!querynew->exec()){
            ms1->setText("Запрос не выполнился");
            ms1->show();
        }
        querynew->first();

        ui->comboBox_2->addItem(querynew->value(0).toString());
        QSqlQuery* query7=new QSqlQuery();
        query7->exec("select DISTINCT Name_Prikaz  from Prikaz");
        while(query7->next()){
            ui->comboBox_2->addItem(query7->value(0).toString());
        }
        ui->comboBox_3->addItem(query->value(3).toString());

        QSqlQuery* query8=new QSqlQuery();
        query8->exec("select DISTINCT is_work  from Otchet");
        while(query8->next()){
            ui->comboBox_3->addItem(query8->value(0).toString());
        }



    }
}

void izmenenieO::on_comboBox_currentIndexChanged(int index)
{
    postcombat=index;
}


void izmenenieO::on_comboBox_2_currentIndexChanged(int index)
{
    postcombat2=index;
}


void izmenenieO::on_comboBox_3_currentIndexChanged(int index)
{
    postcombat3=index;
}


void izmenenieO::on_pushButton_clicked()
{
    QSqlQuery* query=new QSqlQuery();

    QSqlQuery* querynew=new QSqlQuery();
    querynew->prepare("select id_Prikaz from Prikaz where Name_Prikaz= :idsr ");
    querynew->bindValue(":idsr",ui->comboBox_2->itemText(postcombat2));
    QMessageBox* ms1=new QMessageBox();
    if(!querynew->exec()){
        ms1->setText("Запрос не выполнился");
        ms1->show();
    }
    querynew->first();

    query->prepare("exec  updateOtchet :ido,:shetchikId,:data,:PrikazId,:work;");
    query->bindValue(":ido",wp);
    query->bindValue(":shetchikId",ui->comboBox->itemText(postcombat));
     query->bindValue(":data",ui->dateEdit->text());
    query->bindValue(":PrikazId",querynew->value(0).toInt());
    query->bindValue(":work",ui->comboBox_3->itemText(postcombat3));

    QMessageBox* ms=new QMessageBox();
    if(!query->exec()){
        ms->setText("Запрос не выполнился"+query->lastError().databaseText());
        ms->show();
    }

    emit refresh();
    close();
}

