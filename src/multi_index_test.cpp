
#include <set>
#include <iostream>
#include <algorithm>
#include <utility>

#include "boost/multi_index_container.hpp"
#include "boost/multi_index/member.hpp"
#include "boost/multi_index/ordered_index.hpp"

#include "boost/lambda/lambda.hpp"
#include "boost/function.hpp"

#include "multi_index_test.hpp"


using boost::multi_index_container;
using namespace boost::multi_index;

struct stu_num {};
struct stu_name {};
struct stu_age {};


typedef
boost::multi_index_container<
	Student,
	indexed_by<
	ordered_unique<
	tag<stu_num>, BOOST_MULTI_INDEX_MEMBER(Student, unsigned int, stu_num)>,
	ordered_non_unique<
	tag<stu_name>, BOOST_MULTI_INDEX_MEMBER(Student, std::string, stu_name)>,
	ordered_non_unique<
	tag<stu_age>, BOOST_MULTI_INDEX_MEMBER(Student, unsigned int, stu_age)>
	>
> StudentContainer;

Student CreateStudent(const std::string& name, unsigned int age)
{
	static unsigned int currentnum = 1;
	return Student(currentnum++, name, age);
}

std::ostream& operator<<(std::ostream& os, const Course& cou)
{
	os << "course number:" << cou.course_num << "\tcourse name" << cou.course_name << "\tcourse hours:" << cou.course_hour << "\n";

	return os;
}

std::ostream& operator<<(std::ostream& os, const Student& stu)
{
	os << "student number:" << stu.stu_num << "\tstudent name:" << stu.stu_name << "\tstudent age" << stu.stu_age << "\n";
	os << "Main course：\n";
	// lambda
	std::for_each(stu.stu_couselist.begin(), stu.stu_couselist.end(), std::cout << boost::lambda::_1);
	return os;
}

bool operator<(const Course& lhs, const Course& rhs)
{
	return lhs.course_num < rhs.course_num;
}

template<typename Tag, typename MultiIndexContainer>
void print_out_by(const MultiIndexContainer& s)
{
	/* obtain a reference to the index tagged by Tag */
	const typename boost::multi_index::index<MultiIndexContainer, Tag>::type& i = get<Tag>(s);
	typedef typename MultiIndexContainer::value_type value_type;
	/* dump the elements of the index to cout */
	std::copy(i.begin(), i.end(), std::ostream_iterator<value_type>(std::cout));
}

const Course Course::courses[5] = {
	Course(CourseNum_CPP, 80, "C++ programming design"),
	Course(CourseNum_English, 60, "University English"),
	Course(CourseNum_Maths, 45, "Discrete mathematics"),
	Course(CourseNum_Computer, 50, "Principles of Computer Composition"),
	Course(CourseNum_DataStructure, 60, "Data structure")

};



int main()
{
	StudentContainer studentsets;

	Student& stu1 = CreateStudent("John", 19);
	//std::pair<std::set<int>::iterator, bool > result;
	stu1.stu_couselist.insert(Course::courses[Course::CourseNum_CPP]);
	stu1.stu_couselist.insert(Course::courses[Course::CourseNum_English]);
	studentsets.insert(stu1);
	
	Student& stu2 = CreateStudent("Jim", 18);
	stu2.stu_couselist.insert(Course::courses[Course::CourseNum_CPP]);
	stu2.stu_couselist.insert(Course::courses[Course::CourseNum_DataStructure]);
	stu2.stu_couselist.insert(Course::courses[Course::CourseNum_Computer]);
	studentsets.insert(stu2);
	
	Student& stu3 = CreateStudent("Elise", 21);
	stu3.stu_couselist.insert(Course::courses[Course::CourseNum_English]);
	stu3.stu_couselist.insert(Course::courses[Course::CourseNum_Maths]);
	studentsets.insert(stu3);
	
	Student& stu4 = CreateStudent("paul", 18);
	stu4.stu_couselist.insert(Course::courses[Course::CourseNum_Computer]);
	stu4.stu_couselist.insert(Course::courses[Course::CourseNum_Maths]);
	studentsets.insert(stu4);
	
	
	print_out_by<stu_age>(studentsets);

	return 0;
}







