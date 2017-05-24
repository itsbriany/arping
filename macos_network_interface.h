#pragma once

#include "network_interface.h"

class MacOSNetworkInterface : public NetworkInterface {
  public:
    // ----------------- Construction/Destruction --------------------
    MacOSNetworkInterface();
    ~MacOSNetworkInterface() override;

    // ------------------------- Interface ---------------------------
    const std::string& getMacAddress() const override;

  private:
    // ------------------------- Data Members ------------------------
    std::string mMacAddress;

};
