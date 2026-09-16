#pragma once
#include <vector>


namespace calculo {

    struct reservas {
        char nombre[50];
        char apellido[50];
        int edad;
        char deporte[50];
    };
    void altareservas(std::vector<reservas>& lista);
    void listarreservas(const std::vector<reservas>& lista);
    void modificarSocio(std::vector<reservas>& lista);
    void bajaSocio(std::vector<reservas>& lista);
    int guardarArchivo(const std::vector<reservas>& lista);
    int leerArchivo(std::vector<reservas>& lista);

}