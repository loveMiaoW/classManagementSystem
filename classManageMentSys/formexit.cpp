#include "formexit.h"
#include "ui_formexit.h"


FormExit::FormExit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormExit)
{
    ui->setupUi(this);

    ui->label->setGeometry(0,0,180,2000);
    ui->label->setStyleSheet("QLabel{background-color:rgb(61,75,102);}");

    ui->pushButton->setCheckable(true);

    ui->pushButton->setAutoExclusive(true);

    ui->pushButton->setGeometry(20,10,140,40);

    ui->pushButton->setText(tr("安全退出系统"));

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(BtnC()));
}

FormExit::~FormExit()
{
    delete ui;
}

void FormExit::BtnC()
{
    emit ExitApp();
}
