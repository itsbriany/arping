#include "network_interface.h"

NetworkInterface::NetworkInterface(const struct ifaddrs* ifa)
  : mIfp(ifa)
{
  initialize();
}

const std::string& NetworkInterface::getName() const
{
  return mName;
}

void NetworkInterface::initialize()
{
  mName = mIfp->ifa_name;
}
