#include "admwin.h"
#include "ui_admwin.h"
#include <QDesktopWidget>
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>

int AdmWin::Mark = 0;
int AdmWin::Flag = 0;
QString UserChan::str1 = "";
QString UserChan::str2 = "";
AdmWin::AdmWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdmWin)
{
    ui->setupUi(this);
    UserWin = new FormUser;
    UserWin->userInfoInit();
    shenHeWin = new FormUser;
    shenHeWin->shenHeInfoInit();
    TableWin = new FormTable;
    TableStuWin = new FormTable;
    TableTeaWin = new FormTable;
    TableWin->classInfoInit();
    TableStuWin->studentInfoInit();
    TableTeaWin->teacherInfoInit();
    ExitWin = new FormExit;

    ChanUser = new UserChan;
    shenHe = new UserChan;
    ChanUser->UserChanInit();
    shenHe->shenHeUser();
    alretWin = new alret;
    EditUser = new UserEdit;
    useradd = new userAdd;

    clientRect = QApplication::desktop()->availableGeometry();
    clientRect = QApplication::desktop()->availableGeometry(); //用户可用窗口大小【这个很强】
    setWindowIcon(QIcon(":/res/engineer.png"));//设置软件图标
    setWindowTitle(tr("教室管理软件"));//设置软件标题
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    //this->setFixedSize(1000,618);//设置窗口为固定大小
    this->setWindowState(Qt::WindowMaximized);
    this->resize(QSize(clientRect.width(),clientRect.height()));
    //qDebug() << clientRect.width() << endl;
    ui->label->setGeometry(0,0,clientRect.width(),30);//设置标题区域大小
    ui->label->setStyleSheet("background-color:rgb(28,102,220);color:rgb(255,255,255);font-family:'Microsoft YaHei';font-size:14px;");//设置标题区域颜色

    ui->winTitle->setGeometry(10,0,clientRect.width(),30);
    ui->winTitle->setStyleSheet("background-color:rgb(28,102,220);color:rgb(255,255,255);font-family:'Microsoft YaHei';font-size:14px;");

    ui->closeButton->setGeometry(clientRect.width()-30,0,30,30);//设置按钮位置和大小
    ui->closeButton->setToolTip(tr("关闭"));//设置鼠标放上去后的文字提示
    QIcon close_icon(":/res/close2.png");//设置按钮图标所在位置
    ui->closeButton->setIcon(close_icon);//添加按钮图标

    ui->closeButton->setFlat(true);//设置按钮背景透明
    connect(ui->closeButton,SIGNAL(clicked()),this,SLOT(windowClosed()));//连接按钮信号与槽，使点击后关闭窗口
   // connect(ExitWin,SIGNAL(ExitApp()),this,SLOT(windowClosed()));
    ui->closeButton->setStyleSheet("QPushButton:hover{border-image:url(:/res/red1.png);}");//设置鼠标滑过颜色变化



    ui->minButton->setGeometry(clientRect.width()-90,0,30,30);//设置按钮位置和大小
    ui->minButton->setToolTip(tr("最小化"));//设置鼠标放上去后的文字提示
    QIcon min_icon(":/res/min1.png");//设置按钮图标所在位置
    ui->minButton->setIcon(min_icon);//添加按钮图标

    ui->setButton->setGeometry(clientRect.width()-120,0,30,30);
    ui->setButton->setToolTip(tr("设置"));//设置鼠标放上去后的文字提示
    QIcon set_icon(":/res/set.png");//设置按钮图标所在位置
    ui->setButton->setIcon(set_icon);//添加按钮图标
    ui->setButton->setFlat(true);//设置按钮背景透明
    ui->setButton->setStyleSheet("QPushButton:hover{border-image:url(:/res/blue2.png);}");//设置鼠标滑过颜色变化



    ui->minButton->setFlat(true);//设置按钮背景透明
    connect(ui->minButton,SIGNAL(clicked()),this,SLOT(windowMin()));//连接信号与槽，使点击后最小化窗口
    ui->minButton->setStyleSheet("QPushButton:hover{border-image:url(:/res/blue2.png);}");//设置鼠标滑过颜色变化

    ui->maxButton->setGeometry(clientRect.width()-60,0,30,30);//设置按钮位置和大小
    ui->maxButton->setToolTip(tr("最大化"));//设置鼠标放上去后的文字提示
    QIcon max_icon(":/res/max2.png");//设置按钮图标所在位置
    ui->maxButton->setIcon(max_icon);//添加按钮图标

    ui->maxButton->setFlat(true);
    connect(ui->maxButton,SIGNAL(clicked()),this,SLOT(windowMax()));//连接信号与槽，使点击后最小化窗口
    ui->maxButton->setStyleSheet("QPushButton:hover{border-image:url(:/res/blue2.png);}");//设置鼠标滑过颜色变化


    ui->listWidget->setGeometry(0,30,180,clientRect.height());//设置listwidget的位置和大小
    ui->listWidget->setStyleSheet("QListWidget{font-family:'Microsoft YaHei';font-size:15px;}"
                                  "QListWidget{color:rgb(255,255,255); background:rgb(8,17,31);border:0px groove gray;}"
                                  "QListWidget::Item{height:50px;border:0px groove gray;padding-left:15;}"
                                  "QListWidget::Item:hover{background-color:rgb(61,75,102);color:rgb(255,255,255);border-image:url(:/image/ICON/gray.png);border:0px groove gray;}"
                                  "QListWidget::Item:selected{background-color:rgb(61,75,102);color:rgb(255,255,255);border-image:url(:/image/ICON/gray.png);border:0px groove gray;}"
                                  );//设置显示的效果，美化listwidget
    ui->listWidget->setIconSize(QSize(25,25));//设置列表图标大小
    ui->listWidget->setFocusPolicy(Qt::NoFocus);//去掉选中时的虚线框显示（去掉焦点）
    //qDebug() << "------------" << MainWindow::userType << endl;


    //qDebug() << 1 << endl;
    QListWidgetItem *add_item_1 = new QListWidgetItem(ui->listWidget);//声明实例化一个项目
    add_item_1->setText(tr("用户中心"));//给项目命名
    add_item_1->setIcon(QIcon(":/res/yonghu.png"));//给项目添加图标


    QListWidgetItem *add_item_2 = new QListWidgetItem(ui->listWidget);
    add_item_2->setIcon(QIcon(":/res/classRoom.png"));
    add_item_2->setText(tr("教室查询"));

    QListWidgetItem *add_item_3 = new QListWidgetItem(ui->listWidget);
    add_item_3->setIcon(QIcon(":/res/studentInfo.png"));
    add_item_3->setText(tr("学生信息"));
    QListWidgetItem *add_item_4 = new QListWidgetItem(ui->listWidget);
    add_item_4->setIcon(QIcon(":/res/teacherInfo.png"));
    add_item_4->setText(tr("教师信息"));

    QListWidgetItem *add_item_5 = new QListWidgetItem(ui->listWidget);
    add_item_5->setIcon(QIcon(":/res/shenHe.png"));
    add_item_5->setText(tr("审核申请"));

    QListWidgetItem *add_item_6 = new QListWidgetItem(ui->listWidget);
    add_item_6->setIcon(QIcon(":/res/tuichu.png"));
    add_item_6->setText(tr("退出系统"));



    ui->listWidget->setCurrentRow(0);

    ui->stackedWidget->setGeometry(180,30,180,clientRect.height());//设置stackedwidget的位置和大小
    ui->stackedWidget->setStyleSheet("QStackedWidget{background:rgb(255,255,255);}");//设置显示效果
    ui->stackedWidget->addWidget(UserWin);
    ui->stackedWidget->addWidget(TableWin);
    ui->stackedWidget->addWidget(TableStuWin);
    ui->stackedWidget->addWidget(TableTeaWin);
    ui->stackedWidget->addWidget(shenHeWin);
    ui->stackedWidget->addWidget(ExitWin);//添加widget到stackedwidget中成为新的页面
    ui->stackedWidget->setCurrentWidget(UserWin);//设置默认页面为显示页面
    connect(ui->listWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(showPage(QModelIndex)));
    //连接信号与槽，点击列表的某一行，列表发出信号，将本行的索引作为信号发出，改变页面的槽得到信号，获取当前行号，改变页面


    ui->SearBtn->setGeometry(clientRect.width()-406,46,70,30);
    ui->HighBtn->setGeometry(clientRect.width()-326,46,70,30);
    ui->NewBtn->setGeometry(clientRect.width()-246,46,70,30);
    ui->EditBtn->setGeometry(clientRect.width()-166,46,70,30);
    ui->DeleBtn->setGeometry(clientRect.width()-86,46,70,30);
    ui->tableView->setGeometry(370,80,clientRect.width()-380,clientRect.height()-380);
    ui->UpPageBtn->setGeometry(clientRect.width()-76,clientRect.height() - 50,30,30);
    ui->DownPageBtn->setGeometry(clientRect.width()-42,clientRect.height() - 50,30,30);

    ui->SearBtn->setText(tr("筛选"));
    ui->HighBtn->setText(tr("高级"));
    ui->NewBtn->setText(tr("新建"));
    ui->EditBtn->setText(tr("编辑"));
    ui->DeleBtn->setText(tr("删除"));
    ui->UpPageBtn->setToolTip(tr("上一页"));
    ui->DownPageBtn->setToolTip(tr("下一页"));
    ui->SearBtn->setIcon(QIcon(":/res/shaixuan.png"));
    ui->SearBtn->setIconSize(QSize(20,20));
    ui->HighBtn->setIcon(QIcon(":/res/gaojisousuo.png"));
    ui->HighBtn->setIconSize(QSize(20,20));
    ui->NewBtn->setIcon(QIcon(":/res/xinjian.png"));
    ui->NewBtn->setIconSize(QSize(20,20));
    ui->EditBtn->setIcon(QIcon(":/res/bianji.png"));
    ui->EditBtn->setIconSize(QSize(20,20));
    ui->DeleBtn->setIcon(QIcon(":/res/shanchu.png"));
    ui->DeleBtn->setIconSize(QSize(20,20));
    ui->UpPageBtn->setIcon(QIcon(":/res/UpPage.png"));
    ui->DownPageBtn->setIcon(QIcon(":/res/DownPage.png"));

    ui->SearBtn->setStyleSheet("QPushButton{background-color:rgba(53,65,89,100%);border-radius:0px;color:rgb(255,255,255);}"
                               "QPushButton:hover{background-color:rgb(54,112,227);color:rgb(0,0,0);}"
                               "QPushButton:pressed{background-color:rgb(53,65,89);border-style:inset;}");
    ui->HighBtn->setStyleSheet("QPushButton{background-color:rgba(53,65,89,100%);border-radius:0px;color:rgb(255,255,255);}"
                               "QPushButton:hover{background-color:rgb(54,112,227);color:rgb(0,0,0);color:rgb(0,0,0);}"
                               "QPushButton:pressed{background-color:rgb(53,65,89);border-style:inset;}");
    ui->NewBtn->setStyleSheet("QPushButton{background-color:rgba(33,181,95,100%);border-radius:0px;color:rgb(255,255,255);}"
                              "QPushButton:pressed{background-color:rgb(53,65,89);border-style:inset;}");
    ui->EditBtn->setStyleSheet("QPushButton{background-color:rgba(6,155,255,100%);border-radius:0px;color:rgb(255,255,255);}"
                               "QPushButton:pressed{background-color:rgb(53,65,89);border-style:inset;color:rgb(0,0,0);}");
    ui->DeleBtn->setStyleSheet("QPushButton{background-color:rgba(255,102,104,100%);border-radius:0px;color:rgb(255,255,255);}"
                               "QPushButton:pressed{background-color:rgb(53,65,89);border-style:inset;}");
    ui->UpPageBtn->setStyleSheet("QPushButton{background-color:rgba(255,102,104,0%);border-radius:0px;}"
                                 "QPushButton:pressed{border:1px groove gray;}");
    ui->DownPageBtn->setStyleSheet("QPushButton{background-color:rgba(255,102,104,0%);border-radius:0px;}"
                                   "QPushButton:pressed{border:1px groove gray;}");

    ui->tableView->setAlternatingRowColors(true);//设置table隔行变色
    ui->tableView->setFrameShape(QFrame::NoFrame);//设置table无边框
    ui->tableView->setShowGrid(true);//设置table内部线条不显示
    ui->tableView->horizontalHeader()->setStretchLastSection(true);//设置最后一列填满表格
    ui->tableView->resizeColumnsToContents();//设置列宽适应内容调整宽度
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选中表格时为整行选中
    ui->tableView->setFocusPolicy(Qt::NoFocus);//设置选中表格时没有虚线框（不显示焦点）
    ui->tableView->horizontalHeader()->setFixedHeight(30);//设置表头的高度
    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //设置设置表头样式，背景色，字体颜色，大小
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(54,151,255);color:white;padding-left: 4px;\
                                                     font-family:'Microsoft YaHei';font-size:15px;border: 0px solid gray;}");
    //设置table样式，设置表格内容的背景色，字体颜色，大小
    ui->tableView->setStyleSheet("QTableView{color:black;background-color:rgb(173,216,230,0%);\
                                 alternate-background-color:rgb(211,211,211);selection-color:rgb(255,255,255);selection-background-color:rgb(112,128,144);\
    border:0px groove gray;padding:2px 4px;border-radius:0px;\
    font-family:'Microsoft YaHei';font-size:15px;gridline-color:darkgray;}");


    connect(ui->NewBtn,SIGNAL(clicked(bool)),this,SLOT(newBtnFunc()));
    connect(ui->EditBtn,SIGNAL(clicked(bool)),this,SLOT(editBtnFunc()));

    connect(UserWin,SIGNAL(showUserInfo()),this,SLOT(showModel()));
    connect(UserWin,SIGNAL(editUserInfo()),this,SLOT(editUserInfo()));

    connect(TableWin,SIGNAL(showTable()),this,SLOT(showModel()));
    connect(TableStuWin,SIGNAL(showTable()),this,SLOT(showModel()));

    connect(TableTeaWin,SIGNAL(showTable()),this,SLOT(showModel()));
    connect(shenHeWin,SIGNAL(showUserInfo()),this,SLOT(showModel()));
    connect(shenHeWin,SIGNAL(editUserInfo()),this,SLOT(showModel()));
    connect(ExitWin,SIGNAL(ExitApp()),this,SLOT(windowClosed()));
}

