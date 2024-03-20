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
#include "QFile"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(5, 5); // строка|столбец

    {
        QString filename="D:\\QT\\Projects\\DartEvilBest\\DartEvil-version-2\\forTableView";
        QFile file(filename);
        file.open(QIODevice::ReadOnly);
        QTextStream in(&file);

        QString temp=NULL;
        int numOfLines=0;
        while(!in.atEnd())
        {
            in.readLine();
            numOfLines++;
        }
        file.close();
        //qDebug()<<numOfLines;

        file.open(QIODevice::ReadOnly);
        QTextStream mn(&file);
        QString tempNameOfColumn = NULL;
        for(int i=0,j=0,d=0; i<numOfLines;i++)
        {
            temp = mn.readLine();           
            //qDebug() << temp;
            d++;

            if(temp.at(0) == '+')
            {
                j++;
                d=0;
                for(int m=0;m<temp.size();m++)
                {
                    if(temp.at(0)==temp[m])
                        {
                        //qDebug()<<"AA";
                        }
                    else{tempNameOfColumn+=temp[m];}

                }
                model->setHeaderData(numOfColumn, Qt::Horizontal, tempNameOfColumn);
                numOfColumn++;
                qDebug()<<numOfColumn;
                tempNameOfColumn=NULL;
            }
            for(QString x : ArrForTableView)
            {
                if(temp.at(0) == x)
                {
                    temp.removeAt(0);
                    model->setItem(d-1, j-1, new QStandardItem(temp));
                }
            }
        }

        /*model->setHeaderData(0, Qt::Horizontal, "ФИО");
        model->setHeaderData(1, Qt::Horizontal, "Абонемент");
        model->setHeaderData(2, Qt::Horizontal, "Личный тренер");
        model->setHeaderData(3, Qt::Horizontal, "Конец абонемента");
        model->setHeaderData(4, Qt::Horizontal, "Крутой самый?");
        numOfColumn=4;*/

        file.close();
    }//Заполнение

    {
    workWindow = new QWidget;
    QGridLayout *gridLayoutWorkWin = new QGridLayout;
    tableViewMain = new QTableView(workWindow);
    BT_Edit = new QPushButton(workWindow);
    BT_DoFlip = new QPushButton(workWindow);
    QFont font;
    font.setPointSize(21);

    workWindow->setMinimumSize(800,500);
    workWindow->setLayout(gridLayoutWorkWin);

    gridLayoutWorkWin->addWidget(BT_Edit,0,0);
    gridLayoutWorkWin->addWidget(BT_DoFlip,0,1);
    gridLayoutWorkWin->addWidget(tableViewMain,1,0,1,0);

    BT_Edit->setText("Edit");
    BT_DoFlip->setText("Add column");
    BT_Edit->setObjectName("BT_Edit");
    BT_DoFlip->setObjectName("BT_AddColumn");
    QObject::connect(BT_Edit, SIGNAL(clicked()), this, SLOT(on_BT_Edit_clicked()));
    QObject::connect(BT_DoFlip, SIGNAL(clicked()), this, SLOT(on_BT_DoFlip_clicked()));

    tableViewMain->setModel(model);
    tableViewMain->setFont(font);
    tableViewMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableViewMain->setMinimumSize(QSize(800, 500));
    tableViewMain->resizeColumnsToContents();
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

    {
        NewColumnNameInputWindow = new QWidget;
        QGridLayout *NewColumnNameInputWin = new QGridLayout;
        BT_AddColumn_OK = new QPushButton(NewColumnNameInputWindow);
        LE_ColumnName = new QLineEdit(NewColumnNameInputWindow);
        QFont font;
        font.setPointSize(10);

        NewColumnNameInputWindow->setLayout(NewColumnNameInputWin);
        NewColumnNameInputWindow->setMinimumSize(200,100);
        NewColumnNameInputWindow->setMaximumSize(200,100);

        NewColumnNameInputWin->addWidget(LE_ColumnName,0,0);
        NewColumnNameInputWin->addWidget(BT_AddColumn_OK,1,0,1,1);

        LE_ColumnName->setPlaceholderText("column name");
        //LE_Text->setFont(font);

        BT_AddColumn_OK->setText("OK");
        BT_AddColumn_OK->setObjectName("BT_AddColumn_OK");
        BT_AddColumn_OK->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        connect(BT_AddColumn_OK, SIGNAL(clicked()), this, SLOT(on_BT_AddColumn_OK_clicked()));

        NewColumnNameInputWindow->show();
    }//New Column Name Input window
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
        workWindow->show();
    }
    else
    {
        {
        qDebug() << "not nice";
        wrongLogPassWindow = new QWidget;
        wrongLogPassWindow->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::Dialog);
        QGridLayout *gridLayoutWrongLogPassWin = new QGridLayout;
        BT_OK = new QPushButton(wrongLogPassWindow);
        QLineEdit *LE_Text = new QLineEdit(wrongLogPassWindow);
        QFont font;
        font.setPointSize(10);

        wrongLogPassWindow->setLayout(gridLayoutWrongLogPassWin);
        wrongLogPassWindow->setStyleSheet("QLineEdit { background-color: gray }");
        wrongLogPassWindow->setMinimumSize(200,100);
        wrongLogPassWindow->setMaximumSize(200,100);

        gridLayoutWrongLogPassWin->addWidget(LE_Text,0,0);
        gridLayoutWrongLogPassWin->addWidget(BT_OK,1,0,1,1);

        LE_Text->setReadOnly(true);
        LE_Text->setText("Wrong login or password");
        LE_Text->setFont(font);

        BT_OK->setText("OK");
        BT_OK->setObjectName("BT_OK");
        BT_OK->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        connect(BT_OK, SIGNAL(clicked()), this, SLOT(on_BT_OK_clicked()));

        wrongLogPassWindow->show();
        }//wrong login password window

    }
}

