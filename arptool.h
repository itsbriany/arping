#pragma once

#include "network_interface_list.h"

class Arptool {
  public:
    Arptool(int argc, const char* argv[]);
    void run();

  private:
    NetworkInterfaceList mInterfaces;
};
