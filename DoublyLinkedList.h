##ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
	MPointer<Node<T>> head;
	MPointer<Node<T>> tail;
	
public:
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	
	// Insertar un nuevo nodo al final de la lista
	void insert(T value) {
		MPointer<Node<T>> newNode = MPointer<Node<T>>::New();
		*newNode = Node<T>(value);
		if (head.isNull()) {
			head = newNode;
			tail = newNode;
		} else {
			(*tail).next = newNode;
			(*newNode).prev = tail;
			tail = newNode;
		}
	}
	
	MPointer<Node<T>> getHead() {
		return head;
	}
	
	// Imprimir la lista de izquierda a derecha
	void printForward() {
		MPointer<Node<T>> current = head;
		while (!current.isNull()) {
			std::cout << *(*current).data << " ";
			current = (*current).next;
		}
		std::cout << std::endl;
	}
	
	// Imprimir la lista de derecha a izquierda
	void printBackward() {
		MPointer<Node<T>> current = tail;
		while (!current.isNull()) {
			std::cout << *(*current).data << " ";
			current = (*current).prev;
		}
		std::cout << std::endl;
	}
};

#endif