AdmWin::~AdmWin()
{
    delete ui;
}



void AdmWin::windowClosed()//关闭窗口的槽实现
{

    this->close();
}
void AdmWin::windowMin()//最小化窗口的槽实现
{
    this->showMinimized();
}
void AdmWin::windowMax()//最大化窗口的槽实现
{
    if(isMaxWindow){
        resize(1000, 618);
        move((clientRect.width() - this->width())/2, (clientRect.height() - this->height())/2); // 居中
        isMaxWindow = false;
        isHalfWindow = false;
    }else{
        showMaximized();
        resize(clientRect.width(), clientRect.height());
        move(0, 0);
        isMaxWindow = true;
        isHalfWindow = false;
    }
    updateNormalBtn();
}


//···鼠标按下操作···
static QPoint last(0,0);//保存一个坐标
const int TITLE_HEIGHT = 30;//保存标题高度，也就是鼠标点击区域高度
void AdmWin::mousePressEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)//如果点击了标题范围
    {
        last = event->globalPos();//坐标存储为全局坐标，即桌面屏幕坐标
    }
}

//···鼠标移动操作···
//实时修改窗口的坐标
void AdmWin::mouseMoveEvent(QMouseEvent *event)
{

    if(event->y()<TITLE_HEIGHT)//如果选中了标题范围
    {
        if (isMaxWindow || isHalfWindow) {
            //this->showNormal(); // 拖动最大化的窗口是否需要变成正常？
            resize(1000, 618);
            isMaxWindow = false;
            isHalfWindow = false;
        }else{
        int dx = event->globalX() - last.x();//得到鼠标移动后的全局坐标X减去移动前的全局坐标X，得到移动距离dx
        int dy = event->globalY() - last.y();//得到鼠标移动后的全局坐标X减去移动前的全局坐标y，得到移动距离dy
        last = event->globalPos();//更新存储坐标为当前的全局坐标
        this->move(this->x()+dx,this->y()+dy);//设置窗口以当前坐标为基准移动dx和dy距离到新的位置
        }
        if(event->globalY() == 0){ // 鼠标拖动窗体到屏幕顶端最大化窗体
            move(0, 0);
            resize(clientRect.width(), clientRect.height());
            isMaxWindow = true;
            isHalfWindow = false;
        }
        if(event->globalX() < 4){// 鼠标拖动窗体到屏幕最左端窗体占左半边屏幕大小
            resize(1000, clientRect.height());
            move(0, 0);
            isMaxWindow = false;
            isHalfWindow = true;
        }
        if(event->globalX() > clientRect.width() - 4){// 鼠标拖动窗体到屏幕最右端窗体占右半边屏幕大小
            resize(1000, clientRect.height());
            move(clientRect.width()-1000, 0);
            isMaxWindow = false;
            isHalfWindow = true;
        }
    }
       updateNormalBtn();
}

