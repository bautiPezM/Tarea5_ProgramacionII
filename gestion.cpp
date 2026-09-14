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
