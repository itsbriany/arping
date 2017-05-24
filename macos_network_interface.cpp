#include "macos_network_interface.h"

MacOSNetworkInterface::MacOSNetworkInterface()
  : mMacAddress("Not implemented")
{
}

MacOSNetworkInterface::~MacOSNetworkInterface()
{
}

const std::string&
MacOSNetworkInterface::getMacAddress() const
{
  return mMacAddress;
}
