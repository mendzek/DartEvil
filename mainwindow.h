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
    bool check = true;
    QString login;
    QString password;
    QString RightLogin = "asd";
    QString RightPassword = "asd";

private slots:
    void on_BT_AcceptLogPass_clicked();
    void on_BT_Edit_clicked();
    void on_BT_DoFlip_clicked();
    //void on_BT_OK_clicked();

private:
    Ui::MainWindow *ui;
    /*QPushButton *BT_Login;
    QPushButton *BT_Password;
    QTextEdit *TE_Login;
    QTextEdit *TE_LoginHint;
    QTextEdit *TE_Password;
    QTextEdit *TE_PasswordHint;*/

    QStandardItemModel *model;
    QTableView *tableViewMain;
    QPushButton *BT_Edit;
    QPushButton *BT_DoFlip;
};
#endif // MAINWINDOW_H
