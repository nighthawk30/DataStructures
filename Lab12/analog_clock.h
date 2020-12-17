//
// Created by Wit on 11/20/2020.
//

#ifndef LAB12_ANALOG_CLOCK_H
#define LAB12_ANALOG_CLOCK_H

#include "analog_clock.h"

class analog_clock : public unix_clock
{
public:
  analog_clock(unix_clock c) : unix_clock(c) {};
  string get_time()
  {
    string result;
    string topofthemorning = " am";
    // Add correct padding
    if (get_hour() == 12)
    {
      topofthemorning = " pm";
    }
    if (get_hour() > 12)
    {
      result += to_string(get_hour() - 12) + ":";
      topofthemorning = " pm";
    }
    else if (get_hour() == 0)
    {
      result += to_string(12) + ":";
    }
    else
    {
      result += to_string(get_hour()) + ":";
    }

    if (get_minute() < 10)
    {
      result += "0";
    }
    result += to_string(get_minute()) + ":";

    if (get_second() < 10) {
      result += "0";
    }
    result += to_string(get_second());

    result += topofthemorning;

    return result;
  }
};







#endif // LAB12_ANALOG_CLOCK_H
