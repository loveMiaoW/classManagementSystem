#ifndef USERADD_H
#define USERADD_H

#include <QMainWindow>

namespace Ui {
class userAdd;
}

class userAdd : public QMainWindow
{
    Q_OBJECT

public:
    explicit userAdd(QWidget *parent = nullptr);
    ~userAdd();
    void mousePressEvent(QMouseEvent* event);//鼠标按下事件
    void mouseMoveEvent(QMouseEvent* event);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent* event);//是鼠标释放事件
private slots:
    void SaveBtnC();

    void on_CancleBtn_clicked();
private:
    Ui::userAdd *ui;
};

#endif // USERADD_H
