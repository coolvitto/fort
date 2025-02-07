#ifndef CONFSPEEDLIMITMANAGER_H
#define CONFSPEEDLIMITMANAGER_H

#include <QObject>

#include <sqlite/sqlite_types.h>

#include <util/classhelpers.h>
#include <util/ioc/iocservice.h>

class ConfManager;
class SpeedLimit;

class ConfSpeedLimitManager : public QObject, public IocService
{
    Q_OBJECT

public:
    explicit ConfSpeedLimitManager(QObject *parent = nullptr);
    CLASS_DELETE_COPY_MOVE(ConfSpeedLimitManager)

    ConfManager *confManager() const;
    SqliteDb *sqliteDb() const;

signals:
};

#endif // CONFSPEEDLIMITMANAGER_H
