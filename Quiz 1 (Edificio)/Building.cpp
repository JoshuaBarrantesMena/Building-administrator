#include "Building.h"

Building::Building() {
	INI = nullptr;
}

Building::~Building(){
}

void Building::addFloor() {

	Floor* newFloor = new Floor(1);

	if (!INI) {
		INI = newFloor;
		return;
	}
	Floor* currentFloor = INI;

	while (currentFloor->nextFloor != nullptr) {
		currentFloor = currentFloor->nextFloor;
		newFloor->floorLevel = currentFloor->floorLevel;
	}
	newFloor->floorLevel++;
	currentFloor->nextFloor = newFloor;
	newFloor->prevFloor = currentFloor;
}

void Building::addPersonToFloor(int floorLevel, string employeeName) {

	if (!INI) {
		cout << "No hay pisos en el edificio";
		return;
	}
	Floor* current = INI;

	while (current != nullptr && current->floorLevel != floorLevel) {
		current = current->nextFloor;
	}
	if (current == nullptr) {
		cout << "\nNo hay un piso con el nombre '" << floorLevel << "'\n";
		return;
	}
	current->floorEmployees.addPerson(employeeName);
}

void Building::addSaleToPersonToFloor(int floorLevel, int employeePos, int sale) {

	if (!INI) {
		cout << "No hay pisos en el edificio";
		return;
	}
	Floor* current = INI;

	while (current != nullptr && current->floorLevel != floorLevel) {
		current = current->nextFloor;
	}
	if (current == nullptr) {
		cout << "No hay un piso con el nombre '" << floorLevel << "'";
		return;
	}
	current->floorEmployees.addSaleToPerson(employeePos, sale);
	current->floorSaleAmount += sale;
}

void Building::deleteFloor(int floor) {

	if (!INI) {
		cout << "No hay pisos en el edificio";
		return;
	}
	Floor* current = INI;

	if (floor <= 1) {
		INI->nextFloor->floorSaleAmount += INI->floorSaleAmount;
		INI = INI->nextFloor;
		INI->floorEmployees.combineList(current->floorEmployees.head);
		current->nextFloor = nullptr;
		return;
	}
	while (current != nullptr && current->floorLevel < floor) {
		current = current->nextFloor;
	}
	if (current == nullptr) {
		cout << "No existe el piso '" << floor << "' en el edificio";
		return;
	}
	else if (current->floorLevel == floor){
		current->prevFloor->floorSaleAmount += current->floorSaleAmount;
		current->prevFloor->floorEmployees.combineList(current->floorEmployees.head);
		current->floorEmployees.head = nullptr;

		current->prevFloor->nextFloor = current->nextFloor;
		current->nextFloor->prevFloor = current->prevFloor;
		current->nextFloor = nullptr;
		current->prevFloor = nullptr;
		
	}
}

void Building::verifyFloorsSales() {

	if (!INI) {
		cout << "No hay pisos en el edificio";
		return;
	}
	Floor* current = INI;

	while (current != nullptr) {
		if (current->floorSaleAmount != current->floorEmployees.getEmployesSalesAmount()) {
			cout << "Las ventas registradas del piso #" << current->floorLevel << " No coinciden con las registradas por los empleados" << endl;
		}
		else {
			cout << "Ventas del piso #" << current->floorLevel << " sin errores de calculo" << endl;
		}
		current = current->nextFloor;
	}
}

void Building::BuildingManualDestructor(){

	while (INI) {
		Floor* temp = INI;
		INI = INI->nextFloor;
		temp->floorEmployees.EmployeeManualDestructor();
	}
}

int Building::getTotalFloors(){

	Floor* current = INI;
	int total = 0;

	while (current != nullptr) {
		total++;
		current = current->nextFloor;
	}
	return total;
}

bool Building::floorExist(int floor){

	Floor* current = INI;

	while (current != nullptr && current->floorLevel != floor) {
		current = current->nextFloor;
	}
	if (current != nullptr && current->floorLevel) {
		return true;
	}
	return false;
}

void Building::printFloors(){

	Floor* current = INI;
	int actual = 1;

	while (current != nullptr) {
		cout << "Piso #" << current->floorLevel << endl;
		current->floorEmployees.printEmployees();
		actual++;
		current = current->nextFloor;
	}
}

void Building::printFloorsWithEmployees(){

	Floor* current = INI;

	while (current != nullptr) {
		cout << "Empleados del piso #" << current->floorLevel << endl;
		current->floorEmployees.printEmployees();
		current = current->nextFloor;
		cout << "\n";
	}
}

void Building::printEmployeesOfFloor(int floor){

	if (!INI) {
		cout << "No hay pisos en el edificio";
		return;
	}
	Floor* current = INI;

	while (current != nullptr && current->floorLevel != floor){
		current = current->nextFloor;
	}
	if (!current) {
		cout << "No existe el piso #" << floor << endl;
		return;
	}
	current->floorEmployees.printEmployeesWithSales();
}