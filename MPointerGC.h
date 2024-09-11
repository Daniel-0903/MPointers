#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <map>
#include <mutex>
#include <thread>
#include <chrono>

template <typename T>
class MPointer;  // Forward declaration para evitar dependencias circulares

class MPointerGC {
private:
	// Mapa que mantiene los punteros y su conteo de referencias
	std::map<void*, int> pointerMap;
	std::mutex mtx;  // Mutex para proteger las operaciones de concurrencia
	static MPointerGC* instance;  // Singleton
	
	// Constructor privado para singleton
	MPointerGC() {}
	
	// Método privado que revisa y libera memoria periódicamente
	void collect() {
		while (true) {
			std::this_thread::sleep_for(std::chrono::seconds(5));  // Ejecución cada 5 segundos
			std::lock_guard<std::mutex> lock(mtx);
			for (auto it = pointerMap.begin(); it != pointerMap.end();) {
				if (it->second == 0) {  // Si el contador de referencias es 0
					delete static_cast<int*>(it->first);  // Libera la memoria
					it = pointerMap.erase(it);  // Elimina el puntero del mapa
				} else {
					++it;
				}
			}
		}
	}
	
public:
		// Método estático para obtener la instancia del singleton
		static MPointerGC* getInstance() {
			if (!instance) {
				instance = new MPointerGC();
				std::thread(&MPointerGC::collect, instance).detach();  // Inicia el thread de recolección
			}
			return instance;
		}
		
		// Método para registrar un nuevo puntero
		template <typename T>
			void registerPointer(MPointer<T>* ptr) {
			std::lock_guard<std::mutex> lock(mtx);
			pointerMap[ptr] = 1;  // Inicia el contador de referencias en 1
		}
			
			// Método para incrementar el contador de referencias
			void addReference(void* ptr) {
				std::lock_guard<std::mutex> lock(mtx);
				pointerMap[ptr]++;
			}
			
			// Método para decrementar el contador de referencias
			void removeReference(void* ptr) {
				std::lock_guard<std::mutex> lock(mtx);
				if (pointerMap.find(ptr) != pointerMap.end()) {
					pointerMap[ptr]--;
				}
			}
};

// Inicializa el singleton
MPointerGC* MPointerGC::instance = nullptr;

#endif
