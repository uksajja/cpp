#pragma once

#include <iostream>
#include <string>

class StartDate {
private:
	int date;
	int month;
	int year;
public:
	StartDate(int m, int d, int y) {
		// constructor stub
		month = m;
		date = d;
		year = y;
	}
	~StartDate() {
		// TODO Auto-generated destructor stub
	}
	void printStartDate(){
		std::cout << "Joining Date (mm/dd/yy) : " << month <<"/"<<date <<"/"<<year << std::endl;
	}
};

class Emp {
	private:
		std::string name;
		std::string dept;
		StartDate joinDate;
	public:
		Emp(std::string n, std::string dep, StartDate d): name(n), dept(dep), joinDate(d){
			// constructor stub
			name = n;
			dept = dep;
			joinDate = d;
		}
		~Emp() {
			// TODO Auto-generated destructor stub
		}
		void printEmpInfo(){
			std::cout << "Name       : " << name << std::endl;
			std::cout << "Department : " << dept << std::endl;
			joinDate.printStartDate();
		}
};

void test_composition();
