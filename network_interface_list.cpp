#include <iostream>
#include <net/if_arp.h>

#include "network_interface_list.h"

NetworkInterfaceList::NetworkInterfaceList()
  : mIfap(nullptr)
{
  initialize();
}

NetworkInterfaceList::~NetworkInterfaceList()
{
  freeifaddrs(mIfap);
}

void NetworkInterfaceList::show()
{
  iterator it = mInterfaces.begin();
  iterator end = mInterfaces.end(); for (; it != end; ++it) {
    std::shared_ptr<NetworkInterface> interface = *it;
    std::cout << interface->getName() << std::endl;
  }
}

void NetworkInterfaceList::initialize()
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

void NetworkInterfaceList::addInterfaceAddress(const struct ifaddrs* ifa)
{
  if (isLinkLayer(ifa)) {
    mInterfaces.emplace_back(std::make_shared<NetworkInterface>(ifa));
  }
}

bool NetworkInterfaceList::isLinkLayer(const struct ifaddrs* ifa) const
{
  return ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_LINK;
}
