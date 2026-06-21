#include <iostream>
#include <string>
using namespace std;

struct Videojuego {
    int codigo;
    string nombre;
    float precio;
    int cantidad;
};

const int MAX = 100;


void registrarVideojuego(Videojuego juegos[], int &total);
void mostrarInventario(Videojuego juegos[], int total);
int buscarVideojuego(Videojuego juegos[], int total, int codigo);
void registrarVenta(Videojuego juegos[], int total);
void reabastecerInventario(Videojuego juegos[], int total);
void mostrarEstadisticas(Videojuego juegos[], int total);

int main() {

    Videojuego juegos[MAX];

    juegos[0] = {1, "Free Fire", 10.00, 10};
    juegos[1] = {2, "Brawl Stars", 7.99, 20};
    juegos[2] = {3, "Pokemon Go", 15.00, 10};
    juegos[3] = {4, "Pokemon Espada", 100.00, 15};
    juegos[4] = {5, "Fortnite", 33.99, 50};
    juegos[5] = {6, "Fifa 26", 100.00, 33};
    juegos[6] = {7, "Clash of Clans", 4.99, 7};
    juegos[7] = {8, "Clash Royale", 10.00, 5};
    juegos[8] = {9, "Halo", 99.99, 200};
    juegos[9] = {10, "Super Smash Bros.", 59.99, 45};

    int total = 10;
    int opcion;
    
    

    do {
        
        cout << "====================================" << endl;
        cout << "======= TIENDA GAME SV UCA =========" << endl;
        cout << "====================================" << endl; 
        cout << "1. Registrar videojuego" << endl;
        cout << "2. Mostrar inventario" << endl;
        cout << "3. Buscar videojuego" << endl;
        cout << "4. Registrar venta" << endl;
        cout << "5. Reabastecer inventario" << endl;
        cout << "6. Mostrar estadisticas" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cout << endl;
        cin >> opcion;

        switch(opcion) {

            case 1:
                registrarVideojuego(juegos, total);
                break;

            case 2:
                mostrarInventario(juegos, total);
                break;

            case 3: {
                int codigo;
                
                cout << "Ingrese el codigo del videojuego: " << endl;
                cout << endl;
                cin >> codigo;

                int posicion = buscarVideojuego(juegos, total, codigo);

                if(posicion == -1) {
                    cout << "\nVideojuego no encontrado." << endl;
                } else {
                    cout << "\n=== VIDEOJUEGO ENCONTRADO ===";
                    cout << "\nCodigo: " << juegos[posicion].codigo;
                    cout << "\nNombre: " << juegos[posicion].nombre;
                    cout << "\nPrecio: $" << juegos[posicion].precio;
                    cout << "\nCantidad: " << juegos[posicion].cantidad << endl;
                }

                break;
            }

            case 4:
                registrarVenta(juegos, total);
                break;

            case 5:
                reabastecerInventario(juegos, total);
                break;

            case 6:
                mostrarEstadisticas(juegos, total);
                break;

            case 7:
                cout << "\nSaliendo del programa" << endl;
                break;

            default:
                cout << "\nOpcion invalida." << endl;
        }

    } while(opcion != 7);

    return 0;
}

int buscarVideojuego(Videojuego juegos[], int total, int codigo) {

    for(int i = 0; i < total; i++) {
        if(juegos[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}


void registrarVideojuego(Videojuego juegos[], int &total) {

    if(total >= MAX) {
        cout << "\nNo hay espacio para mas videojuegos." << endl;
        return;
    }

    int codigo;

    cout << "\nIngrese el codigo: ";
    cin >> codigo;

    if(buscarVideojuego(juegos, total, codigo) != -1) {
        cout << "\nError: ya existe un videojuego con ese codigo." << endl;
        return;
    }

    juegos[total].codigo = codigo;

    cin.ignore();

    cout << "Ingrese el nombre: ";
    getline(cin, juegos[total].nombre);

    cout << "Ingrese el precio: ";
    cin >> juegos[total].precio;

    cout << "Ingrese la cantidad disponible: ";
    cin >> juegos[total].cantidad;

    total++;
    

    cout << "Videojuego registrado correctamente." << endl;
    cout << endl;
}


void mostrarInventario(Videojuego juegos[], int total) {

    if(total == 0) {
        cout << "\nNo hay videojuegos registrados." << endl;
        return;
    }

    cout << "\n========= INVENTARIO =========";

    for(int i = 0; i < total; i++) {

        cout << "\n=========";
        cout << "\nCodigo: " << juegos[i].codigo;
        cout << "\nNombre: " << juegos[i].nombre;
        cout << "\nPrecio: $" << juegos[i].precio;
        cout << "\nCantidad: " << juegos[i].cantidad;
    }

    cout << endl;
}

void registrarVenta(Videojuego juegos[], int total) {

    int codigo, cantidad;

    cout << "\nIngrese el codigo del videojuego: ";
    cin >> codigo;

    int posicion = buscarVideojuego(juegos, total, codigo);

    if(posicion == -1) {
        cout << "\nVideojuego no encontrado." << endl;
        return;
    }

    cout << "Cantidad a vender: ";
    cin >> cantidad;

    if(cantidad > juegos[posicion].cantidad) {
        cout << "\nNo hay suficientes unidades disponibles." << endl;
    } else {
        juegos[posicion].cantidad -= cantidad;
        cout << "\nVenta realizada correctamente." << endl;
    }
}


void reabastecerInventario(Videojuego juegos[], int total) {

    int codigo, cantidad;

    cout << "\nIngrese el codigo del videojuego: ";
    cin >> codigo;

    int posicion = buscarVideojuego(juegos, total, codigo);

    if(posicion == -1) {
        cout << "\nVideojuego no encontrado." << endl;
        return;
    }

    cout << "Cantidad a agregar: ";
    cin >> cantidad;

    juegos[posicion].cantidad += cantidad;

    cout << "\nInventario actualizado." << endl;
}


void mostrarEstadisticas(Videojuego juegos[], int total) {
    
    cout << endl;
    cout << "========= ESTADISTICAS =========" << endl;

    cout << "\nCantidad total de videojuegos: " << total;

    int suma = 0;

    for(int i = 0; i < total; i++) {
        suma += juegos[i].cantidad;
    }

    cout << "\nCantidad total de unidades: " << suma;

    if(total > 0) {

        int mayor = 0;

        for(int i = 1; i < total; i++) {
            if(juegos[i].cantidad > juegos[mayor].cantidad) {
                mayor = i;
            }
        }

        cout << "\nJuego con mas unidades: ";
        cout << juegos[mayor].nombre;
    }

    cout << endl;
}