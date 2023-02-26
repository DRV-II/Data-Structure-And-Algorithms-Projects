/* Programa que ayuda a una empresa que quiere incursionar en los servicios de
Internet

Autores:
David Román Velasco A01639645
Paulina Lizet Gutiérrez Amezcua A01639948
Juan Pablo Garcia Malta A01639025
Fecha de creación: 2 de noviembre del 2022

Algoritmos implementados:
1 Dijkstra - Complejidad: O(V2)
2 Floyd - Complejidad:  O(V3)
3 Backtracking - Complejidad: O(2^((n+m)^2))
4 Polígono Convexo - Complejidad: O (m*n)

E2. Actividad Integradora 2
*/

#include <cmath>
#include <float.h>
#include <iostream>
#include <limits.h>
#include <map>
#include <stack>
#include <stdio.h>
#include <vector>

using namespace std;
int contador;

// Número de vertices en  el grafo
int N;

// Define un número infinito para los vértices conectados entre sí
#define INF 99999

// Función para encontrar el vértice con el menor valor de distancia.
// Retorna la distancia mínima
int disMinima(int distancia[], bool distanciaMin[]) {
  // Inicializa el valor mínimo
  int min = INT_MAX, min_index;

  for (int n = 0; n < N; n++)
    if (distanciaMin[n] == false && distancia[n] <= min)
      min = distancia[n], min_index = n;
  return min_index;
}

// Función para imprimir la distancia del vértice Dijkstra
void imprimirSolucion(int distancia[], int origen) {
  for (int i = 0; i < N; i++)
    cout << "node " << origen + 1 << " to node " << i + 1 << " : "
         << distancia[i] << endl;
}

// Función que implementa el algoritmo de Dijkstra
// para encontrar el camino más corto en un grafo
// Complejidad: O(V2)
// Retorna el camino más corto utilizando los valores de la matriz
void dijkstra(int **grafo, int origen) {
  int distancia[N]; // Matriz para el camino más corto

  // Será True si el vértice está en el camino mas corto
  // o si se finaliza.
  bool distanciaMin[N];

  // Inicializa las distancias
  for (int i = 0; i < N; i++)
    distancia[i] = INT_MAX, distanciaMin[i] = false;

  // La distancia del vértice fuente es siempre 0
  distancia[origen] = 0;

  // Encuentra el camino más corto para todos los vértices
  for (int count = 0; count < N - 1; count++) {
    // Selecciona el vértice de distancia mínima
    int u = disMinima(distancia, distanciaMin);

    // Marca el vértice como procesado
    distanciaMin[u] = true;

    // Actualiza el valor del vértice
    for (int v = 0; v < N; v++) {

      if (grafo[u][v] < 0) {
        grafo[u][v] = 0;
      }

      // Actualiza dist[v] si no está en sptSet,
      if (!distanciaMin[v] && grafo[u][v] && distancia[u] != INT_MAX &&
          distancia[u] + grafo[u][v] < distancia[v]) {
        distancia[v] = distancia[u] + grafo[u][v];
      }
    }
  }
  // Imprime la matriz de distancia construida
  imprimirSolucion(distancia, origen);
}

// Función para imprimir la solución de Floyd
void printSolution(int **distancia) {
  cout << "Ruta a seguir por el personal que reparte correspondencia: \n";
  cout << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (distancia[i][j] == INF)
        cout << "INF"
             << " ";
      else
        cout << distancia[i][j] << " ";
    }
    cout << endl;
  }
}

// Función que encuentra la distancia mas corta entre parejas de nodos con Floyd
// Complejidad:  O(V3)
// Retorna la solución con el método Floyd
void floydWarshall(int **grafo) {
  int **distancia; // matriz que contendrá la distancia más corta
  int i, j, k;     // nodos

  // Inicializa la matriz y el grafo
  distancia = new int *[N];
  for (int i = 0; i < N; i++) {
    distancia[i] = new int[N];
  }

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      distancia[i][j] = grafo[i][j];

  // Recorre los vértices uno por uno para encontrar los intermedios
  for (k = 0; k < N; k++) {
    // Recorre los vértices raíz
    for (i = 0; i < N; i++) {
      // Recorre los vértices destino
      for (j = 0; j < N; j++) {
        // Si el vértice k es el más corto, actualiza el valor de distancia
        if (distancia[i][j] > (distancia[i][k] + distancia[k][j]) &&
            (distancia[k][j] != INF && distancia[i][k] != INF))
          distancia[i][j] = distancia[i][k] + distancia[k][j];
      }
    }
  }

  // Imprime la distancia más corta entre nodos
  printSolution(distancia);
}

