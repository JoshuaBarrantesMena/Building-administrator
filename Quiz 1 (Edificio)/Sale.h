#pragma once
#include <string>
#include <iostream>
using namespace std;

class Sale {
private:

	struct Node {
		int amount;
		Node* nextNode;

		Node(int newAmount) : amount(newAmount), nextNode(nullptr) {}
	};

	Node* head;

	void sortSales();

public:

	Sale();
	~Sale();
	void add(int);
	int getSalesAmount();

	void SaleManualDestructor();
	void print();
};