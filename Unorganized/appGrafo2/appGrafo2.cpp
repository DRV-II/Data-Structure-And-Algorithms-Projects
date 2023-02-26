/*
Entrega de alumno: David Román Velasco
Matricula: A01639645

Hecho colaborativamente con: Paulina Lizet Gutiérrez Amezcua - A01639948
*/

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

// Clase de Grafo
class Grafo {
	// Numero de vertices
	int N;
  bool Ciclo(int v, bool visited[], int parent);

	// Apuntador a lista que contiene listas adjacentes
	list<int>* adj;
	list<int>* adj2; // Para orden topologico DAG
	// Función recursiva para OrdenTopologico
	void OrdenTopologicoUtil(int n, bool visited[], stack<int>& Stack);

public:
	// Constructor
	Grafo(int N);

	// function to add an edge to graph
	void AgregarBorde(int n, int m);
  bool isTree(); // Devuelve verdadero si grafo es arbol

	// Imprine orden topologico del grafo completo
	void OrdenTopologico(); // Complejidad de tiempo: O (N + E). Espacio auxiliar para stacks: O(N).
	void loadGrafo();
};

Grafo::Grafo(int N)
{
	this->N = N;
	adj = new list<int>[N];
	adj2 = new list<int>[N];
}

void Grafo::AgregarBorde(int n, int m)
{
	adj[n].push_back(m);
	adj[m].push_back(n);

	adj2[n].push_back(m);
}

// Función recursiva para OrdenTopologico
void Grafo::OrdenTopologicoUtil(int n, bool visited[], stack<int>& Stack)
{
	// Marca nodo actual como visitado
	visited[n] = true;

	// Rexcorrer todos vertices adjacentes al vector
	list<int>::iterator i;
	for (i = adj2[n].begin(); i != adj2[n].end(); ++i)
		if (!visited[*i])
			OrdenTopologicoUtil(*i, visited, Stack);

	// Push vertice actual al stack
	Stack.push(n);
}

// Función para orden Topologico DAG
void Grafo::OrdenTopologico()
{
	stack<int> Stack;

	// Marcar vertices como no visitados
	bool* visited = new bool[N];
	for (int i = 0; i < N; i++)
		visited[i] = false;

	// Llamar función recursiva
	// para guardar Topologico
	// Ordenar empezando de todos los vertices uno por uno
	for (int i = 0; i < N; i++)
		if (visited[i] == false)
			OrdenTopologicoUtil(i, visited, Stack);

	// Imprimir stacks
	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

void Grafo::loadGrafo()
{
    for (int n = 0; n < this->N; ++n)
    {
        cout << "\n Lista de Adjacencia "
             << n << "\n head ";
        for (auto x : this -> adj[n])
           cout << "-> " << x;
        printf("\n");
    }
}


// Una funcion recursiva para detectar ciclos en subgrafos alcanzables desde vertice n
bool Grafo::Ciclo(int n, bool visited[], int parent)
{
    // Marcar nodo como visitado
    visited[n] = true;

    // Recorrer vertices adjacentes a este vertice
    list<int>::iterator i;
    for (i = adj[n].begin(); i != adj[n].end(); ++i)
    {
        // Si adjacente no disponible, recorrer ese adjacente
        if (!visited[*i])
        {
           if (Ciclo(*i, visited, n))
              return true;
        }

        // Si adjacente es visitado y no es padre del dicho vertico, encontramos ciclo
        else if (*i != parent)
           return true;
    }
    return false;
}

// Si es arbol devuelve verdadero, si no falso
bool Grafo::isTree()
{
    // Poner todas la vertices como no visitadas
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    // La función ciclo nos sirve para ver si el grafi es ciclicco desde el vertice cero.
		// Y marca los vertices alcanzables de cero
    if (Ciclo(0, visited, -1))
             return false;

    // Si encontramos un vertice no alcanzable desde cero regresamos falso.
    for (int u = 0; u < N; u++)
        if (!visited[u])
           return false;

    return true;
}

// Main
int main()
{

	cout << "Caso 1: Vista del Grafo \n";
	Grafo g0(6);
	g0.AgregarBorde(5, 2);
	g0.AgregarBorde(5, 0);
	g0.AgregarBorde(4, 0);
	g0.AgregarBorde(4, 1);
	g0.loadGrafo();
	cout << endl;

	cout << "Caso 2: Es arbol \n";
	Grafo g1(6);
	g1.AgregarBorde(5, 2);
	g1.AgregarBorde(5, 0);
	g1.AgregarBorde(4, 0);
	g1.AgregarBorde(4, 1);
	g1.AgregarBorde(2, 3);
  g1.AgregarBorde(3, 1);
	g1.loadGrafo();
	if (g1.isTree()==true) {
		cout << "\nGrafo es un árbol\n";
	} else {
		cout << "\nGrafo no es un árbol\n";
	}
	cout << endl;

	cout << "Caso 3: No es arbol \n";
	Grafo g2(5);

	g2.AgregarBorde(1, 0);
	g2.AgregarBorde(0, 2);
	g2.AgregarBorde(0, 3);
	g2.AgregarBorde(3, 4);
	g2.loadGrafo();

	if (g2.isTree()==true) {
		cout << "\nGrafo es un árbol\n";
	} else {
		cout << "\nGrafo no es un árbol\n";
	}
	cout << endl;

	cout << "Caso 4: Orden Topologico \n";
	Grafo g3(6);
  g3.AgregarBorde(5, 2);
  g3.AgregarBorde(5, 0);
  g3.AgregarBorde(4, 0);
  g3.AgregarBorde(4, 1);
  g3.AgregarBorde(2, 3);
  g3.AgregarBorde(3, 1);

	cout << "Orden Topologico de grafo 4 \n";
  // Function Call
  g3.OrdenTopologico();
	cout << endl;

	return 0;
}
