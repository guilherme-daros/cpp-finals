#include "Serial.hpp"

Serial::Serial(std::string PathSerial, int Baudrate) {
  fd = 0;
  pathSerial = PathSerial;
  baudrate = Baudrate;
}

Serial::~Serial() {}

int Serial::openPort() {
  fd = open(pathSerial.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd < 0) {
    return -1;
  }

  // Acquire non-blocking exclusive lock
  if (flock(fd, LOCK_EX | LOCK_NB) == -1) {
  }

  struct termios serial, serial_old;

  // get parameters associated with the terminal
  if (tcgetattr(fd, &serial) == -1) {
    return -1;
  }

  // SERIAL CONFIGURATION
  /* Set Baud Rate */
  cfsetospeed(&serial, baudrate);
  cfsetispeed(&serial, baudrate);

  serial.c_cflag &= ~PARENB;  // Make 8n1
  serial.c_cflag &= ~CSTOPB;
  serial.c_cflag &= ~CSIZE;
  serial.c_cflag |= CS8;

  serial.c_cflag &= ~CRTSCTS;
  serial.c_cc[VMIN] = 1;
  serial.c_cc[VTIME] = 5;
  serial.c_cflag |= CREAD | CLOCAL;

  /* Make raw */
  cfmakeraw(&serial);

  /* Flush Port, then applies attributes */
  tcflush(fd, TCIFLUSH);

  // set attributes to port
  if (tcsetattr(fd, TCSANOW, &serial) == -1) {
    return -1;
  }

  return 1;
}

int Serial::writePort(std::string o_str) {
  // attempt to send
  if (write(fd, &o_str, std::strlen(o_str.c_str())) == -1) {
    return -1;
  }
  return 1;
};

bool Serial::available() {
  int bytes;
  ioctl(fd, FIONREAD, &bytes);

  if (bytes > 0)
    return true;
  else
    return false;
}

std::string Serial::readPort() {
  int bytes;
  std::string i_str;

  ioctl(fd, FIONREAD, &bytes);

  if (bytes > 0) {
    char c;
    while (c != '$') {
      read(fd, &c, 1);
    }

    while (c != '\n') {
      read(fd, &c, 1);
      i_str += c;
    }
  }
  return i_str;
};

int Serial::closePort() {
  tcflush(fd, TCIOFLUSH);
  return 1;
}