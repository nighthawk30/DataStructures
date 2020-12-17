#ifndef _CLOCK_TIME_H
#define _CLOCK_TIME_H

#include <fstream>
#include <string>

using namespace std;

class clock_time
{
  friend bool operator==(clock_time a, clock_time b);//not part of class despite being in class
  friend bool operator!=(clock_time a, clock_time b);
  friend clock_time operator+(clock_time a, clock_time b);
public:
  int get_hour();
  int get_minute();
  int get_second();
  void set_time(int h, int m, int s);
  clock_time();
  clock_time(int h, int m, int s);
private:
  int seconds;
};

ostream& operator<<(ostream &out, clock_time c);
string to_string(clock_time c);


#endif