#include "Clock.h"

string Clock::getCurrentTime()const  {
    auto now = system_clock::now();
    auto in_time_t = system_clock::to_time_t(now);
    tm ltm;
#ifdef _WIN32 
    localtime_s(&ltm, &in_time_t);
#else 
#endif

    stringstream ss;
    ss << setfill('0') << setw(2) << ltm.tm_hour << ":"
       << setfill('0') << setw(2) << ltm.tm_min << ":"
       << setfill('0') << setw(2) << ltm.tm_sec;

    return ss.str();
}