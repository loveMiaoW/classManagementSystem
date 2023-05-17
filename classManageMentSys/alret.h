#ifndef ALRET_H
#define ALRET_H

#include <QMainWindow>
#include <QMouseEvent>
namespace Ui {
class alret;
}

class alret : public QMainWindow
{
    Q_OBJECT

public:
    explicit alret(QWidget *parent = nullptr);
    ~alret();
    void mousePressEvent(QMouseEvent* event);//鼠标按下事件
    void mouseMoveEvent(QMouseEvent* event);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent* event);//是鼠标释放事件
private slots:
    void windowClosed();//关闭窗口的槽声明
private:
    Ui::alret *ui;
};

#endif // ALRET_H
