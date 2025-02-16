#ifndef CONFRULEMANAGER_H
#define CONFRULEMANAGER_H

#include <QObject>

#include <sqlite/sqlite_types.h>

#include <conf/rule.h>
#include <util/classhelpers.h>
#include <util/conf/confruleswalker.h>
#include <util/ioc/iocservice.h>

class ConfManager;

class ConfRuleManager : public QObject, public ConfRulesWalker, public IocService
{
    Q_OBJECT

public:
    explicit ConfRuleManager(QObject *parent = nullptr);
    CLASS_DELETE_COPY_MOVE(ConfRuleManager)

    ConfManager *confManager() const;
    SqliteDb *sqliteDb() const;

    QString ruleNameById(int ruleId);

    void loadRuleSet(Rule &rule, QStringList &ruleSetNames);
    void saveRuleSet(Rule &rule);

    int rulesCountByType(Rule::RuleType ruleType);
    bool checkRuleSetValid(int ruleId, int subRuleId, int extraDepth = 0);

    virtual bool addOrUpdateRule(Rule &rule);
    virtual bool deleteRule(int ruleId);
    virtual bool updateRuleName(int ruleId, const QString &ruleName);
    virtual bool updateRuleEnabled(int ruleId, bool enabled);

    bool walkRules(WalkRulesArgs &wra, const std::function<walkRulesCallback> &func) const override;

    static void walkRulesMapByStmt(WalkRulesArgs &wra, SqliteStmt &stmt);

    void updateDriverRules();

signals:
    void ruleAdded();
    void ruleRemoved(int ruleId, int appRulesCount);
    void ruleUpdated(int ruleId);

private:
    void walkRulesMap(WalkRulesArgs &wra) const;
    bool walkRulesLoop(const std::function<walkRulesCallback> &func) const;
    bool walkGlobalRule(const std::function<walkRulesCallback> &func, quint16 ruleId) const;

    static void fillRule(Rule &rule, const SqliteStmt &stmt);

    bool updateDriverRuleFlag(int ruleId, bool enabled);

    bool beginTransaction();
    void commitTransaction(bool &ok);
};

#endif // CONFRULEMANAGER_H
