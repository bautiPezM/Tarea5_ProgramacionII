#pragma once

#include <fstream>
#include <string>
#include <vector>



int altareservas();
int listaReservas(); //Consulta general de todas las reservas
int busquedaID(); //Busqueda de una reserva por ID
int confirmarReserva(); //Confirmacion de una reserva existente
int modificarReserva(); //Modificacion de una reserva existente
int bajaReserva(); //Baja lógica de una reserva existente
int guardarArchivo(); //Guardar la lista de reservas en un archivo binario
int consultaEspecial();//Consulta especial del caso