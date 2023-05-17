#include "qmysqlquerymodel.h"

#include <QSqlQuery>
#include <QDebug>

QMySqlQueryModel::QMySqlQueryModel(QObject *parent) : QSqlQueryModel(parent)
{

}

//更改数据显示样式，使得居中显示
QVariant QMySqlQueryModel::data(const QModelIndex &index, int role) const
{

    QVariant value=QSqlQueryModel::data(index,role);

    if(role ==  Qt::TextAlignmentRole )
       {
           value   =   (Qt::AlignCenter);
           return value;
       }
       return value;

}
