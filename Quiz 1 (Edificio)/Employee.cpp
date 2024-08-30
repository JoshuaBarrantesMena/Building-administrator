#include "Employee.h"

void Employee::sortEmployees() {

	Person* current = head;
	Person* aux = nullptr;

	string pName;
	int pSalesAmount;
	Sale pPersonSales;

	while (current->nextPerson != nullptr) {

		aux = current->nextPerson;
		while (aux != nullptr) {
			if (aux->name.compare(current->name) <= 0) {
				pName = current->name;
				pSalesAmount = current->saleAmount;
				pPersonSales = current->personSales;

				current->name = aux->name;
				current->saleAmount = aux->saleAmount;
				current->personSales = aux->personSales;

				aux->name = pName;
				aux->saleAmount = pSalesAmount;
				aux->personSales = pPersonSales;
			}
			aux = aux->nextPerson;
		}
		current = current->nextPerson;
	}
}

void Employee::combineList(Person* oldHead){

	if (!head) {
		head = oldHead;
		return;
	}
	Person* current = head;

	while (current->nextPerson != nullptr) {
		current = current->nextPerson;
	}
	current->nextPerson = oldHead;
	sortEmployees();
}

Employee::Employee() {
	head = nullptr;
}

Employee::~Employee() {

	while (head) {
		Person* temp = head;
		head = head->nextPerson;
		delete temp;
	}
}

void Employee::addPerson(string personName) {

	Person* newPerson = new Person(personName);

	if (!head) {
		head = newPerson;
		return;
	}
	Person* aux = head;

	while (aux->nextPerson != nullptr) {
		aux = aux->nextPerson;
	}

	aux->nextPerson = newPerson;
	cout << "\n\nNuevo empleado añadido";
	sortEmployees();
}

void Employee::addSaleToPerson(int personPos, int newValue) {

	if (!head) {
		cout << "No hay empleados en este piso";
		return;
	}
	Person* current = head;
	int pos = 1;

	while (current != nullptr && pos != personPos) {
		pos++;
		current = current->nextPerson;
	}
	if (current == nullptr) {
		cout << "La posicion de este empleado no existe" << endl;
		return;
	}
	current->personSales.add(newValue);
	current->saleAmount += newValue;
	cout << "\nVentas agregadas al empleado '" << current->name << "'\n";
}

int Employee::getEmployesSalesAmount() {

	int allAmount = 0;
	Person* auxPerson = head;

	while (auxPerson != nullptr) {
		allAmount += auxPerson->personSales.getSalesAmount();
		auxPerson = auxPerson->nextPerson;
	}
	return allAmount;
}

void Employee::EmployeeManualDestructor(){

	while (head) {
		Person* temp = head;
		head = head->nextPerson;
		temp->personSales.SaleManualDestructor();
	}
}

void Employee::printEmployeesWithSales() {

	Person* current = head;
	int actual = 1;

	while (current != nullptr) {
		cout << actual << ". " << current->name << endl;
		current->personSales.print();
		cout << endl;
		actual++;
		current = current->nextPerson;
	}
}

void Employee::printEmployees(){

	Person* current = head;
	int iter = 1;

	while (current != nullptr) {
		cout << iter << ". " << current->name << endl;
		current = current->nextPerson;
		iter++;
	}
}