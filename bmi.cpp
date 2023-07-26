#include "bmi.h"
#include "ui_bmi.h"
#include "digical.h"
#include "ui_digical.h"

int checkerW, checkerH;
BMI::BMI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BMI)
{
    ui->setupUi(this);
}

BMI::~BMI()
{
    delete ui;
}

void BMI::on_tEW_selectionChanged()
{
    if(!checkerW){
        ui->tEW->clear();
        ++checkerW;
    }
}

void BMI::on_tEH_selectionChanged()
{
    if(!checkerH){
        ui->tEH->clear();
        ++checkerH;
    }
}

void BMI::on_result_clicked()
{
    double bmi;
    bmi = ui->tEW->toPlainText().toDouble() / (ui->tEH->toPlainText().toDouble() * ui->tEH->toPlainText().toDouble());
    ui->ShBmi->setText(QString::number(bmi));
    if(bmi < 18.5){
        ui->ShRem->setStyleSheet("QLabel{background-color: #FFFF99;border: 1px solid gray;}");
        ui->ShRem->setText("Underweight");
    }
    else if(bmi >= 18.5 && bmi <= 22.9){
        ui->ShRem->setStyleSheet("QLabel{background-color: #FFFFFF;border: 1px solid gray;}");
        ui->ShRem->setText("Normal");
    }
    else if(bmi >= 23 && bmi <= 24.9){
        ui->ShRem->setStyleSheet("QLabel{background-color: #FFFF99;border: 1px solid gray;}");
        ui->ShRem->setText("Overweight");
    }
    else if(bmi >= 25 && bmi <= 29.9){
        ui->ShRem->setStyleSheet("QLabel{background-color: #FF9933;border: 1px solid gray;}");
        ui->ShRem->setText("Pre-Obese");
    }
    else if(bmi >= 30){
        ui->ShRem->setStyleSheet("QLabel{background-color: #FF6666;border: 1px solid gray;}");
        ui->ShRem->setText("Obese");
    }
}


void BMI::on_PB_Back_clicked()
{
    this->hide();
}
