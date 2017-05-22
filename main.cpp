#include "arptool.h"

int main(int argc, const char* argv[])
{
  Arptool arptool(argc, argv);
  arptool.run();
  return 0;
}
