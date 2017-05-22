#pragma once

#include <list>
#include <memory>
#include "network_interface.h"

class NetworkInterfaceList {
  private:
    // ----------------------- Type Definitions ----------------------
    typedef std::list<std::shared_ptr<NetworkInterface>> NetworkInterfaces;

  public:
    // ----------------------- Type Definitions ----------------------
    typedef NetworkInterfaces::iterator iterator;
    typedef NetworkInterfaces::const_iterator const_iterator;

    // ----------------- Construction/Destruction --------------------
    NetworkInterfaceList();
    ~NetworkInterfaceList();

    // ------------------------- Interface ---------------------------
    // Present the list of network interfaces to the user
    void show();

  private:
    // ------------------------- Interface ---------------------------
    void initialize();
    void addInterfaceAddress(const struct ifaddrs* ifa);
    bool isLinkLayer(const struct ifaddrs* ifa) const;

    // ------------------------ Data Members -------------------------
    // The list of dynamically allocated interface addresses
    NetworkInterfaces mInterfaces;

    // The underlying network interface list structure
    struct ifaddrs* mIfap;
};
