#include "calculator.h"
#include "ui_calculator.h"
#include "iostream"
#include "math.h"
#include "QDebug"
#include "string"

#define PI acos(-1)

double firstNum;
int flag = 0;

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->PBZer,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->PB1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->PB2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->PB3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->PB4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->PB5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->PB6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->PB7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->PB8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->PB9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->PBsqr,SIGNAL(released()),this,SLOT(UnaryOperatorPressed()));
    connect(ui->PBSqt,SIGNAL(released()),this,SLOT(UnaryOperatorPressed()));
    connect(ui->PBFact,SIGNAL(released()),this,SLOT(UnaryOperatorPressed()));

    connect(ui->PBPul,SIGNAL(released()),this,SLOT(BinaryOperatorPressed()));
    connect(ui->PBMin,SIGNAL(released()),this,SLOT(BinaryOperatorPressed()));
    connect(ui->PBMul,SIGNAL(released()),this,SLOT(BinaryOperatorPressed()));
    connect(ui->PBDiv,SIGNAL(released()),this,SLOT(BinaryOperatorPressed()));


    connect(ui->PBSin,SIGNAL(released()),this,SLOT(Trig_logOperatorPressed()));
    connect(ui->PBCos,SIGNAL(released()),this,SLOT(Trig_logOperatorPressed()));
    connect(ui->PBTan,SIGNAL(released()),this,SLOT(Trig_logOperatorPressed()));
    connect(ui->PBLog,SIGNAL(released()),this,SLOT(Trig_logOperatorPressed()));


    ui->PBPul->setCheckable(true);
    ui->PBMin->setCheckable(true);
    ui->PBMul->setCheckable(true);
    ui->PBDiv->setCheckable(true);

    ui->PBSin->setCheckable(true);
    ui->PBCos->setCheckable(true);
    ui->PBTan->setCheckable(true);
    ui->PBLog->setCheckable(true);

   //connect(ui->PBClr,SIGNAL(released()),this,SLOT(on_PBClr_pressed()));
   //connect(ui->PBEql,SIGNAL(released()),this,SLOT(on_PBEql_pressed()));
}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::Trig_logOperatorPressed(){
    //double res = 0;
    ui->LabelDisplay->setText("0");
    QPushButton *button = (QPushButton *) sender();
    button->setChecked(true);
}
void Calculator::digit_pressed()
{
    double displayNumber;
    QString newDisplayNumber;

    QPushButton *button = (QPushButton *) sender();

    if((ui->PBPul->isChecked() || ui->PBMin->isChecked() || ui->PBMul->isChecked() || ui->PBDiv->isChecked()) && flag == 1){
        displayNumber = button->text().toDouble();
        flag = 0;
    }
    else
        displayNumber = (ui-> LabelDisplay->text() + button->text()).toDouble();
    newDisplayNumber = QString::number(displayNumber,'g',15);
    ui->LabelDisplay->setText(newDisplayNumber);

}

void Calculator::on_PBDot_released()
{
    ui->LabelDisplay->setText(ui->LabelDisplay->text() + ".");
}

void Calculator::UnaryOperatorPressed()
{
    double displayNumber;
    QString newDisplayNumber;

    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "x²"){
        displayNumber = (ui->LabelDisplay->text().toDouble());
        displayNumber = displayNumber * displayNumber;
        newDisplayNumber = QString::number(displayNumber,'g',15);
        ui->LabelDisplay->setText(newDisplayNumber);
    }
    else if(button->text() == "√x"){
        displayNumber = (ui->LabelDisplay->text().toDouble());
        displayNumber = sqrt(displayNumber);
        newDisplayNumber = QString::number(displayNumber,'g',15);
        ui->LabelDisplay->setText(newDisplayNumber);
    }
    else{
        displayNumber = (ui->LabelDisplay->text().toDouble());

        if(displayNumber == 0)
            displayNumber = 1;

        for (int i = displayNumber - 1;i > 1; --i)
            displayNumber *= i;

        //displayNumber = sqrt(displayNumber);
        newDisplayNumber = QString::number(displayNumber,'g',15);
        ui->LabelDisplay->setText(newDisplayNumber);
    }

}

