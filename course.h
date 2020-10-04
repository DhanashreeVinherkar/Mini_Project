#ifndef __COURSE_H
#define __COURSE_H

#include<iostream>
using namespace std;

class Course {
    int m_startHour;
    int m_endHour;
    int m_startMins;
    int m_endMins;
  public:
    Course();
    Course(int, int, int, int);
    virtual double computeDuration()=0;
    int getStartHour();
    int getEndHour();
    int getStartMins();
    int getEndMins();
};

#endif
