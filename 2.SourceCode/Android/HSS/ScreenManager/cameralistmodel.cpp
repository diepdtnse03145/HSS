#include "cameralistmodel.h"

CameraListModel::CameraListModel(QObject *parent) :
    QAbstractListModel{parent}
{

}

void CameraListModel::add(QString name, QString url)
{
    beginInsertRows(index(_cameraList.size(), 0),
                    _cameraList.size(),
                    _cameraList.size());
    _cameraList.push_back(std::make_pair(name, url));
    endInsertRows();
}

void CameraListModel::clear()
{
    beginResetModel();
    _cameraList.clear();
    endResetModel();
}

int CameraListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return _cameraList.size();
}

QHash<int, QByteArray> CameraListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[UrlRole] = "url";
    return roles;
}

QVariant CameraListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= _cameraList.size())
        return QVariant();

    switch (role){
    case CameraListModel::NameRole:
        return _cameraList[index.row()].first;
    case CameraListModel::UrlRole:
        return _cameraList[index.row()].second;
    }

    return QVariant();
}
