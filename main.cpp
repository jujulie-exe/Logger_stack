#include "include/Logger.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Logger Class ===" << std::endl;

    std::cout << "\n[Test 1] Default Level (DEBUG)" << std::endl;
    Logger::log(Logger::DEBUG, "This is a DEBUG message");
    Logger::log(Logger::INFO, "This is an INFO message");
    Logger::log(Logger::WARNING, "This is a WARNING message");
    Logger::log(Logger::ERROR, "This is an ERROR message");

    std::cout << "\n[Test 2] Changing Level to WARNING" << std::endl;
    Logger::setLevelLog(Logger::WARNING);
    
    Logger::log(Logger::DEBUG, "This DEBUG message should NOT appear");
    Logger::log(Logger::INFO, "This INFO message should NOT appear");
    Logger::log(Logger::WARNING, "This WARNING message SHOULD appear");
    Logger::log(Logger::ERROR, "This ERROR message SHOULD appear");

    std::cout << "\n[Test 3] Changing Level to ERROR" << std::endl;
    Logger::setLevelLog(Logger::ERROR);

    Logger::log(Logger::WARNING, "This WARNING message should NOT appear");
    Logger::log(Logger::ERROR, "This ERROR message SHOULD appear");

    std::cout << "\n=== End of Test ===" << std::endl;

    return 0;
}
