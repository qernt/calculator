#include "mainwindow.h"
#include "./ui_mainwindow.h"

double first_number = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(303, 416);
    this->setWindowTitle("Calculator");

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_Plus,SIGNAL(clicked()),this,SLOT(check_math_operation_buttons()));
    connect(ui->pushButton_Minus,SIGNAL(clicked()),this,SLOT(check_math_operation_buttons()));
    connect(ui->pushButton_Devide,SIGNAL(clicked()),this,SLOT(check_math_operation_buttons()));
    connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(check_math_operation_buttons()));

    ui->pushButton_Plus->setCheckable(true);
    ui->pushButton_Minus->setCheckable(true);
    ui->pushButton_Devide->setCheckable(true);
    ui->pushButton_x->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double number_in_label;
    QString new_lable;

    if(ui->result->text().contains(".") && button->text() == "0")
    {
        new_lable = ui->result->text() + button->text();
    }else
    {
        number_in_label = (ui->result->text() + button->text()).toDouble();
        new_lable = QString::number(number_in_label, 'g', 15);
    }


    ui->result->setText(new_lable);
}

void MainWindow::on_pushButton_Dot_clicked()
{
    if(!ui->result->text().contains("."))
        ui->result->setText(ui->result->text() + ".");
}

void MainWindow::on_pushButton_PlusMinus_clicked()
{
    double number_in_label;
    QString new_lable;
    number_in_label = (ui->result->text()).toDouble() * (-1);
    new_lable = QString::number(number_in_label, 'g', 15);

    ui->result->setText(new_lable);
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->result->setText("0");
}

void MainWindow::on_pushButton_Percent_clicked()
{
    double number_in_label;
    QString new_lable;
    number_in_label = (ui->result->text()).toDouble() * 0.01;
    new_lable = QString::number(number_in_label, 'g', 15);

    ui->result->setText(new_lable);
}

void MainWindow::check_math_operation_buttons()
{
    QPushButton *button = (QPushButton *)sender();

    ui->pushButton_Plus->setChecked(false);
    ui->pushButton_Minus->setChecked(false);
    ui->pushButton_Devide->setChecked(false);
    ui->pushButton_x->setChecked(false);

    first_number = ui->result->text().toDouble();
    ui->result->setText("0");
    button->setChecked(true);
}

void MainWindow::on_pushButton_Equal_clicked()
{
    double result_of_operation = 0;
    QString new_lable;
    if(ui->pushButton_Plus->isChecked())
    {
        result_of_operation = first_number + ui->result->text().toDouble();
        ui->pushButton_Plus->setChecked(false);
    }else if(ui->pushButton_Minus->isChecked())
    {
        result_of_operation = first_number - ui->result->text().toDouble();
        ui->pushButton_Minus->setChecked(false);
    }else if(ui->pushButton_Devide->isChecked())
    {
        if(ui->result->text().toDouble() != 0)
        {
            result_of_operation = first_number / ui->result->text().toDouble();
            ui->pushButton_Devide->setChecked(false);
        }else
        {
            result_of_operation = 0;
            ui->pushButton_Devide->setChecked(false);
        }
    }else if(ui->pushButton_x->isChecked())
    {
        result_of_operation = first_number * ui->result->text().toDouble();
        ui->pushButton_x->setChecked(false);
    }
    new_lable = QString::number(result_of_operation, 'g', 15);
    ui->result->setText(new_lable);
}

