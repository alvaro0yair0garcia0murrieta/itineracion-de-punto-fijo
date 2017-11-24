#ifndef ITERACIONPUNTOFIJO_H
#define ITERACIONPUNTOFIJO_H

#include <QMainWindow>

namespace Ui {
class iteracionpuntofijo;
}

class iteracionpuntofijo : public QMainWindow
{
    Q_OBJECT

public:
    explicit iteracionpuntofijo(QWidget *parent = 0);
    ~iteracionpuntofijo();
     double f(double x);//funtion

private:
    Ui::iteracionpuntofijo *ui;
public slots:
    void metodo1(); //Slot for bisección
    void borar(); //Slot to erase
};

#endif // ITERACIONPUNTOFIJO_H
