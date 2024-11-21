#include <iostream>
#include <iomanip>

using namespace std;

// Lista de productos y sus precios por kilo
string productos[] = {"Arroz", "Azúcar", "Papa", "Maíz", "Lentejas", "Frijol", "Tomate", "Ajo", "Cebolla", "Harina"};
int preciosPorKilo[] = {3000, 4000, 2000, 2500, 5000, 6000, 3500, 8000, 4500, 2800}; 

void mostrarMenuProductos() {
    cout << "\nLista de productos disponibles:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ". " << productos[i] << " - Precio por kilo: $" << preciosPorKilo[i] << " pesos " << endl;
    }
    cout << "0. Finalizar compra" << endl;
}

int main() {
    int opcionProducto;
    float pesoGramos, valorTotal = 0;

    cout << "--- Bienvenido a la Tienda ---" << endl;

    while (true) {    
        mostrarMenuProductos();
  
        cout << "Seleccione el número del producto (o 0 para finalizar): ";
        cin >> opcionProducto;
  
        if (opcionProducto == 0) {
            break;
        }
 
        if (opcionProducto < 1 || opcionProducto > 10) {
            cout << "Opción inválida. Intente nuevamente." << endl;
            continue;
        }

        cout << "Ingrese el peso del producto en gramos: ";
        cin >> pesoGramos;
  
        if (pesoGramos <= 0) {
            cout << "El peso debe ser un número positivo. Intente nuevamente." << endl;
            continue;
        }
 
        float precioPorKilo;
        while (true) {
            cout << "Ingrese el precio por kilo en pesos: ";
            cin >> precioPorKilo;
 
            if (precioPorKilo <= 0) {
                cout << "El precio debe ser un número positivo. Intente nuevamente." << endl;
                continue;
            }
   
            if (precioPorKilo != preciosPorKilo[opcionProducto - 1]) {
                cout << "Precio de la tienda incorrecto. El precio correcto es: $"
                     << preciosPorKilo[opcionProducto - 1] << " pesos." << endl;
            } else {
                break; 
            }
        }
  
        float valorProducto = (pesoGramos / 1000) * precioPorKilo;
        valorTotal += valorProducto;
    
        cout << fixed << setprecision(2);
        cout << "El valor a pagar por " << pesoGramos << " gramos de "
             << productos[opcionProducto - 1] << " es: $" << valorProducto << " pesos." << endl;
    }
  
    cout << "\nEl total de su compra es: $" << valorTotal << " pesos." << endl;
    cout << "Gracias por su compra. ¡Vuelva pronto!" << endl;

    return 0;
}