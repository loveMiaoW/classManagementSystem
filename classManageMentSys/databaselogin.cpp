#include "databaselogin.h"
#include "ui_databaselogin.h"
#include "mainwindow.h"
#include <QDebug>
#include <QMouseEvent>//用到QMouseEvent就要包含这个头文件
#include <QButtonGroup>
DatabaseLogin::DatabaseLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatabaseLogin)
{
    ui->setupUi(this);//ui文件生成的类的构造函数，这个函数的作用是对界面进行初始化

    setWindowIcon(QIcon(":/res/engineer.png"));//设置软件图标
    setWindowTitle(tr("教室管理软件登录"));//设置软件标题
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    this->setFixedSize(300,400);//设置窗口为固定大小

    ui->labelTitle->setGeometry(0,0,300,30);//设置标题区域位置和大小
    ui->labelTitle->setStyleSheet("background-color:rgb(66,65,60)");//设置标题区域颜色

    ui->labelLogin->setGeometry(0,30,300,370);//设置标题区域大小
    ui->labelLogin->setStyleSheet("background-color:rgb(0,135,234)");//设置标题区域颜色


    ui->closeButton->setGeometry(300-30,0,30,30);//设置按钮位置和大小
    ui->closeButton->setToolTip(tr("关闭"));//设置鼠标放上去后的文字提示
    QIcon close_icon(":/res/close.png");//设置按钮图标所在位置
    ui->closeButton->setIcon(close_icon);//添加按钮图标
    ui->closeButton->setFlat(true);//设置按钮背景透明
    connect(ui->closeButton,SIGNAL(clicked()),this,SLOT(windowClosed()));//连接按钮信号与槽，使点击后关闭窗口
    ui->closeButton->setStyleSheet("QPushButton:hover{border-image:url(:/res/red1.png);}");
    //设置鼠标滑过颜色变化


    ui->minButton->setGeometry(300-60,0,30,30);//设置按钮位置和大小
    ui->minButton->setToolTip(tr("最小化"));//设置鼠标放上去后的文字提示
    QIcon min_icon(":/res/min.png");//设置按钮图标所在位置
    ui->minButton->setIcon(min_icon);//添加按钮图标
    ui->minButton->setFlat(true);//设置按钮背景透明
    connect(ui->minButton,SIGNAL(clicked()),this,SLOT(windowMin()));//连接信号与槽，使点击后最小化窗口
    ui->minButton->setStyleSheet("QPushButton:hover{border-image:url(:/res/title_h.png);}");
    //设置鼠标滑过颜色变化



    ui->ico_label->setGeometry(100,50,100,100);//设置标签位置大小
    QString path = ":/res/mysql.png";//设置图标标签所在位置
    QImage img(path);//声明图片变量并保存图标标签
    img = img.scaled(100,100);//调整图标大小以适应标签
    ui->ico_label->setPixmap(QPixmap::fromImage(img));//在标签上显示图标

    ui->usernameEdit->setPlaceholderText("登录用户");//设置提醒文字，在输入时会自动消失
    ui->passwordEdit->setPlaceholderText("登录密码");



    ui->usernameEdit->setMaxLength(12);//限制输入最大字符数
    ui->passwordEdit->setMaxLength(12);



    ui->usernameEdit->setEchoMode(QLineEdit::Normal);//设置输入时正常显示输入文字
    ui->passwordEdit->setEchoMode(QLineEdit::Password);//设置输入时不显示文字，显示特殊字符



    ui->usernameEdit->setGeometry(50,200,200,30);//设置每个lineedit的位置和大小
    ui->passwordEdit->setGeometry(50,240,200,30);

    ui->Warnning->setGeometry(50,265,200,30);
    ui->Warnning->setStyleSheet("font-family:'Microsoft YaHei';font-size:14px;color:red;");
    ui->Warnning->setText(tr("用户名或密码错误！"));
    ui->Warnning->hide();

    //设置lineedit的边框样式
    ui->usernameEdit->setStyleSheet("border:2px groove gray;border-radius:15px;padding:2px 4px;\
                                selection-background-color: blue;");
    ui->passwordEdit->setStyleSheet("border:2px groove gray;border-radius:15px;padding:2px 4px;\
                                selection-background-color: blue;");


    ui->loginBtn->setGeometry(100,340,100,40);//设置按钮的位置和大小
    ui->loginBtn->setText(tr("登录"));//设置按钮上的文字
    //设置按钮的文字样式，特殊样式等
    ui->loginBtn->setStyleSheet("QPushButton{font-family:'Microsoft YaHei';font-size:18px;}"
                            "QPushButton{background-color:rgba(0,91,156,100%);\
                            color:white;border-radius:20px;border:2px groove gray;border-style:outset;}"
                            "QPushButton:hover{background-color:white;color:black;}"
                            "QPushButton:pressed{background-color:rgb(85,170,255);border-style:inset;}");

    setTabOrder(ui->usernameEdit,ui->passwordEdit);//设置tab键顺序，设置程序一开始焦点就在用户名输入框处

    ui->loginBtn->setFocusPolicy(Qt::NoFocus);//设置只有输入框能够获得焦点，其余失去焦点
    ui->ico_label->setFocusPolicy(Qt::NoFocus);
    ui->minButton->setFocusPolicy(Qt::NoFocus);
    ui->labelLogin->setFocusPolicy(Qt::NoFocus);
    ui->labelTitle->setFocusPolicy(Qt::NoFocus);
    ui->closeButton->setFocusPolicy(Qt::NoFocus);

    ui->stu->setChecked(1);
    QButtonGroup *group = new QButtonGroup(this);
    group->addButton(ui->adm,0);
    group->addButton(ui->tea,1);
    group->addButton(ui->stu,2);

    ui->adm->setGeometry(40,300,100,15);
    ui->stu->setGeometry(120,300,100,15);
    ui->tea->setGeometry(200,300,100,15);
/*相关信号与槽设置*/
    connect(ui->loginBtn,SIGNAL(clicked(bool)),this,SLOT(LoginBtnC()));



}


