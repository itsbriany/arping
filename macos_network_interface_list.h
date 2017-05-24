#pragma once

#include "network_interface_list.h"

class MacOSNetworkInterfaceList : public NetworkInterfaceList {
  public:
    // ----------------- Construction/Destruction --------------------
    MacOSNetworkInterfaceList();
    ~MacOSNetworkInterfaceList() override;
};
