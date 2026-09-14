#pragma once
#include <fstream>
#include <string>
#include <vector>
struct Reservas {
		int idReserva;
		char Responsable[50];
		char Aula[50];
		int CantidadPersonas;
		bool confirmada;
		bool Activo;

};

void altareservas(std::vector<reservas>& lista);
void listarreservas(const std::vector<reservas>& lista);
void modificarSocio(std::vector<reservas>& lista);
void bajaSocio(std::vector<reservas>& lista);
int guardarArchivo(const std::vector<reservas>& lista);
int leerArchivo(std::vector<reservas>& lista);
