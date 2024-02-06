#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(5, 5); // строка|столбец

    {
        model->setItem(0, 0, new QStandardItem("ПЕРВЫЙ"));
        model->setItem(0, 1, new QStandardItem("20"));
        model->setItem(0, 2, new QStandardItem("1"));
        model->setItem(0, 3, new QStandardItem("ДЖУН"));
        model->setItem(0, 4, new QStandardItem("100.000"));


        model->setItem(1, 0, new QStandardItem("ВТОРОЙ"));
        model->setItem(1, 1, new QStandardItem("30"));
        model->setItem(1, 2, new QStandardItem("5"));
        model->setItem(1, 3, new QStandardItem("МИДЛ"));
        model->setItem(1, 4, new QStandardItem("200.000"));

        model->setItem(2, 0, new QStandardItem("ТРЕТИЙ"));
        model->setItem(2, 1, new QStandardItem("20"));
        model->setItem(2, 2, new QStandardItem("2"));
        model->setItem(2, 3, new QStandardItem("ДЖУН"));
        model->setItem(2, 4, new QStandardItem("100.000"));

        model->setItem(3, 0, new QStandardItem("ЧЕТВЕРТЫЙ"));
        model->setItem(3, 1, new QStandardItem("30"));
        model->setItem(3, 2, new QStandardItem("8"));
        model->setItem(3, 3, new QStandardItem("СЕНЬЕР"));
        model->setItem(3, 4, new QStandardItem("200.000"));

        model->setItem(4, 0, new QStandardItem("ПЯТЫЙ"));
        model->setItem(4, 1, new QStandardItem("40"));
        model->setItem(4, 2, new QStandardItem("15"));
        model->setItem(4, 3, new QStandardItem("СЕНЬЕР"));
        model->setItem(4, 4, new QStandardItem("500.000"));


        model->setHeaderData(0, Qt::Horizontal, "ФИО");
        model->setHeaderData(1, Qt::Horizontal, "Возраст");
        model->setHeaderData(2, Qt::Horizontal, "Стаж работы");
        model->setHeaderData(3, Qt::Horizontal, "Уровень");
        model->setHeaderData(4, Qt::Horizontal, "Зарплата");
    }//Заполнение

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setMinimumSize(QSize(500, 250));
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setModel(model);
    ui->tableView->setHidden(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BT_Edit_clicked()
{
    if(check == true)
    {
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->BT_Edit->setText("Edit");
        check=false;
    }
    else
    {
        ui->tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
        ui->BT_Edit->setText("Save");
        check=true;
    }
}

