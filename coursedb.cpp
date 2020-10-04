#include<iostream>
#include "course.h"
#include "educourse.h"
#include "coursedb.h"
#include <list>
#include<iterator>
using namespace std;

void EduCourseDb::addCourse(int shour, int ehour, int smins, int emins, string courseId, string subject, int lect, double price) {
    courses.push_back(EduCourse(shour, ehour, smins, emins, courseId, subject, lect, price));
}
void EduCourseDb::removeCourse(string id) {
    std::list<EduCourse> :: iterator iter;
    for(iter=courses.begin(); iter!=courses.end(); iter++) {
        if (iter->getCourseId() == id) {
            courses.erase(iter);
            break;
        }
    }
}
EduCourse* EduCourseDb::findCourseById(string id) {
    std::list<EduCourse>::iterator iter;
    for (iter=courses.begin(); iter!=courses.end(); iter++) {
        if (id == iter->getCourseId()) {
            return &(*iter);
        }
    }
    return NULL;
}
int EduCourseDb::countCoursesBySubject(string subject) {
    int count=0;
    std::list<EduCourse> ::iterator iter;
    for(iter=courses.begin(); iter!=courses.end(); iter++) {
        if (iter->getSubject() == subject)
            count++;
    }
    return count;
}
int EduCourseDb::countAll() {
    return courses.size();
}
double EduCourseDb::computeMaxLecture() {
    std::list<EduCourse> :: iterator iter = courses.begin();
    double maxLectures = iter->getNumberLectures();
    iter++;
    for(; iter!= courses.end(); ++iter) {
        if(maxLectures < iter->getNumberLectures()) {
            maxLectures = iter->getNumberLectures();
        }
    }
    return (maxLectures);
}
double EduCourseDb::computeMaxPrice() {
    std::list<EduCourse> :: iterator iter = courses.begin();
    double maxPrice = iter->getPrice();
    iter++;
    for(; iter!= courses.end(); ++iter) {
        if(maxPrice < iter->getPrice()) {
            maxPrice = iter->getPrice();
        }
    }
    return (maxPrice);
}

double EduCourseDb::computeMaxTime() {
    std::list<EduCourse> :: iterator iter = courses.begin();
    double maxTime = iter->computeDuration();
    iter++;
    for(; iter!= courses.end(); ++iter) {
        if(maxTime < iter->computeDuration()) {
            maxTime = iter->computeDuration();
        }
    }
    return (maxTime);
}
double EduCourseDb::computeMinTime() {
    std::list<EduCourse> :: iterator iter = courses.begin();
    double minTime = iter->computeDuration();
    iter++;
    for(; iter!= courses.end(); ++iter) {
        if(minTime > iter->computeDuration()) {
            minTime = iter->computeDuration();
        }
    }
    return (minTime);
}


