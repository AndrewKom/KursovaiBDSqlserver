#include "izmenenieprikaz.h"
#include "ui_izmenenieprikaz.h"

izmeneniePrikaz::izmeneniePrikaz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::izmeneniePrikaz)
{
    ui->setupUi(this);

    postcombat=0;
    wp=0;
}

izmeneniePrikaz::~izmeneniePrikaz()
{
    delete ui;
}



void izmeneniePrikaz::on_comboBox_currentIndexChanged(int index)
{
      postcombat=index;
}

void izmeneniePrikaz::obr_sendID(int pos){
    QSqlQuery* query = new QSqlQuery();
    query->prepare("select name_Prikaz, Svazanniy_Prikaz, Date_Prikaz from Prikaz where id_Prikaz=?");
    query->bindValue(0,pos);
    wp=pos;
    if(query->exec()){
        query->next();
        ui->lineEdit_2->setText(query->value(0).toString());

        QSqlQuery* querynew = new QSqlQuery();
        querynew->prepare("SELECT z.Name_Prikaz FROM Prikaz p left join Prikaz z on z.id_Prikaz=p.Svazanniy_Prikaz where p.id_Prikaz=?");
        querynew->bindValue(0,pos);
        QMessageBox* ms1=new QMessageBox();
        if(!querynew->exec()){
            ms1->setText("Запрос не выполнился");
            ms1->show();
        }
        querynew->first();


        ui->comboBox->addItem(querynew->value(0).toString());
        QSqlQuery* query5=new QSqlQuery();
        query5->exec("select DISTINCT Name_Prikaz  from Prikaz");
        while(query5->next()){
            ui->comboBox->addItem(query5->value(0).toString());
        }
        ui->dateEdit->setDate(QDate::fromString(query->value(2).toString(),"yyyy-MM-dd"));



    }
}


void izmeneniePrikaz::on_pushButton_clicked()
{
    if (ui->lineEdit_2->displayText().isEmpty()){
        QMessageBox::warning(this, "Внимание","Вы не ввели название");
    }
    else{
    QSqlQuery* query=new QSqlQuery();

    QSqlQuery* querynew=new QSqlQuery();
    querynew->prepare("select id_Prikaz from Prikaz where Name_Prikaz= :idsr ");
    querynew->bindValue(":idsr",ui->comboBox->itemText(postcombat));
    QMessageBox* ms1=new QMessageBox();
    if(!querynew->exec()){
        ms1->setText("Запрос не выполнился");
        ms1->show();
    }
    querynew->first();

    query->prepare("exec  updatePrikaz :Idp, :name,:sv,:data;");
    query->bindValue(":Idp",wp);
    query->bindValue(":name",ui->lineEdit_2->text());
    query->bindValue(":sv",querynew->value(0).toInt());
    query->bindValue(":data",ui->dateEdit->text());

    QMessageBox* ms=new QMessageBox();
    if(!query->exec()){
        ms->setText("Запрос не выполнился"+query->lastError().databaseText());
        ms->show();
    }

    emit refresh();
    close();
   }
}

