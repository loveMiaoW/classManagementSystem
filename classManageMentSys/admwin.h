#ifndef ADMWIN_H
#define ADMWIN_H
#include "formuser.h"
#include "formtable.h"
#include "qmysqlquerymodel.h"
#include "formexit.h"
#include "userchan.h"
#include "alret.h"
#include "useredit.h"
#include "useradd.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QDesktopWidget>
namespace Ui {
class AdmWin;
}

class AdmWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdmWin(QWidget *parent = nullptr);
    ~AdmWin();

    void mousePressEvent(QMouseEvent* event);//鼠标按下事件
    void mouseMoveEvent(QMouseEvent* event);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent* event);//是鼠标释放事件
    void mouseDoubleClickEvent(QMouseEvent *event);
    void updateNormalBtn();

    void setTitle();

private slots:
    void windowClosed();//关闭窗口的槽声明
    void windowMin();//最小化窗口的槽声明
    void windowMax();
    void showPage(const QModelIndex &index);
    void showModel();
    void newBtnFunc();
    void editUserInfo();
    void editBtnFunc();
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::AdmWin *ui;
    FormUser *UserWin;
    FormUser *shenHeWin;
    FormTable *TableWin;
    FormTable *TableStuWin;
    FormExit *ExitWin;
    FormTable *TableTeaWin;
    UserChan *ChanUser;
    UserChan *shenHe;
    alret   *alretWin;
    UserEdit *EditUser;
    QMySqlQueryModel *model;
    userAdd *useradd;
public:
    QRect clientRect;
    bool isMaxWindow;
    bool isHalfWindow;
    QString userStrInfo;
    QString userId;
    static int Mark;
    static int Flag;
};

#endif // ADMWIN_H
