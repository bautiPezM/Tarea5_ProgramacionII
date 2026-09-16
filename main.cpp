#include<iostream>
#include "gestion.h"

using namespace std;

int main() {


    do {
        char opcion = ' ';
        cout << "CASO 3: RESERVA DE AULAS Y LABORATORIO" << endl;
        cout << "Seleccione una opcion: " << endl;
        cout << "Alta de reservas" << endl;
        cout << "Consulta general" << endl;
        cout << "Busqueda por ID" << endl;
        cout << "Modificacion" << endl;
        cout << "Confirmar reserva" << endl;
        cout << "Baja logica" << endl;
        cin >> opcion;
        switch (opcion) {
        case '1': {
             int valor = altareservas();
             if (valor == -1) cout << "ocurrio un error"<<endl;

        }break;
        case '2': {
            int valor = listaReservas();
            if (valor == -1) cout << "ocurrio un error" << endl;
            if (valor == 1) cout << "se realizo con exito"<<endl;

        }break;
        case '3': {
            int valor = busquedaID();
            if (valor == -1) { cout << "ocurrio un error" << endl; 
            return;
            }
            cout << "ID: " << valor<<endl;


        }break;
        case '4': {
            int valor = bajaReserva();
            if (valor == -1) cout << "ocurrio un error" << endl;
            if (valor == 0) cout << "se realizo con exito" << endl;

        }break;
        case '5': {
            int valor = modificarReserva();
            if (valor == -1) cout << "ocurrio un error" << endl;
            if (valor == 0) cout << "se realizo con exito" << endl;

        }break;
        case '6': {
            int valor = confirmarReserva();
            if (valor == -1) cout << "ocurrio un error" << endl;
            if (valor == 0) cout << "se realizo con exito" << endl;
        }break;

        }

    } while (opcion != '7');



}

