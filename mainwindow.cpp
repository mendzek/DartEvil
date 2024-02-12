#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QWidget"
#include "QTableView"
#include "QPushButton"
#include "QGridLayout"
#include "QLineEdit"
#include "QString"
#include "QStyle"
#include "QObject"

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

    {
    QWidget *workWindow = new QWidget;
    QGridLayout *gridLayoutWorkWin = new QGridLayout;
    QTableView *tableViewMain = new QTableView(workWindow);
    QPushButton *BT_Edit = new QPushButton(workWindow);
    QPushButton *BT_DoFlip = new QPushButton(workWindow);
    QFont font;
    font.setPointSize(21);

    workWindow->setMinimumSize(800,500);
    workWindow->setLayout(gridLayoutWorkWin);

    gridLayoutWorkWin->addWidget(BT_Edit,0,0);
    gridLayoutWorkWin->addWidget(BT_DoFlip,0,1);
    gridLayoutWorkWin->addWidget(tableViewMain,1,0,1,0);

    BT_Edit->setText("Edit");
    BT_DoFlip->setText("Do flip");
    BT_Edit->setObjectName("BT_Edit");
    BT_DoFlip->setObjectName("BT_DoFlip");
    QObject::connect(BT_Edit, SIGNAL(clicked()), this, SLOT(on_BT_Edit_clicked()));
    QObject::connect(BT_DoFlip, SIGNAL(clicked()), this, SLOT(on_BT_DoFlip_clicked()));

    tableViewMain->setModel(model);
    tableViewMain->setFont(font);
    tableViewMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableViewMain->setMinimumSize(QSize(800, 500));
    tableViewMain->resizeColumnsToContents();

    workWindow->show();

    qDebug() << BT_Edit->objectName();
    qDebug() << BT_DoFlip->objectName();
    }//work window
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BT_Edit_clicked()
{
    if(check == true)
    {
        tableViewMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        BT_Edit->setText("Edit");
        check=false;
    }
    else
    {
        tableViewMain->setEditTriggers(QAbstractItemView::AllEditTriggers);
        BT_Edit->setText("Save");
        check=true;
    }
}

void MainWindow::on_BT_DoFlip_clicked()
{
    BT_DoFlip->setText("ssssss");
}

void MainWindow::on_BT_AcceptLogPass_clicked()
{
    login = ui->LE_Login->text();
    password = ui->LE_Password->text();

    login = "asd";
    password = "asd"; //чтобы не писать логин пароль всегда

    if(RightLogin == login && RightPassword == password)
    {
        qDebug() << "nice";
        MainWindow *mainWindow = this;
        mainWindow->close();
    }
    else
    {
        {
        qDebug() << "not nice";
        QWidget *wrongLogPassWindow = new QWidget;
        QGridLayout *gridLayoutWrongLogPassWin = new QGridLayout;
        //QPushButton *BT_OK = new QPushButton(wrongLogPassWindow);
        QLineEdit *LE_Text = new QLineEdit(wrongLogPassWindow);
        QFont font;
        font.setPointSize(10);

        wrongLogPassWindow->setLayout(gridLayoutWrongLogPassWin);
        wrongLogPassWindow->setStyleSheet("QLineEdit { background-color: gray }");
        wrongLogPassWindow->setMinimumSize(200,50);
        wrongLogPassWindow->setMaximumSize(200,50);

        gridLayoutWrongLogPassWin->addWidget(LE_Text,0,0);
        //gridLayoutWrongLogPassWin->addWidget(BT_OK,1,0,1,1);

        LE_Text->setReadOnly(true);
        LE_Text->setText("Wrong login or password");
        LE_Text->setFont(font);

        /*BT_OK->setText("OK");
        BT_OK->setObjectName("BT_OK");
        BT_OK->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        connect(BT_OK, SIGNAL(clicked()), this, SLOT(on_BT_OK_clicked()));*/

        wrongLogPassWindow->show();

        //qDebug() << BT_OK->objectName();
        }//wrong login password window

    }
}

/*void MainWindow::on_BT_OK_clicked()
{
    //QWidget *wrongLogPassWindow = wrongLogPassWindow;
    //wrongLogPassWindow->close();
    wrongLogPassWindow->close();
}*/