DatabaseLogin::~DatabaseLogin()
{
    delete ui;
}


//···鼠标按下操作···
static QPoint last(0,0);//保存一个坐标
const int TITLE_HEIGHT = 30;//保存标题高度，也就是鼠标点击区域高度
void DatabaseLogin::mousePressEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)//如果点击了标题范围
    {
        last = event->globalPos();//坐标存储为全局坐标，即桌面屏幕坐标

    }
}

//···鼠标移动操作···
//实时修改窗口的坐标
void DatabaseLogin::mouseMoveEvent(QMouseEvent *event)
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
void DatabaseLogin::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)//选中标题栏
    {
        int dx = event->globalX() - last.x();//得到鼠标移动后的全局坐标X减去移动前的全局坐标X，得到移动距离dx
        int dy = event->globalY() - last.y();//得到鼠标移动后的全局坐标X减去移动前的全局坐标y，得到移动距离dy
        this->move(this->x()+dx,this->y()+dy);//设置窗口以当前坐标为基准移动dx和dy距离到新的位置
    }
}


void DatabaseLogin::windowClosed()//关闭窗口的槽实现
{
    this->close();
}

void DatabaseLogin::windowMin()//最小化窗口的槽实现
{
    this->showMinimized();

}

void DatabaseLogin::LoginBtnC()
{

    MainWindow::UserInfo<<ui->usernameEdit->text()<<ui->passwordEdit->text();
    //emit sendData();
    if(ui->adm->isChecked())
    {
        emit sendLoginSuccessAdm();
        qDebug() << "login userType" << MainWindow::userType << endl;
    }
    else if(ui->stu->isChecked())
    {
        emit sendLoginSuccessStu();
        qDebug() << "login userType" << MainWindow::userType << endl;
    }
    else if(ui->tea->isChecked())
    {
        emit sendLoginSuccessTea();
    }
}

void DatabaseLogin::ClearEdit()
{
    ui->usernameEdit->clear();
    ui->passwordEdit->clear();
    MainWindow::UserInfo.clear();
    ui->usernameEdit->setFocus();
    ui->usernameEdit->setStyleSheet("border:2px groove red;border-radius:15px;padding:2px 4px;\
                                selection-background-color: blue;");
    ui->passwordEdit->setStyleSheet("border:2px groove red;border-radius:15px;padding:2px 4px;\
                                selection-background-color: blue;");
    ui->Warnning->show();
}



void DatabaseLogin::on_adm_toggled(bool checked)
{
    if(ui->adm->isChecked())
    {
        MainWindow::userType = 0;
    }
    else {
        MainWindow::userType = -1;
    }
}

void DatabaseLogin::on_stu_toggled(bool checked)
{
    if(ui->stu->isChecked())
    {
        MainWindow::userType = 1;
    }
    else {
        MainWindow::userType = -1;
    }

}

void DatabaseLogin::on_tea_toggled(bool checked)
{
    if(ui->tea->isChecked())
    {
        MainWindow::userType = 2;
    }
    else {
        MainWindow::userType = -1;
    }
}
