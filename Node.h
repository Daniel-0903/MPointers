#ifndef NODE_H
#define NODE_H

#include "MPointer.h"

template <typename T>
class Node {
public:
	MPointer<T> data;  // Dato almacenado en el nodo
	MPointer<Node<T>> next;  // Puntero al siguiente nodo
	MPointer<Node<T>> prev;  // Puntero al nodo anterior
	
	// Constructor
	Node(T value) {
		data = MPointer<T>::New();
		*data = value;
		next = nullptr;
		prev = nullptr;
	}
};

#endif
