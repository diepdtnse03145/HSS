#ifndef ACTIVITYLISTMODEL_H
#define ACTIVITYLISTMODEL_H

#include <QAbstractListModel>

class ActivityListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ActivityListModel(QObject* parent);
    enum ActivityListRole{
        ValueRole  = Qt::UserRole + 1,
        TimeRole
    };

    void add(QString time, QString value);

public slots:
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    void clear();

protected:
    QHash<int, QByteArray> roleNames() const;
    std::vector<std::pair<QString, QString>> _activityList;

};

#endif // ACTIVITYLISTMODEL_H
