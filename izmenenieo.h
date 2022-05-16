#ifndef IZMENENIEO_H
#define IZMENENIEO_H

#include <QWidget>
#include <qmessagebox.h>
#include <QSqlQuery>

namespace Ui {
class izmenenieO;
}

class izmenenieO : public QWidget
{
    Q_OBJECT

public:
    explicit izmenenieO(QWidget *parent = nullptr);
    ~izmenenieO();

    int postcombat;
    int postcombat2;
    int postcombat3;

private slots:
    void obr_sendID(int);

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_clicked();

signals:
     void refresh();
private:
    Ui::izmenenieO *ui;
};

#endif // IZMENENIEO_H
