#include"course.h"
#include"educourse.h"
#include<gtest/gtest.h>
namespace {
class CourseTest : public ::testing::Test {

  protected:
    void SetUp() { // override {
        ptr = new EduCourse(10, 11, 30, 30, "1070968", "Business Finance", 1, 1500);
    }
    void TearDown() {
        delete ptr;
    }
    Course *ptr;
};

TEST_F(CourseTest, DefaultConstructor) {
    EduCourse ec;
    EXPECT_EQ(0, ec.getCourseId().length());
    EXPECT_EQ(0, ec.getSubject().length());
    EXPECT_EQ(0, ec.getNumberLectures());
    EXPECT_EQ(0, ec.getPrice());
    EXPECT_EQ(0, ec.getStartHour());
    EXPECT_EQ(0, ec.getEndHour());
    EXPECT_EQ(0, ec.getStartMins());
    EXPECT_EQ(0, ec.getEndMins());
}
TEST_F(CourseTest, ParameterizedConstructor) {
    EduCourse *fptr = dynamic_cast<EduCourse*>(ptr);
    EXPECT_EQ(10, fptr->getStartHour());
    EXPECT_EQ(11, fptr->getEndHour());
    EXPECT_EQ(30, fptr->getStartMins());
    EXPECT_EQ(30, fptr->getEndMins());
    EXPECT_STREQ("1070968", fptr->getCourseId().c_str());
    EXPECT_STREQ("Business Finance", fptr->getSubject().c_str());
    EXPECT_EQ(1, fptr->getNumberLectures());
    EXPECT_EQ(1500, fptr->getPrice());
}
TEST_F(CourseTest, ComputationTest) {
    EXPECT_EQ(3600, ptr->computeDuration());    //in seconds
}
TEST_F(CourseTest, AnotherTest) {
    EduCourse ec(10, 12, 30, 15, "1113822", "Graphic Design", 2, 3000);
    Course *pt = &ec;
    EXPECT_EQ(10, ec.getStartHour());
    EXPECT_EQ(12, ec.getEndHour());
    EXPECT_EQ(30, ec.getStartMins());
    EXPECT_EQ(15, ec.getEndMins());
    EXPECT_STREQ("1113822", ec.getCourseId().c_str());
    EXPECT_STREQ("Graphic Design", ec.getSubject().c_str());
    EXPECT_EQ(2, ec.getNumberLectures());
    EXPECT_EQ(3000, ec.getPrice());
    EXPECT_EQ(6300, pt->computeDuration());
    //EXPECT_STREQ("1:0", ptr->computeDuration().c_str());
}
}
