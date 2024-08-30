#pragma once
#include "Sale.h"

class Employee {
public:

	struct Person {
		string name;
		int saleAmount;
		Sale personSales;

		Person* nextPerson;
		Person(string newName) : name(newName), saleAmount(0), nextPerson(nullptr) {}
	};

	Person* head;

	void sortEmployees();
	void combineList(Person*);

	Employee();
	~Employee();

	void addPerson(string);
	void addSaleToPerson(int, int);
	int getEmployesSalesAmount();

	void EmployeeManualDestructor();
	void printEmployeesWithSales();
	void printEmployees();
	
};