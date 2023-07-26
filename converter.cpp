#include "converter.h"
#include "ui_converter.h"
#include "digical.h"

Converter::Converter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Converter)
{
    ui->setupUi(this);
    ui->Comb->setCurrentIndex(0);
    ui->CombInput->clear();
    ui->CombInput->addItems({"Feet/s","Inch/es","Kilometer/s","Light year/s","Meter/s","Yard/s"});
    ui->CombOut->clear();
    ui->CombOut->addItems({"Feet/s","Inch/es","Kilometer/s","Light year/s","Meter/s","Yard/s"});

}

Converter::~Converter()
{
    delete ui;
}
void Converter::on_Comb_activated(const QString &arg1)
{
    if(arg1 == "Time"){
        ui->CombInput->clear();
        ui->input->clear();
        ui->CombInput->addItems({"Year/s","Month/s","Week/s","Day/s","Hours/s","Minute/s","Second/s"});
        ui->CombOut->clear();
        ui->output->clear();
        ui->CombOut->addItems({"Year/s","Month/s","Week/s","Day/s","Hours/s","Minute/s","Second/s"});
    }
    else if(arg1 == "Length"){
        ui->CombInput->clear();
        ui->CombInput->addItems({"Feet/s","Inch/es","Kilometer/s","Light year/s","Meter/s","Yard/s"});
        ui->CombOut->clear();
        ui->output->clear();
        ui->CombOut->addItems({"Feet/s","Inch/es","Kilometer/s","Light year/s","Meter/s","Yard/s"});
    }
    else if(arg1 == "Weight"){
        ui->CombInput->clear();
        ui->input->clear();
        ui->CombInput->addItems({"Gram/s","Kilogram/s","Pound/s"});
        ui->CombOut->clear();
        ui->output->clear();
        ui->CombOut->addItems({"Gram/s","Kilogram/s","Pound/s"});
    }
    else if(arg1 == "Temperature"){
        ui->CombInput->clear();
        ui->input->clear();
        ui->CombInput->addItems({"Celsius","Fahrenheit","Kelvin"});
        ui->CombOut->clear();
        ui->output->clear();
        ui->CombOut->addItems({"Celsius","Fahrenheit","Kelvin"});
    }
}


