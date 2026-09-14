#include "gestionar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void gestionar::menu() {
	int opcion;
	do {

		std::cout << "1. reservas actuales" << std::endl;
		std::cout << "2. Modificar reserva" << std::endl;
		std::cout << "3. Salir" << std::endl;
		std::cout << "Seleccione una opcion: ";
		std::cin >> opcion;
		switch (opcion) {
		case 1:
			gestionar::sacar();
			break;
		case 2:
			gestionar::modificar();
			break;
		case 3:
			std::cout << "Saliendo..." << std::endl;
			break;
		default:
			std::cout << "Opcion invalida" << std::endl;
			break;
		}
	} while (opcion != 3);
}

void gestionar::alta() {
	std::ofstream archivo("reservas.soc", std::ios::binary);
	if (!archivo) {
		std::cout << "Error al abrir el archivo" << std::endl;
		return;
	}
	socio socio1 = { "Juan", "Perez", 25, "Futbol" };
	socio socio2 = { "Maria", "Gomez", 30, "Natacion" };
	socio socio3 = { "Pedro", "Lopez", 28, "Tenis" };
	socio socio4 = { "Ana", "Martinez", 22, "Voley" };
	socio socio5 = { "Luis", "Garcia", 35, "Basket" };

	archivo.write(reinterpret_cast<char*>(&socio1), sizeof(socio));
	archivo.write(reinterpret_cast<char*>(&socio2), sizeof(socio));
	archivo.write(reinterpret_cast<char*>(&socio3), sizeof(socio));
	archivo.write(reinterpret_cast<char*>(&socio4), sizeof(socio));
	archivo.write(reinterpret_cast<char*>(&socio5), sizeof(socio));
	archivo.close();
}

void gestionar::sacar() {
	std::ifstream archivo("reservas.soc", std::ios::binary);
	if (!archivo) {
		std::cout << "Error al abrir el archivo" << std::endl;
		return;
	}
	socio socioLeido;
	while (archivo.read(reinterpret_cast<char*>(&socioLeido), sizeof(socio))) {
		std::cout << "Nombre: " << socioLeido.nombre << std::endl;
		std::cout << "Apellido: " << socioLeido.apellido << std::endl;
		std::cout << "Edad: " << socioLeido.edad << std::endl;
		std::cout << "Deporte: " << socioLeido.deporte << std::endl;
		std::cout << "---" << std::endl;
	}
	archivo.close();
}

void gestionar::modificar() {
	std::fstream archivo("reservas.soc", std::ios::in | std::ios::out | std::ios::binary);  
	if (!archivo) {
		std::cout << "Error al abrir el archivo" << std::endl;
		return;
	}
	socio socioLeido;
	int posicion = 0;
	while (archivo.read(reinterpret_cast<char*>(&socioLeido), sizeof(socio))) {
		std::cout << "Nombre: " << socioLeido.nombre << std::endl;
		std::cout << "Apellido: " << socioLeido.apellido << std::endl;
		std::cout << "Edad: " << socioLeido.edad << std::endl;
		std::cout << "Deporte: " << socioLeido.deporte << std::endl;
		std::cout << "---" << std::endl;
		posicion++;
	}
	int socioAModificar;
	std::cout << "Ingrese el numero del socio a modificar (1-" << posicion << "): ";
	std::cin >> socioAModificar;
	if (socioAModificar < 1 || socioAModificar > posicion) {
		std::cout << "Numero de socio invalido" << std::endl;
		return;
	}
	
    int bajaReserva() {
        std::fstream archivo("reservas.bin", std::ios::binary | std::ios::in | std::ios::out);
        if (!archivo)  
        {
            std::cerr << "Error al abrir archivo";
            return -1;
        }
        int idbuscar;
        std::cout << "Ingrese el id a eliminar: "; std::cin >> idbuscar;
        reservass r;
        bool encontrado = false;
        while (archivo.read(reinterpret_cast<char*>(&r), sizeof(reservass)))
        {
            if (r.idreservas == idbuscar && r.Activo) {
                encontrado = true;
                int posicion = static_cast<int>(archivo.tellg()) - sizeof(reservass);
                    r.Activo = false;
                archivo.seekp(posicion);
                archivo.write(reinterpret_cast<char*>(&r), sizeof(reservass));
            }

           return 0;
        }
        
    }
	socio nuevoSocio;
	std::cout << "Ingrese el nuevo nombre: ";
	std::cin >> nuevoSocio.nombre;
	std::cout << "Ingrese el nuevo apellido: ";
	std::cin >> nuevoSocio.apellido;
	std::cout << "Ingrese la nueva edad: ";
	std::cin >> nuevoSocio.edad;
	std::cout << "Ingrese el nuevo deporte: ";
	std::cin >> nuevoSocio.deporte;
	archivo.seekp((socioAModificar - 1) * sizeof(socio), std::ios::beg);
	archivo.write(reinterpret_cast<char*>(&nuevoSocio), sizeof(socio));
	archivo.close();
}
