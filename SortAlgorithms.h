#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include "Node.h"

// BubbleSort
template <typename T>
void bubbleSort(MPointer<Node<T>> head) {
	bool swapped;
	MPointer<Node<T>> current;
	do {
		swapped = false;
		current = head;
		while (current->next != nullptr) {
			if (*(*current)->data > *(*current)->next->data) {
				std::swap(*(*current)->data, *(*current)->next->data);  // Intercambio de datos
				swapped = true;
			}
			current = (*current)->next;
		}
	} while (swapped);
}

// InsertionSort
template <typename T>
	void insertionSort(MPointer<Node<T>> head) {
	MPointer<Node<T>> sorted = nullptr;  // Lista inicialmente vacía
	MPointer<Node<T>> current = head;
	
	while (current != nullptr) {
		MPointer<Node<T>> next = (*current)->next;  // Almacena el siguiente nodo
		if (sorted == nullptr || *(*sorted)->data >= *(*current)->data) {
			(*current)->next = sorted;
			sorted = current;
		} else {
			MPointer<Node<T>> temp = sorted;
			while (temp->next != nullptr && *(*temp->next)->data < *(*current)->data) {
				temp = (*temp)->next;
			}
			(*current)->next = (*temp)->next;
			(*temp)->next = current;
		}
		current = next;
	}
	head = sorted;  // Actualiza la lista
}
	
	// QuickSort Partition
	template <typename T>
		MPointer<Node<T>> partition(MPointer<Node<T>> low, MPointer<Node<T>> high) {
		T pivot = *(*high)->data;
		MPointer<Node<T>> i = low->prev;
		
		for (MPointer<Node<T>> j = low; j != high; j = (*j)->next) {
			if (*(*j)->data <= pivot) {
				i = (i == nullptr) ? low : (*i)->next;
				std::swap(*(*i)->data, *(*j)->data);
			}
		}
		i = (i == nullptr) ? low : (*i)->next;
		std::swap(*(*i)->data, *(*high)->data);
		return i;
	}
		
		// QuickSort
		template <typename T>
			void quickSort(MPointer<Node<T>> low, MPointer<Node<T>> high) {
			if (low != nullptr && high != nullptr && low != high && low != (*high)->next) {
				MPointer<Node<T>> pivot = partition(low, high);
				quickSort(low, (*pivot)->prev);
				quickSort((*pivot)->next, high);
			}
		}
			
#endif
			
