#include"educourse.h"
#include<iostream>
using namespace std;

EduCourse::EduCourse():
    m_courseId{""}, m_subject{""}, m_numberLectures{0}, m_price{0} {}
EduCourse::EduCourse(int shour, int ehour, int smins, int emins, string courseId, string subject, int lect, double price):
    Course(shour, ehour, smins, emins), m_courseId{courseId}, m_subject{subject}, m_numberLectures{lect}, m_price{price} {}
double EduCourse::computeDuration() {
    int hr1 = Course::getStartHour();
    int hr2 = Course::getEndHour();
    int min1 = Course::getStartMins();
    int min2 = Course::getEndMins();
    double result;
    if (hr2 < hr1) {
        int sum1 = hr1 * 3600 + min1 *60;
        int sum2 = (hr2 + 24)*3600 + min2 * 60;
        result = sum2 - sum1;
    } else {
        int sum1 = hr1 * 3600 + min1 *60;
        int sum2 = hr2 *3600 + min2 * 60;
        result = sum2 - sum1;
    }
    return result;
}
/*string EduCourse::getCourseId() {
    return m_courseId;
}*/
string EduCourse::getSubject() {
    return m_subject;
}
int EduCourse::getNumberLectures() {
    return m_numberLectures;
}
double EduCourse::getPrice() {
    return m_price;
}
