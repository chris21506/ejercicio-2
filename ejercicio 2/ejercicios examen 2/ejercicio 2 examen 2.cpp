//Julio Christopher Beltran Solano
// youtube video https://youtu.be/9LKr1mGdkTA?si=E5MbE22sj_Nk66IG
#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

// Clase plantilla que implementa una lista ligada con nodos centinela
template <typename T>
class SentinelLinkedList {
private:
    // Estructura interna del nodo
    struct Node {
        T value;
        Node* next;

        Node(const T& val, Node* nxt = nullptr) : value(val), next(nxt) {}
    };

    Node* head; // Nodo centinela al inicio
    Node* tail; // Nodo centinela al final
    int count;  // Número de elementos en la lista

public:
    // Constructor: crea nodos centinela vacíos
    SentinelLinkedList() {
        head = new Node(T());      // Nodo centinela inicial
        tail = new Node(T());      // Nodo centinela final
        head->next = tail;         // Lista vacía entre head y tail
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

    // Inserta un nuevo nodo al final (antes del nodo tail)
    void PushBack(const T& value) {
        Node* current = head;
        // Avanzamos hasta el nodo justo antes del tail
        while (current->next != tail) {
            current = current->next;
        }
        Node* nuevo = new Node(value, tail);
        current->next = nuevo;
        count++;
    }

    // Elimina y retorna el primer elemento (después del head)
    T PopFront() {
        if (head->next == tail) {
            throw underflow_error("Lista vacía");
        }
        Node* nodoEliminar = head->next;
        T valor = nodoEliminar->value;
        head->next = nodoEliminar->next;
        delete nodoEliminar;
        count--;
        return valor;
    }

    // Devuelve el valor del primer elemento (sin eliminarlo)
    T Front() {
        if (head->next == tail) {
            throw underflow_error("Lista vacía");
        }
        return head->next->value;
    }

    // Devuelve el número de elementos en la lista
    int GetCount() const {
        return count;
    }
};
