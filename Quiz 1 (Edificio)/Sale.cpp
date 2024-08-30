#include "Sale.h"

void Sale::sortSales() {

	Node* current = head;
	Node* aux = nullptr;

	int value;

	while (current->nextNode != nullptr) {

		aux = current->nextNode;
		while (aux != nullptr) {

			if (current->amount < aux->amount) {
				value = current->amount;
				current->amount = aux->amount;
				aux->amount = value;
			}

			aux = aux->nextNode;
		}

		current = current->nextNode;
	}
}

Sale::~Sale() {

}

Sale::Sale() {
	head = nullptr;
}

void Sale::add(int value) {

	Node* newAmount = new Node(value);

	if (!head) {
		head = newAmount;
		return;
	}

	Node* aux = head;

	while (aux->nextNode != nullptr) {
		aux = aux->nextNode;
	}
	aux->nextNode = newAmount;

	sortSales();
}

int Sale::getSalesAmount() {
	
	int allAmount = 0;
	Node* current = head;

	while (current != nullptr) {
		allAmount += current->amount;
		current = current->nextNode;
	}
	return allAmount;
}

void Sale::SaleManualDestructor(){

	while (head) {
		Node* temp = head;
		head = head->nextNode;
		delete temp;
	}
}

void Sale::print() {
	
	Node* current = head;

	while (current != nullptr) {
		cout << "  " << current->amount << endl;
		current = current->nextNode;
	}
}