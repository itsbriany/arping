#include <sys/ioctl.h>
#include <net/if.h>
#include <iostream>

#include "linux_network_interface.h"


LinuxNetworkInterface::LinuxNetworkInterface(const struct ifaddrs* ifa)
  : mIfp(ifa)
{
  initialize();
}

LinuxNetworkInterface::~LinuxNetworkInterface()
{
}

const std::string& LinuxNetworkInterface::getMacAddress() const
{
  return mName;
}

void LinuxNetworkInterface::initialize()
{
  mName = mIfp->ifa_name;
  setHardwareAddress();
}

void LinuxNetworkInterface::setHardwareAddress()
{
  struct ifreq ifr;
  if (mName.size() >= sizeof(ifr.ifr_name)) {
    std::cout << "Interface name " << mName << " is too long" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  size_t interfaceNameSize = mName.size();
  memcpy(ifr.ifr_name, mName.data(), interfaceNameSize);
  ifr.ifr_name[interfaceNameSize] = 0;

  int fd = socket(PF_LOCAL, SOCK_DGRAM, 0);
  if (fd == -1) {
    std::cout << strerror(errno) << std::endl;
  }

  // TODO This still needs work
  if (ioctl(fd, SIOCGIFHWADDR, &ifr) == -1) {
    close(fd);
    std::cout << strerror(errno) << std::endl;
    std::exit(EXIT_FAILURE);
  }
  close(fd);
}
