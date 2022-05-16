#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView,SIGNAL(customContextMenuRequested(QPoint)),SLOT(CustomMenu(QPoint)));
    ui->tableView_2->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView_2,SIGNAL(customContextMenuRequested(QPoint)),SLOT(CustomMenus(QPoint)));
    ui->tableView_4->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView_4,SIGNAL(customContextMenuRequested(QPoint)),SLOT(CustomMenup(QPoint)));

    ui->tableView_3->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView_3,SIGNAL(customContextMenuRequested(QPoint)),SLOT(CustomMenuo(QPoint)));



    fl=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    logwin=new login();
    logwin->show();
}





void MainWindow::on_pushButton_clicked()
{
    fl=1;
        model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM Rabotnik");
        if (model->lastError().isValid())
            qDebug() << model->lastError();

        model->setHeaderData(0, Qt::Horizontal,"id");
        model->setHeaderData(1, Qt::Horizontal,"Имя");
        model->setHeaderData(2, Qt::Horizontal,"Должность");
        model->setHeaderData(3, Qt::Horizontal,"Отдел");

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->show();

        model1 = new QSqlQueryModel();
        model1->setQuery("SELECT * FROM shetchik");
        if (model1->lastError().isValid())
            qDebug() << model1->lastError();

        model1->setHeaderData(0, Qt::Horizontal,"id");
        model1->setHeaderData(1, Qt::Horizontal,"Установлен");
        model1->setHeaderData(2, Qt::Horizontal,"До");
        model1->setHeaderData(3, Qt::Horizontal,"Марка");
        model1->setHeaderData(4, Qt::Horizontal,"Рабочий");
        model1->setHeaderData(5, Qt::Horizontal,"Помещение");


        ui->tableView_2->setModel(model1);
        ui->tableView_2->resizeColumnsToContents();
        ui->tableView_2->show();

        model2 = new QSqlQueryModel();
        model2->setQuery("SELECT * FROM Prikaz");
        if (model2->lastError().isValid())
            qDebug() << model2->lastError();

        model2->setHeaderData(0, Qt::Horizontal,"id");
        model2->setHeaderData(1, Qt::Horizontal,"Название");
        model2->setHeaderData(2, Qt::Horizontal,"Главный приказ");
        model2->setHeaderData(3, Qt::Horizontal,"Дата");


        ui->tableView_4->setModel(model2);
        ui->tableView_4->resizeColumnsToContents();
        ui->tableView_4->show();

        model3 = new QSqlQueryModel();
        model3->setQuery("SELECT * FROM Otchet");
        if (model3->lastError().isValid()){
            qDebug() << model3->lastError();
            QMessageBox::warning(this, "Внимание","Вы не подключились к базе данных");

}
        model3->setHeaderData(0, Qt::Horizontal,"id");
        model3->setHeaderData(1, Qt::Horizontal,"Счетчик");
        model3->setHeaderData(2, Qt::Horizontal,"Дата отчета");
        model3->setHeaderData(3, Qt::Horizontal,"Приказ");
        model3->setHeaderData(4, Qt::Horizontal,"Работает");

        ui->tableView_3->setModel(model3);
        ui->tableView_3->resizeColumnsToContents();
        ui->tableView_3->show();
}



void MainWindow::on_pushButton_2_clicked()
{
    model4 = new QSqlQueryModel();
    model4->setQuery("SELECT * FROM History");
    if (model4->lastError().isValid()){
        qDebug() << model4->lastError();
        QMessageBox::warning(this, "Внимание","Вы не подключились к базе данных");

}
    else{
    model4->setHeaderData(0, Qt::Horizontal,"id");
    model4->setHeaderData(1, Qt::Horizontal,"Отчет");
    model4->setHeaderData(2, Qt::Horizontal,"Операция");
    model4->setHeaderData(3, Qt::Horizontal,"Дата");

    QTableView *view = new QTableView;
    view->setModel(model4);
    view->resizeColumnsToContents();
    view->show();
    }
}


void MainWindow::on_actionselect_case_any_triggered()
{
    select_r=new Selecter();
    select_r->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    add_s=new addRab();
    connect(add_s,SIGNAL(refresh()),this,SLOT(obr_refresh()));
    add_s->show();
}

void MainWindow::obr_refresh(){
    on_pushButton_clicked();
}


void MainWindow::CustomMenu(QPoint pos)
{
    if (fl==1){
        QModelIndex index = ui->tableView->indexAt(pos);
        globid = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toInt();

        QMenu* menu= new QMenu(this);
        QAction* izmrab= new QAction("Изменить",this);
        connect(izmrab,SIGNAL(triggered()),this,SLOT(izm_zap()));

        QAction* udrab = new QAction("Удалить",this);
        connect(udrab,SIGNAL(triggered()),this,SLOT(del_zap()));
        menu->addAction(izmrab);
        menu->addAction(udrab);
        menu->popup(ui->tableView->viewport()->mapToGlobal(pos));

    }
}

