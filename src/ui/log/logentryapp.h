#ifndef LOGENTRYAPP_H
#define LOGENTRYAPP_H

#include "logentry.h"

class LogEntryApp : public LogEntry
{
public:
    explicit LogEntryApp(quint32 pid = 0, const QString &kernelPath = QString());

    FortLogType type() const override { return FORT_LOG_TYPE_APP; }

    bool blocked() const { return m_blocked; }
    void setBlocked(bool blocked) { m_blocked = blocked; }

    bool alerted() const { return m_alerted; }
    void setAlerted(bool alerted) { m_alerted = alerted; }

    quint32 pid() const { return m_pid; }
    void setPid(quint32 pid) { m_pid = pid; }

    QString kernelPath() const { return m_kernelPath; }
    void setKernelPath(const QString &kernelPath) { m_kernelPath = kernelPath; }

    QString path() const;

private:
    bool m_blocked : 1 = true;
    bool m_alerted : 1 = true;
    quint32 m_pid = 0;
    QString m_kernelPath;
};

#endif // LOGENTRYAPP_H
