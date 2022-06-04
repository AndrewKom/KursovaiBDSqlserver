#ifndef ADDRAB_H
#define ADDRAB_H

#include <QWidget>
#include <qmessagebox.h>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class addRab;
}

class addRab : public QWidget
{
    Q_OBJECT

public:
    explicit addRab(QWidget *parent = nullptr);
    ~addRab();

    int postcombat;
    int postcombat1;
    int postcombat3;
    int postcombat4;
    int postcombat5;
    int postcombat6;
    int postcombat7;
    int postcombat8;
    int postcombat9;
private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);
    void on_pushButton_2_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_4_currentIndexChanged(int index);

    void on_comboBox_5_currentIndexChanged(int index);

    void on_pushButton_3_clicked();

    void on_comboBox_6_currentIndexChanged(int index);

    void on_pushButton_4_clicked();

    void on_comboBox_7_currentIndexChanged(int index);

    void on_comboBox_8_currentIndexChanged(int index);

    void on_comboBox_9_currentIndexChanged(int index);

signals:
    void refresh();

private:
    Ui::addRab *ui;
};

#endif // ADDRAB_H
