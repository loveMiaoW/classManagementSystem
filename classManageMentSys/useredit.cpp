#include "useredit.h"
#include "ui_useredit.h"
#include <QMouseEvent>//用到QMouseEvent就要包含这个头文件
#include <QButtonGroup>
UserEdit::UserEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserEdit)
{
    ui->setupUi(this);

}

UserEdit::~UserEdit()
{
    delete ui;
}


//···鼠标按下操作···
static QPoint last(0,0);//保存一个坐标
const int TITLE_HEIGHT = 30;//保存标题高度，也就是鼠标点击区域高度
void UserEdit::mousePressEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)//如果点击了标题范围
    {
        last = event->globalPos();//坐标存储为全局坐标，即桌面屏幕坐标

    }
}

//···鼠标移动操作···
//实时修改窗口的坐标
void UserEdit::mouseMoveEvent(QMouseEvent *event)
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
void UserEdit::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)//选中标题栏
    {
        int dx = event->globalX() - last.x();//得到鼠标移动后的全局坐标X减去移动前的全局坐标X，得到移动距离dx
        int dy = event->globalY() - last.y();//得到鼠标移动后的全局坐标X减去移动前的全局坐标y，得到移动距离dy
        this->move(this->x()+dx,this->y()+dy);//设置窗口以当前坐标为基准移动dx和dy距离到新的位置
    }
}


void UserEdit::addWinInit()
{
    setWindowIcon(QIcon(":/res/engineer.png"));//设置软件图标
    setWindowTitle(tr("添加用户"));//设置软件标题
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setFixedSize(470,360);//设置窗口为固定大小

    ui->TitleLab->setGeometry(0,0,470,30);//设置标题区域位置和大小
    ui->TitleLab->setStyleSheet("QLabel{background-color:rgb(53,65,89);border-top-left-radius:8px;border-top-right-radius:8px;}");//设置标题区域颜色

    ui->InerLab->setGeometry(0,30,470,360);//设置标题区域大小
    ui->InerLab->setStyleSheet("QLabel{background-color:rgb(255,255,255);}");//设置标题区域颜色

    ui->UserLab->setGeometry(50,80,80,30);
    ui->UserLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->UserLab->setText(tr("编号："));
    ui->AccountLab->setGeometry(50,140,80,30);
    ui->AccountLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->AccountLab->setText(tr("账户类型："));
    ui->PasswordLab->setGeometry(5000,140,80,30);
    ui->PasswordLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->PasswordLab->setText(tr("原始密码："));
    ui->NewPassLab->setGeometry(50,200,80,30);
    ui->NewPassLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->NewPassLab->setText(tr("新密码："));
    ui->SurePassLab->setGeometry(50,240,80,30);
    ui->SurePassLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->SurePassLab->setText(tr("确认密码："));
    ui->label->setGeometry(10,0,80,30);
    ui->label->setText(tr("添加用户"));

    ui->UserLineEdit->setGeometry(130,80,250,30);
    ui->ManRBtn->setGeometry(130,140,90,30);
    ui->NorRBtn->setGeometry(230,140,90,30);
    ui->stuRBtn->setGeometry(330,140,90,30);
    ui->PasswordEdit->setGeometry(5000,160,250,30);
    ui->NewPassEdit->setGeometry(130,200,250,30);
    ui->SurePassEdit->setGeometry(130,240,250,30);
    ui->SaveBtn->setGeometry(370,310,75,30);
    ui->CancleBtn->setGeometry(290,310,75,30);
    ui->CloseBtn->setGeometry(432,0,30,30);
    ui->CloseBtn->setIcon(QIcon(":/res/close2.png"));
    ui->CloseBtn->setToolTip(tr("关闭"));

    connect(ui->CloseBtn,&QPushButton::clicked,this,&UserEdit::close);//这个牛逼

    ui->PasswordEdit->setEchoMode(QLineEdit::Password);//设置输入时不显示文字，显示特殊字符
    ui->NewPassEdit->setEchoMode(QLineEdit::Password);
    ui->SurePassEdit->setEchoMode(QLineEdit::Password);//设置输入时不显示文字，显示特殊字符
    ui->ManRBtn->setEnabled(true);
    ui->NorRBtn->setEnabled(true);
    ui->UserLineEdit->setEnabled(true);
    ui->ManRBtn->setFocusPolicy(Qt::NoFocus);
    ui->NorRBtn->setFocusPolicy(Qt::NoFocus);
    ui->label->setFocusPolicy(Qt::NoFocus);
    ui->TitleLab->setFocusPolicy(Qt::NoFocus);
    ui->InerLab->setFocusPolicy(Qt::NoFocus);
    ui->CloseBtn->setFocusPolicy(Qt::NoFocus);
    ui->SaveBtn->setFocusPolicy(Qt::NoFocus);
    ui->CancleBtn->setFocusPolicy(Qt::NoFocus);
    ui->NewPassLab->setFocusPolicy(Qt::NoFocus);



    this->setStyleSheet("QLabel{font-family:'Microsoft YaHei';font-size:15px;}"
                        "QLabel#label{color:white;}"
                        "QRadioButton{font-family:'Microsoft YaHei';font-size:15px;}"
                        "QRadioButton:indicator{width:15px;height:15px;}"
                        "QRadioButton:indicator:unchecked{image: url(:/res/unchecked.png);}"
                        "QRadioButton:indicator:checked{image: url(:/res/checked.png);}"
                        "QPushButton:hover#CloseBtn{background-color:rgb(233,66,66);}"
                        "QLineEdit{border:none;border-radius:0px;padding:2px 4px;"
                        "selection-background-color: blue;background-color:rgb(244,245,247);"
                        "font-family:'Microsoft YaHei';font-size:15px;}"
                        "QPushButton#CancleBtn{color:black;}"
                        "QPushButton:hover#CancleBtn{background-color:rgb(233,66,66);color:white;}"
                        "QPushButton#SaveBtn{background-color:rgb(76,136,255);}"
                        "QPushButton:pressed#SaveBtn{background-color:rgb(53,95,179);}");
    ui->stuRBtn->setEnabled(true);
    ui->ManRBtn->setEnabled(true);
    ui->NorRBtn->setEnabled(true);
    ui->stuRBtn->setChecked(1);

    //信号与槽
    connect(ui->SaveBtn,SIGNAL(clicked(bool)),this,SLOT(SaveBtnC()));
    QButtonGroup *group = new QButtonGroup(this);
    group->addButton(ui->ManRBtn,0);
    group->addButton(ui->NorRBtn,1);
    group->addButton(ui->stuRBtn,2);
}

