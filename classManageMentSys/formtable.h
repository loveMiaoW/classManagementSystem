#ifndef FORMTABLE_H
#define FORMTABLE_H

#include <QWidget>

namespace Ui {
class FormTable;
}

class FormTable : public QWidget
{
    Q_OBJECT

public:
    explicit FormTable(QWidget *parent = nullptr);
    ~FormTable();
    void classInfoInit();
    void studentInfoInit();
    void teacherInfoInit();

signals:
    void showTable();


private slots:
    void btnTeaBuild1C();
    void btnTeaBuild2C();
    void btnTeaBuild3C();
    void btnExpBuild1C();
    void btnExpBuild2C();
    void btnExpBuild3C();
    void btnMultHallC();
    void btnQiuShiC();
    void btnShareSqrC();
    void btnDutyRoomC();
    void btnAllFunc();

private:
    Ui::FormTable *ui;
};

#endif // FORMTABLE_H
