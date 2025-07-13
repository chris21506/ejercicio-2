//Julio Christopher Beltran Solano
// youtube video https://youtu.be/9LKr1mGdkTA?si=E5MbE22sj_Nk66IG
#pragma once

#include <iostream>
using namespace std;

#define QUEUE_DEFAULT_SIZE 12


template <typename T>
class Queue
{
	Queue()
	{
		head = 0;
		tail = 0;
		count = 0;
	}

	int GetCountSimple() { return size; }

	// Esta solo es un ejemplo de que se podría llegar a sobrevivir sin la variable size.
	// cuántos elementos tiene esta Queue dentro
	int GetCount();

	// añade el valor value al final de la fila.
	void Enqueue(T value);

	// quitar el primer elemento de la fila y regresa su valor T
	T Dequeue();

private:
	T data[QUEUE_DEFAULT_SIZE];
	int head;
	int tail;
	int count;

};


template <typename T>
int Queue<T>::GetCount()
{
	// en el caso sencillo, es nada más regresar Tail - Head
	int difference = tail - head;
	// Si difference es igual o mayor que 0, entonces regresamos ese valor.
	if (difference >= 0)
		return difference;
	else
		QUEUE_DEFAULT_SIZE + difference; // es '+' difference porque difference es negativo.

	// EJEMPLOS
	// head = 7
	// tail = 12
	// diff = 5, es positivo así que nos regresa 5, está bien.

	// head es 7, tail es 3
	// diff es 3-7 = -4
	// es negativo, entonces regresamos QUEUE_DEFAULT_SIZE - 4
	// que sería 12 - 4 -> 8
}


template <typename T>
void Queue<T>::Enqueue(T value)
{
	// primero checamos si sí cabe en la fila.
	// esto lo hacemos viendo si los valores de head y tail son iguales
	if (count == QUEUE_DEFAULT_SIZE)
	{
		cout << "advertencia, está tratando de añadir elementos a una fila que ya está llena" << endl;
		return; // salimos de la función.
	}

	// incrementar el count.
	count++;

	// poner el valor value en el índice que nos diga tail
	data[tail] = value;
	// finalmente, incrementamos tail
	tail++;
	// si tail ya se sale del arreglo, entonces lo ciclamos al inicio del arreglo.
	if (tail == QUEUE_DEFAULT_SIZE)
		tail = 0;
}

template <typename T>
T Queue<T>::Dequeue()
{
	// primero checamos si la queue está vacía, 
	if (count == 0)
	{
		// si sí está vacía, imprimimos una advertencia y salimos de la función.
		cout << "advertencia, está tratando de quitar elementos a una fila que está vacía" << endl;
		return; // salimos de la función.
	}

	// decrementamos count
	count--;
	// quitamos el elemento donde nos dice Head
	T result = data[head];
	// movemos head al siguiente
	head++;
	if (head == QUEUE_DEFAULT_SIZE) // lo ciclamos para que no se salga del arreglo.
		head = 0;

}
#pragma once

#include <iostream>
#include "SentinelLinkedList.h" // Asegúrate de incluir tu clase lista ligada centinela aquí
using namespace std;

template <typename T>
class LQueue
{
public:
	LQueue()
	{
		count = 0;
	}

	int GetCountSimple() { return count; }

	int GetCount()
	{
		return list.GetCount(); // Usa la función de SentinelLinkedList
	}

	// Añade al final (O(1))
	void Enqueue(T value)
	{
		list.PushBack(value); // Agrega al final
		count++;
	}

	// Quita del frente (O(1))
	T Dequeue()
	{
		if (count == 0)
		{
			cout << "advertencia, está tratando de quitar elementos a una fila que está vacía" << endl;
			return {};
		}
		T value = list.PopFront(); // Saca el primero
		count--;
		return value;
	}

private:
	SentinelLinkedList<T> list;
	int count;
};