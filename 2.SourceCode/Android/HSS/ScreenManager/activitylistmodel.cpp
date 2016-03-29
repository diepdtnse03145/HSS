#include "activitylistmodel.h"

ActivityListModel::ActivityListModel(QObject* parent) :
    QAbstractListModel{parent}
{

}

void ActivityListModel::add(QString time, QString value)
{
    _activityList.push_back(std::make_pair(time, value));
}

void ActivityListModel::clear()
{
    _activityList.clear();
}

int ActivityListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return _activityList.size();
}

QHash<int, QByteArray> ActivityListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ValueRole] = "value";
    roles[TimeRole] = "time";
    return roles;
}

QVariant ActivityListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= _activityList.size())
        return QVariant();

    switch (role){
    case ActivityListModel::TimeRole:
        return _activityList[index.row()].first;
    case ActivityListModel::ValueRole:
        return _activityList[index.row()].second;
    }

    return QVariant();

}

