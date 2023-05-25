#include "userchan.h"
#include "ui_userchan.h"
#include "mainwindow.h"
#include <QMouseEvent>//用到QMouseEvent就要包含这个头文件
#include <QDebug>
#include <QMessageBox>
UserChan::UserChan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserChan)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/res/engineer.png"));//设置软件图标


}

UserChan::~UserChan()
{
    delete ui;
}

void UserChan::shenHeUser()
{
    setWindowTitle(tr("审核"));//设置软件标题
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setFixedSize(470,240);//设置窗口为固定大小

    ui->TitleLab->setGeometry(0,0,470,30);//设置标题区域位置和大小
    ui->TitleLab->setStyleSheet("QLabel{background-color:rgb(53,65,89);border-top-left-radius:8px;border-top-right-radius:8px;}");//设置标题区域颜色

    ui->InerLab->setGeometry(0,30,470,360);//设置标题区域大小
    ui->InerLab->setStyleSheet("QLabel{background-color:rgb(255,255,255);}");//设置标题区域颜色

    ui->UserLab->setGeometry(50,80,80,30);
    ui->UserLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->UserLab->setText(tr("申请人："));

    ui->PasswordLab->setGeometry(50,140,80,30);
    ui->PasswordLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->PasswordLab->setText(tr("原因："));

    ui->label->setGeometry(10,0,80,30);
    ui->label->setText(tr("审核"));

    ui->UserEdit->setGeometry(130,80,250,30);

    ui->PasswordEdit->setGeometry(130,140,250,30);

    ui->SaveBtn->setGeometry(370,200,75,30);
    ui->CancleBtn->setGeometry(290,200,75,30);
    ui->SaveBtn->setText("不同意");
    ui->CancleBtn->setText("同意");
    ui->CloseBtn->setGeometry(432,0,30,30);
    ui->CloseBtn->setIcon(QIcon(":/res/close2.png"));
    ui->CloseBtn->setToolTip(tr("关闭"));

    connect(ui->CloseBtn,SIGNAL(clicked(bool)),this,SLOT(CloseBtnC()));//这个牛逼

    //ui->PasswordEdit->setEchoMode(QLineEdit::Password);//设置输入时不显示文字，显示特殊字符
    ui->label->setFocusPolicy(Qt::NoFocus);
    ui->TitleLab->setFocusPolicy(Qt::NoFocus);
    ui->InerLab->setFocusPolicy(Qt::NoFocus);
    ui->CloseBtn->setFocusPolicy(Qt::NoFocus);
    ui->SaveBtn->setFocusPolicy(Qt::NoFocus);
    ui->CancleBtn->setFocusPolicy(Qt::NoFocus);

    setTabOrder(ui->UserEdit,ui->PasswordEdit);

    ui->Warnning->setGeometry(130,175,200,30);
    ui->Warnning->setStyleSheet("font-family:'Microsoft YaHei';font-size:14px;color:red;");
    ui->Warnning->setText(tr("用户名或密码错误！"));
    ui->Warnning->hide();





    this->setStyleSheet("QLabel{font-family:'Microsoft YaHei';font-size:15px;}"
                        "QLabel#label{color:white;}"
                        "QRadioButton{font-family:'Microsoft YaHei';font-size:15px;}"
                        "QRadioButton:indicator{width:15px;height:15px;}"
                        "QRadioButton:indicator:unchecked{image: url(:/image/ICON/unchecked.png);}"
                        "QRadioButton:indicator:checked{image: url(:/image/ICON/checked.png);}"
                        "QPushButton:hover#CloseBtn{background-color:rgb(233,66,66);}"
                        "QLineEdit{border:none;border-radius:0px;padding:2px 4px;"
                        "selection-background-color: blue;background-color:rgb(244,245,247);"
                        "font-family:'Microsoft YaHei';font-size:15px;}"
                        "QPushButton#CancleBtn{color:black;}"
                        "QPushButton:hover#CancleBtn{background-color:rgb(233,66,66);color:white;}"
                        "QPushButton#SaveBtn{background-color:rgb(76,136,255);}"
                        "QPushButton:pressed#SaveBtn{background-color:rgb(53,95,179);}");
    //连接信号与槽
    connect(ui->SaveBtn,SIGNAL(clicked(bool)),this,SLOT(SaveBtnC()));
    connect(ui->CancleBtn,SIGNAL(clicked(bool)),this,SLOT(func()));
}

