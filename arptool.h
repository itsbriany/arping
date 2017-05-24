#pragma once

#ifndef __APPLE__
#include "linux_network_interface_list.h"
#else
#include "macos_network_interface_list.h"
#endif

class Arptool {
  public:
    Arptool(int argc, const char* argv[]);
    void run();

  private:
#ifndef __APPLE__
    LinuxNetworkInterfaceList mInterfaces;
#else
    MacOSNetworkInterfaceList mInterfaces;
#endif
};
