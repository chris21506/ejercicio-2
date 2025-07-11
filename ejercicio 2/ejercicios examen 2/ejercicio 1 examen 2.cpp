//Julio Christopher Beltran Solano
// youtube video https://youtu.be/_WaoQWAcxw0?si=UdOLgMvwFddjCTBu
#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

// Clase plantilla para una lista ligada con nodo centinela
template <typename T>
class SentinelLinkedList {
private:
    // Definición del nodo
    struct Node {
        T value;
        Node* next;

        Node(const T& val, Node* nxt = nullptr) : value(val), next(nxt) {}
    };

    Node* head; // Nodo centinela al inicio
    Node* tail; // Nodo centinela al final
    int count;  // Contador de elementos

public:
    // Constructor: inicializa los nodos centinela
    SentinelLinkedList() {
        head = new Node(T());     // Nodo centinela al inicio (no guarda datos útiles)
        tail = new Node(T());     // Nodo centinela final
        head->next = tail;        // Al principio, head apunta directamente a tail
        count = 0;
    }

    // Destructor: libera todos los nodos
    ~SentinelLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Devuelve el número de elementos en la lista
    int GetCount() const {
        return count;
    }

    // ================================
    // NUEVA FUNCIÓN: PushFront
    // ================================
    // Inserta un nuevo nodo justo después del nodo head (al inicio de la lista)
    void PushFront(const T& value) {
        Node* nuevo = new Node(value);    // Crea nuevo nodo con el valor dado
        nuevo->next = head->next;         // El nuevo nodo apunta al que estaba después del head
        head->next = nuevo;               // El head ahora apunta al nuevo nodo
        count++;                          // Aumenta el contador
    }

    // ================================
    // NUEVA FUNCIÓN: PopFront
    // ================================
    // Elimina el primer nodo después del head y retorna su valor
    T PopFront() {
        if (head->next == tail) {
            // Si no hay elementos entre head y tail, la lista está vacía
            throw underflow_error("Lista vacía: no se puede hacer PopFront");
        }

        Node* nodoEliminar = head->next;   // Nodo a eliminar (el primero real)
        T valor = nodoEliminar->value;     // Guardamos el valor para retornarlo
        head->next = nodoEliminar->next;   // Saltamos el nodo a eliminar
        delete nodoEliminar;               // Liberamos memoria
        count--;                           // Disminuimos el contador
        return valor;                      // Retornamos el valor eliminado
    }
};