void UserChan::UserChanInit()
{
    setWindowTitle(tr("切换用户"));//设置软件标题
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setFixedSize(470,240);//设置窗口为固定大小

    ui->TitleLab->setGeometry(0,0,470,30);//设置标题区域位置和大小
    ui->TitleLab->setStyleSheet("QLabel{background-color:rgb(53,65,89);border-top-left-radius:8px;border-top-right-radius:8px;}");//设置标题区域颜色

    ui->InerLab->setGeometry(0,30,470,360);//设置标题区域大小
    ui->InerLab->setStyleSheet("QLabel{background-color:rgb(255,255,255);}");//设置标题区域颜色

    ui->UserLab->setGeometry(50,80,80,30);
    ui->UserLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->UserLab->setText(tr("用户名："));

    ui->PasswordLab->setGeometry(50,140,80,30);
    ui->PasswordLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->PasswordLab->setText(tr("密码："));

    ui->label->setGeometry(10,0,80,30);
    ui->label->setText(tr("切换用户"));

    ui->UserEdit->setGeometry(130,80,250,30);

    ui->PasswordEdit->setGeometry(130,140,250,30);

    ui->SaveBtn->setGeometry(370,200,75,30);
    ui->CancleBtn->setGeometry(290,200,75,30);
    ui->CloseBtn->setGeometry(432,0,30,30);
    ui->CloseBtn->setIcon(QIcon(":/res/close2.png"));
    ui->CloseBtn->setToolTip(tr("关闭"));

    connect(ui->CloseBtn,SIGNAL(clicked(bool)),this,SLOT(CloseBtnC()));//这个牛逼

    ui->PasswordEdit->setEchoMode(QLineEdit::Password);//设置输入时不显示文字，显示特殊字符
    ui->label->setFocusPolicy(Qt::NoFocus);
    ui->TitleLab->setFocusPolicy(Qt::NoFocus);
    ui->InerLab->setFocusPolicy(Qt::NoFocus);
    ui->CloseBtn->setFocusPolicy(Qt::NoFocus);
    ui->SaveBtn->setFocusPolicy(Qt::NoFocus);
    ui->CancleBtn->setFocusPolicy(Qt::NoFocus);

    setTabOrder(ui->UserEdit,ui->PasswordEdit);

    ui->Warnning->setGeometry(130,175,200,30);
    ui->Warnning->setStyleSheet("font-family:'Microsoft YaHei';font-size:14px;color:red;");
    ui->Warnning->setText(tr("用户名或密码错误！"));
    ui->Warnning->hide();





    this->setStyleSheet("QLabel{font-family:'Microsoft YaHei';font-size:15px;}"
                        "QLabel#label{color:white;}"
                        "QRadioButton{font-family:'Microsoft YaHei';font-size:15px;}"
                        "QRadioButton:indicator{width:15px;height:15px;}"
                        "QRadioButton:indicator:unchecked{image: url(:/image/ICON/unchecked.png);}"
                        "QRadioButton:indicator:checked{image: url(:/image/ICON/checked.png);}"
                        "QPushButton:hover#CloseBtn{background-color:rgb(233,66,66);}"
                        "QLineEdit{border:none;border-radius:0px;padding:2px 4px;"
                        "selection-background-color: blue;background-color:rgb(244,245,247);"
                        "font-family:'Microsoft YaHei';font-size:15px;}"
                        "QPushButton#CancleBtn{color:black;}"
                        "QPushButton:hover#CancleBtn{background-color:rgb(233,66,66);color:white;}"
                        "QPushButton#SaveBtn{background-color:rgb(76,136,255);}"
                        "QPushButton:pressed#SaveBtn{background-color:rgb(53,95,179);}");
    //连接信号与槽
    connect(ui->SaveBtn,SIGNAL(clicked(bool)),this,SLOT(SaveBtnC()));
}

