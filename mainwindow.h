#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QTableView>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget *wrongLogPassWindow;
    QWidget *NewColumnNameInputWindow;
    QWidget *workWindow;
    bool check = false;
    std::list<QString> ArrForTableView{"!","@","#","$","%","^","&","*","(",")","_"};
    int numOfColumn=0;
    QString login;
    QString password;
    QString RightLogin = "asd";
    QString RightPassword = "asd";
    QString columnName=NULL;
    QString tempShit=NULL;

private slots:
    void on_BT_AcceptLogPass_clicked();
    void on_BT_Edit_clicked();
    void on_BT_DoFlip_clicked();
    void on_BT_OK_clicked();
    void on_BT_AddColumn_OK_clicked();

private:
    Ui::MainWindow *ui;

    QStandardItemModel *model;
    QTableView *tableViewMain;
    QPushButton *BT_Edit;
    QPushButton *BT_DoFlip;
    QPushButton *BT_OK;
    QPushButton *BT_AddColumn_OK;
    QLineEdit *LE_ColumnName;
};
#endif // MAINWINDOW_H
