#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct nodo {
    int dato;
    nodo* siguiente;
};

void insertarlista(nodo*&, int n);
void mostrarLista(nodo* lista);
void actualizarNodo(nodo* lista, int n, int nuevoDato);

int main() {
    nodo* lista = NULL;
    char opcion;

    do {
        cout << "MENU:" << endl;
        cout << "1. Insertar un numero" << endl;
        cout << "2. Mostrar la lista circular" << endl;
        cout << "3. Actualizar numero" << endl;
        cout << "4. Salir"<< endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1': {
                int dato;
                cout << "Digite un numero: ";
                cin >> dato;
                cout<<"\n";
                insertarlista(lista, dato);
                break;
            }
            case '2' :{
                mostrarLista(lista);
                cout<<"\n";
                break;
            }
            case '3': {
                int dato, nuevoDato;
                cout << " Numero a actualizar: ";
                cin >> dato;
                cout << " Nuevo numero: ";
                cin >> nuevoDato;
                cout << "\n";
                actualizarNodo(lista, dato, nuevoDato);
                break;
            }
            case '4':
                cout << "Adios :D" << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (opcion != '4');

    return 0;
}

void insertarlista(nodo*& lista, int n) {
    nodo* nuevonodo = new nodo();
    nuevonodo->dato = n;
    if (lista == nullptr) {
        lista = nuevonodo;
        nuevonodo->siguiente = nuevonodo;  
    } else {
        nodo* ultimo = lista;
        while (ultimo->siguiente != lista) {
            ultimo = ultimo->siguiente;
        }
        nuevonodo->siguiente = lista;
        lista = nuevonodo;
        ultimo->siguiente = lista; 
    }
    cout << "Elemento " << n << " insertado en la lista correctamente" << endl;
}
void actualizarNodo(nodo* lista, int n, int nuevoDato) {
    if (lista == nullptr) {
        cout << "La lista está vacía" << endl;
        return;
    }

    nodo* m = lista;
    do {
        if (m->dato == n) {
            m->dato = nuevoDato;
            cout << "Elemento " << n << " actualizado a " << nuevoDato << " correctamente" << endl;
            return;
        }
        m = m->siguiente;
    } while (m != lista);
    cout << "Elemento " << n << " no ha sido encontrado en la lista" << endl;
}
void mostrarLista(nodo* lista) {
    if (lista == nullptr) {
        cout << "La lista está vacía" << endl;
        return;
    }

    nodo* actual = lista;
    do {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    } while (actual != lista);
    cout << endl;
}