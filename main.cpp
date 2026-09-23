#include<iostream>
#include "gestion.h"

using namespace std;

int main() {
    char opcion = ' ';

    do {

        cout << "CASO 3: RESERVA DE AULAS Y LABORATORIO" << endl;
        cout << "1. Alta de reservas" << endl;
        cout << "2. Consulta general" << endl;
        cout << "3. Busqueda por ID" << endl;
        cout << "4. Modificacion" << endl;
        cout << "5. Confirmar reserva" << endl;
        cout << "6. Baja logica" << endl;
        cout << "7. Consulta especial" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
        case '1': {
            cout << endl;
            int valor = altareservas();
            if (valor == -1) cout << "ocurrio un error" << endl;
            cout << endl;
            system("pause");
            break;
        }
        case '2': {
            cout << endl;
            int valor = listaReservas();
            if (valor == -1) cout << "ocurrio un error" << endl;
            if (valor == 1) cout << "se realizo con exito" << endl;
            cout << endl;
            system("pause");
            break;
        }
        case '3': {
            cout << endl;
            int valor = busquedaID();
            if (valor == -1) cout << "ocurrio un error" << endl;
            else  cout << "se realizo con exito" << endl;
            system("pause");
            break;
        }
        case '4': {
            cout << endl;
            int valor = modificarReserva();
            if (valor == -1) cout << "ocurrio un error" << endl;
            if (valor == 0) cout << "se realizo con exito" << endl;
            cout << endl;
            system("pause");
            break;
        }
        case '5': {
            cout << endl;
            int valor = confirmarReserva();
            if (valor == -1) cout << "ocurrio un error" << endl;
            if (valor == 0) cout << "se realizo con exito" << endl;
            cout << endl;
            system("pause");
            break;
        }
        case '6': {
            cout << endl;
            int valor = bajaReserva();
            if (valor == -1) cout << "ocurrio un error" << endl;
            if (valor == 0) cout << "se realizo con exito" << endl;
            cout << endl;
            system("pause");
            break;
        }
        case '7': {
            cout << endl;
            int valor = consultaEspecial();
            if (valor == -1) cout << "ocurrio un error" << endl;
            if (valor == 0) cout << "se realizo con exito" << endl;
            cout << endl;
            system("pause");
            break;
        }
        case '8': {
            cout << "Saliendo del programa..." << endl;
            system("pause");
            break;
        }
        default: {
            cout << "Opcion invalida. Intente de nuevo" << endl;
            system("pause");
            break;
        }
        }
        system("cls");
    } while (opcion != '8');

    return 0;

}
