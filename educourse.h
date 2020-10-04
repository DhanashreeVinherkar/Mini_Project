#ifndef __EDUCOURSE_H
#define __EDUCOURSE_H

#include"course.h"
using namespace std;

class EduCourse: public Course {
    string m_courseId;
    string m_subject;
    int m_numberLectures;
    double m_price;
  public:
    EduCourse();
    EduCourse(int, int, int, int, string, string, int, double);
    double computeDuration() override;
    string getCourseId();
    string getSubject();
    int getNumberLectures();
    double getPrice();
};
#endif
