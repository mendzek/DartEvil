ifndef WINDOWLOGINPASSWORD_H
#define WINDOWLOGINPASSWORD_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class windowLoginPassword : public QWidget
{
    Q_OBJECT
public:
    explicit windowLoginPassword(QWidget *parent = nullptr);
    ~windowLoginPassword();
};

#endif // WINDOWLOGINPASSWORD_H
