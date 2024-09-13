#ifndef MPOINTER_H
#define MPOINTER_H

#include <iostream>
#include "MPointerGC.h"

template <typename T>
class MPointer {
private:
	T* ptr;  // Puntero que encapsularemos
	int id;  // ID único del MPointer
	static MPointerGC* gc;  // Instancia del Garbage Collector
	
public:
	// Constructor por defecto
	MPointer() : ptr(nullptr) {
		id = -1;  // ID por defecto
	}
	
	// Sobrecarga del operador de asignación para nullptr
	MPointer<T>& operator=(std::nullptr_t) {
		gc->getInstance()->removeReference(ptr);
		delete ptr;
		ptr = nullptr;
		return *this;
	}
	
	// Destructor
	~MPointer() {
		gc->getInstance()->removeReference(ptr);
		delete ptr;
		std::cout << "MPointer destruido con ID " << id << std::endl;
	}
	
	// Sobrecarga del operador *
	T& operator*() {
		return *ptr;
	}
	
	// Sobrecarga del operador &
	T* operator&() {
		return ptr;
	}
	
	// Sobrecarga del operador de asignación
	MPointer<T>& operator=(const MPointer<T>& other) {
		if (this != &other) {
			if (ptr) {
				gc->getInstance()->removeReference(ptr);
				delete ptr;
			}
			ptr = new T(*other.ptr);
			id = other.id;
			gc->getInstance()->addReference(ptr);
		}
		return *this;
	}
	
	// Método estático para crear un nuevo MPointer
	static MPointer<T> New() {
		MPointer<T> p;
		p.ptr = new T();
		p.id = gc->getInstance()->registerPointer(p.ptr);  // Se registra el puntero crudo
		return p;
	}
	
	// Verificación si el puntero es nulo
	bool isNull() const {
		return ptr == nullptr;
	}
	
	// Sobrecarga del operador ==
	bool operator==(const MPointer<T>& other) const {
		return this->ptr == other.ptr;
	}
	
	// Sobrecarga del operador !=
	bool operator!=(const MPointer<T>& other) const {
		return this->ptr != other.ptr;
	}
};

// Inicializa el singleton del Garbage Collector
//template <typename T>
//MPointerGC* MPointer<T>::gc = MPointerGC::getInstance();

#endif
