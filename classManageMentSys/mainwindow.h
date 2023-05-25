#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "databaselogin.h"

#include "formuser.h"
#include "formtable.h"
#include "qmysqlquerymodel.h"
#include "formexit.h"
#include "userchan.h"
#include "alret.h"
#include "useredit.h"
#include "admwin.h"

#include <QMainWindow>
#include <QDesktopWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mousePressEvent(QMouseEvent* event);//鼠标按下事件
    void mouseMoveEvent(QMouseEvent* event);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent* event);//是鼠标释放事件
    void mouseDoubleClickEvent(QMouseEvent *event);
    void updateNormalBtn();
signals:
    void clearData();

private slots:
    void receiveStu();
    void receiveTea();
    void receiveAdm();
    void windowClosed();//关闭窗口的槽声明
    void windowMin();//最小化窗口的槽声明
    void windowMax();
    void newBtnFunc();
    void editBtnFunc();


    void showPage(const QModelIndex &index);
    void showModel();
    void showInfo();
    void newAddWin();
    void editUserInfo();
private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QMySqlQueryModel *model;
    DatabaseLogin *LoginWin;
    FormUser *UserWin;
    FormTable *TableWin;
    FormUser *classInfo;
    FormUser *applyInfo;
    FormUser *caoZuo;
    FormExit *ExitWin;
    UserChan * ChanUser;
    alret   *alretWin;
    UserEdit *EditUser;
    UserEdit *addWin;
    AdmWin *admwin;
public:
    static QStringList UserInfo;
    bool isRun;
    QRect clientRect;
    bool isMaxWindow;
    bool isHalfWindow;
    static int Mark;
    static int index;
    static QString Table;
    static int userType;
};
#endif // MAINWINDOW_H