//···鼠标释放操作···
void AdmWin::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)//选中标题栏
    {
        int dx = event->globalX() - last.x();//得到鼠标移动后的全局坐标X减去移动前的全局坐标X，得到移动距离dx
        int dy = event->globalY() - last.y();//得到鼠标移动后的全局坐标X减去移动前的全局坐标y，得到移动距离dy
        this->move(this->x()+dx,this->y()+dy);//设置窗口以当前坐标为基准移动dx和dy距离到新的位置
    }
}
void AdmWin::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)//如果点击了标题范围
    {
        if(isMaxWindow){
            resize(1000, 618);
            move((clientRect.width() - this->width())/2, (clientRect.height() - this->height())/2); // 居中
            isMaxWindow = false;
            isHalfWindow = false;
        }else{
            showMaximized();
            resize(clientRect.width(), clientRect.height());
            move(0, 0);
            isMaxWindow = true;
            isHalfWindow = false;
        }
    }
    updateNormalBtn();
}



void AdmWin::setTitle()
{
    qDebug() << userStrInfo << endl;
     ui->label->setText(userStrInfo);
     ui->winTitle->setText(userStrInfo);
}

void AdmWin::updateNormalBtn()
{
    if(isMaxWindow){
        ui->maxButton->setToolTip(tr("还原"));
        ui->closeButton->setGeometry(clientRect.width()-30,0,30,30);//设置按钮位置和大小
        ui->minButton->setGeometry(clientRect.width()-90,0,30,30);//设置按钮位置和大小
        ui->maxButton->setGeometry(clientRect.width()-60,0,30,30);//设置按钮位置和大小
        ui->setButton->setGeometry(clientRect.width()-120,0,30,30);

        ui->maxButton->setIcon(QIcon(":/res/huanyuan.png"));//添加按钮图标
        ui->SearBtn->setGeometry(clientRect.width()-406,46,70,30);
        ui->HighBtn->setGeometry(clientRect.width()-326,46,70,30);
        ui->NewBtn->setGeometry(clientRect.width()-246,46,70,30);
        ui->EditBtn->setGeometry(clientRect.width()-166,46,70,30);
        ui->DeleBtn->setGeometry(clientRect.width()-86,46,70,30);
        ui->tableView->setGeometry(370,80,clientRect.width()-380,600);
        ui->UpPageBtn->setGeometry(clientRect.width()-76,685,30,30);
        ui->DownPageBtn->setGeometry(clientRect.width()-42,685,30,30);

    }else if(isHalfWindow){
            ui->closeButton->setGeometry(1000-30,0,30,30);//设置按钮位置和大小
            ui->minButton->setGeometry(1000-90,0,30,30);//设置按钮位置和大小
            ui->maxButton->setGeometry(1000-60,0,30,30);//设置按钮位置和大小
            ui->setButton->setGeometry(1000-120,0,30,30);
            ui->tableView->setGeometry(370,80,1000-380,600);
            ui->UpPageBtn->setGeometry(1000-76,685,30,30);
            ui->DownPageBtn->setGeometry(1000-42,685,30,30);

        }else{
            ui->maxButton->setToolTip(tr("最大化"));
            ui->closeButton->setGeometry(1000-30,0,30,30);//设置按钮位置和大小
            ui->minButton->setGeometry(1000-90,0,30,30);//设置按钮位置和大小
            ui->maxButton->setGeometry(1000-60,0,30,30);//设置按钮位置和大小
            ui->setButton->setGeometry(1000-120,0,30,30);
            ui->maxButton->setIcon(QIcon(":/res/max2.png"));//添加按钮图标
            ui->SearBtn->setGeometry(1000-406,46,70,30);
            ui->HighBtn->setGeometry(1000-326,46,70,30);
            ui->NewBtn->setGeometry(1000-246,46,70,30);
            ui->EditBtn->setGeometry(1000-166,46,70,30);
            ui->DeleBtn->setGeometry(1000-86,46,70,30);
            ui->tableView->setGeometry(370,80,1000-380,500);
            ui->UpPageBtn->setGeometry(1000-76,585,30,30);//
            ui->DownPageBtn->setGeometry(1000-42,585,30,30);//
        }
}

