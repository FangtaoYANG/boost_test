#pragma once

#include <string>


struct Course
{
	unsigned int		course_num;
	unsigned int		course_hour;
	std::string		course_name;


	enum CourseNum_Enum
	{
		CourseNum_CPP = 0,
		CourseNum_English,
		CourseNum_Maths,
		CourseNum_Computer,
		CourseNum_DataStructure
	};

	static	const Course courses[5];

	Course(unsigned int num, unsigned int hour, std::string name);
};

Course::Course(unsigned int num, unsigned int hour, std::string name) :
	course_num(num),
	course_hour(hour),
	course_name(name)
{
}


struct Student
{
	unsigned int		stu_num;
	std::string		stu_name;
	unsigned int		stu_age;
	std::set<Course>	stu_couselist;

	friend Student CreateStudent(const std::string& name, unsigned int age);

private:
	Student(unsigned int num, const std::string& name, unsigned int age);
};

Student::Student(unsigned int num, const std::string& name, unsigned int age) :
	stu_num(num),
	stu_name(name),
	stu_age(age)
{
}



