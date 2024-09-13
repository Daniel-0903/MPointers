#include "DoublyLinkedList.h"
#include "SortAlgorithms.h"
#include <iostream>

int main() {
	DoublyLinkedList<int> list;
	
	list.insert(4);
	list.insert(2);
	list.insert(7);
	list.insert(1);
	list.insert(9);
	
	std::cout << "Lista original: ";
	list.printForward();
	
	// Ordenar con BubbleSort
	bubbleSort(list.getHead());
	std::cout << "Lista ordenada con BubbleSort: ";
	list.printForward();
	
	// Insertar más elementos y probar InsertionSort
	list.insert(5);
	list.insert(3);
	
	insertionSort(list.getHead());
	std::cout << "Lista ordenada con InsertionSort: ";
	list.printForward();
	
	// Insertar más elementos y probar QuickSort
	list.insert(6);
	list.insert(8);
	
	quickSort(list.getHead(), list.getHead());
	std::cout << "Lista ordenada con QuickSort: ";
	list.printForward();
	
	return 0;
}

