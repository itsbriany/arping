#include <iostream>

#include "network_interface_list.h"


NetworkInterfaceList::NetworkInterfaceList()
{
}

NetworkInterfaceList::~NetworkInterfaceList()
{
}

void NetworkInterfaceList::show()
{
  iterator it = mInterfaces.begin();
  iterator end = mInterfaces.end(); for (; it != end; ++it) {
    std::shared_ptr<NetworkInterface> interface = *it;
    std::cout << interface->getMacAddress() << std::endl;
  }
}

NetworkInterfaceList::NetworkInterfaces& NetworkInterfaceList::interfaces()
{
  return mInterfaces;
}