// Clase para crear puntos 
struct Punto {
  int x, y;
}; 

// Se ubica el punto en X
int cX(const void *a, const void *b) {
  Punto *p1 = (Punto *)a, *p2 = (Punto *)b;
  return (p1->x != p2->x) ? (p1->x - p2->x) : (p1->y - p2->y);
} 

// Se ubica el punto en y
int cY(const void *a, const void *b) {
  Punto *p1 = (Punto *)a, *p2 = (Punto *)b;
  return (p1->y != p2->y) ? (p1->y - p2->y) : (p1->x - p2->x);
}

// Se obtiene la distancia entre puntos
float distancia(Punto p1, Punto p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Funcion para llamar a la distancia entre cada punto y obtener el minimo
float distanciaMin(Punto P[], int n) {
  float min = FLT_MAX;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (distancia(P[i], P[j]) < min)
        min = distancia(P[i], P[j]);
  return min;
} 

float min(float x, float y) { return (x < y) ? x : y; }

// Encuentra el punto más cercano
float cercano(Punto strip[], int size, float d) {
  float min = d;

  for (int i = 0; i < size; ++i)
    for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
      if (distancia(strip[i], strip[j]) < min)
        min = distancia(strip[i], strip[j]);

  return min;
} 

float puntoMasCerca(Punto Px[], Punto Py[], int n) {

  if (n <= 3)
    return distanciaMin(Px, n);

  int mid = n / 2;
  Punto midPunto = Px[mid];

  Punto Pyl[mid];
  Punto Pyr[n - mid];
  int li = 0, ri = 0;
  for (int i = 0; i < n; i++) {
    if ((Py[i].x < midPunto.x ||
         (Py[i].x == midPunto.x && Py[i].y < midPunto.y)) &&
        li < mid)
      Pyl[li++] = Py[i];
    else
      Pyr[ri++] = Py[i];
  } // funcion de utilidad para encontrar los puntos más cercanos

  float dl = puntoMasCerca(Px, Pyl, mid);
  float dr = puntoMasCerca(Px + mid, Pyr, n - mid);

  float d = min(dl, dr);

  Punto strip[n];
  int j = 0;
  for (int i = 0; i < n; i++)
    if (abs(Py[i].x - midPunto.x) < d)
      strip[j] = Py[i], j++;

  return cercano(strip, j, d);
}

float pCercano(Punto P[], int n) {
  Punto Px[n];
  Punto Py[n];
  for (int i = 0; i < n; i++) {
    Px[i] = P[i];
    Py[i] = P[i];
  }

  qsort(Px, n, sizeof(Punto), cX);
  qsort(Py, n, sizeof(Punto), cY);

  return puntoMasCerca(Px, Py, n);
}

// Función que muestra la matriz con la solución backtracking
void solucion(vector<vector<int>> &sol) {
  for (int i = 0; i < sol.size(); i++) {
    for (int j = 0; j < sol[i].size(); j++) {
      if (sol[i][j] == 0) {
        cout << 0 << "   ";
      } else {
        cout << sol[i][j] << "  ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

// Función para comprobar si es seguro pasar por el laberinto.
bool continuar(int renglon, int columna, int **visited, int n, int m) {
  // Si no es igual a 0 regresa True para continuar
  return (renglon < n && columna < m && renglon >= 0 && columna >= 0 &&
          visited[renglon][columna] != 0);
}

// Función que encuentra el camino seguro para salir del laberinto con
// backtracking Complejidad O(2^((n+m)^2)) Devuelve la matriz de valores
// booleanos (0|1) que representan el camino para salir del laberinto.
void backtracking(int **matriz, int renglon, int columna, int n, int m,
                  vector<vector<int>> &sol) {
  // Cuando llega a la última celda, se retorna la ruta.
  if (renglon == n - 1 && columna == m - 1) {
    sol[renglon][columna] = matriz[renglon][columna];
    solucion(
        sol); // Se manda llamar la función anterior para imprimir la solución
    cout << "El flujo maximo para este camino es :" << contador << endl;
    cout << endl;

    sol[renglon][columna] = 0;
    return;
  }

  // Los lugares que ya recorrió las marca como falso (0)
  int camino = matriz[renglon][columna];
  sol[renglon][columna] = camino;
  matriz[renglon][columna] = 0;

  // Si encuentra un 1, da un paso para abajo.
  if (continuar(renglon + 1, columna, matriz, n, m)) {
    int siguientePesoNodo =
        matriz[renglon + 1][columna]; // Valor del nodo futuro

    contador = (siguientePesoNodo < contador) ? siguientePesoNodo : contador;

    backtracking(matriz, renglon + 1, columna, n, m, sol);
  }
  // Si encuentra un 1 da el siguiente paso arriba
  else if (continuar(renglon - 1, columna, matriz, n, m)) {
    int siguientePesoNodo = matriz[renglon - 1][columna];

    contador = (siguientePesoNodo < contador) ? siguientePesoNodo : contador;

    backtracking(matriz, renglon - 1, columna, n, m, sol);
  }

  // Si encuentra un 1 da el siguiente paso hacia la derecha.
  if (continuar(renglon, columna + 1, matriz, n, m)) {
    int siguientePesoNodo = matriz[renglon][columna + 1];

    contador = (siguientePesoNodo < contador) ? siguientePesoNodo : contador;

    backtracking(matriz, renglon, columna + 1, n, m, sol);
  }
  // Si encuentra un 1, da un paso para la izquierda.
  else if (continuar(renglon, columna - 1, matriz, n, m)) {
    int siguientePesoNodo = matriz[renglon][columna - 1];

    contador = (siguientePesoNodo < contador) ? siguientePesoNodo : contador;

    backtracking(matriz, renglon, columna - 1, n, m, sol);
  }

  // Usa backtracking para regresar los caminos originales y encontrar otros
  // caminos.
  matriz[renglon][columna] = camino;

  // Elimina el camino
  sol[renglon][columna] = 0;
  return;
}

struct punto {
  int x, y;
};

punto p0; // punto para ordenar otros puntos

// Función para encontrar el punto próximo más alto en la pila
punto puntoMasAlto(stack<punto> &S) {
  punto p = S.top();
  S.pop();
  punto res = S.top();
  S.push(p);
  return res;
}

// Función para intercambiar dos puntos
void intercambio(punto &p1, punto &p2) {
  punto temp = p1;
  p1 = p2;
  p2 = temp;
}

// Función para calcular el cuadrado de la distancia entre puntos.
int distancia(punto p1, punto p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Función para encontrar la orientación de los puntos
// Retorna 0 si son colineales, 1 si son agujas de reloj y 
// 2 si están en sentido anti-horario
int orientacion(punto p, punto q, punto r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if (val == 0)
    return 0;
  return (val > 0) ? 1 : 2;
}

// Función para ordenar una matriz de
// puntos con respecto al primer punto.
int comparar(const void *vp1, const void *vp2) {
  punto *p1 = (punto *)vp1;
  punto *p2 = (punto *)vp2;

  // Encuentra la orientación
  int o = orientacion(p0, *p1, *p2);
  if (o == 0)
    return (distancia(p0, *p2) >= distancia(p0, *p1)) ? -1 : 1;

  return (o == 2) ? -1 : 1;
}

// Función para imprimir el casco convexo de un conjunto de n puntos.
// Complejidad: O(nLogn)
// Retorna una pila en orden contrario al sentido de las manecillas del reloj.
void crearPoligono(punto puntos[], int n) {
  // Encuentra el punto más bajo
  int ymin = puntos[0].y, min = 0;
  for (int i = 1; i < n; i++) {
    int y = puntos[i].y;

    // Elige el de la parte inferior o izquierda
    if ((y < ymin) || (ymin == y && puntos[i].x < puntos[min].x))
      ymin = puntos[i].y, min = i;
  }

  // Coloca el punto inferior en la primera posición
  intercambio(puntos[0], puntos[min]);

  // Ordena n-1 puntos con respecto al primer punto.
  p0 = puntos[0];
  qsort(&puntos[1], n - 1, sizeof(punto), comparar);

  // En caso de que dos o más puntos forman el mismo ángulo con p0.
  int matriz = 1; // Inicializa el tamaño de la matriz modificada
  for (int i = 1; i < n; i++) {

    // Elimina i mientras el ángulo de i e i+1 sea el mismo
    // con respecto a p0
    while (i < n - 1 && orientacion(p0, puntos[i], puntos[i + 1]) == 0)
      i++;

    puntos[matriz] = puntos[i];
    matriz++; // Actualizar el tamaño de la matriz modificada
  }

  // Si la matriz tiene menos de 3 puntos, da error.
  if (matriz < 3)
    return;

  stack<punto> S; // Pila vacía
  S.push(puntos[0]);
  S.push(puntos[1]);
  S.push(puntos[2]);

  // Procesa los n-3 puntos restantes
  for (int i = 3; i < matriz; i++) {
    // Continua quitando la parte superior de la pila
    while (S.size() > 1 && orientacion(puntoMasAlto(S), S.top(), puntos[i]) != 2)
      S.pop();
    S.push(puntos[i]);
  }

  // Mientras la pila no este vacía
  while (!S.empty()) {
    punto p = S.top();
    cout << "(" << p.x << ", " << p.y << ")"
         << " ";
    S.pop();
  }
}

int main() {
  int tempValue;
  cout << "Ingresa el número de nodos: ";
  cin >> N;
  cout << endl;

  // PARTE 1
  // Creamos matriz con N números
  cout << "----------PARTE 1----------" << endl;
  int **matriz1;
  matriz1 = new int *[N];
  for (int i = 0; i < N; i++) {
    matriz1[i] = new int[N];
  }

  cout << endl;
  cout << "Ingresa valores de matriz: " << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> tempValue;
      matriz1[i][j] = tempValue;
    }
  }
  cout << endl;
  cout << "Forma de cablear las colonias con fibra: " << endl;
  // Dijstra
  // Llamamos a la solución de dijkstra dentro de un ciclo
  for (int i = 0; i < N; i++) {
    dijkstra(matriz1, i);
  }

  cout << endl;
  cout << endl;

  // PARTE 2
  cout << "----------PARTE 2----------" << endl;
  // Imprime resultado de Floyd
  cout << endl;
  floydWarshall(matriz1);
  cout << endl;
  cout << endl;

  // PARTE 3
  cout << "----------PARTE 3----------" << endl;
  int **matriz2;
  matriz2 = new int *[N];
  for (int i = 0; i < N; i++) {
    matriz2[i] = new int[N];
  }

  cout << endl;
  cout << "Ingresa los valores de la matriz: " << endl;
  cout << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> tempValue;
      matriz2[i][j] = tempValue;
    }
  }

  vector<vector<int>> sol; // Guarda el camino recorrido.
  sol.resize(N, std::vector<int>(N));

  // Backtracking
  cout << endl; 
  cout << "Valor de flujo máximo de información del nodo inicial al nodo final: " << endl;
  cout << endl;
  // Iniciamos contador
  contador = matriz2[0][0]; // En primer nodo
  backtracking(matriz2, 0, 0, N, N, sol);
  cout << endl;

  // PARTE 4
  cout << "----------PARTE 4----------" << endl;
  cout << endl;
  cout << "Ingresa las coordenadas de los puntos " << endl;
  int aux1;
  int aux2;
  punto P[N];
  for (int i = 0; i < N; i++) {
    cin >> aux1 >> aux2;
    P[i] = {aux1, aux2};
  }

  int n = sizeof(P) / sizeof(P[0]);

  cout << endl;
  cout << "Lista de polígonos: " << endl;
  crearPoligono(P, n);
  cout << endl;

  return 0;
}