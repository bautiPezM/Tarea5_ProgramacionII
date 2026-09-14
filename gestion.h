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

int altareservas(); 
int listaReservas(); //Consulta general de todas las reservas
int busquedaID(); //Busqueda de una reserva por ID
int confirmarReserva(); //Confirmacion de una reserva existente
int modificarReserva(); //Modificacion de una reserva existente
int bajaReserva(); //Baja lógica de una reserva existente
int guardarArchivo(); //Guardar la lista de reservas en un archivo binario
