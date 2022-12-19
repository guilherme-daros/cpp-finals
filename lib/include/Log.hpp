#pragma once
#include <ctime>
#include <iostream>
#include <string>

void Log(std::string agent, std::string message) {
  char buf[100];
  std::time_t timepoint;
  std::time(&timepoint);
  strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

  std::cout << buf << " [" << agent << "] "
            << "- " << message << std::endl;
}