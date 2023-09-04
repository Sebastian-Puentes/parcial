#include <iostream>
#include <conio.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}  

int main() {
    const int limiteSuma = 30; 
    int numeros[30]; 
    int contador = 0; 
    while (contador < 30) {
        int opcion;
        cout << "Menú:" << endl;
        cout << "1. Ingresar numero" << endl;
        cout << "2. Ordenar numeros e imprimir" <<endl;
        cout << "3. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        if (opcion == 1) {
            if (contador < 30) {
                cout << "Ingrese un numero entero: ";
                cin >> numeros[contador];
                contador++;
            } else {
            cout << "Se ha alcanzado el límite de numeros." << endl;
            }
        } else if (opcion == 2) {
            bubbleSort(numeros, contador);
            cout << "Numeros ordenados: ";
            for (int i = 0; i < contador; i++) {
                cout << numeros[i] << " ";
            }
            cout << std::endl;
        } else if (opcion == 3) {
            cout << "Saliendo del programa." << std::endl;
            break;
        } else {
            cout << "Opcion no valida. Por favor, elija 1, 2 o 3." << std::endl;
        }
    }
    return 0;
}




