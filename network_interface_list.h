#pragma once

#include <list>
#include <memory>

#include "network_interface.h"

class NetworkInterfaceList {
  protected:
    // ----------------------- Type Definitions ----------------------
    typedef std::list<std::shared_ptr<NetworkInterface>> NetworkInterfaces;

  public:
    // ----------------------- Type Definitions ----------------------
    typedef NetworkInterfaces::iterator iterator;
    typedef NetworkInterfaces::const_iterator const_iterator;

    // ----------------- Construction/Destruction --------------------
    NetworkInterfaceList();
    virtual ~NetworkInterfaceList();

    // ------------------------- Interface ---------------------------
    // Present the list of network interfaces to the user
    void show();

  protected:
    NetworkInterfaces& interfaces();

  private:
    // ------------------------ Data Members -------------------------
    // The list of dynamically allocated interface addresses
    NetworkInterfaces mInterfaces;
};
