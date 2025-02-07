#include "speedlimit.h"

bool SpeedLimit::isNameEqual(const SpeedLimit &o) const
{
    return name == o.name;
}

bool SpeedLimit::isOptionsEqual(const SpeedLimit &o) const
{
    return enabled == o.enabled && inbound == o.inbound && packetLoss == o.packetLoss
            && latency == o.latency && kbps == o.kbps && bufferSize == o.bufferSize;
}
