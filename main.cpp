#include "DoublyLinkedList.h"
#include "SortAlgorithms.h"
#include <iostream>
#include "MPointer.h"
int main() {
	/*DoublyLinkedList<int> list;
	
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
	list.printForward();*/
	// Prueba 1: Verificar sobrecarga del operador &
	std::cout << "Prueba 1: Verificar sobrecarga del operador &" << std::endl;
	MPointer<int> myPtr = MPointer<int>::New();
	*myPtr = 42;
	
	std::cout << "Dirección en myPtr: " << &myPtr << std::endl;
	std::cout << "Valor en myPtr: " << *myPtr << std::endl;
	
	int* rawPtr = &myPtr;  // Verificar que el operador & devuelve la dirección del puntero encapsulado
	std::cout << "Dirección usando int* rawPtr = &myPtr: " << rawPtr << std::endl;
	std::cout << std::endl;
	
	// Prueba 2: Verificar que el destructor llama a MPointerGC y libera la memoria
	std::cout << "Prueba 2: Verificar el llamado del destructor y liberación de memoria" << std::endl;
	{
		MPointer<int> tempPtr = MPointer<int>::New();
		*tempPtr = 55;
		std::cout << "Valor en tempPtr: " << *tempPtr << std::endl;
	} // El destructor debería ser llamado aquí
	std::cout << "tempPtr fue destruido. Si el contador llegó a 0, la memoria debería haber sido liberada." << std::endl;
	std::cout << std::endl;
	
	// Prueba 3: Verificar que MPointerGC asigna IDs únicos y libera la memoria al llegar a cero
	std::cout << "Prueba 3: Verificar que MPointerGC asigna IDs únicos" << std::endl;
	MPointer<int> myPtr1 = MPointer<int>::New();
	MPointer<int> myPtr2 = MPointer<int>::New();
	
	std::cout << "Asignando valor 100 a myPtr1." << std::endl;
	*myPtr1 = 100;
	
	std::cout << "Asignando valor 200 a myPtr2." << std::endl;
	*myPtr2 = 200;
	
	std::cout << "Destruyendo ambos punteros." << std::endl;
	std::cout << std::endl;
	
	// Prueba 4: Verificar algoritmo BubbleSort con MPointer y listas doblemente enlazadas
	std::cout << "Prueba 4: Verificar algoritmo BubbleSort" << std::endl;
	DoublyLinkedList<int> listBubble;
	listBubble.insert(3);
	listBubble.insert(1);
	listBubble.insert(5);
	listBubble.insert(4);
	listBubble.insert(2);
	
	std::cout << "Lista antes de BubbleSort: ";
	listBubble.printForward();
	
	bubbleSort(listBubble.getHead());
	
	std::cout << "Lista después de BubbleSort: ";
	listBubble.printForward();
	std::cout << std::endl;
	
	// Prueba 5: Verificar algoritmo QuickSort con MPointer y listas doblemente enlazadas
	std::cout << "Prueba 5: Verificar algoritmo QuickSort" << std::endl;
	DoublyLinkedList<int> listQuick;
	listQuick.insert(7);
	listQuick.insert(2);
	listQuick.insert(9);
	listQuick.insert(5);
	listQuick.insert(1);
	
	std::cout << "Lista antes de QuickSort: ";
	listQuick.printForward();
	
	quickSort(listQuick.getHead(), listQuick.getHead());
	
	std::cout << "Lista después de QuickSort: ";
	listQuick.printForward();
	std::cout << std::endl;
	
	// Prueba 6: Verificar algoritmo InsertionSort con MPointer y listas doblemente enlazadas
	std::cout << "Prueba 6: Verificar algoritmo InsertionSort" << std::endl;
	DoublyLinkedList<int> listInsertion;
	listInsertion.insert(4);
	listInsertion.insert(1);
	listInsertion.insert(3);
	listInsertion.insert(2);
	listInsertion.insert(5);
	
	std::cout << "Lista antes de InsertionSort: ";
	listInsertion.printForward();
	
	insertionSort(listInsertion.getHead());
	
	std::cout << "Lista después de InsertionSort: ";
	listInsertion.printForward();
	std::cout << std::endl;
	return 0;
}


