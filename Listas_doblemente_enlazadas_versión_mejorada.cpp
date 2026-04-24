#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void insertarInicio(Nodo*& head, Nodo*& tail, int valor) {
    Nodo* nuevo = new Nodo{valor, head, NULL};

    if (head != NULL)
        head->anterior = nuevo;
    else
        tail = nuevo;

    head = nuevo;
}

void insertarFinal(Nodo*& head, Nodo*& tail, int valor) {
    Nodo* nuevo = new Nodo{valor, NULL, tail};

    if (tail != NULL)
        tail->siguiente = nuevo;
    else
        head = nuevo;

    tail = nuevo;
}

void mostrarAdelante(Nodo* head) {
    while (head != NULL) {
        cout << head->dato << " <-> ";
        head = head->siguiente;
    }
    cout << "NULL\n";
}

void mostrarAtras(Nodo* tail) {
    while (tail != NULL) {
        cout << tail->dato << " <-> ";
        tail = tail->anterior;
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

void eliminar(Nodo*& head, Nodo*& tail, int valor) {
    Nodo* temp = head;

    while (temp != NULL && temp->dato != valor) {
        temp = temp->siguiente;
    }

    if (temp == NULL) return;

    if (temp->anterior == NULL) {
        head = temp->siguiente;
        if (head != NULL)
            head->anterior = NULL;
        else
            tail = NULL;
    } else if (temp->siguiente == NULL) {
        tail = temp->anterior;
        tail->siguiente = NULL;
    } else {
        temp->anterior->siguiente = temp->siguiente;
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
    Nodo* tail = NULL;
    int op, valor;

    do {
        cout << "\n===== MENU (TAIL) =====\n";
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
            case 1: cin >> valor; insertarInicio(head, tail, valor); break;
            case 2: cin >> valor; insertarFinal(head, tail, valor); break;
            case 3: mostrarAdelante(head); break;
            case 4: mostrarAtras(tail); break;
            case 5:
                cin >> valor;
                cout << (buscar(head, valor) ? "SI existe\n" : "NO existe\n");
                break;
            case 6: cin >> valor; eliminar(head, tail, valor); break;
            case 7: cout << "Total: " << contar(head) << endl; break;
        }

    } while (op != 0);

    liberar(head);
}