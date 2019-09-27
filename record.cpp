#include "record.h"

#include<iostream>
#include<string>
using namespace std;

record::record(int _id, string _name, int _age, string _department, string _designation, string _reporting_to)
{	
	set_id(_id);
	set_name(_name);
	set_department(_department);
	set_designation(_designation);
	set_reporting_to(_reporting_to);
	set_age(_age);
}


void record::display()
{
	cout << get_name() << "\t" << get_age() << "\t" << get_department() << "\t" << get_designation() << "\t" << get_reporting_to() << "\n";

}

void record::set_name(string _name)
{
	name = _name;
}
void record::set_department(string _department)
{
	department = _department;
}
void record::set_designation(string _designation)
{
	designation = _designation;
}
void record::set_reporting_to(string _reporting_to)
{
	reporting_to = _reporting_to;
}
void record::set_age(int _age)
{
	age = _age;
}
void record::set_id(int _id)
{
	id = _id;
}

string record::get_name()
{
	return name;
}
string record::get_department()
{
	return department;
}
string record::get_designation()
{
	return designation;
}
string record::get_reporting_to()
{
	return reporting_to;
}
int record::get_age()
{
	return age;
}
int record::get_id()
{
	return id;
}

string record::get_variable_value(int choice)
{
	if (choice == 1)
		return get_name();
	if (choice == 3)
		return get_department();
	if (choice == 4)
		return get_designation();
	if (choice == 5)
		return get_reporting_to();
}