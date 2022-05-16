#include "izmenenieprikaz.h"
#include "ui_izmenenieprikaz.h"

izmeneniePrikaz::izmeneniePrikaz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::izmeneniePrikaz)
{
    ui->setupUi(this);

    postcombat=0;
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
    if(query->exec()){
        query->next();
        ui->lineEdit_2->setText(query->value(0).toString());
        ui->comboBox->addItem(query->value(1).toString());

        QSqlQuery* query5=new QSqlQuery();
        query5->exec("select DISTINCT id_Prikaz  from Prikaz");
        while(query5->next()){
            ui->comboBox->addItem(query5->value(0).toString());
        }
        ui->dateEdit->setDate(QDate::fromString(query->value(2).toString(),"yyyy-MM-dd"));

        ui->lineEdit->setText(QString::number(pos));

    }
}


void izmeneniePrikaz::on_pushButton_clicked()
{
    if (ui->lineEdit_2->displayText().isEmpty()){
        QMessageBox::warning(this, "Внимание","Вы не ввели название");
    }
    else{
    QSqlQuery* query=new QSqlQuery();
    query->prepare("exec  updatePrikaz :Idp, :name,:sv,:data;");
    query->bindValue(":Idp",ui->lineEdit->text().toInt());
    query->bindValue(":name",ui->lineEdit_2->text());
    query->bindValue(":sv",ui->comboBox->itemText(postcombat));
    query->bindValue(":data",ui->dateEdit->text());

    QMessageBox* ms=new QMessageBox();
    if(!query->exec()){
        ms->setText("Запрос не выполнился");
        ms->show();
    }

    emit refresh();
    close();
   }
}

