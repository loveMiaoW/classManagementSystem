#ifndef USERCHAN_H
#define USERCHAN_H

#include <QWidget>

namespace Ui {
class UserChan;
}

class UserChan : public QWidget
{
    Q_OBJECT

public:
    explicit UserChan(QWidget *parent = nullptr);
    ~UserChan();
    void UserChanInit();
    void shenHeUser();
    void setEditText(QString &str1,QString &str2);
    //void UserChanInit();
    static QString str1;
    static QString str2;
private:
    void mousePressEvent(QMouseEvent* event);//鼠标按下事件
    void mouseMoveEvent(QMouseEvent* event);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent* event);//是鼠标释放事件

signals:


private slots:
    void SaveBtnC();
    void Warn();
    void Correct();
    void CloseBtnC();
    void func();
    void on_CancleBtn_clicked();

private:
    Ui::UserChan *ui;
};

#endif // USERCHAN_H
