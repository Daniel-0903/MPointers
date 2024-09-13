#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <map>
#include <iostream>

template <typename T>
class MPointer;  // Forward declaration

class MPointerGC {
private:
	std::map<void*, int> pointerMap;  // Mapa de punteros a su conteo de referencias
	static MPointerGC* instance;  // Instancia del singleton
	
	// Constructor privado para singleton
	MPointerGC() {}
	
public:
		// Método estático para obtener la instancia del singleton
		static MPointerGC* getInstance() {
			if (!instance) {
				instance = new MPointerGC();
			}
			return instance;
		}
		
		// Método para registrar un nuevo puntero
		template <typename T>
			void registerPointer(MPointer<T>* ptr) {
			pointerMap[ptr] = 1;  // Inicia el contador de referencias en 1
		}
			
			// Método para incrementar el contador de referencias
			void addReference(void* ptr) {
				if (pointerMap.find(ptr) != pointerMap.end()) {
					pointerMap[ptr]++;
				}
			}
			
			// Método para decrementar el contador de referencias
			void removeReference(void* ptr) {
				if (pointerMap.find(ptr) != pointerMap.end()) {
					pointerMap[ptr]--;
					if (pointerMap[ptr] == 0) {
						delete static_cast<MPointer<void>*>(ptr);  // Libera la memoria si ya no tiene referencias
						pointerMap.erase(ptr);  // Elimina el puntero del mapa
					}
				}
			}
			
			// Método manual para liberar memoria no referenciada
			void collect() {
				for (auto it = pointerMap.begin(); it != pointerMap.end();) {
					if (it->second == 0) {  // Si el contador de referencias es 0
						delete static_cast<MPointer<void>*>(it->first);  // Libera la memoria
						it = pointerMap.erase(it);  // Elimina el puntero del mapa
					} else {
						++it;
					}
				}
			}
};

// Inicializa el singleton
MPointerGC* MPointerGC::instance = nullptr;

#endif
