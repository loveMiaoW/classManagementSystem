#ifndef QMYSQLQUERYMODEL_H
#define QMYSQLQUERYMODEL_H

//#include <QObject>
#include <QSqlQueryModel>

class QMySqlQueryModel : public QSqlQueryModel
{
public:
    QMySqlQueryModel(QObject *parent);

    QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;

};

#endif // QMYSQLQUERYMODEL_H

