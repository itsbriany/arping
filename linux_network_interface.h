#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <string>

#include "network_interface.h"

class LinuxNetworkInterface : public NetworkInterface {
  public:
    // ----------------- Construction/Destruction --------------------

    LinuxNetworkInterface(const struct ifaddrs* ifa);
    ~LinuxNetworkInterface() override;

    // ------------------------- Interface ---------------------------
    const std::string& getMacAddress() const override;

  private:
    // ----------------------- Type Definitions ----------------------

    // ------------------------- Interface ---------------------------
    void initialize();
    void setHardwareAddress();

    // ------------------------ Data Members -------------------------

    // The underlying network interface structure
    const struct ifaddrs* mIfp;

    // Interface name
    std::string mName;
};
