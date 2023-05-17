#ifndef DATABASELOGIN_H
#define DATABASELOGIN_H

#include <QWidget>

namespace Ui {
class DatabaseLogin;
}

class DatabaseLogin : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseLogin(QWidget *parent = nullptr);
    ~DatabaseLogin();


private:
    void mousePressEvent(QMouseEvent* event);//鼠标按下事件
    void mouseMoveEvent(QMouseEvent* event);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent* event);//是鼠标释放事件

signals:
    void sendLoginSuccessStu();
    void sendLoginSuccessTea();
    void sendLoginSuccessAdm();
    void sendStu();
    void sendTea();
    void sendAdm();
private slots:
    void windowClosed();//关闭窗口的槽声明
    void windowMin();//最小化窗口的槽声明
    void LoginBtnC();
    void ClearEdit();


    void on_adm_toggled(bool checked);

    void on_stu_toggled(bool checked);

    void on_tea_toggled(bool checked);

private:
    Ui::DatabaseLogin *ui;
};

#endif // DATABASELOGIN_H
