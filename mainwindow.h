#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "ui_login.h"

#include "selecter.h"
#include "ui_selecter.h"

#include <QSqlQueryModel>
#include <QSqlError>

#include "addrab.h"
#include "ui_addrab.h"

#include "izmenenierab.h"
#include "ui_izmenenierab.h"

#include "izmens.h"
#include "ui_izmens.h"

#include "izmenenieprikaz.h"
#include "ui_izmenenieprikaz.h"

#include "izmenenieo.h"
#include "ui_izmenenieo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
login* logwin;
Selecter* select_r;
addRab* add_s;
izmenenierab* izmrab;
izmenS* izms;
izmeneniePrikaz* izmp;
izmenenieO* izmo;

int globid;
int globid2;
int globid3;
int globid4;
int fl;

private slots:
void on_action_triggered();

void on_pushButton_clicked();

void on_pushButton_2_clicked();

void on_actionselect_case_any_triggered();

void on_pushButton_3_clicked();

void obr_refresh();

void CustomMenu(QPoint);

void CustomMenus(QPoint);

void CustomMenup(QPoint);

void CustomMenuo(QPoint);
void del_zap();

void izm_zap();

void del_zaps();

void izm_zaps();

void del_zapp();

void izm_zapp();

void del_zapo();

void izm_zapo();
void on_pushButton_4_clicked();

signals:
void sendID(int);
private:
    Ui::MainWindow *ui;
    QSqlQueryModel* model;
    QSqlQueryModel* model1;
    QSqlQueryModel* model2;
    QSqlQueryModel* model3;
    QSqlQueryModel* model4;

};
#endif // MAINWINDOW_H