void AdmWin::showPage(const QModelIndex &index)//显示页面，实现页面切换的槽函数的实现
{
    int i = index.row();//获取列表当前行号，从0开始
    qDebug()<<index << " " << i << endl;;
    Flag = i;
    switch(i)//选择判断是第几行，相应改变stackedwidget的页面显示
    {
    case 0: ui->stackedWidget->setCurrentWidget(UserWin);break;
    case 1: ui->stackedWidget->setCurrentWidget(TableWin);break;
    case 2: ui->stackedWidget->setCurrentWidget(TableStuWin);break;
    case 3: ui->stackedWidget->setCurrentWidget(TableTeaWin);break;
    case 4: ui->stackedWidget->setCurrentWidget(shenHeWin);break;
    case 5: ui->stackedWidget->setCurrentWidget(ExitWin);break;
    default: ui->stackedWidget->setCurrentWidget(UserWin);break;
    }
}

void AdmWin::newBtnFunc()
{
    EditUser->addWinInit();
    EditUser->show();

}

void AdmWin::editBtnFunc()
{
    EditUser->editWinInit();
    EditUser->show();

}



void AdmWin::showModel()
{
    //利用MVC将数据库表内容显示在tableView上
    qDebug() << "现在在mainwindow窗口" << "接收到showUserInfo信号" << Flag<< endl;
    model = new QMySqlQueryModel(this);
    //model->setQuery(QString("select * from %1;").arg(data));
    //列名
    int iM = AdmWin::Mark;
    qDebug() << iM << endl;
    if(AdmWin::Flag == 0)
    {
        qDebug() << "if 0" << endl;
        switch (iM)
        {
            case 0:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from admin where admin_id='%1';").arg(userId));
                model->setHeaderData(0,Qt::Horizontal,tr("管理员编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("姓名"));
                model->setHeaderData(2,Qt::Horizontal,tr("登录密码"));

                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,300);
                ui->tableView->setColumnWidth(1,300);
                ui->tableView->setColumnWidth(2,300);
            }
                break;
            case 1:
            {

            }
                break;
        }
    }
    else if(AdmWin::Flag == 1)
    {
        qDebug() << "if 1" << endl;
        switch(iM)
        {
            case 22:
                {
                    ui->tableView->verticalHeader()->hide();//不显示序号
                    model->setQuery(QString("select * from classroom where classroom_type='%1';").arg("一号教学楼"));
                    model->setHeaderData(0,Qt::Horizontal,tr("教室编号"));
                    model->setHeaderData(1,Qt::Horizontal,tr("教室名字"));
                    model->setHeaderData(2,Qt::Horizontal,tr("教室类型"));
                    model->setHeaderData(3,Qt::Horizontal,tr("教室位置"));
                    model->setHeaderData(4,Qt::Horizontal,tr("教室状态"));
                    model->setHeaderData(5,Qt::Horizontal,tr("教室容量"));

                    ui->tableView->setModel(model);//放数据
                    ui->tableView->setColumnWidth(0,150);
                    ui->tableView->setColumnWidth(1,150);
                    ui->tableView->setColumnWidth(2,150);
                    ui->tableView->setColumnWidth(3,150);
                    ui->tableView->setColumnWidth(4,150);
                    ui->tableView->setColumnWidth(5,150);

                }
                    break;
                case 23:
                {
                    ui->tableView->verticalHeader()->hide();//不显示序号
                    model->setQuery(QString("select * from classroom where classroom_type='%1';").arg("二号教学楼"));
                    model->setHeaderData(0,Qt::Horizontal,tr("教室编号"));
                    model->setHeaderData(1,Qt::Horizontal,tr("教室名字"));
                    model->setHeaderData(2,Qt::Horizontal,tr("教室类型"));
                    model->setHeaderData(3,Qt::Horizontal,tr("教室位置"));
                    model->setHeaderData(4,Qt::Horizontal,tr("教室状态"));
                    model->setHeaderData(5,Qt::Horizontal,tr("教室容量"));

                    ui->tableView->setModel(model);//放数据
                    ui->tableView->setColumnWidth(0,150);
                    ui->tableView->setColumnWidth(1,150);
                    ui->tableView->setColumnWidth(2,150);
                    ui->tableView->setColumnWidth(3,150);
                    ui->tableView->setColumnWidth(4,150);
                    ui->tableView->setColumnWidth(5,150);
                }
                    break;
                case 24:
                {
                    ui->tableView->verticalHeader()->hide();//不显示序号
                    model->setQuery(QString("select * from classroom where classroom_type='%1';").arg("三号教学楼"));
                    model->setHeaderData(0,Qt::Horizontal,tr("教室编号"));
                    model->setHeaderData(1,Qt::Horizontal,tr("教室名字"));
                    model->setHeaderData(2,Qt::Horizontal,tr("教室类型"));
                    model->setHeaderData(3,Qt::Horizontal,tr("教室位置"));
                    model->setHeaderData(4,Qt::Horizontal,tr("教室状态"));
                    model->setHeaderData(5,Qt::Horizontal,tr("教室容量"));

                    ui->tableView->setModel(model);//放数据
                    ui->tableView->setColumnWidth(0,150);
                    ui->tableView->setColumnWidth(1,150);
                    ui->tableView->setColumnWidth(2,150);
                    ui->tableView->setColumnWidth(3,150);
                    ui->tableView->setColumnWidth(4,150);
                    ui->tableView->setColumnWidth(5,150);
                }
                    break;
                case 25:
                {
                    ui->tableView->verticalHeader()->hide();//不显示序号
                    model->setQuery(QString("select * from classroom where classroom_type='%1';").arg("一号实验楼"));
                    model->setHeaderData(0,Qt::Horizontal,tr("教室编号"));
                    model->setHeaderData(1,Qt::Horizontal,tr("教室名字"));
                    model->setHeaderData(2,Qt::Horizontal,tr("教室类型"));
                    model->setHeaderData(3,Qt::Horizontal,tr("教室位置"));
                    model->setHeaderData(4,Qt::Horizontal,tr("教室状态"));
                    model->setHeaderData(5,Qt::Horizontal,tr("教室容量"));

                    ui->tableView->setModel(model);//放数据
                    ui->tableView->setColumnWidth(0,150);
                    ui->tableView->setColumnWidth(1,150);
                    ui->tableView->setColumnWidth(2,150);
                    ui->tableView->setColumnWidth(3,150);
                    ui->tableView->setColumnWidth(4,150);
                    ui->tableView->setColumnWidth(5,150);
                }
                    break;
                case 26:
                {
                    ui->tableView->verticalHeader()->hide();//不显示序号
                    model->setQuery(QString("select * from classroom where classroom_type='%1';").arg("二号实验楼"));
                    model->setHeaderData(0,Qt::Horizontal,tr("教室编号"));
                    model->setHeaderData(1,Qt::Horizontal,tr("教室名字"));
                    model->setHeaderData(2,Qt::Horizontal,tr("教室类型"));
                    model->setHeaderData(3,Qt::Horizontal,tr("教室位置"));
                    model->setHeaderData(4,Qt::Horizontal,tr("教室状态"));
                    model->setHeaderData(5,Qt::Horizontal,tr("教室容量"));

                    ui->tableView->setModel(model);//放数据
                    ui->tableView->setColumnWidth(0,150);
                    ui->tableView->setColumnWidth(1,150);
                    ui->tableView->setColumnWidth(2,150);
                    ui->tableView->setColumnWidth(3,150);
                    ui->tableView->setColumnWidth(4,150);
                    ui->tableView->setColumnWidth(5,150);
                }
                    break;
                case 27:
                {
                    ui->tableView->verticalHeader()->hide();//不显示序号
                    model->setQuery(QString("select * from classroom where classroom_type='%1';").arg("三号实验楼"));
                    model->setHeaderData(0,Qt::Horizontal,tr("教室编号"));
                    model->setHeaderData(1,Qt::Horizontal,tr("教室名字"));
                    model->setHeaderData(2,Qt::Horizontal,tr("教室类型"));
                    model->setHeaderData(3,Qt::Horizontal,tr("教室位置"));
                    model->setHeaderData(4,Qt::Horizontal,tr("教室状态"));
                    model->setHeaderData(5,Qt::Horizontal,tr("教室容量"));

                    ui->tableView->setModel(model);//放数据
                    ui->tableView->setColumnWidth(0,150);
                    ui->tableView->setColumnWidth(1,150);
                    ui->tableView->setColumnWidth(2,150);
                    ui->tableView->setColumnWidth(3,150);
                    ui->tableView->setColumnWidth(4,150);
                    ui->tableView->setColumnWidth(5,150);
                }
                    break;
                case 28:
                {
                    ui->tableView->verticalHeader()->hide();//不显示序号
                    model->setQuery(QString("select * from classroom where classroom_type='%1';").arg("多功能放映厅"));
                    model->setHeaderData(0,Qt::Horizontal,tr("教室编号"));
                    model->setHeaderData(1,Qt::Horizontal,tr("教室名字"));
                    model->setHeaderData(2,Qt::Horizontal,tr("教室类型"));
                    model->setHeaderData(3,Qt::Horizontal,tr("教室位置"));
                    model->setHeaderData(4,Qt::Horizontal,tr("教室状态"));
                    model->setHeaderData(5,Qt::Horizontal,tr("教室容量"));

                    ui->tableView->setModel(model);//放数据
                    ui->tableView->setColumnWidth(0,150);
                    ui->tableView->setColumnWidth(1,150);
                    ui->tableView->setColumnWidth(2,150);
                    ui->tableView->setColumnWidth(3,150);
                    ui->tableView->setColumnWidth(4,150);
                    ui->tableView->setColumnWidth(5,150);
                }
                    break;
                case 29:
                {
                    ui->tableView->verticalHeader()->hide();//不显示序号
                    model->setQuery(QString("select * from classroom where classroom_type='%1';").arg("求是堂"));
                    model->setHeaderData(0,Qt::Horizontal,tr("教室编号"));
                    model->setHeaderData(1,Qt::Horizontal,tr("教室名字"));
                    model->setHeaderData(2,Qt::Horizontal,tr("教室类型"));
                    model->setHeaderData(3,Qt::Horizontal,tr("教室位置"));
                    model->setHeaderData(4,Qt::Horizontal,tr("教室状态"));
                    model->setHeaderData(5,Qt::Horizontal,tr("教室容量"));

                    ui->tableView->setModel(model);//放数据
                    ui->tableView->setColumnWidth(0,150);
                    ui->tableView->setColumnWidth(1,150);
                    ui->tableView->setColumnWidth(2,150);
                    ui->tableView->setColumnWidth(3,150);
                    ui->tableView->setColumnWidth(4,150);
                    ui->tableView->setColumnWidth(5,150);
                }
                    break;
                case 30:
                {
                    ui->tableView->verticalHeader()->hide();//不显示序号
                    model->setQuery(QString("select * from classroom where classroom_type='%1';").arg("共享空间"));
                    model->setHeaderData(0,Qt::Horizontal,tr("教室编号"));
                    model->setHeaderData(1,Qt::Horizontal,tr("教室名字"));
                    model->setHeaderData(2,Qt::Horizontal,tr("教室类型"));
                    model->setHeaderData(3,Qt::Horizontal,tr("教室位置"));
                    model->setHeaderData(4,Qt::Horizontal,tr("教室状态"));
                    model->setHeaderData(5,Qt::Horizontal,tr("教室容量"));

                    ui->tableView->setModel(model);//放数据
                    ui->tableView->setColumnWidth(0,150);
                    ui->tableView->setColumnWidth(1,150);
                    ui->tableView->setColumnWidth(2,150);
                    ui->tableView->setColumnWidth(3,150);
                    ui->tableView->setColumnWidth(4,150);
                    ui->tableView->setColumnWidth(5,150);
                }
                    break;
                case 31:
                {
                    ui->tableView->verticalHeader()->hide();//不显示序号
                    model->setQuery(QString("select * from classroom where classroom_type='%1';").arg("值班室"));
                    model->setHeaderData(0,Qt::Horizontal,tr("教室编号"));
                    model->setHeaderData(1,Qt::Horizontal,tr("教室名字"));
                    model->setHeaderData(2,Qt::Horizontal,tr("教室类型"));
                    model->setHeaderData(3,Qt::Horizontal,tr("教室位置"));
                    model->setHeaderData(4,Qt::Horizontal,tr("教室状态"));
                    model->setHeaderData(5,Qt::Horizontal,tr("教室容量"));

                    ui->tableView->setModel(model);//放数据
                    ui->tableView->setColumnWidth(0,150);
                    ui->tableView->setColumnWidth(1,150);
                    ui->tableView->setColumnWidth(2,150);
                    ui->tableView->setColumnWidth(3,150);
                    ui->tableView->setColumnWidth(4,150);
                    ui->tableView->setColumnWidth(5,150);
                }
                    break;
                case 32:
                {
                    ui->tableView->verticalHeader()->hide();//不显示序号
                    model->setQuery(QString("select * from classroom;"));
                    model->setHeaderData(0,Qt::Horizontal,tr("教室编号"));
                    model->setHeaderData(1,Qt::Horizontal,tr("教室名字"));
                    model->setHeaderData(2,Qt::Horizontal,tr("教室类型"));
                    model->setHeaderData(3,Qt::Horizontal,tr("教室位置"));
                    model->setHeaderData(4,Qt::Horizontal,tr("教室状态"));
                    model->setHeaderData(5,Qt::Horizontal,tr("教室容量"));

                    ui->tableView->setModel(model);//放数据
                    ui->tableView->setColumnWidth(0,150);
                    ui->tableView->setColumnWidth(1,150);
                    ui->tableView->setColumnWidth(2,150);
                    ui->tableView->setColumnWidth(3,150);
                    ui->tableView->setColumnWidth(4,150);
                    ui->tableView->setColumnWidth(5,150);
                }
                    break;
                case 33:
                {

                }
                    break;
        }
    }
    else if(AdmWin::Flag == 2)
    {
        qDebug() << "在这里" << endl;


        switch(iM)
        {
        case 22:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setHeaderData(0,Qt::Horizontal,tr("学生编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("学生名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("学生性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(4,Qt::Horizontal,tr("专业班级"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));
                model->setQuery(QString("select * from student where pro_Class like '%1';").arg("法医学%"));
                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);

            }
                break;
            case 23:
            {
            ui->tableView->verticalHeader()->hide();//不显示序号
            model->setHeaderData(0,Qt::Horizontal,tr("学生编号"));
            model->setHeaderData(1,Qt::Horizontal,tr("学生名字"));
            model->setHeaderData(2,Qt::Horizontal,tr("学生性别"));
            model->setHeaderData(3,Qt::Horizontal,tr("登陆密码"));
            model->setHeaderData(4,Qt::Horizontal,tr("专业班级"));
            model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));
            model->setQuery(QString("select * from student where pro_Class like '%1';").arg("会计学%"));
            ui->tableView->setModel(model);//放数据
            ui->tableView->setColumnWidth(0,150);
            ui->tableView->setColumnWidth(1,150);
            ui->tableView->setColumnWidth(2,150);
            ui->tableView->setColumnWidth(3,150);
            ui->tableView->setColumnWidth(4,300);
            ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 24:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from student where pro_Class like '%1';").arg("物流管理%"));
                model->setHeaderData(0,Qt::Horizontal,tr("学生编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("学生名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("学生性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(4,Qt::Horizontal,tr("专业班级"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));

                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 25:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from student where pro_Class like '%1';").arg("计算机科学与技术%"));
                model->setHeaderData(0,Qt::Horizontal,tr("学生编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("学生名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("学生性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(4,Qt::Horizontal,tr("专业班级"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));

                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 26:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from student where pro_Class like '%1';").arg("生命科学%"));
                model->setHeaderData(0,Qt::Horizontal,tr("学生编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("学生名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("学生性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(4,Qt::Horizontal,tr("专业班级"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));

                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 27:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from student where pro_Class like '%1';").arg("水利水电%"));
                model->setHeaderData(0,Qt::Horizontal,tr("学生编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("学生名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("学生性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(4,Qt::Horizontal,tr("专业班级"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));
                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 28:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from student where pro_Class like '%1';").arg("食品安全%"));
                model->setHeaderData(0,Qt::Horizontal,tr("学生编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("学生名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("学生性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(4,Qt::Horizontal,tr("专业班级"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));

                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 29:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from student where pro_Class like '%1';").arg("数学%"));
                model->setHeaderData(0,Qt::Horizontal,tr("学生编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("学生名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("学生性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(4,Qt::Horizontal,tr("专业班级"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));

                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 30:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from student where pro_Class like '%1';").arg("音乐%"));
                model->setHeaderData(0,Qt::Horizontal,tr("学生编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("学生名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("学生性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(4,Qt::Horizontal,tr("专业班级"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));

                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 31:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from student where pro_Class like '%1';").arg("美术%"));
                model->setHeaderData(0,Qt::Horizontal,tr("学生编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("学生名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("学生性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(4,Qt::Horizontal,tr("专业班级"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));

                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 32:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from student;"));
                model->setHeaderData(0,Qt::Horizontal,tr("学生编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("学生名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("学生性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(4,Qt::Horizontal,tr("专业班级"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));

                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 33:
            {

            }
                break;
        }
    }
    else if(AdmWin::Flag == 3)
    {
        qDebug() << " ---" << endl;
        switch(iM)
        {
        case 22:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setHeaderData(0,Qt::Horizontal,tr("员工编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("员工名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("员工性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("员工职位"));
                model->setHeaderData(4,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));
                model->setQuery(QString("select * from teacher where position like '%1';").arg("讲师"));
                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);

            }
                break;
            case 23:
            {
            ui->tableView->verticalHeader()->hide();//不显示序号
            model->setHeaderData(0,Qt::Horizontal,tr("员工编号"));
            model->setHeaderData(1,Qt::Horizontal,tr("员工名字"));
            model->setHeaderData(2,Qt::Horizontal,tr("员工性别"));
            model->setHeaderData(3,Qt::Horizontal,tr("员工职位"));
            model->setHeaderData(4,Qt::Horizontal,tr("登陆密码"));
            model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));
            model->setQuery(QString("select * from teacher where position like '%1';").arg("辅导员"));
            ui->tableView->setModel(model);//放数据
            ui->tableView->setColumnWidth(0,150);
            ui->tableView->setColumnWidth(1,150);
            ui->tableView->setColumnWidth(2,150);
            ui->tableView->setColumnWidth(3,150);
            ui->tableView->setColumnWidth(4,300);
            ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 24:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setHeaderData(0,Qt::Horizontal,tr("员工编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("员工名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("员工性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("员工职位"));
                model->setHeaderData(4,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));
                model->setQuery(QString("select * from teacher where position like '%1';").arg("行政人员"));

                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 25:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setHeaderData(0,Qt::Horizontal,tr("员工编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("员工名字"));
                model->setHeaderData(2,Qt::Horizontal,tr("员工性别"));
                model->setHeaderData(3,Qt::Horizontal,tr("员工职位"));
                model->setHeaderData(4,Qt::Horizontal,tr("登陆密码"));
                model->setHeaderData(5,Qt::Horizontal,tr("联系方式"));
                model->setQuery(QString("select * from teacher where position like '%1';").arg("教授"));

                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,150);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,300);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
        }
    }
    else if(AdmWin::Flag == 4)
    {
        qDebug() <<"++++" << endl;
        switch (iM)
        {
            case 0:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from application where status = '%1';").arg(0));
                model->setHeaderData(0,Qt::Horizontal,tr("申请者编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("申请人姓名"));
                model->setHeaderData(2,Qt::Horizontal,tr("申请时间"));
                model->setHeaderData(3,Qt::Horizontal,tr("申请教师"));
                model->setHeaderData(4,Qt::Horizontal,tr("申请原因"));
                model->setHeaderData(5,Qt::Horizontal,tr("当前状态"));
                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,300);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,150);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
            case 1:
            {
                ui->tableView->verticalHeader()->hide();//不显示序号
                model->setQuery(QString("select * from application where status = '%1';").arg(1));
                model->setHeaderData(0,Qt::Horizontal,tr("申请者编号"));
                model->setHeaderData(1,Qt::Horizontal,tr("申请人姓名"));
                model->setHeaderData(2,Qt::Horizontal,tr("申请时间"));
                model->setHeaderData(3,Qt::Horizontal,tr("申请教师"));
                model->setHeaderData(4,Qt::Horizontal,tr("申请原因"));
                model->setHeaderData(5,Qt::Horizontal,tr("当前状态"));
                ui->tableView->setModel(model);//放数据
                ui->tableView->setColumnWidth(0,150);
                ui->tableView->setColumnWidth(1,150);
                ui->tableView->setColumnWidth(2,300);
                ui->tableView->setColumnWidth(3,150);
                ui->tableView->setColumnWidth(4,150);
                ui->tableView->setColumnWidth(5,150);
            }
                break;
        }
    }
    else if(AdmWin::Flag == 5)
    {

    }


}

void AdmWin::editUserInfo()
{
    ChanUser->show();
}

void AdmWin::on_tableView_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *Imodel=ui->tableView->model();

    QModelIndex Iindex = Imodel->index(index.row(),0);  //index.row()为算选择的行号。1为所选中行的第一列。。
    QModelIndex Iindex2 = Imodel->index(index.row(),4);
    QVariant datatemp=Imodel->data(Iindex);
    QVariant datatemp2=Imodel->data(Iindex2);
    QString name=Imodel->data(index).toString();        //name即为所选择行的第一列的值
    QString name2=Imodel->data(Iindex2).toString();
    shenHe->setEditText(name,name2);
    UserChan::str1 = name;
    UserChan::str2 = name2;
    shenHe->show();
}
