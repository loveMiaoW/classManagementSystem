#include "formtable.h"
#include "ui_formtable.h"
#include <QFile>
#include "mainwindow.h"

FormTable::FormTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTable)
{
    ui->setupUi(this);


}

FormTable::~FormTable()
{
    delete ui;
}

void FormTable::classInfoInit()
{
    //导入资源文件中的qss文件，对QPushButton下拉列表进行样式设置
    QFile qss(":/qss/style.qss");//设置qss文件打开路径
    qss.open(QFile::ReadOnly);//只读，打开qss文件
    if(qss.isOpen())
    {
        qApp->setStyleSheet(qss.readAll());//如果打开成功，设置样式
        qss.close();//关闭qss文件
    }

    ui->label->setGeometry(0,0,180,2000);
    ui->label->setStyleSheet("QLabel{background-color:rgb(61,75,102);}");

    ui->btnTeaBuild1->setCheckable(true);
    ui->btnTeaBuild2->setCheckable(true);
    ui->btnTeaBuild3->setCheckable(true);
    ui->btnExpBuild1->setCheckable(true);
    ui->btnExpBuild2->setCheckable(true);
    ui->btnExpBuild3->setCheckable(true);
    ui->btnMultHall->setCheckable(true);
    ui->btnQiuShi->setCheckable(true);
    ui->btnShareSqr->setCheckable(true);
    ui->btnDutyRoom->setCheckable(true);
    ui->btnAll->setCheckable(true);

    ui->btnTeaBuild1->setAutoExclusive(true);
    ui->btnTeaBuild2->setAutoExclusive(true);
    ui->btnTeaBuild3->setAutoExclusive(true);
    ui->btnExpBuild1->setAutoExclusive(true);
    ui->btnExpBuild2->setAutoExclusive(true);
    ui->btnExpBuild3->setAutoExclusive(true);
    ui->btnMultHall->setAutoExclusive(true);
    ui->btnQiuShi->setAutoExclusive(true);
    ui->btnShareSqr->setAutoExclusive(true);
    ui->btnDutyRoom->setAutoExclusive(true);
    ui->btnAll->setAutoExclusive(true);
    ui->btnTeaBuild1->setGeometry(20,10,140,40);
    ui->btnTeaBuild2->setGeometry(20,55,140,40);
    ui->btnTeaBuild3->setGeometry(20,100,140,40);
    ui->btnExpBuild1->setGeometry(20,145,140,40);
    ui->btnExpBuild2->setGeometry(20,190,140,40);
    ui->btnExpBuild3->setGeometry(20,235,140,40);
    ui->btnMultHall->setGeometry(20,280,140,40);
    ui->btnQiuShi->setGeometry(20,325,140,40);
    ui->btnShareSqr->setGeometry(20,370,140,40);
    ui->btnDutyRoom->setGeometry(20,415,140,40);
    ui->btnAll->setGeometry(20,460,140,40);
    ui->btnTeaBuild1->setText(tr("一号教学楼"));
    ui->btnTeaBuild2->setText(tr("二号教学楼"));
    ui->btnTeaBuild3->setText(tr("三号教学楼"));
    ui->btnExpBuild1->setText(tr("一号实验楼"));
    ui->btnExpBuild2->setText(tr("二号实验楼"));
    ui->btnExpBuild3->setText(tr("三号实验楼"));
    ui->btnMultHall->setText(tr("多功能放映厅"));
    ui->btnQiuShi->setText(tr("求是堂"));
    ui->btnShareSqr->setText(tr("共享空间"));
    ui->btnDutyRoom->setText(tr("值班室"));
    ui->btnAll->setText(tr("显示所有信息"));

    //一堆的信号与槽
    connect(ui->btnTeaBuild1,SIGNAL(clicked(bool)),this,SLOT(btnTeaBuild1C()));
    connect(ui->btnTeaBuild2,SIGNAL(clicked(bool)),this,SLOT(btnTeaBuild2C()));
    connect(ui->btnTeaBuild3,SIGNAL(clicked(bool)),this,SLOT(btnTeaBuild3C()));
    connect(ui->btnExpBuild1,SIGNAL(clicked(bool)),this,SLOT(btnExpBuild1C()));
    connect(ui->btnExpBuild2,SIGNAL(clicked(bool)),this,SLOT(btnExpBuild2C()));
    connect(ui->btnExpBuild3,SIGNAL(clicked(bool)),this,SLOT(btnExpBuild3C()));
    connect(ui->btnMultHall,SIGNAL(clicked(bool)),this,SLOT(btnMultHallC()));
    connect(ui->btnQiuShi,SIGNAL(clicked(bool)),this,SLOT(btnQiuShiC()));
    connect(ui->btnShareSqr,SIGNAL(clicked(bool)),this,SLOT(btnShareSqrC()));
    connect(ui->btnDutyRoom,SIGNAL(clicked(bool)),this,SLOT(btnDutyRoomC()));
    connect(ui->btnAll,SIGNAL(clicked(bool)),this,SLOT(btnAllFunc()));
}

