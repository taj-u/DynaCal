#ifndef CONVERTER_H
#define CONVERTER_H

#include <QWidget>

namespace Ui {
class Converter;
}

class Converter : public QWidget
{
    Q_OBJECT

public:
    explicit Converter(QWidget *parent = nullptr);
    ~Converter();

private slots:
    void on_Comb_activated(const QString &arg1);


    void on_CombOut_highlighted(const QString &arg1);


    void on_PB_Back_clicked();

private:
    Ui::Converter *ui;
};

#endif // CONVERTER_H
