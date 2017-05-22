#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <ifaddrs.h>

#include <string>

class NetworkInterface {
  public:
    // ----------------------- Type Definitions ----------------------

    // ----------------- Construction/Destruction --------------------
    NetworkInterface(const struct ifaddrs* ifa);

    // ------------------------- Interface ---------------------------
    const std::string& getName() const;

  private:
    // ----------------------- Type Definitions ----------------------

    // ------------------------- Interface ---------------------------
    void initialize();

    // ------------------------ Data Members -------------------------

    // The underlying network interface structure
    const struct ifaddrs* mIfp;

    // Interface name
    std::string mName;
};