void FormTable::studentInfoInit()
{
    QFile qss(":/qss/style.qss");//设置qss文件打开路径
    qss.open(QFile::ReadOnly);//只读，打开qss文件
    if(qss.isOpen())
    {
        qApp->setStyleSheet(qss.readAll());//如果打开成功，设置样式
        qss.close();//关闭qss文件
    }

    ui->label->setGeometry(0,0,180,2000);
    ui->label->setStyleSheet("QLabel{background-color:rgb(61,75,102);}");

    ui->btnTeaBuild1->setCheckable(true);
    ui->btnTeaBuild2->setCheckable(true);
    ui->btnTeaBuild3->setCheckable(true);
    ui->btnExpBuild1->setCheckable(true);
    ui->btnExpBuild2->setCheckable(true);
    ui->btnExpBuild3->setCheckable(true);
    ui->btnMultHall->setCheckable(true);
    ui->btnQiuShi->setCheckable(true);
    ui->btnShareSqr->setCheckable(true);
    ui->btnDutyRoom->setCheckable(true);
    ui->btnAll->setCheckable(true);

    ui->btnTeaBuild1->setAutoExclusive(true);
    ui->btnTeaBuild2->setAutoExclusive(true);
    ui->btnTeaBuild3->setAutoExclusive(true);
    ui->btnExpBuild1->setAutoExclusive(true);
    ui->btnExpBuild2->setAutoExclusive(true);
    ui->btnExpBuild3->setAutoExclusive(true);
    ui->btnMultHall->setAutoExclusive(true);
    ui->btnQiuShi->setAutoExclusive(true);
    ui->btnShareSqr->setAutoExclusive(true);
    ui->btnDutyRoom->setAutoExclusive(true);
    ui->btnAll->setAutoExclusive(true);
    ui->btnTeaBuild1->setGeometry(20,10,140,40);
    ui->btnTeaBuild2->setGeometry(20,55,140,40);
    ui->btnTeaBuild3->setGeometry(20,100,140,40);
    ui->btnExpBuild1->setGeometry(20,145,140,40);
    ui->btnExpBuild2->setGeometry(20,190,140,40);
    ui->btnExpBuild3->setGeometry(20,235,140,40);
    ui->btnMultHall->setGeometry(20,280,140,40);
    ui->btnQiuShi->setGeometry(20,325,140,40);
    ui->btnShareSqr->setGeometry(20,370,140,40);
    ui->btnDutyRoom->setGeometry(20,415,140,40);
    ui->btnAll->setGeometry(20,460,140,40);
    ui->btnTeaBuild1->setText(tr("法医学"));
    ui->btnTeaBuild2->setText(tr("会计学"));
    ui->btnTeaBuild3->setText(tr("物流管理"));
    ui->btnExpBuild1->setText(tr("计算机科学与技术"));
    ui->btnExpBuild2->setText(tr("生命科学"));
    ui->btnExpBuild3->setText(tr("水利水电"));
    ui->btnMultHall->setText(tr("食品安全"));
    ui->btnQiuShi->setText(tr("数学系"));
    ui->btnShareSqr->setText(tr("音乐系"));
    ui->btnDutyRoom->setText(tr("美术系"));
    ui->btnAll->setText(tr("显示所有信息"));

    //一堆的信号与槽
    connect(ui->btnTeaBuild1,SIGNAL(clicked(bool)),this,SLOT(btnTeaBuild1C()));
    connect(ui->btnTeaBuild2,SIGNAL(clicked(bool)),this,SLOT(btnTeaBuild2C()));
    connect(ui->btnTeaBuild3,SIGNAL(clicked(bool)),this,SLOT(btnTeaBuild3C()));
    connect(ui->btnExpBuild1,SIGNAL(clicked(bool)),this,SLOT(btnExpBuild1C()));
    connect(ui->btnExpBuild2,SIGNAL(clicked(bool)),this,SLOT(btnExpBuild2C()));
    connect(ui->btnExpBuild3,SIGNAL(clicked(bool)),this,SLOT(btnExpBuild3C()));
    connect(ui->btnMultHall,SIGNAL(clicked(bool)),this,SLOT(btnMultHallC()));
    connect(ui->btnQiuShi,SIGNAL(clicked(bool)),this,SLOT(btnQiuShiC()));
    connect(ui->btnShareSqr,SIGNAL(clicked(bool)),this,SLOT(btnShareSqrC()));
    connect(ui->btnDutyRoom,SIGNAL(clicked(bool)),this,SLOT(btnDutyRoomC()));
    connect(ui->btnAll,SIGNAL(clicked(bool)),this,SLOT(btnAllFunc()));
}

