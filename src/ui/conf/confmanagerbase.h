#ifndef CONFMANAGERBASE_H
#define CONFMANAGERBASE_H

#include <QObject>

#include <sqlite/sqlite_types.h>

class ConfManager;
class FirewallConf;

class ConfManagerBase : public QObject
{
    Q_OBJECT

public:
    explicit ConfManagerBase(QObject *parent = nullptr);

    ConfManager *confManager() const;
    FirewallConf *conf() const;
    SqliteDb *sqliteDb() const;

protected:
    bool beginTransaction();
    void commitTransaction(bool &ok);
};

#endif // CONFMANAGERBASE_H
