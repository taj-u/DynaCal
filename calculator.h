#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void digit_pressed();
    void on_PBDot_released();
    void UnaryOperatorPressed();
    void BinaryOperatorPressed();
    void Trig_logOperatorPressed();
    void on_PBEql_released();
    void on_PBClr_released();
    void on_PBC_clicked();
    void on_PB_Back_clicked();
};

#endif // CALCULATOR_H