void Calculator::BinaryOperatorPressed()
{
    QPushButton *button = (QPushButton *) sender();
    firstNum = ui->LabelDisplay->text().toDouble();
    button->setChecked(true);
    flag = 1;
}



/*void Calculator::on_PBEql_released()
{
    qDebug()<<"Eql";
    double displayNumber, secondNum = 0;
    QString newDisplayNumber;
    secondNum = ui->LabelDisplay->text().toDouble();
    if(ui->PBPul->isChecked()){
        displayNumber = firstNum + secondNum;
        newDisplayNumber = QString::number(displayNumber,'g',15);
        ui->LabelDisplay->setText(newDisplayNumber);
        ui->PBPul->setChecked(false);
    }
    else if(ui->PBPul->isChecked()){
        displayNumber = firstNum - secondNum;
        newDisplayNumber = QString::number(displayNumber,'g',15);
        ui->LabelDisplay->setText(newDisplayNumber);
        ui->PBMin->setChecked(false);
    }
    else if(ui->PBPul->isChecked()){
        displayNumber = firstNum * secondNum;
        newDisplayNumber = QString::number(displayNumber,'g',15);
        ui->LabelDisplay->setText(newDisplayNumber);
        ui->PBMul->setChecked(false);
    }
    else{
        displayNumber = firstNum / secondNum;
        newDisplayNumber = QString::number(displayNumber,'g',15);
        ui->LabelDisplay->setText(newDisplayNumber);
        ui->PBDiv->setChecked(false);
    }
}*/

void Calculator::on_PBClr_released()
{
    ui->LabelDisplay->setText(QString::number(0));
}

void Calculator::on_PBEql_released()
{
    double displayNumber, secondNum = 0;
    QString newDisplayNumber;
    secondNum = ui->LabelDisplay->text().toDouble();
    if(ui->PBPul->isChecked()){
        displayNumber = firstNum + secondNum;
        newDisplayNumber = QString::number(displayNumber,'g',15);
        ui->LabelDisplay->setText(newDisplayNumber);
        ui->PBPul->setChecked(false);
    }
    else if(ui->PBMin->isChecked()){
        displayNumber = firstNum - secondNum;
        newDisplayNumber = QString::number(displayNumber,'g',15);
        ui->LabelDisplay->setText(newDisplayNumber);
        ui->PBMin->setChecked(false);
    }
    else if(ui->PBMul->isChecked()){
        displayNumber = firstNum * secondNum;
        newDisplayNumber = QString::number(displayNumber,'g',15);
        ui->LabelDisplay->setText(newDisplayNumber);
        ui->PBMul->setChecked(false);
    }
    else if(ui->PBDiv->isChecked()){
        displayNumber = firstNum / secondNum;
        newDisplayNumber = QString::number(displayNumber,'g',15);
        ui->LabelDisplay->setText(newDisplayNumber);
        ui->PBDiv->setChecked(false);
    }
    else if(ui->PBSin->isChecked()){
        ui->LabelDisplay->setText(QString::number((sin(secondNum * PI / 180)), 'g', 10));
        ui->PBSin->setChecked(false);
    }
    else if(ui->PBCos->isChecked()){
        ui->LabelDisplay->setText(QString::number((cos(secondNum * PI / 180)), 'g', 10));
        ui->PBCos->setChecked(false);
    }
    else if(ui->PBTan->isChecked()){
        ui->LabelDisplay->setText(QString::number((tan(secondNum * PI / 180)), 'g', 10));
        ui->PBTan->setChecked(false);
    }
    else if(ui->PBLog->isChecked()){
        ui->LabelDisplay->setText(QString::number(log(secondNum), 'g', 10));
        ui->PBLog->setChecked(false);
    }
}


void Calculator::on_PBC_clicked()
{
    QString str = ui->LabelDisplay->text();
    ui->LabelDisplay->setText(str.chopped(1));
    if(str.chopped(1) == NULL)
        ui->LabelDisplay->setText("0");
}

void Calculator::on_PB_Back_clicked()
{
    this->hide();
}
