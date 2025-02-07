#include "confmanagerbase.h"

#include <sqlite/sqlitedb.h>

#include <util/ioc/ioccontainer.h>

#include "confmanager.h"

ConfManagerBase::ConfManagerBase(QObject *parent) : QObject(parent) { }

ConfManager *ConfManagerBase::confManager() const
{
    return IoC<ConfManager>();
}

FirewallConf *ConfManagerBase::conf() const
{
    return confManager()->conf();
}

SqliteDb *ConfManagerBase::sqliteDb() const
{
    return confManager()->sqliteDb();
}

bool ConfManagerBase::beginTransaction()
{
    return sqliteDb()->beginWriteTransaction();
}

void ConfManagerBase::commitTransaction(bool &ok)
{
    ok = sqliteDb()->endTransaction(ok);
}
