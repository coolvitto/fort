#ifndef CONFSPEEDLIMITMANAGER_H
#define CONFSPEEDLIMITMANAGER_H

#include <QObject>

#include <util/classhelpers.h>
#include <util/ioc/iocservice.h>

#include "confmanagerbase.h"

class SpeedLimit;

class ConfSpeedLimitManager : public ConfManagerBase, public IocService
{
    Q_OBJECT

public:
    explicit ConfSpeedLimitManager(QObject *parent = nullptr);
    CLASS_DELETE_COPY_MOVE(ConfSpeedLimitManager)
};

#endif // CONFSPEEDLIMITMANAGER_H
