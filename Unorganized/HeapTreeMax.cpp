//Programa que utiliza un heap con operaciones top, push, pop, empty, size y
//Simula una fila priorizada de enteros con prioridad de valor mayor.
//Autores: Paulina Lizet Gutiérrez Amezcua A01639948,
//David Román Velasco A01639645
//Fecha de creación: 18 de octubre del 2021
//Act 3.2 - Árbol Heap: Implementando una fila priorizada
#include<iostream>
#include<climits>
using namespace std;

// Función para intercambiar dos enteros.
void swap(int *x, int *y);

class MaxHeap
{
	int *arr; // Puntero a una matriz de elementos en el heap
	int capacidad; // Capacidad del heap
	int tam; // Número de elementos

public:

	// Constructor
	MaxHeap(int capacidad);

	// Apila el subárbol con la raíz en el índice dado
	void MaxHeapify(int );

	int padre(int i)
	{
		return (i-1)/2;
	}

	// Obtiene el índice del hijo izquierdo del nodo en el índice i
	int left(int i)
	{
		return (2*i + 1);
	}

	// Obtiene el índice del hijo derecho del nodo en el índice i
	int right(int i)
	{
		 return (2*i + 2);
	}

	int pop();
	bool empty();
	int size();

	// Devuelve el valor mas alto.
	int top()
	{
		 return arr[0];
	}

	//Inserts una nueva key
	void push(int key);

};

// Construye un heap a partir de una matriz y tamaño dados.
MaxHeap::MaxHeap(int cap)
{
	tam = 0;
	capacidad = cap;
	arr = new int[cap];
}

// Inserta uns nueva clave
void MaxHeap::push(int key)
{
	if (tam == capacidad)
	{
		cout << "\nOverflow: No se puede ingresar\n";
		return;
	}

	// Inserta la nueva clave al final
	tam++;
	int i = tam - 1;
	arr[i] = key;

	// Fix the min heap property if it is violated
	while (i != 0 && arr[padre(i)] < arr[i])
	{
	swap(&arr[i], &arr[padre(i)]);
	i = padre(i);
	}
}

// Saca  el dato que tiene mayor prioridad
int MaxHeap::pop()
{
	if (tam <= 0)
		return INT_MAX;
	if (tam == 1)
	{
		tam--;
		return arr[0];
	}

	// Guarda el valor máximo y lo elimina del heap
	int root = arr[0];
	arr[0] = arr[tam-1];
	tam--;
	MaxHeapify(0);

	return root;
}

// Regresa un valor boleeano diciendo si esta vacía o tiene datos.
bool MaxHeap::empty()
{
	if (tam <= 0)
  {
		return true;
	}

	else
	{
		return false;
	}
}

// Regresa la cantidad de datos que tiene
int MaxHeap::size()
{
	return tam;
}

// Método recursivo para apilar un subárbol con la raíz en el índice dado
void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
		int r = right(i);
    int mayor = i;
    if (l < tam && arr[l] > arr[i])
        mayor = l;
    if (r < tam && arr[r] > arr[mayor])
        mayor = r;
    if (mayor != i)
    {
        swap(&arr[i], &arr[mayor]);
        MaxHeapify(mayor);
    }
}

// Función para cambiar dos elementos
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Imprime el heap
MaxHeap print(MaxHeap h)
{
	MaxHeap pq(h.size());
	while (!h.empty()) {
		cout << '\t' << h.top();
		pq.push(h.top());
		h.pop();
	}
	cout << '\n';
	return pq;
}

int main()
{
  MaxHeap h1(5);
  cout<<"\n------ Caso de prueba 1 -----"<<endl;
  // Agrega elementos al final de la cola de prioridad.
  h1.push(50);
  h1.push(80);
  h1.push(10);
  h1.push(5);
  h1.push(12);

  // Imprime la cola de prioridad.
  cout << "Priority queue: ";
  h1 = print(h1);
  cout << "\nTamaño prority queue: "<< h1.size(); // Devuelve el tamaño de la cola.
  cout << "\nElemento superior: " << h1.top(); // Devuelve el elemento superior de la cola.
  cout << "\nPrority queue : ";
  h1.pop();
  h1 = print(h1);
  cout<<endl;

  return 0;
}
