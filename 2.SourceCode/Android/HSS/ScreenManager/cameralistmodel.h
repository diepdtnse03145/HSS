#ifndef CAMERALISTMODEL_H
#define CAMERALISTMODEL_H

#include <QAbstractListModel>
#include <vector>

class CameraListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    CameraListModel(QObject* parent = 0);

    enum CameraListRole{
        NameRole  = Qt::UserRole + 1,
        UrlRole
    };

    void add(QString name, QString url);

public slots:
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    void clear();

protected:
    QHash<int, QByteArray> roleNames() const;
    std::vector<std::pair<QString, QString>> _cameraList;
};

#endif // CAMERALISTMODEL_H
