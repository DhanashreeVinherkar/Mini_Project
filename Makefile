all: all.out 
all.out : course.o educourse.o coursedb.o course-test.o coursedb-test.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
coursedb-test.o: coursedb-test.cpp course.h educourse.h coursedb.h
	g++ $< -c
course-test.o: course-test.cpp course.h educourse.h
	g++ $< -c
coursedb.o : coursedb.cpp coursedb.h educourse.h course.h
	g++ $< -c
educourse.o : educourse.cpp educourse.h course.h
	g++ $< -c    
course.o : course.cpp course.h
	g++ $< -c
clean:
	rm -rf *.o *.out
