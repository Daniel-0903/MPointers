#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <map>

template <typename T>
class MPointer;

class MPointerGC {
private:
	// Cambiamos el tipo de clave a MPointer<T>* para que acepte correctamente punteros de tipo MPointer<T>
	std::map<void*, int> pointerMap;  // Mapa que almacena punteros y sus referencias
	static MPointerGC* instance;      // Instancia del singleton
	
	MPointerGC() {}  // Constructor privado
	
public:
		static MPointerGC* getInstance() {
			if (!instance) {
				instance = new MPointerGC();
			}
			return instance;
		}
		
		// M�todo para registrar un nuevo puntero de tipo T*
		template <typename T>
			int registerPointer(T* ptr) {
			pointerMap[ptr] = 1;  // Inicia el contador de referencias en 1
			return pointerMap.size();  // Devuelve el ID basado en el tama�o del mapa
		}
			
			// M�todo para incrementar el contador de referencias
			template <typename T>
				void addReference(T* ptr) {
				auto it = pointerMap.find(static_cast<void*>(ptr));
				if (it != pointerMap.end()) {
					pointerMap[ptr]++;
				}
			}
				
				// M�todo para decrementar el contador de referencias y liberar si llega a cero
				template <typename T>
					void removeReference(T* ptr) {
					auto it = pointerMap.find(static_cast<void*>(ptr));
					if (it != pointerMap.end()) {
						pointerMap[ptr]--;
						if (pointerMap[ptr] == 0) {
							delete ptr;
							pointerMap.erase(ptr);  // Elimina el puntero del mapa
						}
					}
				}
					
					// Recolector de basura manual
					void collect() {
						for (auto it = pointerMap.begin(); it != pointerMap.end();) {
							if (it->second == 0) {
								delete static_cast<typename std::remove_pointer<decltype(it->first)>::type*>(it->first);
								it = pointerMap.erase(it);
							} else {
								++it;
							}
						}
					}
};

// Definici�n de la instancia est�tica del singleton


#endif

