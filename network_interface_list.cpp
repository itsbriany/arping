#include <iostream>

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
  iterator end = mInterfaces.end();
  for (; it != end; ++it) {
    std::shared_ptr<NetworkInterface> interface = *it;
    std::cout << interface->getName() << std::endl;
  }
}

void NetworkInterfaceList::initialize()
{
  int32_t successful = 0;
  if (getifaddrs(&mIfap) != successful) {
    std::cout << strerror(errno) << std::endl;
    std::exit(EXIT_FAILURE);
  }

  struct ifaddrs *address = nullptr;
  for (address = mIfap; address; address = address->ifa_next) {
    addInterfaceAddress(address);
  }
}

void NetworkInterfaceList::addInterfaceAddress(struct ifaddrs* address)
{
  mInterfaces.emplace_back(std::make_shared<NetworkInterface>(address));
}
