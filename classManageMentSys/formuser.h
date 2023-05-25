#ifndef FORMUSER_H
#define FORMUSER_H

#include <QWidget>

namespace Ui {
class FormUser;
}

class FormUser : public QWidget
{
    Q_OBJECT

public:
    explicit FormUser(QWidget *parent = nullptr);
    ~FormUser();
    void shenHeInfoInit();
    void userInfoInit();
    void userClassInit();
    void applyInfoInit();
    void userCaoZuoInit();
private slots:
    void userInfo();
    void userInfoEdit();
signals:
    void showUserInfo();
    void editUserInfo();

private:
    Ui::FormUser *ui;
};

#endif // FORMUSER_H
