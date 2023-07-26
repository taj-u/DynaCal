#ifndef AGECALCULATOR_H
#define AGECALCULATOR_H

#include <QWidget>

namespace Ui {
class AgeCalculator;
}

class AgeCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit AgeCalculator(QWidget *parent = nullptr);
    ~AgeCalculator();

private slots:
    void on_PB_res_clicked();

    void on_PB_Back_clicked();

private:
    Ui::AgeCalculator *ui;
};

#endif // AGECALCULATOR_H
