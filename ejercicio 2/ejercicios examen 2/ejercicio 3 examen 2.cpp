//Julio Christopher Beltran Solano
//youtube video https://youtu.be/sjtlbHbhMiU?si=IffD85pENUZgAbWh
#include <iostream>
#include <forward_list> // Para usar std::forward_list
#include <stdexcept>    // Para lanzar excepciones
using namespace std;

// Clase plantilla LStack: Implementa una pila (Stack) usando forward_list
template <typename T>
class LStack {
private:
    forward_list<T> elementos; // Lista ligada simple para almacenar los elementos
    int cantidadElementos;     // Lleva el conteo de los elementos en la pila

public:
    // Constructor por defecto: inicia pila vacía
    LStack() : cantidadElementos(0) {}

    // Función para insertar un nuevo elemento al tope de la pila
    void Push(const T& valor) {
        elementos.push_front(valor); // Insertamos al inicio (O(1))
        cantidadElementos++;         // Aumentamos el contador
    }

    // Función para remover el elemento del tope de la pila
    void Pop() {
        if (elementos.empty()) {
            throw underflow_error("Error: la pila está vacía"); // Evita eliminar si no hay elementos
        }
        elementos.pop_front(); // Elimina el primer elemento (O(1))
        cantidadElementos--;   // Disminuye el contador
    }

    // Función para obtener el elemento del tope de la pila sin eliminarlo
    T& Peak() {
        if (elementos.empty()) {
            throw underflow_error("Error: la pila está vacía"); // Evita acceder a elemento inexistente
        }
        return elementos.front(); // Retorna el primer elemento (O(1))
    }

    // Función para saber cuántos elementos hay en la pila
    int Count() const {
        return cantidadElementos; // Devuelve el número de elementos
    }

    // Función para verificar si la pila está vacía
    bool EstaVacia() const {
        return elementos.empty(); // true si la lista está vacía
    }
};

// ======================
// Función main de prueba
// ======================
int main() {
    LStack<int> pila;

    // Insertamos elementos
    pila.Push(10);
    pila.Push(20);
    pila.Push(30);

    cout << "Elemento en el tope: " << pila.Peak() << endl;       // Debe mostrar 30
    cout << "Elementos en la pila: " << pila.Count() << endl;    // Debe mostrar 3

    pila.Pop(); // Elimina 30

    cout << "Nuevo tope: " << pila.Peak() << endl;               // Debe mostrar 20
    cout << "Elementos restantes: " << pila.Count() << endl;     // Debe mostrar 2

    return 0;
}
