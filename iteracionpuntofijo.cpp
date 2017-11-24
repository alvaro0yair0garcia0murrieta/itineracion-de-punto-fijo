#include "iteracionpuntofijo.h"
#include "ui_iteracionpuntofijo.h"
#include <cmath>

iteracionpuntofijo::iteracionpuntofijo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iteracionpuntofijo)
{
    ui->setupUi(this);
    // Conexions
    connect(ui->metodo,SIGNAL(clicked()),this,SLOT(metodo1()));
    connect(ui->borrar,SIGNAL(clicked()),this,SLOT(borar()));
    connect(ui->sal,SIGNAL(clicked()),this,SLOT(close()));
}

iteracionpuntofijo::~iteracionpuntofijo()
{
    delete ui;
}

double iteracionpuntofijo::f(double x)
{
    return (667.38/x)*(1-exp(-0.146843*x))-40;
}

void iteracionpuntofijo::metodo1()
{
    QString temp,temp2,temp3,temp4;          //strings
   double  x1s=ui->x1->value();//x
    double ea=ui->er->value();//error

    double xr;//evaluated function
    double ei=100;//error = 100%
    int i=0;//interactions

    while(ei>ea)//method
    {
        xr=f(x1s);
        ei=100*std::abs(xr-x1s)/xr;
        x1s=xr;
        i++;

           if(i==100)
              break;
    }
    temp.append("Raiz=").append(temp2.setNum(x1s)).append("\nError=").append(temp3.setNum(ei)).append("\nItineracion").append(temp4.setNum(i));
    ui->texto->setText(temp);//text
}

void iteracionpuntofijo:: borar()
{
    ui->er->setValue(0.0);
    ui->x1->setValue(0.0);
    ui->texto->clear();

}
