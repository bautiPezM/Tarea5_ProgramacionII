#include "gestion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits> 

struct Reservas {
	int idReserva;
	char Responsable[50];
	char Aula[50];
	int CantidadPersonas;
	bool confirmada;
	bool Activo;

};

int listaReservas() {
	Reservas reservas;
	std::ifstream archivo("reservas.dat", std::ios::binary);
	if (!archivo) {
		std::cout << "Error al abrir el archivo" << std::endl;
		return -1;
	}

	while (archivo.read(reinterpret_cast<char*>(&reservas), sizeof(Reservas))) {
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
	Reservas reservas;
	std::ifstream archivo("reservas.dat", std::ios::binary);
	if (!archivo) {
		std::cout << "Error al abrir el archivo" << std::endl;
		return -1;
	}
	while (archivo.read(reinterpret_cast<char*>(&reservas), sizeof(Reservas))) {
		if (reservas.idReserva == id) {
			std::cout << "ID: " << reservas.idReserva << std::endl;
			std::cout << "Responsable: " << reservas.Responsable << std::endl;
			std::cout << "Aula: " << reservas.Aula << std::endl;
			std::cout << "Cantidad de personas: " << reservas.CantidadPersonas << std::endl;
			std::cout << "Confirmada: " << (reservas.confirmada ? "Si" : "No") << std::endl;
			std::cout << "Activo: " << (reservas.Activo ? "Si" : "No") << std::endl;
			archivo.close();
			return reservas.idReserva; // Reserva encontrada
		}
	}
	archivo.close();
	std::cout << "Reserva con ID " << id << " no encontrada." << std::endl;
	return -1; // Reserva no encontrada
}

int altareservas() {
	std::ofstream archivo("reservas.dat", std::ios::binary | std::ios::app);
	if (!archivo) {
		std::cout << "Error al abrir el archivo" << std::endl;
		return 1;
	}

	Reservas p;
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

	archivo.write(reinterpret_cast<char*>(&p), sizeof(Reservas));
	archivo.close();

	return 0;
}
int bajaReserva() {
	std::fstream archivo("reservas.dat", std::ios::binary | std::ios::in | std::ios::out);
	if (!archivo) {
		std::cerr << "Error al abrir archivo";
		return -1;
	}
	int idbuscar;
	std::cout << "Ingrese el id a eliminar: "; std::cin >> idbuscar;
	Reservas r;
	bool encontrado = false;
	while (archivo.read(reinterpret_cast<char*>(&r), sizeof(Reservas))) {
		if (r.idReserva == idbuscar && r.Activo) {
			encontrado = true;
			int posicion = static_cast<int>(archivo.tellg()) - sizeof(Reservas);
			r.Activo = false;
			archivo.seekp(posicion);
			archivo.write(reinterpret_cast<char*>(&r), sizeof(Reservas));
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
	bool encontrado = false;
	while (archivo.read(reinterpret_cast<char*>(&reservas_lectura), sizeof(Reservas))) {
		if (reservas_lectura.idReserva == idEncontrado) {
			encontrado = true;

			int posicion = static_cast<int>(archivo.tellg()) - sizeof(Reservas);
			std::cout << "ingrese el nuevo responsable: ";
			std::cin >> reservas_lectura.Responsable;
			std::cout << "ingrese el nuevo aula: ";
			std::cin >> reservas_lectura.Aula;
			std::cout << "ingrese la nueva cantidad de personas: ";
			std::cin >> reservas_lectura.CantidadPersonas;

			char opcion = ' ';

			do {
				std::cout << "ingrese si es confirmada" << std::endl;
				std::cout << "si: 1" << std::endl;
				std::cout << "no: 0" << std::endl;
				std::cin >> opcion;


			} while (opcion != '1' && opcion != '0');


			reservas_lectura.confirmada = (opcion == '1');


			do {

				std::cout << "ingrese si es activa" << std::endl;
				std::cout << "si: 1" << std::endl;
				std::cout << "no: 0" << std::endl;
				std::cin >> opcion;



			} while (opcion != '1' && opcion != '0');
			reservas_lectura.Activo = (opcion == '1');

			archivo.seekp(posicion);
			archivo.write(reinterpret_cast<char*>(&reservas_lectura), sizeof(Reservas));
			break;
		}
	}
	if (encontrado) {
		std::cout << "modificacion finalizada." << std::endl;
	}
	else std::cout << "no existe el id";
	archivo.close();
	return 0;

}

int confirmarReserva() {
	std::fstream archivo("reservas.dat", std::ios::binary | std::ios::in | std::ios::out);
	if (!archivo) {
		std::cerr << "Error al abrir archivo";
		return -1;
	}
	int idbuscar;
	std::cout << "Ingrese el id a confirmar: "; std::cin >> idbuscar;
	Reservas r;
	bool encontrado = false;

	while (archivo.read(reinterpret_cast<char*>(&r), sizeof(Reservas))) {
		if (r.idReserva == idbuscar && r.Activo && r.confirmada == false) {
			encontrado = true;
			int posicion = static_cast<int>(archivo.tellg()) - sizeof(Reservas);
			r.confirmada = true;
			archivo.seekp(posicion);
			archivo.write(reinterpret_cast<char*>(&r), sizeof(Reservas));
			break;
		}
		else if (r.idReserva == idbuscar && r.Activo && r.confirmada == true) {
			encontrado = true;
			std::cout << "La reserva ya está confirmada." << std::endl;
			break;
		}
		else if (r.idReserva == idbuscar && !r.Activo) {
			encontrado = true;
			std::cout << "La reserva ha sido dada de baja." << std::endl;
			break;
		}
	}
	if (!encontrado) {
		std::cout << "No se encontró la reserva con el ID especificado." << std::endl;
	}
	archivo.close();
	return 0;
}



int guardarArchivo() {
	std::ofstream archivo("reservas.dat", std::ios::binary | std::ios::in | std::ios::out);
	if (!archivo) throw std::invalid_argument("No hay valores validos");

	std::vector<Reservas> lista;

	for (size_t i = 0; i < sizeof(Reservas); i++) {




		archivo.write(reinterpret_cast<const char*>(&lista[i]), sizeof(Reservas));
	}
	archivo.close();
	return 0;
}

