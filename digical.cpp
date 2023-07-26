#include "digical.h"
#include "ui_digical.h"

DigiCal::DigiCal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DigiCal)
{
    ui->setupUi(this);
}

DigiCal::~DigiCal()
{
    delete ui;
}


void DigiCal::on_ButtonCal_clicked()
{
    calculator.show();
    //this->hide();
}

void DigiCal::on_ButtonBMIC_clicked()
{
    bmi.show();
    //this-> hide();
}

void DigiCal::on_ButtoAgeC_clicked()
{
    agecalc.show();
    //this-> hide();
}

void DigiCal::on_ButtonCon_clicked()
{
    converter.show();
    //this-> hide();
}
