#include <gtest/gtest.h>
#include "MPointer.h"
#include "MPointerGC.h"
#include "DoublyLinkedList.h"
#include "SortAlgorithms.h"

// Prueba b�sica de creaci�n y asignaci�n
TEST(MPointerTest, BasicCreationAndAssignment) {
	MPointer<int> myPtr = MPointer<int>::New();
	*myPtr = 10;
	EXPECT_EQ(*myPtr, 10);
	
	MPointer<int> myPtr2 = MPointer<int>::New();
	*myPtr2 = 20;
	EXPECT_EQ(*myPtr2, 20);
	
	// Asignaci�n de un MPointer a otro
	myPtr2 = myPtr;
	EXPECT_EQ(*myPtr2, 10);
}

// Prueba del recolector de basura al destruir un puntero
TEST(MPointerTest, GarbageCollection) {
	MPointer<int> myPtr = MPointer<int>::New();
	*myPtr = 15;
	
	MPointer<int> myPtr2 = myPtr; // myPtr2 comparte la misma direcci�n que myPtr
	EXPECT_EQ(*myPtr2, 15);
	
	myPtr = nullptr; // myPtr se elimina, pero myPtr2 a�n existe
	EXPECT_EQ(*myPtr2, 15);
	
	myPtr2 = nullptr; // myPtr2 tambi�n se elimina, el recolector debe liberar la memoria
}

// Prueba de sobrecarga del operador & y *
TEST(MPointerTest, DereferenceAndAddressOf) {
	MPointer<int> myPtr = MPointer<int>::New();
	*myPtr = 25;
	
	int* ptrAddress = &myPtr;
	EXPECT_EQ(*ptrAddress, 25);
}


// Prueba de inserci�n en la lista doblemente enlazada
TEST(DoublyLinkedListTest, InsertionTest) {
	DoublyLinkedList<int> list;
	list.insert(5);
	list.insert(10);
	list.insert(3);
	
	// Verificamos que la lista se haya insertado correctamente
	EXPECT_EQ(*list.getHead()->data, 5);
	EXPECT_EQ(*list.getHead()->next->data, 10);
	EXPECT_EQ(*list.getHead()->next->next->data, 3);
}

// Prueba de BubbleSort
TEST(SortingTest, BubbleSortTest) {
	DoublyLinkedList<int> list;
	list.insert(4);
	list.insert(1);
	list.insert(3);
	list.insert(2);
	
	bubbleSort(list.getHead());
	
	// Verificaci�n del orden correcto despu�s del BubbleSort
	EXPECT_EQ(*list.getHead()->data, 1);
	EXPECT_EQ(*list.getHead()->next->data, 2);
	EXPECT_EQ(*list.getHead()->next->next->data, 3);
	EXPECT_EQ(*list.getHead()->next->next->next->data, 4);
}

// Prueba de InsertionSort
TEST(SortingTest, InsertionSortTest) {
	DoublyLinkedList<int> list;
	list.insert(4);
	list.insert(1);
	list.insert(3);
	list.insert(2);
	
	insertionSort(list.getHead());
	
	// Verificaci�n del orden correcto despu�s del InsertionSort
	EXPECT_EQ(*list.getHead()->data, 1);
	EXPECT_EQ(*list.getHead()->next->data, 2);
	EXPECT_EQ(*list.getHead()->next->next->data, 3);
	EXPECT_EQ(*list.getHead()->next->next->next->data, 4);
}

// Prueba de QuickSort
TEST(SortingTest, QuickSortTest) {
	DoublyLinkedList<int> list;
	list.insert(4);
	list.insert(1);
	list.insert(3);
	list.insert(2);
	
	quickSort(list.getHead(), list.getHead()->next->next->next);
	
	// Verificaci�n del orden correcto despu�s del QuickSort
	EXPECT_EQ(*list.getHead()->data, 1);
	EXPECT_EQ(*list.getHead()->next->data, 2);
	EXPECT_EQ(*list.getHead()->next->next->data, 3);
	EXPECT_EQ(*list.getHead()->next->next->next->data, 4);
}
