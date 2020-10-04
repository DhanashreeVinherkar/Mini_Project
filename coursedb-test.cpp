#include "course.h"
#include "educourse.h"
#include "coursedb.h"
#include <gtest/gtest.h>
namespace {
class EduCourseDbTest : public ::testing::Test {

  protected:
    void SetUp() {
        courses.addCourse(12, 13, 30, 30, "1011058", "Business Finance", 2, 2000);
        courses.addCourse(14, 15, 15, 5, "192870", "Business Finance", 3, 2500);
        courses.addCourse(13, 15, 5, 0, "739964", "Graphic Design", 4, 3000);
        courses.addCourse(10, 14, 0, 0, "403100", "Web Development", 5, 3500);
        courses.addCourse(11, 12, 15, 20, "476268", "Business Finance", 2, 2500);
        courses.addCourse(9, 12, 15, 7, "1167710", "Musical Instruments", 1, 1500);
    }
    void TearDown() {}
    EduCourseDb courses;
};
TEST_F(EduCourseDbTest, AddCourseTest) {
    courses.addCourse(9, 12, 15, 7, "592338", "Musical Instruments", 1, 1500);
    EXPECT_NE((Course*)NULL, courses.findCourseById("592338"));
    EXPECT_EQ(7, courses.countAll());
}
TEST_F(EduCourseDbTest, RemoveCourseTest) {
    courses.removeCourse("403100");
    EXPECT_EQ(NULL, courses.findCourseById("403100"));
    EXPECT_EQ(5, courses.countAll());
}
TEST_F(EduCourseDbTest, CountTest) {
    EXPECT_EQ(6, courses.countAll());
}
TEST_F(EduCourseDbTest, CountBySubjectTest) {
    int count = courses.countCoursesBySubject("Business Finance");
    EXPECT_EQ(3, count);
}
TEST_F(EduCourseDbTest, MaxTimeTest) {
    double MaxTime = courses.computeMaxTime();
    EXPECT_EQ(14400, MaxTime);
    double MinTime = courses.computeMinTime();
    EXPECT_EQ(3000, MinTime);
}
TEST_F(EduCourseDbTest, AnotherTest) {
    courses.addCourse(10, 2, 15, 0, "975046", "Web Development", 5, 3200);
    courses.addCourse(11, 1, 15, 10, "564966", "Business Finance", 2, 2500);
    int count = courses.countCoursesBySubject("Web Development");
    double maxLectures = courses.computeMaxLecture();
    double maxPrice = courses.computeMaxPrice();
    EXPECT_EQ(8, courses.countAll());
    EXPECT_EQ(2, count);
    EXPECT_EQ(5, maxLectures);
    EXPECT_EQ(3500, maxPrice);
}
}
