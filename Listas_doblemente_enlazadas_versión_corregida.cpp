#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void insertarInicio(Nodo*& head, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = head;
    nuevo->anterior = NULL;

    if (head != NULL) {
        head->anterior = nuevo;
    }

    head = nuevo;
}

void insertarFinal(Nodo*& head, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (head == NULL) {
        nuevo->anterior = NULL;
        head = nuevo;
        return;
    }

    Nodo* temp = head;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    temp->siguiente = nuevo;
    nuevo->anterior = temp;
}

void mostrarAdelante(Nodo* head) {
    Nodo* temp = head;
    while (temp != NULL) {
        cout << temp->dato << " <-> ";
        temp = temp->siguiente;
    }
    cout << "NULL\n";
}

void mostrarAtras(Nodo* head) {
    if (head == NULL) return;

    Nodo* temp = head;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    while (temp != NULL) {
        cout << temp->dato << " <-> ";
        temp = temp->anterior;
    }
    cout << "NULL\n";
}

bool buscar(Nodo* head, int valor) {
    while (head != NULL) {
        if (head->dato == valor)
            return true;
        head = head->siguiente;
    }
    return false;
}

void eliminar(Nodo*& head, int valor) {
    Nodo* temp = head;

    while (temp != NULL && temp->dato != valor) {
        temp = temp->siguiente;
    }

    if (temp == NULL) return;

    if (temp->anterior == NULL) {
        head = temp->siguiente;
        if (head != NULL)
            head->anterior = NULL;
    } else {
        temp->anterior->siguiente = temp->siguiente;
        if (temp->siguiente != NULL)
            temp->siguiente->anterior = temp->anterior;
    }

    delete temp;
}

int contar(Nodo* head) {
    int c = 0;
    while (head != NULL) {
        c++;
        head = head->siguiente;
    }
    return c;
}

void liberar(Nodo*& head) {
    while (head != NULL) {
        Nodo* temp = head;
        head = head->siguiente;
        delete temp;
    }
}

int main() {
    Nodo* head = NULL;
    int op, valor;

    do {
        cout << "\n===== MENU =====\n";
        cout << "Nombre: Jimy Aroldo Morales Carranza\n";
        cout << "1. Insertar inicio\n";
        cout << "2. Insertar final\n";
        cout << "3. Mostrar adelante\n";
        cout << "4. Mostrar atras\n";
        cout << "5. Buscar\n";
        cout << "6. Eliminar\n";
        cout << "7. Contar\n";
        cout << "0. Salir\n";
        cin >> op;

        switch(op) {
            case 1: cin >> valor; insertarInicio(head, valor); break;
            case 2: cin >> valor; insertarFinal(head, valor); break;
            case 3: mostrarAdelante(head); break;
            case 4: mostrarAtras(head); break;
            case 5:
                cin >> valor;
                cout << (buscar(head, valor) ? "SI existe\n" : "NO existe\n");
                break;
            case 6: cin >> valor; eliminar(head, valor); break;
            case 7: cout << "Total: " << contar(head) << endl; break;
        }

    } while (op != 0);

    liberar(head);
}