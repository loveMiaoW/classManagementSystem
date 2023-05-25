#include "formuser.h"
#include "ui_formuser.h"
#include "mainwindow.h"
#include "formuser.h"
#include <QDebug>
FormUser::FormUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUser)
{
    ui->setupUi(this);



}

FormUser::~FormUser()
{
    delete ui;
}
void FormUser::shenHeInfoInit()
{
    ui->label->setGeometry(0,0,180,2000);
    ui->label->setStyleSheet("QLabel{background-color:rgb(61,75,102);}");

    ui->btnUserInfo->setCheckable(true);
    ui->btnUserEdit->setCheckable(true);
    ui->btnUserInfo->setAutoExclusive(true);
    ui->btnUserEdit->setAutoExclusive(true);

    ui->btnUserInfo->setGeometry(20,10,140,40);
    ui->btnUserEdit->setGeometry(20,55,140,40);
    ui->btnUserInfo->setText(tr("未审核"));
    ui->btnUserEdit->setText(tr("已审核"));

    connect(ui->btnUserInfo,SIGNAL(clicked(bool)),this,SLOT(userInfo()));
    connect(ui->btnUserEdit,SIGNAL(clicked(bool)),this,SLOT(userInfoEdit()));

    ui->btnUserInfo->setEnabled(true);
}

void FormUser::userInfoInit()
{

    ui->label->setGeometry(0,0,180,2000);
    ui->label->setStyleSheet("QLabel{background-color:rgb(61,75,102);}");

    ui->btnUserInfo->setCheckable(true);
    ui->btnUserEdit->setCheckable(true);
    ui->btnUserInfo->setAutoExclusive(true);
    ui->btnUserEdit->setAutoExclusive(true);

    ui->btnUserInfo->setGeometry(20,10,140,40);
    ui->btnUserEdit->setGeometry(20,55,140,40);
    ui->btnUserInfo->setText(tr("个人信息"));
    ui->btnUserEdit->setText(tr("切换用户"));

    connect(ui->btnUserInfo,SIGNAL(clicked(bool)),this,SLOT(userInfo()));
    connect(ui->btnUserEdit,SIGNAL(clicked(bool)),this,SLOT(userInfoEdit()));

    ui->btnUserInfo->setEnabled(true);

}

void FormUser::userInfo()
{
    MainWindow::Mark = 0;
    AdmWin::Mark = 0;
    MainWindow::Table = "select * from student;";
    qDebug() << "现在是formUser页面 qPushButton被点击 弹出了一个showUserInfo信号" << endl;
    emit showUserInfo();
}

void FormUser::userInfoEdit()
{
    MainWindow::Mark = 1;
    AdmWin::Mark = 1;
    emit editUserInfo();
}

void FormUser::userClassInit()
{
    ui->label->setGeometry(0,0,180,2000);
    ui->label->setStyleSheet("QLabel{background-color:rgb(61,75,102);}");

    ui->btnUserInfo->setCheckable(true);
    ui->btnUserEdit->setCheckable(true);
    ui->btnUserInfo->setAutoExclusive(true);
    ui->btnUserEdit->setAutoExclusive(true);

    ui->btnUserInfo->setGeometry(20,10,140,40);
    ui->btnUserEdit->setGeometry(20,55,140,40);
    ui->btnUserInfo->setText(tr("必修课"));
    ui->btnUserEdit->setText(tr("选修课"));

    //connect(ui->btnUserInfo,SIGNAL(clicked(bool)),this,SLOT(userInfo()));
    //connect(ui->btnUserEdit,SIGNAL(clicked(bool)),this,SLOT(userInfoEdit()));

    ui->btnUserInfo->setEnabled(true);
}

void FormUser::applyInfoInit()
{
    ui->label->setGeometry(0,0,180,2000);
    ui->label->setStyleSheet("QLabel{background-color:rgb(61,75,102);}");

    ui->btnUserInfo->setCheckable(true);
    ui->btnUserEdit->setCheckable(true);
    ui->btnUserInfo->setAutoExclusive(true);
    ui->btnUserEdit->setAutoExclusive(true);

    ui->btnUserInfo->setGeometry(20,10,140,40);
    ui->btnUserEdit->setGeometry(20,55,140,40);
    ui->btnUserInfo->setText(tr("申请使用"));
    ui->btnUserEdit->setText(tr("查看状态"));

    connect(ui->btnUserInfo,SIGNAL(clicked(bool)),this,SLOT(userInfo()));
    connect(ui->btnUserEdit,SIGNAL(clicked(bool)),this,SLOT(userInfoEdit()));

    ui->btnUserInfo->setEnabled(true);
}

void FormUser::userCaoZuoInit()
{
    ui->label->setGeometry(0,0,180,2000);
    ui->label->setStyleSheet("QLabel{background-color:rgb(61,75,102);}");

    ui->btnUserInfo->setCheckable(true);
    ui->btnUserEdit->setCheckable(true);
    ui->btnUserInfo->setAutoExclusive(true);
    ui->btnUserEdit->setAutoExclusive(true);

    ui->btnUserInfo->setGeometry(20,10,140,40);
    ui->btnUserEdit->setGeometry(20,55,140,40);
    ui->btnUserInfo->setText(tr("登陆"));
    ui->btnUserEdit->setText(tr("登出"));

    //connect(ui->btnUserInfo,SIGNAL(clicked(bool)),this,SLOT(userInfo()));
    //connect(ui->btnUserEdit,SIGNAL(clicked(bool)),this,SLOT(userInfoEdit()));

    ui->btnUserInfo->setEnabled(true);
}
//void FormUser::change()
//{
//    if(MainWindow::userType == true){
//        ui->btnUserInfo->setEnabled(true);
//    }else{
//        ui->btnUserInfo->setEnabled(false);
//    }

//}
