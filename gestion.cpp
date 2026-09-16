#include "gestionar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int listaReservas() {
	Reserva reservas;
	std::ifstream archivo("reservas.bin", std::ios::binary);
	if (!archivo) {
		std::cout << "Error al abrir el archivo" << std::endl;
		return -1;
	}

	while (archivo.read(reinterpret_cast<char*>(&reservas), sizeof(Reserva))) {
		std::cout << "ID: " << reservas.idReserva << std::endl;
		std::cout << "Responsable: " << reservas.Responsable << std::endl;
		std::cout << "Aula: " << reservas.Aula << std::endl;
		std::cout << "Cantidad de personas: " << reservas.CantidadPersonas << std::endl;
		std::cout << "Confirmada: " << (reservas.confirmada ? "Si" : "No") << std::endl;
		std::cout << "Activo: " << (reservas.Activo ? "Si" : "No") << std::endl;
		std::cout << "---" << std::endl;
	}
	archivo.close();
	return 1;
}
int busquedaID() {
	int id;
	std::cout << "Ingrese el ID de la reserva a buscar: ";
	std::cin >> id;
	Reserva reservas;
	std::ifstream archivo("reservas.bin", std::ios::binary);
	if (!archivo) {
		std::cout << "Error al abrir el archivo" << std::endl;
		return -1;
	}
	while (archivo.read(reinterpret_cast<char*>(&reservas), sizeof(Reserva))) {
		if (reservas.idReserva == id) {
			std::cout << "ID: " << reservas.idReserva << std::endl;
			std::cout << "Responsable: " << reservas.Responsable << std::endl;
			std::cout << "Aula: " << reservas.Aula << std::endl;
			std::cout << "Cantidad de personas: " << reservas.CantidadPersonas << std::endl;
			std::cout << "Confirmada: " << (reservas.confirmada ? "Si" : "No") << std::endl;
			std::cout << "Activo: " << (reservas.Activo ? "Si" : "No") << std::endl;
			archivo.close();
			return 1; // Reserva encontrada
		}
	}
	archivo.close();
	std::cout << "Reserva con ID " << id << " no encontrada." << std::endl;
	return 0; // Reserva no encontrada
}

int altareservas() {
	std::ofstream archivo("reservas.bin", std::ios::binary| std::ios::app);
	if (!archivo) {
		std::cout << "Error al abrir el archivo" << std::endl;
		return 1;
	}
	
	Reserva p;
	std::cout << "id de reserva: ";
	std::cin >> p.idReserva;
	std::cout << "Responsable: ";
	std::cin >> p.Responsable;
	std::cout << "Aula: ";
	std::cin >> p.Aula;
	std::cout << "Cantidad de personas: ";
	std::cin >> p.CantidadPersonas;
	p.confirmada = false;
	p.Activo = true;

	archivo.write(reinterpret_cast<char*>(&p), sizeof(Reserva));
	archivo.close();
}
int bajaReserva() {
    std::fstream archivo("reservas.bin", std::ios::binary | std::ios::in | std::ios::out);
    if (!archivo){
            std::cerr << "Error al abrir archivo";
            return -1;
    }
    int idbuscar;
    std::cout << "Ingrese el id a eliminar: "; std::cin >> idbuscar;
    Reserva r;
    bool encontrado = false;
    while (archivo.read(reinterpret_cast<char*>(&r), sizeof(Reserva))){
        if (r.idreservas == idbuscar && r.Activo) {
            encontrado = true;
            int posicion = static_cast<int>(archivo.tellg()) - sizeof(Reserva);
            r.Activo = false;
            archivo.seekp(posicion);
            archivo.write(reinterpret_cast<char*>(&r), sizeof(Reserva));
			break;
        }
    }
	return 0;
}

int modificarReserva() {

	std::fstream archivo("reservas.dat", std::ios::in | std::ios::out | std::ios::binary);
	if (!archivo) {
		std::cout << "Error al abrir el archivo" << std::endl;
		return -1;
	}
	int idEncontrado = busquedaID();
	if (idEncontrado == -1) {
		std::cout << "no existe el id" << std::endl;
		return -1;
	}
	Reservas reservas_lectura;
	bool encontrado;
	while (archivo.read(reinterpret_cast<char*>(&reservas_lectura)), sizeof(reservas)) {
		if (reservas_lectura.ID == idEncontrado) {
			encontrado = true;

			int posicion = static_cast<int>(archivo.tellg() - sizeof(Reservas));
			std::cout << "ingrese el nuevo responsable: ";
			std::cin >> reservas_lectura.responsable;
			std::cout << "ingrese el nuevo aula: ";
			std::cin >> reservas_lectura.aula;
			std::cout << "ingrese la nueva cantidad de personas: ";
			std::cin >> reservas_lectura.cantidad;
			bool opcion = false;
			std::cout << "ingrese si es confirmada o activa"<<std::endl;
			do {
				std::cout << "si escribe 1 selecciona confirmada si escribe 0 selecciona activa: ";
				cin >> opcion;
			} while (opcion != 1 && opcion != 0) 
			if (opcion == 1)	reservas_lectura.activa = 1;
			if(opcion == 0) reservas_lectura.confirmada = 1;
			
			std::cin >> reservas_lectura.confirmada;
			if (reservas_lectura.confirmada == 0) {
				std::cout << "ingrese si es confirmada, si:1 no:0: ";
				std::cin >> reservas_lectura.activa;
			}
			archivo.seekp(posicion);
			archivo.write(reinterpret_cast<char*>(&reservas_lectura), sizeof(Reservas));
			break;
		}
	}
	if (encontrado){
		std::cout << "modificacion finalizada." << endl;}
	else std::cout << "no existe el id";
	archivo.close();
	return 0;
}
