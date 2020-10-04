#ifndef __COURSEDB_H
#define __COURSEDB_H
#include<list>
#include<iterator>

class EduCourseDb {
    std::list<EduCourse> courses;
  public:
    void addCourse(int, int, int, int, string, string, int, double);
    void removeCourse(string);
    EduCourse* findCourseById(string);
    int countCoursesBySubject(string);
    int countAll();
    double computeMaxLecture();
    double computeMaxPrice();
    double computeMaxTime();
    double computeMinTime();
};



#endif
