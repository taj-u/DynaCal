#include "agecalculator.h"
#include "ui_agecalculator.h"
#include "time.h"
#include "ctime"
#include "iostream"

AgeCalculator::AgeCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgeCalculator)
{
    ui->setupUi(this);
}

AgeCalculator::~AgeCalculator()
{
    delete ui;
}

void AgeCalculator::on_PB_res_clicked()
{
    double d = ui->CombD->currentText().toDouble();
    double m = ui->CombM->currentIndex() + 1 ;
    double y = ui->CombY->currentText().toDouble() ;

    ui->LabelM->setText(QString::number(ui->CombM->currentIndex() + 1,'g',15));
    time_t now = time(0);

    tm *ltm = localtime(&now);

    //various components of tm structure.
    //current date.
    double yy = 1900 + ltm->tm_year;
    double mm = 1 + ltm->tm_mon;
    double dd =  ltm->tm_mday;
    if(dd < d){
        dd += 30;
        --mm;
    }
    if(mm < m){
        mm += 12;
        --yy;
    }
    if(yy - y < 0){
        ui->LabelR->setStyleSheet("QLabel{background-color: #FF6666;border: 1px solid gray;}");
        ui->LabelR->setText("Invalid Input");
        ui->LabelD->setText("0");
        ui->LabelM->setText("0");
        ui->LabelY->setText("0");
    }
    else{
        ui->LabelR->setStyleSheet("QLabel{background-color: #d3d7cf;border: 1px solid gray;}");
        ui->LabelR->setText("Your Age is :");
        ui->LabelD->setText(QString::number(dd - d,'g',4));
        ui->LabelM->setText(QString::number(mm - m,'g',4));
        ui->LabelY->setText(QString::number(yy - y,'g',4));
    }
}

void AgeCalculator::on_PB_Back_clicked()
{
    this->hide();
}
