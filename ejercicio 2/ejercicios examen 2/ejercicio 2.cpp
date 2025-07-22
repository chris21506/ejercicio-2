//Julio Christopher Beltran Solano
// youtube video https://youtu.be/9LKr1mGdkTA?si=E5MbE22sj_Nk66IG
#pragma once

#include <iostream>
#include "SentinelLinkedList.h" // Asegúrate que tenga PushBack, PopFront, GetCount, IsEmpty
using namespace std;

template <typename T>
class LQueue
{
public:
	// Retorna el número de elementos, delegando a la lista
	int GetCount() {
		return list.GetCount();
	}

	void Enqueue(T value) {
		list.PushBack(value); // Añade al final
	}

	T Dequeue() {
		return list.PopFront(); // Quita del frente
	}

private:
	SentinelLinkedList<T> list;
};

#include "Queue.h"
#include "LQueue.h"
#include <iostream>
using namespace std;

int main() {
	cout << "=== PRUEBA DE Queue (arreglo fijo) ===" << endl;
	Queue<int> q1;

	q1.Enqueue(1);
	q1.Enqueue(2);
	q1.Enqueue(3);

	cout << "Elementos en Queue: " << q1.GetCount() << endl;

	cout << "Dequeue: " << q1.Dequeue() << endl;
	cout << "Dequeue: " << q1.Dequeue() << endl;

	cout << "Elementos restantes: " << q1.GetCount() << endl;

	cout << "\n=== PRUEBA DE LQueue (lista ligada) ===" << endl;
	LQueue<int> q2;

	q2.Enqueue(10);
	q2.Enqueue(20);
	q2.Enqueue(30);

	cout << "Elementos en LQueue: " << q2.GetCount() << endl;

	cout << "Dequeue: " << q2.Dequeue() << endl;
	cout << "Dequeue: " << q2.Dequeue() << endl;

	cout << "Elementos restantes: " << q2.GetCount() << endl;

	return 0;
}
