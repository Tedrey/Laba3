// Logger.cpp
#include "Logger.h"

void Logger::log(const std::string& message) {
    std::ofstream logFile("log.txt", std::ios::app);
    logFile << message << std::endl;
}
