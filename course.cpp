#include "course.h"
#include<iostream>
using namespace std;

Course::Course():
    m_startHour{0}, m_endHour{0}, m_startMins{0}, m_endMins{0} {}
Course::Course(int shour, int ehour, int smins, int emins):
    m_startHour{shour}, m_endHour{ehour}, m_startMins{smins}, m_endMins{emins} {}
int Course::getStartHour() {
    return m_startHour;
}
int Course::getEndHour() {
    return m_endHour;
}
int Course::getStartMins() {
    return m_startMins;
}
int Course::getEndMins() {
    return m_endMins;
}
