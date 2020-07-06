//
// Created by Vineet Ghatge Hemantkumar on 2020-07-05.
//
#include <string>
#include "format.h"

using std::string;
using std::to_string;

#define HOUR 3600
#define MINUTE 60

string Format::ElapsedTime(long seconds)
{
    long time_hours = seconds / HOUR;
    long time_left = seconds % HOUR;
    long time_minutes = {time_left / MINUTE};
    long time_seconds = {time_left % MINUTE};

    string time_hours_str = ConvertToString(time_hours);
    string time_minutes_str = ConvertToString(time_minutes);
    string time_seconds_str = ConvertToString(time_seconds);

    return time_hours_str + ":" + time_minutes_str + ":" + time_seconds_str;
}

string Format::ConvertToString(long value) {
    return (value < 10) ? ("0" + to_string(value)) : to_string(value);
}