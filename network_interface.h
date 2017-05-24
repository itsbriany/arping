#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>

#include <string>

class NetworkInterface {
  public:
    // ----------------- Construction/Destruction --------------------
    NetworkInterface();
    virtual ~NetworkInterface();

    // ------------------------- Interface ---------------------------
    virtual const std::string& getMacAddress() const = 0;
};
