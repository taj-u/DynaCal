#ifndef DIGICAL_H
#define DIGICAL_H

#include <QMainWindow>
#include "calculator.h"
#include "bmi.h"
#include "agecalculator.h"
#include "converter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DigiCal; }
QT_END_NAMESPACE

class DigiCal : public QMainWindow
{
    Q_OBJECT

public:
    DigiCal(QWidget *parent = nullptr);
    ~DigiCal();

private slots:
    void on_ButtonCal_clicked();

    void on_ButtonBMIC_clicked();

    void on_ButtoAgeC_clicked();

    void on_ButtonCon_clicked();

public:
    Ui::DigiCal *ui;
    Calculator calculator;
    BMI bmi;
    AgeCalculator agecalc;
    Converter converter;
};
#endif // DIGICAL_H
