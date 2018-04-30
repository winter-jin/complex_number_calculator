#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置字体
    QFont ft;
    ft.setPointSize(10);
    ui->complex_number_one->setFont(ft);
    ui->complex_number_result->setFont(ft);
    ui->complex_number_two->setFont(ft);
    ui->operator_2->setFont(ft);
    ui->image_part_one->setFont(ft);
    ui->image_part_result->setFont(ft);
    ui->image_part_two->setFont(ft);
    ui->real_part_one->setFont(ft);
    ui->real_part_two->setFont(ft);
    ui->real_part_result->setFont(ft);

    //设置文字
    ui->complex_number_one->setText(QString::fromLocal8Bit("复数1"));
    ui->complex_number_result->setText(QString::fromLocal8Bit("复数计算结果"));
    ui->complex_number_two->setText(QString::fromLocal8Bit("复数2"));
    ui->operator_2->setText(QString::fromLocal8Bit("运算符"));
    ui->image_part_one->setText(QString::fromLocal8Bit("虚部"));
    ui->image_part_result->setText(QString::fromLocal8Bit("虚部"));
    ui->image_part_two->setText(QString::fromLocal8Bit("虚部"));
    ui->real_part_one->setText(QString::fromLocal8Bit("实部"));
    ui->real_part_two->setText(QString::fromLocal8Bit("实部"));
    ui->real_part_result->setText(QString::fromLocal8Bit("实部"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double real1 = ui->real_one->text().toDouble();
    double real2 = ui->real_two->text().toDouble();
    double image1 = ui->image_one->text().toDouble();
    double image2 = ui->image_two->text().toDouble();
    if(ui->operator_3->text()=="+")
    {
        double real3 = real1 + real2;
        double image3 = image1 + image2;
        ui->real_result->setText(QString::number(real3, 10, 4));
        ui->image_result->setText(QString::number(image3, 10, 4));
    }
    else if(ui->operator_3->text()=="-")
    {
        double real3 = real1 - real2;
        double image3 = image1 - image2;
        ui->real_result->setText(QString::number(real3, 10, 4));
        ui->image_result->setText(QString::number(image3, 10, 4));
    }
    else if(ui->operator_3->text()=="*")
    {
        double real3 = real1 * real2 + (-1) * image1 *image2;
        double image3 = real2 * image1 + real1 * image2;
        ui->real_result->setText(QString::number(real3, 10, 4));
        ui->image_result->setText(QString::number(image3, 10, 4));
    }
    else
    {
        ui->operator_3->setText(QString::fromLocal8Bit("请重新输入运算符"));
    }
}
