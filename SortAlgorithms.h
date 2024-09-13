#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include "Node.h"

// BubbleSort
template <typename T>
void bubbleSort(MPointer<Node<T>> head) {
	bool swapped;
	do {
		swapped = false;
		MPointer<Node<T>> current = head;
		while (!(*current).next.isNull()) {
			if (*(*current).data > *(*(*current).next).data) {
				std::swap(*(*current).data, *(*(*current).next).data);
				swapped = true;
			}
			current = (*current).next;
		}
	} while (swapped);
}

// InsertionSort
template <typename T>
	void insertionSort(MPointer<Node<T>> head) {
	MPointer<Node<T>> sorted = MPointer<Node<T>>();  // Inicialización corregida
	MPointer<Node<T>> current = head;
	
	while (!current.isNull()) {
		MPointer<Node<T>> next = (*current).next;
		if (sorted.isNull() || *(*sorted).data >= *(*current).data) {
			(*current).next = sorted;
			sorted = current;
		} else {
			MPointer<Node<T>> temp = sorted;
			while (!(*temp).next.isNull() && *(*(*temp).next).data < *(*current).data) {
				temp = (*temp).next;
			}
			(*current).next = (*temp).next;
			(*temp).next = current;
		}
		current = next;
	}
	head = sorted;
}
	
	// QuickSort
	template <typename T>
		MPointer<Node<T>> partition(MPointer<Node<T>> low, MPointer<Node<T>> high) {
		T pivotValue = *(*high).data;
		MPointer<Node<T>> i = low;
		
		for (MPointer<Node<T>> j = low; j != high; j = (*j).next) {  // Comparación corregida
			if (*(*j).data <= pivotValue) {
				std::swap(*(*i).data, *(*j).data);
				i = (*i).next;
			}
		}
		std::swap(*(*i).data, *(*high).data);
		return i;
	}
		
		template <typename T>
			void quickSort(MPointer<Node<T>> low, MPointer<Node<T>> high) {
			if (!low.isNull() && !high.isNull() && low != high && (*low).next != high) {  // Comparación corregida
				MPointer<Node<T>> pivot = partition(low, high);
				quickSort(low, (*pivot).prev);
				quickSort((*pivot).next, high);
			}
		}
			
#endif
			
			
