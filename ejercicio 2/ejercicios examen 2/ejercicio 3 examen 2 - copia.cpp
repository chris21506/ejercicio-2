//Julio Christopher Beltran Solano
//youtube video https://youtu.be/sjtlbHbhMiU?si=IffD85pENUZgAbWh
#include <iostream>
#include <forward_list>
#include <stdexcept>
using namespace std;

template <typename T>
class LStack {
private:
    forward_list<T> elementos;
    int cantidadElementos;

public:
    LStack() : cantidadElementos(0) {}

    void Push(const T& valor) {
        elementos.push_front(valor);
        cantidadElementos++;
    }

    T Pop() {
        if (elementos.empty()) {
            throw underflow_error("Error: la pila está vacía");
        }
        T valor = elementos.front();
        elementos.pop_front();
        cantidadElementos--;
        return valor;
    }

    T& Peak() {
        if (elementos.empty()) {
            throw underflow_error("Error: la pila está vacía");
        }
        return elementos.front();
    }

    int Count() const {
        return cantidadElementos;
    }

    bool EstaVacia() const {
        return elementos.empty();
    }
};

int main() {
    LStack<int> pila;

    pila.Push(10);
    pila.Push(20);
    pila.Push(30);

    cout << "Elemento en el tope: " << pila.Peak() << endl;       // 30
    cout << "Elementos en la pila: " << pila.Count() << endl;    // 3

    int valorEliminado = pila.Pop(); // Ahora Pop devuelve el valor eliminado
    cout << "Se eliminó: " << valorEliminado << endl;            // 30

    cout << "Nuevo tope: " << pila.Peak() << endl;               // 20
    cout << "Elementos restantes: " << pila.Count() << endl;     // 2

    return 0;
}