//Programa que utiliza un heap con operaciones top, push, pop, empty, size y
//Simula una fila priorizada de enteros con prioridad de valor mayor.
//Autores: David Román Velasco A01639645,
// Paulina Lizet Gutiérrez Amezcua A01639948
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

	//Inserta una nueva clave
	void push(int key);

};

// Construye un heap a partir de una matriz y tamaño dados.
MaxHeap::MaxHeap(int cap)
{
	tam = 0;
	capacidad = cap;
	arr = new int[cap];
}

// Inserta una nueva clave
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

	// Arregla el heap
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

// Regresa la cantidad de datos que tiene el heap
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
  // Caso 1
  MaxHeap h1(7); // Tamaño del heap
  cout<<"\n\t - - - Fila priorizada 1 - - - "<<endl;
  // Agrega elementos al final de la cola de prioridad.
  h1.push(40);
  h1.push(90);
  h1.push(5);
  h1.push(10);
  h1.push(8);
	h1.push(81);
	h1.push(14);

  // Imprime la cola de prioridad.
  cout << "\nFila priorizada: ";
  h1 = print(h1);
	bool vacio = h1.empty();
	if (vacio == true) {
		cout<<"\nLa fila priorizada no tiene datos \n";
	}
	else {
		cout<<"\nLa fila priorizada tiene datos \n";
	}
  cout << "Tamaño: "<< h1.size(); // Devuelve el tamaño de la cola.
  cout << "\nElemento superior: " << h1.top(); // Devuelve el elemento superior de la cola.
  cout << "\nFila priorizada despues de pop(): ";
  h1.pop(); // Elimina el elemento superior
  h1 = print(h1); // Imprime el arreglo
  cout<<endl;

  // Caso 2
  MaxHeap h2(6);
  cout<<"\n\t - - - Fila priorizada 2 - - - "<<endl;
  h2.push(22);
  h2.push(94);
  h2.push(3);
  h2.push(72);
  h2.push(29);
  h2.push(106);

  cout << "\nFila priorizada: ";
  h2 = print(h2);
	bool vacio2 = h2.empty();
	if (vacio2 == true) {
		cout<<"\nLa fila priorizada no tiene datos \n";
	}
	else {
		cout<<"\nLa fila priorizada tiene datos \n";
	}
  cout << "Tamaño: "<< h2.size();
  cout << "\nElemento superior: " << h2.top();
  cout << "\nFila priorizada despues de pop() : ";
  h2.pop();
  h2 = print(h2);
  cout<<endl;

  // Caso 3
  MaxHeap h3(5);
  cout<<"\n\t - - - Fila priorizada 3 - - - "<<endl;
  h3.push(9);
  h3.push(68);
  h3.push(84);
  h3.push(14);
	h3.push(3);

  cout << "\nFila priorizada: ";
  h3 = print(h3);
	bool vacio3 = h3.empty();
	if (vacio3 == true) {
		cout<<"\nLa fila priorizada no tiene datos \n";
	}
	else {
		cout<<"\nLa fila priorizada tiene datos \n";
	}
  cout << "Tamaño: "<< h3.size();
  cout << "\nElemento superior: " << h3.top();
  cout << "\nFila priorizada despues de pop() : ";
  h3.pop();
  h3 = print(h3);
  cout<<endl;

  // Caso 4
  MaxHeap h4(6);
  cout<<"\n\t - - - Fila priorizada 4 - - - "<<endl;
  h4.push(9);
  h4.push(0);
  h4.push(1);
  h4.push(74);
  h4.push(15);
  h4.push(54);

  cout << "\nFila priorizada: ";
  h4 = print(h4);
	bool vacio4 = h4.empty();
	if (vacio4 == true) {
		cout<<"\nLa fila priorizada no tiene datos \n";
	}
	else {
		cout<<"\nLa fila priorizada tiene datos \n";
	}
  cout << "Tamaño: "<< h4.size();
  cout << "\nElemento superior: " << h4.top();
  cout << "\nFila priorizada despues de pop() : ";
  h4.pop();
  h4 = print(h4);
  cout<<endl;

	// Caso vacío
  MaxHeap h5(5); // Tamaño del heap
  cout<<"\n\t - - - Fila priorizada 5 - - - "<<endl;
	bool vacio5 = h5.empty();
	if (vacio5 == true) {
		cout<<"\nLa fila priorizada no tiene datos \n";
	}
	else {
		cout<<"\nLa fila priorizada tiene datos \n";
	}
	cout << "Tamaño: "<< h5.size();
  cout << "\nElemento superior: " << h5.top();
  cout << "\nFila priorizada despues de pop() : ";
  h5.pop();
  h5 = print(h5);
  cout<<endl;
  return 0;
}
