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
    int readPort(std::string i_str);
    int sendPort(std::string testString);
    int closePort();

   private:
    std::string pathSerial;
    int baudrate;

    // filedescriptors
    int fd;
};