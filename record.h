#pragma once
#include<iostream>
#include<string>
using namespace std;
class record
{
private:
	int id, age;
	string name, department, designation, reporting_to;
public:
	record(int,string,int,string,string,string);
	void display();
	void set_name(string);
	void set_department(string);
	void set_designation(string);
	void set_reporting_to(string);
	void set_age(int);
	void set_id(int);

	string get_name();
	string get_department();
	string get_designation();
	string get_reporting_to();
	int get_age();
	int get_id();
	string get_variable_value(int);

	
};