void Converter::on_CombOut_highlighted(const QString &arg1)
{

        if(arg1 == "Feet/s" && ui->CombInput->currentText() == "Feet/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Meter/s" && ui->CombInput->currentText() == "Feet/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 0.3048, 'g', 15));
        }
        if(arg1 == "Kilometer/s" && ui->CombInput->currentText() == "Feet/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 0.0003048, 'g', 15));
        }
        if(arg1 == "Inch/es" && ui->CombInput->currentText() == "Feet/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 12, 'g', 15));
        }
        if(arg1 == "Yard/s" && ui->CombInput->currentText() == "Feet/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 0.333333, 'g', 15));
        }
        if(arg1 == "Light year/s" && ui->CombInput->currentText() == "Feet/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 3.22174e-17, 'g', 15));
        }


        if(arg1 == "Feet/s" && ui->CombInput->currentText() == "Inch/es"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 0.0833333, 'g', 15));
        }
        if(arg1 == "Meter/s" && ui->CombInput->currentText() == "Inch/es"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 0.0254, 'g', 15));
        }
        if(arg1 == "Kilometer/s" && ui->CombInput->currentText() == "Inch/es"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 2.54e-5, 'g', 15));
        }
        if(arg1 == "Inch/es" && ui->CombInput->currentText() == "Inch/es"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Yard/s" && ui->CombInput->currentText() == "Inch/es"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 0.0277778, 'g', 15));
        }
        if(arg1 == "Light year/s" && ui->CombInput->currentText() == "Inch/es"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 2.6848e-18, 'g', 15));
        }


        if(arg1 == "Feet/s" && ui->CombInput->currentText() == "Meter/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 3.28084, 'g', 15));
        }
        if(arg1 == "Meter/s" && ui->CombInput->currentText() == "Meter/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Kilometer/s" && ui->CombInput->currentText() == "Meter/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 0.001, 'g', 15));
        }
        if(arg1 == "Inch/es" && ui->CombInput->currentText() == "Meter/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 39.3701, 'g', 15));
        }
        if(arg1 == "Yard/s" && ui->CombInput->currentText() == "Meter/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 1.09361, 'g', 15));
        }
        if(arg1 == "Light year/s" && ui->CombInput->currentText() == "Meter/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 1.057e-16, 'g', 15));
        }


        if(arg1 == "Feet/s" && ui->CombInput->currentText() == "Kilometer/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 3280.84, 'g', 15));
        }
        if(arg1 == "Meter/s" && ui->CombInput->currentText() == "Kilometer/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 1000, 'g', 15));
        }
        if(arg1 == "Kilometer/s" && ui->CombInput->currentText() == "Kilometer/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Inch/es" && ui->CombInput->currentText() == "Kilometer/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 39370.1, 'g', 15));
        }
        if(arg1 == "Yard/s" && ui->CombInput->currentText() == "Kilometer/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 1093.61, 'g', 15));
        }
        if(arg1 == "Light year/s" && ui->CombInput->currentText() == "Kilometer/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 1.057e-13, 'g', 15));
        }


        if(arg1 == "Feet/s" && ui->CombInput->currentText() == "Yard/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 3, 'g', 15));
        }
        if(arg1 == "Meter/s" && ui->CombInput->currentText() == "Yard/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 0.9144, 'g', 15));
        }
        if(arg1 == "Kilometer/s" && ui->CombInput->currentText() == "Yard/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 0.0009144, 'g', 15));
        }
        if(arg1 == "Inch/es" && ui->CombInput->currentText() == "Yard/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 36, 'g', 15));
        }
        if(arg1 == "Yard/s" && ui->CombInput->currentText() == "Yard/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Light year/s" && ui->CombInput->currentText() == "Yard/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 9.6652e-17, 'g', 15));
        }


        if(arg1 == "Feet/s" && ui->CombInput->currentText() == "Light year/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 3.28084, 'g', 15));
        }
        if(arg1 == "Meter/s" && ui->CombInput->currentText() == "Light year/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 9.461e+15, 'g', 15));
        }
        if(arg1 == "Kilometer/s" && ui->CombInput->currentText() == "Light year/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 9.461e+12, 'g', 15));
        }
        if(arg1 == "Inch/es" && ui->CombInput->currentText() == "Light year/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 3.725e+17, 'g', 15));
        }
        if(arg1 == "Yard/s" && ui->CombInput->currentText() == "Light year/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 1.035e+16, 'g', 15));
        }
        if(arg1 == "Light year/s" && ui->CombInput->currentText() == "Light year/s"){
            ui->output->setText(ui->input->text());
        }



        if(arg1 == "Celsius" && ui->CombInput->currentText() == "Celsius"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Fahrenheit" && ui->CombInput->currentText() == "Celsius"){
            ui->output->setText(QString::number(((ui->input->text().toDouble() * 9) / 5) + 32, 'g', 15));
        }
        if(arg1 == "Kelvin" && ui->CombInput->currentText() == "Celsius"){
            ui->output->setText(QString::number(ui->input->text().toDouble() + 273.15, 'g', 15));
        }


        if(arg1 == "Celsius" && ui->CombInput->currentText() == "Fahrenheit"){
            ui->output->setText(QString::number(((ui->input->text().toDouble() - 32) * 5) / 9, 'g', 15));
        }
        if(arg1 == "Fahrenheit" && ui->CombInput->currentText() == "Fahrenheit"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Kelvin" && ui->CombInput->currentText() == "Fahrenheit"){
            ui->output->setText(QString::number((((ui->input->text().toDouble() - 32) * 5) / 9) + 273.15, 'g', 15));
        }

        if(arg1 == "Celsius" && ui->CombInput->currentText() == "Kelvin"){
            ui->output->setText(QString::number(ui->input->text().toDouble() - 273.15, 'g', 15));
        }
        if(arg1 == "Fahrenheit" && ui->CombInput->currentText() == "Kelvin"){
            ui->output->setText(QString::number((((ui->input->text().toDouble() - 273.15) * 9) / 5) + 32, 'g', 15));
        }
        if(arg1 == "Kelvin" && ui->CombInput->currentText() == "Kelvin"){
           ui->output->setText(ui->input->text());
        }


        if(arg1 == "Gram/s" && ui->CombInput->currentText() == "Gram/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Kilogram/s" && ui->CombInput->currentText() == "Gram/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 1000, 'g', 15));
        }
        if(arg1 == "Pound/s" && ui->CombInput->currentText() == "Gram/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 453.592, 'g', 15));
        }


        if(arg1 == "Gram/s" && ui->CombInput->currentText() == "Kilogram/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 1000, 'g', 15));
        }
        if(arg1 == "Kilogram/s" && ui->CombInput->currentText() == "Kilogram/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Pound/s" && ui->CombInput->currentText() == "Kilogram/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 2.205, 'g', 15));
        }

        if(arg1 == "Gram/s" && ui->CombInput->currentText() == "Pound/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 453.592, 'g', 15));
        }
        if(arg1 == "Kilogram/s" && ui->CombInput->currentText() == "Pound/s"){
           ui->output->setText(QString::number(ui->input->text().toDouble() / 2.205, 'g', 15));
        }
        if(arg1 == "Pound/s" && ui->CombInput->currentText() == "Pound/s"){
             ui->output->setText(ui->input->text());
        }


        if(arg1 == "Year/s" && ui->CombInput->currentText() == "Year/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Month/s" && ui->CombInput->currentText() == "Year/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 12, 'g', 15));
        }
        if(arg1 == "Week/s" && ui->CombInput->currentText() == "Year/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 52.1429, 'g', 15));
        }
        if(arg1 == "Day/s" && ui->CombInput->currentText() == "Year/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 365, 'g', 15));
        }
        if(arg1 == "Hours/s" && ui->CombInput->currentText() == "Year/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 8760, 'g', 15));
        }
        if(arg1 == "Minute/s" && ui->CombInput->currentText() == "Year/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 525600, 'g', 15));
        }
        if(arg1 == "Second/s" && ui->CombInput->currentText() == "Year/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 3.154e+7, 'g', 15));
        }


        if(arg1 == "Year/s" && ui->CombInput->currentText() == "Month/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 3280.84, 'g', 15));
        }
        if(arg1 == "Month/s" && ui->CombInput->currentText() == "Month/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Week/s" && ui->CombInput->currentText() == "Month/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Day/s" && ui->CombInput->currentText() == "Month/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 39370.1, 'g', 15));
        }
        if(arg1 == "Hours/s" && ui->CombInput->currentText() == "Month/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 1093.61, 'g', 15));
        }
        if(arg1 == "Minute/s" && ui->CombInput->currentText() == "Month/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 1.057e-13, 'g', 15));
        }
        if(arg1 == "Second/s" && ui->CombInput->currentText() == "Month/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 1093.61, 'g', 15));
        }


        if(arg1 == "Year/s" && ui->CombInput->currentText() == "Week/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 12, 'g', 15));
        }
        if(arg1 == "Month/s" && ui->CombInput->currentText() == "Week/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 0.230137, 'g', 15));
        }
        if(arg1 == "Week/s" && ui->CombInput->currentText() == "Week/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Day/s" && ui->CombInput->currentText() == "Week/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 7, 'g', 15));
        }
        if(arg1 == "Hours/s" && ui->CombInput->currentText() == "Week/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 168, 'g', 15));
        }
        if(arg1 == "Minute/s" && ui->CombInput->currentText() == "Week/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 10080, 'g', 15));
        }
        if(arg1 == "Second/s" && ui->CombInput->currentText() == "Week/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 604800, 'g', 15));
        }


        if(arg1 == "Year/s" && ui->CombInput->currentText() == "Day/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 365, 'g', 15));
        }
        if(arg1 == "Month/s" && ui->CombInput->currentText() == "Day/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 30.417, 'g', 15));
        }
        if(arg1 == "Week/s" && ui->CombInput->currentText() == "Day/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 7, 'g', 15));
        }
        if(arg1 == "Day/s" && ui->CombInput->currentText() == "Day/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Hours/s" && ui->CombInput->currentText() == "Day/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 24, 'g', 15));
        }
        if(arg1 == "Minute/s" && ui->CombInput->currentText() == "Day/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 1440, 'g', 15));
        }
        if(arg1 == "Second/s" && ui->CombInput->currentText() == "Day/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 86400, 'g', 15));
        }


        if(arg1 == "Year/s" && ui->CombInput->currentText() == "Hours/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 8760, 'g', 15));
        }
        if(arg1 == "Month/s" && ui->CombInput->currentText() == "Hours/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 730, 'g', 15));
        }
        if(arg1 == "Week/s" && ui->CombInput->currentText() == "Hours/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 168, 'g', 15));
        }
        if(arg1 == "Day/s" && ui->CombInput->currentText() == "Hours/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 24, 'g', 15));
        }
        if(arg1 == "Hours/s" && ui->CombInput->currentText() == "Hours/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Minute/s" && ui->CombInput->currentText() == "Hours/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 60, 'g', 15));
        }
        if(arg1 == "Second/s" && ui->CombInput->currentText() == "Hours/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 3600, 'g', 15));
        }


        if(arg1 == "Year/s" && ui->CombInput->currentText() == "Minute/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 525600
, 'g', 15));
        }
        if(arg1 == "Month/s" && ui->CombInput->currentText() == "Minute/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 730, 'g', 15));
        }
        if(arg1 == "Week/s" && ui->CombInput->currentText() == "Minute/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 43800, 'g', 15));
        }
        if(arg1 == "Day/s" && ui->CombInput->currentText() == "Minute/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 1440, 'g', 15));
        }
        if(arg1 == "Hours/s" && ui->CombInput->currentText() == "Minute/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 60, 'g', 15));
        }
        if(arg1 == "Minute/s" && ui->CombInput->currentText() == "Minute/s"){
            ui->output->setText(ui->input->text());
        }
        if(arg1 == "Second/s" && ui->CombInput->currentText() == "Minute/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() * 60, 'g', 15));
        }


        if(arg1 == "Year/s" && ui->CombInput->currentText() == "Second/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 3.154e+7, 'g', 15));
        }
        if(arg1 == "Month/s" && ui->CombInput->currentText() == "Second/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 2.628e+6, 'g', 15));
        }
        if(arg1 == "Week/s" && ui->CombInput->currentText() == "Second/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 604800, 'g', 15));
        }
        if(arg1 == "Day/s" && ui->CombInput->currentText() == "Second/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 86400, 'g', 15));
        }
        if(arg1 == "Hours/s" && ui->CombInput->currentText() == "Second/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 3600, 'g', 15));
        }
        if(arg1 == "Minute/s" && ui->CombInput->currentText() == "Second/s"){
            ui->output->setText(QString::number(ui->input->text().toDouble() / 60, 'g', 15));
        }
        if(arg1 == "Second/s" && ui->CombInput->currentText() == "Second/s"){
            ui->output->setText(ui->input->text());
        }
    }

void Converter::on_PB_Back_clicked()
{
    this->hide();
}
