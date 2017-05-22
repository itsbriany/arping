#include "network_interface.h"

NetworkInterface::NetworkInterface(struct ifaddrs* address)
  : mIfp(address)
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
