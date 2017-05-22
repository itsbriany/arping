#pragma once

#include <string>
#include <ifaddrs.h>

class NetworkInterface {
  public:
    // ----------------------- Type Definitions ----------------------

    // ----------------- Construction/Destruction --------------------
    NetworkInterface(struct ifaddrs* address);

    // ------------------------- Interface ---------------------------
    const std::string& getName() const;

  private:
    // ----------------------- Type Definitions ----------------------

    // ------------------------- Interface ---------------------------
    void initialize();

    // ------------------------ Data Members -------------------------

    // The underlying network interface structure
    struct ifaddrs* mIfp;

    // Interface name
    std::string mName;
};
