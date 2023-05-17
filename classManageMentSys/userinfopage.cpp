#include "userinfopage.h"
#include "ui_userinfopage.h"

UserInfoPage::UserInfoPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfoPage)
{
    ui->setupUi(this);
    //this->setFixedSize(180,700);
    ui->label->setGeometry(0,0,180,700);
    ui->label->setStyleSheet("QLabel{background-color:rgb(61,75,102);}");

//    ui->UserEditBtn->setCheckable(true);
//    ui->UserChangeBtn->setCheckable(true);
//    ui->UserEditBtn->setAutoExclusive(true);
//    ui->UserChangeBtn->setAutoExclusive(true);

    ui->UserEditBtn->setGeometry(20,10,140,40);
    ui->UserChangeBtn->setGeometry(20,55,140,40);
    ui->UserEditBtn->setText(tr("编辑用户"));
    ui->UserChangeBtn->setText(tr("切换用户"));

//    connect(ui->UserEditBtn,SIGNAL(clicked(bool)),this,SLOT(userEditC()));
//    connect(ui->UserChangeBtn,SIGNAL(clicked(bool)),this,SLOT(UserChangeC()));

//    ui->UserEditBtn->setEnabled(false);
}

UserInfoPage::~UserInfoPage()
{
    delete ui;
}