void FormTable::teacherInfoInit()
{
    QFile qss(":/qss/style.qss");//设置qss文件打开路径
    qss.open(QFile::ReadOnly);//只读，打开qss文件
    if(qss.isOpen())
    {
        qApp->setStyleSheet(qss.readAll());//如果打开成功，设置样式
        qss.close();//关闭qss文件
    }

    ui->label->setGeometry(0,0,180,2000);
    ui->label->setStyleSheet("QLabel{background-color:rgb(61,75,102);}");

    ui->btnTeaBuild1->setCheckable(true);
    ui->btnTeaBuild2->setCheckable(true);
    ui->btnTeaBuild3->setCheckable(true);
    ui->btnExpBuild1->setCheckable(true);
    ui->btnExpBuild2->setCheckable(true);
    ui->btnExpBuild3->setCheckable(true);
    ui->btnMultHall->setCheckable(true);
    ui->btnQiuShi->setCheckable(true);
    ui->btnShareSqr->setCheckable(true);
    ui->btnDutyRoom->setCheckable(true);
    ui->btnAll->setCheckable(true);

    ui->btnTeaBuild1->setAutoExclusive(true);
    ui->btnTeaBuild2->setAutoExclusive(true);
    ui->btnTeaBuild3->setAutoExclusive(true);
    ui->btnExpBuild1->setAutoExclusive(true);
    ui->btnExpBuild2->setAutoExclusive(true);
    ui->btnExpBuild3->setAutoExclusive(true);
    ui->btnMultHall->setAutoExclusive(true);
    ui->btnQiuShi->setAutoExclusive(true);
    ui->btnShareSqr->setAutoExclusive(true);
    ui->btnDutyRoom->setAutoExclusive(true);
    ui->btnAll->setAutoExclusive(true);
    ui->btnTeaBuild1->setGeometry(20,10,140,40);
    ui->btnTeaBuild2->setGeometry(20,55,140,40);
    ui->btnTeaBuild3->setGeometry(20,100,140,40);
    ui->btnExpBuild1->setGeometry(20,145,140,40);
    ui->btnExpBuild2->setGeometry(2000,190,140,40);
    ui->btnExpBuild3->setGeometry(2000,235,140,40);
    ui->btnMultHall->setGeometry(2000,280,140,40);
    ui->btnQiuShi->setGeometry(2000,325,140,40);
    ui->btnShareSqr->setGeometry(2000,370,140,40);
    ui->btnDutyRoom->setGeometry(2000,415,140,40);
    ui->btnAll->setGeometry(200,190,140,40);
    ui->btnTeaBuild1->setText(tr("讲师"));
    ui->btnTeaBuild2->setText(tr("辅导员"));
    ui->btnTeaBuild3->setText(tr("行政人员"));
    ui->btnExpBuild1->setText(tr("教授"));
//    ui->btnExpBuild2->setText(tr(""));
//    ui->btnExpBuild3->setText(tr("水利水电"));
//    ui->btnMultHall->setText(tr("食品安全"));
//    ui->btnQiuShi->setText(tr("数学系"));
//    ui->btnShareSqr->setText(tr("音乐系"));
//    ui->btnDutyRoom->setText(tr("美术系"));
    ui->btnAll->setText(tr("显示所有信息"));

    //一堆的信号与槽
    connect(ui->btnTeaBuild1,SIGNAL(clicked(bool)),this,SLOT(btnTeaBuild1C()));
    connect(ui->btnTeaBuild2,SIGNAL(clicked(bool)),this,SLOT(btnTeaBuild2C()));
    connect(ui->btnTeaBuild3,SIGNAL(clicked(bool)),this,SLOT(btnTeaBuild3C()));
    connect(ui->btnExpBuild1,SIGNAL(clicked(bool)),this,SLOT(btnExpBuild1C()));
//    connect(ui->btnExpBuild2,SIGNAL(clicked(bool)),this,SLOT(btnExpBuild2C()));
//    connect(ui->btnExpBuild3,SIGNAL(clicked(bool)),this,SLOT(btnExpBuild3C()));
//    connect(ui->btnMultHall,SIGNAL(clicked(bool)),this,SLOT(btnMultHallC()));
//    connect(ui->btnQiuShi,SIGNAL(clicked(bool)),this,SLOT(btnQiuShiC()));
//    connect(ui->btnShareSqr,SIGNAL(clicked(bool)),this,SLOT(btnShareSqrC()));
//    connect(ui->btnDutyRoom,SIGNAL(clicked(bool)),this,SLOT(btnDutyRoomC()));
//    connect(ui->btnAll,SIGNAL(clicked(bool)),this,SLOT(btnAllFunc()));
}

