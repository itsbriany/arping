#pragma once

#include "network_interface.h"

class LinuxNetworkInterfaceList : public NetworkInterface {
  public:
    // ----------------- Construction/Destruction --------------------
    LinuxNetworkInterfaceList();
    ~LinuxNetworkInterfaceList() override;

  private:
    // ------------------------- Interface ---------------------------
    void initialize();
    void addInterfaceAddress(const struct ifaddrs* ifa);
    bool isLinkLayer(const struct ifaddrs* ifa) const;

    // ------------------------ Data Members -------------------------
    // The underlying network interface list structure
    struct ifaddrs* mIfap;
};
