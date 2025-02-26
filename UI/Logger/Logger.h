
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include "../../lib/lib.h"

enum Colors
{
    Default = 7,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Pink = 5,
    Yellow = 6,
    White = 7,
    BrightBlue = 9,
    BrightGreen = 10,
    BrightCyan = 11,
    BrightRed = 12,
    BrightPink = 13,
    BrightYellow = 14,
    BrightWhite = 15
};

class Logger
{
public:
    static bool is_print_logs;

    static const unsigned short _debug = 10;
    static const unsigned short _info = 11;
    static const unsigned short _error = 12;
    static const unsigned short _warning = 14;
    static const unsigned short _default = 7;

    static void debug(std::string message);
    static void info(std::string message);
    static void error(std::string message);
    static void warning(std::string message);
    static void log(std::string message, Colors color);
};

#endif
