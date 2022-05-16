#ifndef SELECTER_H
#define SELECTER_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlError>

#include <QMessageBox>
namespace Ui {
class Selecter;
}

class Selecter : public QWidget
{
    Q_OBJECT

public:
    explicit Selecter(QWidget *parent = nullptr);
    ~Selecter();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Selecter *ui;
    QSqlQueryModel* model;
};

#endif // SELECTER_H
