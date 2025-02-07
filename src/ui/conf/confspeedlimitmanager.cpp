#include "confspeedlimitmanager.h"

#include <QLoggingCategory>

#include <sqlite/dbquery.h>
#include <sqlite/sqlitedb.h>
#include <sqlite/sqlitestmt.h>

#include <conf/speedlimit.h>
#include <driver/drivermanager.h>
#include <util/conf/confbuffer.h>
#include <util/conf/confutil.h>
#include <util/ioc/ioccontainer.h>

#include "confmanager.h"

namespace {

const QLoggingCategory LC("confSpeedLimit");

const char *const sqlInsertSpeedLimit = "INSERT INTO speed_limit(limit_id, enabled, inbound,"
                                        "    kbps, packet_loss, latency, bufsize, name)"
                                        "  VALUES(?1, ?2, ?3, ?4, ?5, ?6, ?7, ?8);";

const char *const sqlUpdateSpeedLimit = "UPDATE speed_limit"
                                        "  SET enabled = ?2, inbound = ?3, kbps = ?4,"
                                        "    packet_loss = ?5, latency = ?6,"
                                        "    bufsize = ?7, name = ?8"
                                        "  WHERE limit_id = ?1;";

const char *const sqlDeleteSpeedLimit = "DELETE FROM speed_limit WHERE limit_id = ?1"
                                        "  RETURNING inbound;";

const char *const sqlDeleteAppInSpeedLimit = "UPDATE app"
                                             "  SET in_limit_id = NULL"
                                             "  WHERE in_limit_id = ?1;";

const char *const sqlDeleteAppOutSpeedLimit = "UPDATE app"
                                              "  SET out_limit_id = NULL"
                                              "  WHERE out_limit_id = ?1;";

const char *const sqlUpdateSpeedLimitName = "UPDATE speed_limit SET name = ?2 WHERE limit_id = ?1;";

const char *const sqlUpdateSpeedLimitEnabled =
        "UPDATE speed_limit SET enabled = ?2 WHERE limit_id = ?1;";

}

ConfSpeedLimitManager::ConfSpeedLimitManager(QObject *parent) : ConfManagerBase(parent) { }
