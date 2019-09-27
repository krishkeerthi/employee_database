#pragma once
#include "record.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class emp_db
{
private:
	vector<record> records;
public:
	emp_db();
	void run();
	void split(string&, char,vector<string>&);
	void show(vector<record>&);
	void search(vector<record>&);
	void by_string(vector<record>&,int);
	void by_int(vector<record>&);
	int equals(string, string);
	int not_equals(string, string);
	int starts_with(string, string);
	int ends_with(string, string);
	int contains(string, string);
	int not_contains(string, string);
	void count_by_field();





	
};

