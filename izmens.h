#ifndef IZMENS_H
#define IZMENS_H

#include <QWidget>
#include <qmessagebox.h>
#include <QSqlQuery>
#include <QSqlError>
namespace Ui {
class izmenS;
}

class izmenS : public QWidget
{
    Q_OBJECT

public:
    explicit izmenS(QWidget *parent = nullptr);
    ~izmenS();

    int postcombat;
    int postcombat2;
    int postcombat3;
    int wp;
private slots:
    void obr_sendID(int);
    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_clicked();

signals:
     void refresh();
private:
    Ui::izmenS *ui;
};

#endif // IZMENS_H
