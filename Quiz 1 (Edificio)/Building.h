#pragma once
#include "Employee.h"

class Building : public Employee {
private:

	struct Floor{
		int floorLevel;
		int floorSaleAmount;
		Employee floorEmployees;
		Floor* nextFloor;
		Floor* prevFloor;

		Floor(int level) : floorLevel(level), floorSaleAmount(0), nextFloor(nullptr), prevFloor(nullptr) {}
	};

	Floor* INI;

public:

	Building();
	~Building();

	void addFloor();
	void addPersonToFloor(int, string);
	void addSaleToPersonToFloor(int, int, int);
	void verifyFloorsSales();
	void deleteFloor(int);

	void BuildingManualDestructor();
	int getTotalFloors();
	bool floorExist(int);
	void printFloors();
	void printFloorsWithEmployees();
	void printEmployeesOfFloor(int);
};