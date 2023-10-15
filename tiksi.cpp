#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct InventarioItem {
    string nombre;
    int cantidad;
};

vector<InventarioItem> inventario;

void agregarItem() {
    InventarioItem item;
    cout << "Ingrese el nombre del suministro: ";
    cin.ignore();
    getline(cin, item.nombre);
    cout << "Ingrese la cantidad: ";
    cin >> item.cantidad;
    inventario.push_back(item);
    cout << "El suministro ha sido agregado al inventario.\n";
}

void mostrarInventario() {
    if (inventario.empty()) {
        cout << "El inventario está vacío.\n";
        return;
    }

    cout << "Inventario:\n";
    for (const auto& item : inventario) {
        cout << "Nombre: " << item.nombre << ", Cantidad: " << item.cantidad << "\n";
    }
}

void modificarItem() {
    if (inventario.empty()) {
        cout << "El inventario está vacío. No hay elementos para modificar.\n";
        return;
    }

    string nombreBusqueda;
    cout << "Ingrese el nombre del suministro que desea modificar: ";
    cin.ignore();
    getline(cin, nombreBusqueda);

    auto it = find_if(inventario.begin(), inventario.end(), [nombreBusqueda](const InventarioItem& item) {
        return item.nombre == nombreBusqueda;
    });

    if (it != inventario.end()) {
        cout << "Ingrese la nueva cantidad: ";
        cin >> it->cantidad;
        cout << "Cantidad actualizada correctamente.\n";
    } else {
        cout << "El suministro no se encontró en el inventario.\n";
    }
}

int main() {
    int opcion;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Agregar suministro\n";
        cout << "2. Modificar suministro\n";
        cout << "3. Mostrar inventario\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarItem();
                break;
            case 2:
                modificarItem();
                break;
            case 3:
                mostrarInventario();
                break;
            case 4:
                cout << "Saliendo del programa. ¡Hasta luego!\n";
                return 0;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
                break;
        }
    }

    return 0;
}