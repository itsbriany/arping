#include <iostream>
#include <net/if_arp.h>

#include "linux_network_interface.h"
#include "linux_network_interface_list.h"

LinuxNetworkInterfaceList::LinuxNetworkInterfaceList()
  : mIfap(nullptr)
{
  initialize();
}

LinuxNetworkInterfaceList::~LinuxNetworkInterfaceList()
{
  freeifaddrs(mIfap);
}

void LinuxNetworkInterfaceList::initialize()
{
  if (getifaddrs(&mIfap) == -1) {
    std::cout << strerror(errno) << std::endl;
    std::exit(EXIT_FAILURE);
  }

  struct ifaddrs *ifa = nullptr;
  for (ifa = mIfap; ifa; ifa = ifa->ifa_next) {
    addInterfaceAddress(ifa);
  }
}

void LinuxNetworkInterfaceList::addInterfaceAddress(const struct ifaddrs* ifa)
{
  if (isLinkLayer(ifa)) {
    mInterfaces.emplace_back(std::make_shared<LinuxNetworkInterface>(ifa));
  }
}

bool LinuxNetworkInterfaceList::isLinkLayer(const struct ifaddrs* ifa) const
{
  return ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_LINK;
}