void FormTable::btnTeaBuild1C()
{
    MainWindow::Mark = 2;
    AdmWin::Mark = 22;
    MainWindow::Table = "select * from bathtub;";
    emit showTable();
}

void FormTable::btnTeaBuild2C()
{
    MainWindow::Mark = 3;
    AdmWin::Mark = 23;
    MainWindow::Table = "select * from curingagent;";
    emit showTable();

}

void FormTable::btnTeaBuild3C()
{
    MainWindow::Mark = 4;
    AdmWin::Mark = 24;
    MainWindow::Table = "select * from curingagentcosting;";
    emit showTable();
}

void FormTable::btnExpBuild1C()
{
    MainWindow::Mark = 5;
    AdmWin::Mark = 25;
    MainWindow::Table = "select * from fiberglass;";
    emit showTable();
}

void FormTable::btnExpBuild2C()
{
    MainWindow::Mark = 6;
    AdmWin::Mark = 26;
    MainWindow::Table = "select * from fiberglasscosting;";
    emit showTable();
}

void FormTable::btnExpBuild3C()
{
    MainWindow::Mark = 7;
    AdmWin::Mark = 27;
    MainWindow::Table = "select * from resin;";
    emit showTable();
}

void FormTable::btnMultHallC()
{
    MainWindow::Mark = 8;
    AdmWin::Mark = 28;
    MainWindow::Table = "select * from resincosting;";
    emit showTable();
}

void FormTable::btnQiuShiC()
{
    MainWindow::Mark = 9;
    AdmWin::Mark = 29;
    MainWindow::Table = "select * from userlogin;";
    emit showTable();
}

void FormTable::btnShareSqrC()
{
    MainWindow::Mark = 10;
    AdmWin::Mark = 30;
    MainWindow::Table = "select * from robot;";
    emit showTable();
}

void FormTable::btnDutyRoomC()
{
    MainWindow::Mark = 11;
    AdmWin::Mark = 31;
    MainWindow::Table = "select * from workdata;";
    emit showTable();
}

void FormTable::btnAllFunc()
{
    MainWindow::Mark = 12;
    AdmWin::Mark = 32;
    emit showTable();
}
