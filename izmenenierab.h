#ifndef IZMENENIERAB_H
#define IZMENENIERAB_H

#include <QWidget>
#include <qmessagebox.h>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class izmenenierab;
}

class izmenenierab : public QWidget
{
    Q_OBJECT

public:
    explicit izmenenierab(QWidget *parent = nullptr);
    ~izmenenierab();





    int postcombat;
    int postcombat1;
    int wp;
private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);
    void obr_sendID(int);

    void on_pushButton_clicked();
signals:
     void refresh();
private:
    Ui::izmenenierab *ui;
};

#endif // IZMENENIERAB_H
