#ifndef IZMENENIEPRIKAZ_H
#define IZMENENIEPRIKAZ_H

#include <QWidget>
#include <qmessagebox.h>
#include <QSqlQuery>

namespace Ui {
class izmeneniePrikaz;
}

class izmeneniePrikaz : public QWidget
{
    Q_OBJECT

public:
    explicit izmeneniePrikaz(QWidget *parent = nullptr);
    ~izmeneniePrikaz();


    int postcombat;

private slots:
    void obr_sendID(int);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

signals:
     void refresh();
private:
    Ui::izmeneniePrikaz *ui;
};

#endif // IZMENENIEPRIKAZ_H
