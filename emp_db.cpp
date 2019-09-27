#include "emp_db.h"
#include"record.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;



emp_db::emp_db()
{
	fstream logfile;
	logfile.open("data.txt");
	int id, age;
	string line,name,dept,design,rept;
	vector<string> fields;

	getline(logfile, line);

	while (getline(logfile, line))
	{
		split(line, '|',fields);
		id = stoi(fields[0]);
		name = fields[1];
		age = stoi(fields[2]);
		dept = fields[3];
		design = fields[4];
		rept = fields[5];

		record obj(id, name, age, dept, design, rept);
		records.push_back(obj);
		
		fields.clear();
	}
}

void emp_db::split(string& l, char delim,vector<string>& s)
{
	stringstream ss;
	ss.str(l);
	string value;

	while (getline(ss, value, delim))
		s.push_back(value);
	
}

void emp_db::run()
{
	char c;
	vector<record> temp;
	while (1)
	{
		temp.assign(records.begin(), records.end());
		cout << "1.show\n2.search\n3.count\nenter your input:\t";
		cin >> c;
		if (c == 'x')
			break;
		switch (c)
		{
		case '1':
			show(records);
			break;

		case '2':
			search(temp);
			break;

		case '3':
			count_by_field();
			break;

		default:
			cout << "\nincorrect selections";
			break;

		}

		system("pause");
		system("cls");
	}
}

void emp_db::show(vector<record>& t)
{
	for (auto it = t.begin(); it < t.end(); it++)
		(*it).display();
}

void emp_db::search(vector<record>& t)
{
	char choice;
	cout << "1.By_name\n2.By_age\n3.By_departmet\n4.By_designation\n5.By_reporting_to\n enter your choice:\t";
	cin >> choice;

	switch (choice)
	{
	case '1':
		by_string(t,1);
		break;

	case '2':
		by_int(t);
		break;

	case '3':
		by_string(t, 3);
		break;

	case '4':
		by_string(t, 4);
		break;

	case '5':
		by_string(t, 5);
		break;

	default:
		cout << "\nincorrect selections";
		break;
	}

	cout << "\nwant to add more constraints (y/n):\n";
	cin >> choice;

	system("cls");

	if (choice == 'y')
		search(t);
	else
		show(t);
	


}

void emp_db::by_string(vector<record>& t,int n)
{
	char choice;
	string text,value;

	cout << "1.equals\n2.not equals\n3.starts with\n4.ends with\n5.contains\n6.not contains\n enter your choice:\t";
	cin >> choice;
	cout << "\nenter text:\t";
	cin.ignore();
	getline(cin, text);
	//cin >> text;

	switch (choice)
	{
	case '1':
		for (auto it = t.begin(); it < t.end();)
		{
			value= (*it).get_variable_value(n);
			if (!equals(value, text))
				it=t.erase(it);
			else
				it++;
		}
		break;

	case '2':
		for (auto it = t.begin(); it < t.end();)
		{
			value = (*it).get_variable_value(n);
			if (!not_equals(value, text))
				it = t.erase(it);
			else
				it++;
		}
		break;

	case '3':
		for (auto it = t.begin(); it < t.end();)
		{
			value = (*it).get_variable_value(n);
			if (!starts_with(value, text))
				it = t.erase(it);
			else
				it++;
		}
		break;

	case '4':
		for (auto it = t.begin(); it < t.end();)
		{
			value = (*it).get_variable_value(n);
			if (!ends_with(value, text))
				it = t.erase(it);
			else
				it++;
		}
		break;

	case '5':
		for (auto it = t.begin(); it < t.end();)
		{
			value = (*it).get_variable_value(n);
			if (!contains(value, text))
				it = t.erase(it);
			else
				it++;
		}
		break;
	case '6':
		for (auto it = t.begin(); it < t.end();)
		{
			value = (*it).get_variable_value(n);
			if (!not_contains(value, text))
				it = t.erase(it);
			else
				it++;
		}
		break;

	default:
		cout << "\nincorrect selections";
		break;
	}

}

int emp_db::equals(string value, string key)
{
	return (value == key);
}
int emp_db::not_equals(string value, string key)
{
	return !(value == key);
}
int emp_db::starts_with(string value, string key)
{
	size_t limit = key.size();
	for (int i = 0; i < limit; i++)
	{
		if (value[i] != key[i])
			return 0;
	}
	return 1;
}
int emp_db::ends_with(string value, string key)
{
	size_t limit = key.size()-1,val_limit=value.size()-1;
	for (int i = limit; i >=0; i--)
	{
		if (value[val_limit-i] != key[limit-i])
			return 0;
	}
	return 1;
}
int emp_db::contains(string value, string key)
{
	return value.find(key) != string::npos;
}
int emp_db::not_contains(string value, string key)
{
	return value.find(key) == string::npos;
}

void emp_db::by_int(vector<record>& t)
{
	char choice;
	int age;

	cout << "1.greater than\n2.lesser than\n3.equal to\n4.not equal to\n enter your choice:\t";
	cin >> choice;
	cout << "\nenter age:\t";
	cin >> age;
	cout << "\nage is " << age;

	switch (choice)
	{
	case '1':
		for (auto it = t.begin(); it < t.end(); )
		{
			if ((*it).get_age() < age)
				it = t.erase(it);
			else
				it++;
		}
		break;

	case '2':
		for (auto it = t.begin(); it < t.end();)

		{
			if ((*it).get_age() > age)
				it = t.erase(it);
			else
				it++;
		}
		break;

	case '3':
		for (auto it = t.begin(); it < t.end();)
		{
			if ((*it).get_age() != age)
				it = t.erase(it);
			else
				it++;
		}
		break;

	case '4':
		for (auto it = t.begin(); it < t.end();)
		{
			if ((*it).get_age() == age)
				it = t.erase(it);
			else
				it++;
		}
		break;

	default:
		cout << "\nincorrect selections";
		break;
	}
}

void emp_db::count_by_field()
{
	map<string, int> designation_map,department_map,reporting_to_map;
	string designation, department, reporting_to;
	for (auto it = records.begin(); it < records.end(); it++)
	{
		designation = (*it).get_designation();
		if (designation_map.find(designation) != designation_map.end())
			designation_map[designation] += 1;
		else
			designation_map[designation] = 1;

		department = (*it).get_department();
		if (department_map.find(department) != department_map.end())
			department_map[department] += 1;
		else
			department_map[department] = 1;

		reporting_to = (*it).get_reporting_to();
		if (reporting_to_map.find(reporting_to) != reporting_to_map.end())
			reporting_to_map[reporting_to] += 1;
		else
			reporting_to_map[reporting_to] = 1;

	}
	cout << "designation \t\t count\n";
	for (auto it = designation_map.begin(); it != designation_map.end(); it++)
		cout << (*it).first << "\t" << (*it).second<<"\n";
	
	cout << "\n\ndepartment \t\t count\n";
	for (auto it = department_map.begin(); it != department_map.end(); it++)
		cout << (*it).first << "\t" << (*it).second<<"\n";

	cout << "\n\nreporting_to \t\t count\n";
	for (auto it = reporting_to_map.begin(); it != reporting_to_map.end(); it++)
		cout << (*it).first << "\t" << (*it).second<<"\n";
	
}