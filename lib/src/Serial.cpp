#include "Serial.hpp"

Serial::Serial(std::string PathSerial, int Baudrate) {
    fd = 0;
    pathSerial = PathSerial;
    baudrate = Baudrate;
}

Serial::~Serial() {
}

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

    // safe old parameters
    serial_old = serial;
    // SERIAL CONFIGURATION
    /* Set Baud Rate */
    cfsetospeed(&serial, (speed_t)baudrate);
    cfsetispeed(&serial, (speed_t)baudrate);

    //     Setting other Port Stuff
    serial.c_cflag &= ~PARENB;  // Make 8n1
    serial.c_cflag &= ~CSTOPB;
    serial.c_cflag &= ~CSIZE;
    serial.c_cflag |= CS8;

    serial.c_cflag &= ~CRTSCTS;        // no flow control
    serial.c_cc[VMIN] = 1;             // read doesn't block
    serial.c_cc[VTIME] = 5;            // 0.5 seconds read timeout
    serial.c_cflag |= CREAD | CLOCAL;  // turn on READ & ignore ctrl lines

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
int Serial::readPort(std::string i_str) {
    int bytes;
    ioctl(fd, FIONREAD, &bytes);
    std::cout << bytes;
    return 1;
};

int Serial::closePort() {
    close(fd);
    return 1;
}