void MainWindow::on_BT_OK_clicked()
{
    wrongLogPassWindow->close();
}

void MainWindow::on_BT_AddColumn_OK_clicked()
{
    columnName=LE_ColumnName->text();
    model->setItem(0, numOfColumn-1, new QStandardItem(" "));
    NewColumnNameInputWindow->close();

    QString filename="D:\\QT\\Projects\\DartEvilBest\\DartEvil-version-2\\forTableView";
    QFile fileOld(filename);
    fileOld.open(QIODevice::ReadWrite);
    QTextStream streamIn(&fileOld);
    while (!streamIn.atEnd())
    {
        QString list = streamIn.readAll();
        fileOld.resize(0);
        QTextStream stream(&fileOld);
        stream<<list<<"+"<<columnName<<"\n";
    }
    fileOld.close();

    filename="D:\\QT\\Projects\\DartEvilBest\\DartEvil-version-2\\forTableView";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QString temp=NULL;
    int numOfLines=0;
    QTextStream in(&file);
    while(!in.atEnd())
    {
        in.readLine();
        numOfLines++;
    }
    file.close();
    //qDebug()<<numOfLines;

    file.open(QIODevice::ReadOnly);
    QTextStream mn(&file);
    QString tempNameOfColumn = NULL;
    numOfColumn=0;
    for(int i=0,j=0,d=0; i<numOfLines;i++)
    {
        temp = mn.readLine();
        //qDebug() << temp;
        d++;


        if(temp.at(0) == '+')
        {
            j++;
            d=0;
            for(int m=0;m<temp.size();m++)
            {
                if(temp.at(0)==temp[m])
                {
                    //qDebug()<<"AA";
                }
                else{tempNameOfColumn+=temp[m];}

            }
            model->setHeaderData(numOfColumn, Qt::Horizontal, tempNameOfColumn);
            numOfColumn++;
            qDebug()<<numOfColumn;
            tempNameOfColumn=NULL;
        }
        for(QString x : ArrForTableView)
        {
            if(temp.at(0) == x)
            {
                temp.removeAt(0);
                model->setItem(d-1, j-1, new QStandardItem(temp));
            }
        }
    }

    file.close();
}
