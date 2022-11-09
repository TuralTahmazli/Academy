#include<iostream>
#include<cassert>
using namespace std;
#include"Student.h"
#include"Group.h"
#include"Academy.h"


int main()
{
	Student* student = new Student("Tural", "Tahmazli");
	Student* student1 = new Student("Tural1", "Tahmazli");
	Group* group = new Group("FBES_12210_az", new Student * [1] {student}, 1);
	group->appendStudent(student1);
	Academy* academy = new Academy("Step IT", new Group * [1] {group},1);
	academy->print();
}