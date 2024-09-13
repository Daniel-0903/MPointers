#ifndef MPOINTER_H
#define MPOINTER_H

#include <iostream>
#include "MPointerGC.h"

template <typename T>
class MPointer {
private:
	T* ptr;  // Puntero que encapsularemos
	static MPointerGC* gc;  // Instancia del recolector de basura
	
public:
	// Constructor: Inicializa el puntero y lo registra en el GC
	MPointer() {
		ptr = new T();  // Reserva memoria para el tipo T
		gc->registerPointer(this);  // Registra el puntero en el GC
		std::cout << "MPointer creado y memoria reservada." << std::endl;
	}
	
	// Destructor: Libera la referencia en el GC
	~MPointer() {
		gc->removeReference(this);
		delete ptr;
		std::cout << "MPointer destruido y memoria liberada." << std::endl;
	}
	
	// Sobrecarga del operador * (dereference) para obtener o asignar valor
	T& operator*() {
		return *ptr;  // Devuelve el valor apuntado
	}
	
	// Sobrecarga del operador & para obtener la direcci�n del puntero
	T* operator&() {
		return ptr;  // Devuelve la direcci�n del puntero encapsulado
	}
	
	// Sobrecarga del operador de asignaci�n
	MPointer<T>& operator=(const MPointer<T>& other) {
		if (this != &other) {  // Evitar auto-asignaci�n
			gc->removeReference(this);
			delete ptr;  // Libera la memoria actual
			ptr = new T(*other.ptr);  // Asigna una nueva copia
			gc->addReference(&other);  // Incrementa la referencia del puntero asignado
		}
		return *this;
	}
	
	// M�todo est�tico para crear un nuevo MPointer
	static MPointer<T> New() {
		return MPointer<T>();  // Llama al constructor por defecto
	}
	
	// M�todo para ejecutar manualmente la recolecci�n de basura
	static void collectGarbage() {
		gc->collect();
	}
};

// Inicializa el singleton de GC
template <typename T>
MPointerGC* MPointer<T>::gc = MPointerGC::getInstance();

#endif