//···鼠标按下操作···
static QPoint last(0,0);//保存一个坐标
const int TITLE_HEIGHT = 30;//保存标题高度，也就是鼠标点击区域高度
void UserChan::mousePressEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)//如果点击了标题范围
    {
        last = event->globalPos();//坐标存储为全局坐标，即桌面屏幕坐标

    }
}

//···鼠标移动操作···
//实时修改窗口的坐标
void UserChan::mouseMoveEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)//如果选中了标题范围
    {
        int dx = event->globalX() - last.x();//得到鼠标移动后的全局坐标X减去移动前的全局坐标X，得到移动距离dx
        int dy = event->globalY() - last.y();//得到鼠标移动后的全局坐标X减去移动前的全局坐标y，得到移动距离dy
        last = event->globalPos();//更新存储坐标为当前的全局坐标
        this->move(this->x()+dx,this->y()+dy);//设置窗口以当前坐标为基准移动dx和dy距离到新的位置
    }
}

//···鼠标释放操作···
void UserChan::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)//选中标题栏
    {
        int dx = event->globalX() - last.x();//得到鼠标移动后的全局坐标X减去移动前的全局坐标X，得到移动距离dx
        int dy = event->globalY() - last.y();//得到鼠标移动后的全局坐标X减去移动前的全局坐标y，得到移动距离dy
        this->move(this->x()+dx,this->y()+dy);//设置窗口以当前坐标为基准移动dx和dy距离到新的位置
    }
}

void UserChan::func()
{
    qDebug() << "ww2wwwwwwwwwww";
    QSqlQuery sql;
    //QString strSql = QString("insert into application values('%1','%2','%3','%4','%5','%6');").arg(MainWindow::UserInfo.at(0)).arg(QString("student")).arg(appTime).arg(appClass).arg(appRes).arg(0);
    //QString strSql = QString("insert into application values('%1','%2','%3','%4','%5','%6','%7');").arg(9).arg("a").arg("b").arg("c").arg("d");
    QString strSql = QString("update application set status = 1 where application_name like '%1' && application_reason like '%2';").arg(UserChan::str1).arg(UserChan::str2);
    bool sqlFlag = sql.exec(strSql);
    if(sqlFlag == false)
    {
        qDebug() << "sqlQure faile" << endl;
        qDebug() << sql.lastError();
    }
    bool ret = sql.seek(0);
    qDebug() << ret << sqlFlag ;
    if(sqlFlag == true)
    {
        //QMessageBox::critical(this,"提交申请","等待管理员审核");
        this->hide();
    }

}

void UserChan::SaveBtnC()
{
    MainWindow::UserInfo.clear();
    MainWindow::UserInfo<<ui->UserEdit->text()<<ui->PasswordEdit->text();
    //emit userChan();

}

void UserChan::Warn()
{
    ui->Warnning->show();
    ui->UserEdit->clear();
    ui->PasswordEdit->clear();

}

void UserChan::Correct()
{
    ui->UserEdit->clear();
    ui->PasswordEdit->clear();
    ui->Warnning->hide();
    this->hide();
}

void UserChan::CloseBtnC()
{
    ui->Warnning->hide();
    ui->UserEdit->clear();
    ui->PasswordEdit->clear();
    this->hide();
}

void UserChan::on_CancleBtn_clicked()
{
    ui->Warnning->hide();
    ui->UserEdit->clear();
    ui->PasswordEdit->clear();
    this->hide();

}

void UserChan::setEditText(QString &str1,QString &str2)
{
    ui->UserEdit->setText(str1);
    ui->PasswordEdit->setText(str2);
}
