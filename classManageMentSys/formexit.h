#ifndef FORMEXIT_H
#define FORMEXIT_H

#include <QWidget>

namespace Ui {
class FormExit;
}

class FormExit : public QWidget
{
    Q_OBJECT

public:
    explicit FormExit(QWidget *parent = nullptr);
    ~FormExit();

signals:
    void ExitApp();


private slots:
    void BtnC();



private:
    Ui::FormExit *ui;
};

#endif // FORMEXIT_H
