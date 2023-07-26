#ifndef BMI_H
#define BMI_H

#include <QWidget>
#include "ui_digical.h"

namespace Ui {
class BMI;
}

class BMI : public QWidget
{
    Q_OBJECT

public:
    explicit BMI(QWidget *parent = nullptr);
    ~BMI();

private slots:

    void on_tEW_selectionChanged();

    void on_tEH_selectionChanged();

    void on_result_clicked();


    void on_PB_Back_clicked();

private:
    Ui::BMI *ui;
    Ui::DigiCal *mn;

};

#endif // BMI_H