void MainWindow::del_zap(){
    QSqlQuery* query = new QSqlQuery();
    query->prepare("exec DeleteRabotnik ?;");
    query->bindValue(0,globid);

    if(query->exec()){
        on_pushButton_clicked();
    }
}
void MainWindow::izm_zap(){
    izmrab=new izmenenierab();
    connect(this,SIGNAL(sendID(int)),izmrab,SLOT(obr_sendID(int)));
    emit sendID(globid);
    connect(izmrab,SIGNAL(refresh()),this,SLOT(obr_refresh()));
    izmrab->show();

    disconnect(this,SIGNAL(sendID(int)),izmrab,SLOT(obr_sendID(int)));
}


void MainWindow::CustomMenus(QPoint pos)
{
    if (fl==1){
        QModelIndex index = ui->tableView_2->indexAt(pos);
        globid2 = ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),0)).toInt();

        QMenu* menus= new QMenu(this);
        QAction* izmrabs= new QAction("Изменить",this);
        connect(izmrabs,SIGNAL(triggered()),this,SLOT(izm_zaps()));

        QAction* udrabs = new QAction("Удалить",this);
        connect(udrabs,SIGNAL(triggered()),this,SLOT(del_zaps()));
        menus->addAction(izmrabs);
        menus->addAction(udrabs);
        menus->popup(ui->tableView_2->viewport()->mapToGlobal(pos));

    }
}


void MainWindow::del_zaps(){
    QSqlQuery* query = new QSqlQuery();
    query->prepare("exec Deleteshetchik ?;");
    query->bindValue(0,globid2);

    if(query->exec()){
        on_pushButton_clicked();
    }
}
void MainWindow::izm_zaps(){
    izms=new izmenS();
    connect(this,SIGNAL(sendID(int)),izms,SLOT(obr_sendID(int)));
    emit sendID(globid2);
    connect(izms,SIGNAL(refresh()),this,SLOT(obr_refresh()));
    izms->show();

    disconnect(this,SIGNAL(sendID(int)),izms,SLOT(obr_sendID(int)));

}


void MainWindow::CustomMenup(QPoint pos)
{
    if (fl==1){
        QModelIndex index = ui->tableView_4->indexAt(pos);
        globid4 = ui->tableView_4->model()->data(ui->tableView_4->model()->index(index.row(),0)).toInt();

        QMenu* menup= new QMenu(this);
        QAction* izmrabp= new QAction("Изменить",this);
        connect(izmrabp,SIGNAL(triggered()),this,SLOT(izm_zapp()));

        QAction* udrabp = new QAction("Удалить",this);
        connect(udrabp,SIGNAL(triggered()),this,SLOT(del_zapp()));
        menup->addAction(izmrabp);
        menup->addAction(udrabp);
        menup->popup(ui->tableView_4->viewport()->mapToGlobal(pos));

    }
}


void MainWindow::del_zapp(){
    QSqlQuery* query = new QSqlQuery();
    query->prepare("exec DeletePrikaz ?;");
    query->bindValue(0,globid4);

    if(query->exec()){
        on_pushButton_clicked();
    }
}
void MainWindow::izm_zapp(){
    izmp=new izmeneniePrikaz();
    connect(this,SIGNAL(sendID(int)),izmp,SLOT(obr_sendID(int)));
    emit sendID(globid4);
    connect(izmp,SIGNAL(refresh()),this,SLOT(obr_refresh()));
    izmp->show();

    disconnect(this,SIGNAL(sendID(int)),izmp,SLOT(obr_sendID(int)));

}




void MainWindow::CustomMenuo(QPoint pos)
{
    if (fl==1){
        QModelIndex index = ui->tableView_3->indexAt(pos);
        globid3 = ui->tableView_3->model()->data(ui->tableView_3->model()->index(index.row(),0)).toInt();

        QMenu* menuo= new QMenu(this);
        QAction* izmrabo= new QAction("Изменить",this);
        connect(izmrabo,SIGNAL(triggered()),this,SLOT(izm_zapo()));

        QAction* udrabo = new QAction("Удалить",this);
        connect(udrabo,SIGNAL(triggered()),this,SLOT(del_zapo()));
        menuo->addAction(izmrabo);
        menuo->addAction(udrabo);
        menuo->popup(ui->tableView_3->viewport()->mapToGlobal(pos));

    }
}


void MainWindow::del_zapo(){
    QSqlQuery* query = new QSqlQuery();
    query->prepare("exec DeleteOtchet ?;");
    query->bindValue(0,globid3);

    if(query->exec()){
        on_pushButton_clicked();
    }
}
void MainWindow::izm_zapo(){
    izmo=new izmenenieO();
    connect(this,SIGNAL(sendID(int)),izmo,SLOT(obr_sendID(int)));
    emit sendID(globid3);
    connect(izmo,SIGNAL(refresh()),this,SLOT(obr_refresh()));
    izmo->show();

    disconnect(this,SIGNAL(sendID(int)),izmo,SLOT(obr_sendID(int)));

}


void MainWindow::on_pushButton_4_clicked()
{


    QSqlQuery* query = new QSqlQuery();
    query->exec("delete from History;");
}

