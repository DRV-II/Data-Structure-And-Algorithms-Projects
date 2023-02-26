// Programa que implementa una tabla de dispersión que incluye técnica de hashing
// así como el manejo de colisiones a través de dirección abierta y sondeo lineal.
// Autor: David Román Velasco - A01639645
// En colaboración con: Paulina Lizet Gutiérrez Amezcua - A01639948

#include <list>
#include <iostream>
#include <vector>
using namespace std;

void Imprimir(int arr[], int n)
  {
    // Iterando e imprimiendo arreglo
    for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }
  }

void Imprimir(vector<int> arr, int n)
  {
    // Iterando e imprimiendo arreglo
    for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }
  }

class Hash
{
	int Listas; // No. de listas

	// Apuntador a array que contiene listas
	list<int> *tabla;

public:
	Hash(int V); // Constructor

	// Inserta llave a la tabla hash
	void Insertar(int x);

	// borra llave de tabla hash
	void Eliminar(int key);

	// función hash que mapea valores de llave
	int FuncionHash(int x) {
		return (x % Listas);
	}

	void Chain();
};

Hash::Hash(int c)
{
	this->Listas = c;
	tabla = new list<int>[Listas];
}

void Hash::Insertar(int key)
{
	int indice = FuncionHash(key);
	tabla[indice].push_back(key);
}

void Hash::Eliminar(int key)
{
// Obtyener indice hash de la llave
int indice = FuncionHash(key);

// Encontrar llave en indice de la lista
list <int> :: iterator i;
for (i = tabla[indice].begin();
		i != tabla[indice].end(); i++) {
	if (*i == key)
	break;
}

// si se encuentra la llave, borrarla
if (i != tabla[indice].end())
	tabla[indice].erase(i);
}

// función para desplegar tabla hash
void Hash::Chain() {
for (int i = 0; i < Listas; i++) {
	cout << i;
	for (auto x : tabla[i])
	cout << " --> " << x;
	cout << endl;
}
}

// Hash cuadratico
// Compleidad de tiempo: O(N * L), donde N es la longitud del array, y L el tamaño de la tabla hash
// Espacio Auxiliar: O(1).
class hashQuadratic
{
private:
  int tamano; // Tamaño de hash
  int *tabla = new int[0];
	//vector<int> tabla;

public:

  hashQuadratic(int tam) {
    // Asignar tamaño de tabla hash
    this->tamano = tam;

    // Inicializamos tabla hash
    for (int i = 0; i < tamano; i++)
    {
      //this->tabla[i].push_back(-1);
      this->tabla[i] = -1;
    }
  }

  // Función para implementar forma cuadratica
  void quadratic(int arr[], int N)
  {
    // Iterar por el array
    for (int i = 0; i < N; i++)
    {
      // Asignando valor de hash
      int hv = arr[i] % this->tamano;
      // Insertar en tabla si no hay colisión
      if (this->tabla[hv] == -1)
        this->tabla[hv] = arr[i];
      else
      {
        // Si hay colisión, iterar por todas las asignaciones cuadraticas
        for (int j = 0; j < this->tamano; j++)
        {
          // Calcular nuevo valor hash
          int t = (hv + j * j) % this->tamano;
          if (this->tabla[t] == -1)
          {
            // Salir de loop despues de insertar valor hash
            this->tabla[t] = arr[i];
            break;
          }
        }
      }
    }
    Imprimir(this->tabla, N);
    cout<<endl;
  }
};

// MAIN
int main()
{
  cout<< endl<<"Caso 1: crear hashing con chain"<<endl;
  // Array que contiene las llaves a mapear
  int a[] = {20, 9, 30, 10, 12};
  int n = sizeof(a)/sizeof(a[0]);

  // Insertar llaves en tabla hash
  Hash h(7); // 7 es el numero de listas
  // tabla hash
  for (int i = 0; i < n; i++)
    h.Insertar(a[i]);
  h.Chain();

  cout<<endl<< "Caso 2: eliminar 30 de tabla hash con chain"<<endl;
  // Borrar 30 de tabla
  h.Eliminar(30);

  // Mostrar tabla
  h.Chain();
  /*
  cout<< endl<<"Caso 3: crear segudo hashing con chain"<<endl;
  // Array que contiene las llaves a mapear
  int a2[] = {30, 19, 40, 20, 22};
  int n2 = sizeof(a2)/sizeof(a2[0]);

  // Insertar llaves en tabla hash
  Hash h2(7); // 7 es el numero de listas
  // tabla hash
  for (int i = 0; i < n; i++)
    h2.Insertar(a2[i]);
  h2.Chain();
*/
  cout<<endl<< "Caso 3: crear hashing con metodo cuadratico"<<endl;
  // Cuadratico:
  //int arreglo[] = {50, 700, 76, 85, 92, 73, 101};
  int N = 7; // Numero de datos en arreglo

  int *arr = new int[N];

  arr[0] = 90;
  arr[1] = 65;
  arr[2] = 100;
  arr[3] = 20;
  arr[4] = 45;
  arr[5] = 84;
  arr[6] = 61;

  // Tamaño de la tabla hash e inicialización
  int l = 7; // Tamaño de la tabla de hash
  hashQuadratic hash1(l);

  hash1.quadratic(arr, N);

  cout<<endl<< "Caso 4: crear hashing con metodo cuadratico"<<endl;
  int N2 = 7; // Numero de datos en arreglo

  int *arr1 = new int[N2];

  arr1[0] = 45;
  arr1[1] = 70;
  arr1[2] = 50;
  arr1[3] = 40;
  arr1[4] = 90;
  arr1[5] = 60;
  arr1[6] = 30;
  //arr1[7] = 20;

  // Tamaño de la tabla hash e inicialización
  int l2 = 7; // Tamaño de la tabla de hash
  hashQuadratic hash2(l2);

  hash2.quadratic(arr1, N2);

  return 0;
}
