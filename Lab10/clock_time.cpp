#include "clock_time.h"

int clock_time::get_hour()
{
  return seconds / 3600;
}

int clock_time::get_minute()
{
  return (seconds % 3600) / 60;
}

int clock_time::get_second()
{
  return seconds % 60;
}

void clock_time::set_time(int h, int m, int s)
{
  seconds = h * 3600 + m * 60 + s;
  int fix = seconds % (60 * 60 * 24);
  if (seconds < 0)//if it is negative
  {
    seconds = 60 * 60 * 24 + fix;//add the negative remainder to the maximum time
  }
  else
  {
    seconds = fix;
  }
}

clock_time::clock_time()
{
  set_time(0, 0, 0);
}

clock_time::clock_time(int h, int m, int s)
{
  set_time(h, m, s);
}

ostream& operator<<(ostream &out, clock_time c)
{
  return out << to_string(c);
}

string to_string(clock_time c)
{
  string output = to_string(c.get_hour()) + ":";
  if (c.get_minute() < 10)
  {
    output += "0";
  }
  output += to_string(c.get_minute()) + ":";
  if (c.get_second() < 10)
  {
    output += "0";
  }
  output += to_string(c.get_second());

  return output;
}

bool operator==(clock_time a, clock_time b)
{
  return (a.seconds == b.seconds);
}

bool operator!=(clock_time a, clock_time b)
{
  return (a.seconds != b.seconds);
}

clock_time operator+(clock_time a, clock_time b)
{
  return clock_time(0, 0, a.seconds + b.seconds);
}