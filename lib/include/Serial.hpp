#include <fcntl.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <string>

class Serial {
 public:
  Serial(std::string paramPathSerial, int paramBaudrate);
  ~Serial();

  int openPort();
  int writePort(std::string o_str);

  std::string readPort();

  bool available();

  int closePort();

 private:
  std::string pathSerial;
  int baudrate;

  // filedescriptors
  int fd;
};