void UserEdit::editWinInit()
{
    setWindowIcon(QIcon(":/res/engineer.png"));//设置软件图标
    setWindowTitle(tr("编辑用户"));//设置软件标题
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setFixedSize(470,360);//设置窗口为固定大小

    ui->TitleLab->setGeometry(0,0,470,30);//设置标题区域位置和大小
    ui->TitleLab->setStyleSheet("QLabel{background-color:rgb(53,65,89);border-top-left-radius:8px;border-top-right-radius:8px;}");//设置标题区域颜色

    ui->InerLab->setGeometry(0,30,470,360);//设置标题区域大小
    ui->InerLab->setStyleSheet("QLabel{background-color:rgb(255,255,255);}");//设置标题区域颜色

    ui->UserLab->setGeometry(50,80,80,30);
    ui->UserLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->UserLab->setText(tr("编号："));
    ui->AccountLab->setGeometry(50,120,80,30);
    ui->AccountLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->AccountLab->setText(tr("账户类型："));
    ui->PasswordLab->setGeometry(50,160,80,30);
    ui->PasswordLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->PasswordLab->setText(tr("原始密码："));
    ui->NewPassLab->setGeometry(50,200,80,30);
    ui->NewPassLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->NewPassLab->setText(tr("新密码："));
    ui->SurePassLab->setGeometry(50,240,80,30);
    ui->SurePassLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ui->SurePassLab->setText(tr("确认新密码："));
    ui->label->setGeometry(10,0,80,30);
    ui->label->setText(tr("修改密码"));

    ui->UserLineEdit->setGeometry(130,80,250,30);
    ui->ManRBtn->setGeometry(130,120,90,30);
    ui->NorRBtn->setGeometry(230,120,90,30);
    ui->stuRBtn->setGeometry(330,120,90,30);
    ui->PasswordEdit->setGeometry(130,160,250,30);
    ui->NewPassEdit->setGeometry(130,200,250,30);
    ui->SurePassEdit->setGeometry(130,240,250,30);
    ui->SaveBtn->setGeometry(370,310,75,30);
    ui->CancleBtn->setGeometry(290,310,75,30);
    ui->CloseBtn->setGeometry(432,0,30,30);
    ui->CloseBtn->setIcon(QIcon(":/res/close2.png"));
    ui->CloseBtn->setToolTip(tr("关闭"));

    connect(ui->CloseBtn,&QPushButton::clicked,this,&UserEdit::close);//这个牛逼

    ui->PasswordEdit->setEchoMode(QLineEdit::Password);//设置输入时不显示文字，显示特殊字符
    ui->NewPassEdit->setEchoMode(QLineEdit::Password);
    ui->SurePassEdit->setEchoMode(QLineEdit::Password);//设置输入时不显示文字，显示特殊字符
    ui->ManRBtn->setEnabled(true);
    ui->NorRBtn->setEnabled(true);
    ui->UserLineEdit->setEnabled(true);
    ui->ManRBtn->setFocusPolicy(Qt::NoFocus);
    ui->NorRBtn->setFocusPolicy(Qt::NoFocus);
    ui->label->setFocusPolicy(Qt::NoFocus);
    ui->TitleLab->setFocusPolicy(Qt::NoFocus);
    ui->InerLab->setFocusPolicy(Qt::NoFocus);
    ui->CloseBtn->setFocusPolicy(Qt::NoFocus);
    ui->SaveBtn->setFocusPolicy(Qt::NoFocus);
    ui->CancleBtn->setFocusPolicy(Qt::NoFocus);
    ui->NewPassLab->setFocusPolicy(Qt::NoFocus);



    this->setStyleSheet("QLabel{font-family:'Microsoft YaHei';font-size:15px;}"
                        "QLabel#label{color:white;}"
                        "QRadioButton{font-family:'Microsoft YaHei';font-size:15px;}"
                        "QRadioButton:indicator{width:15px;height:15px;}"
                        "QRadioButton:indicator:unchecked{image: url(:/res/unchecked.png);}"
                        "QRadioButton:indicator:checked{image: url(:/res/checked.png);}"
                        "QPushButton:hover#CloseBtn{background-color:rgb(233,66,66);}"
                        "QLineEdit{border:none;border-radius:0px;padding:2px 4px;"
                        "selection-background-color: blue;background-color:rgb(244,245,247);"
                        "font-family:'Microsoft YaHei';font-size:15px;}"
                        "QPushButton#CancleBtn{color:black;}"
                        "QPushButton:hover#CancleBtn{background-color:rgb(233,66,66);color:white;}"
                        "QPushButton#SaveBtn{background-color:rgb(76,136,255);}"
                        "QPushButton:pressed#SaveBtn{background-color:rgb(53,95,179);}");
    ui->stuRBtn->setEnabled(true);
    ui->ManRBtn->setEnabled(true);
    ui->NorRBtn->setEnabled(true);
    ui->stuRBtn->setChecked(1);

    //信号与槽
    connect(ui->SaveBtn,SIGNAL(clicked(bool)),this,SLOT(SaveBtnC()));
    QButtonGroup *group = new QButtonGroup(this);
    group->addButton(ui->ManRBtn,0);
    group->addButton(ui->NorRBtn,1);
    group->addButton(ui->stuRBtn,2);
}
void UserEdit::SaveBtnC()
{

    this->hide();
}

void UserEdit::on_CancleBtn_clicked()
{
    this->hide();
}
