/* Este programa contiene casos de prueba para los diferentes
algoritmos de ordenamiento y busqueda

Autor: David Román Velasco
Matricula: A01639645
Fecha: 10-09-2021
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Función de busqueda secuencial
// Complejidad: Mejor O(1), Promedio O(n), Peor O(n)
int busqSecuencial(vector<int> a, int k) { //
    int n = a.size(); // Tamaño de vector
    int i=0;
    while (i<n and a[i] != k) { // Mientras valor actual es diferente al valor buscado
      i = i+1;
    }
    if (i < n) { // Si seguimos recorriendo el vector
      return i;
    }
    else { // Si paramos de recorrer el vector
      return -1;
    }
}

// Función de busqueda Binaria
// Complejidad: Mejor O(1), Promedio O(log_2 n), Peor O(log n)
int busqBinaria(vector<int> a, int k) { //
    int n = a.size(); // Tamaño de vector
    int l=0;
    int r = n-1;
    while (l <= r) {
      int m=floor((l+r)/2); // Se redondea hacia abajo la mitad
      if (k==a[m]) { // Si el valor buscado es igual a a[m]
          return m; // Regresa el indice
      }
      else if (k < a[m]) { // En caso de que el valor buscado sea menor al valor actual
          r = m-1;
      }
      else { // En caso de que el valor buscado sea mayor al valor actual
          l = m+1;
      }
    }
    return -1;
}

// Función de Bubble-Sort
// Complejidad: Mejor O(n), Promedio y Peor O(n²)
vector<int> ordenBurbuja(vector<int> a) {
    int n=a.size(); // Tamaño de vector
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if(a[j]>a[j+1]) {
                int tmp_value=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp_value;
            }
        }
    }
    return a;
}

// Función Ordena Intercambio
// Complejidad: Mejor O(n), Promedio y Peor O(n²)
vector<int> ordenaIntercambio(vector<int> a){
  int n=a.size(); // Tamaño de vector
  int k,j;
  for (int i = 0; i < n; i++)
  {
    k=a[i];
    j=i-1;
    while (j>=0 && a[j]>k) // Comparación de anterior con el actual
    {
      a[j+1]=a[j]; // Asignación del actual con el anterior
      j=j-1;
    }
    a[j+1]=k; // El actual ahora es el anterior

  }
  return a;
}

// Función complementaria de Merge-Sort
void merge(vector<int> &a, int l, int m, int r) {
    // Tamaño de subarreglos a fusionar
    int n1 = m-l+1;
    int n2 = r-m;
    int left[n1];
    int right[n2];
    // Copiar datos en subarreglos temporales
    for (int i=0; i < n1; i++) {
        left[i]=a[l+i];
    }
    for (int j=0; j < n2; j++) {
        right[j]=a[m+1+j];
    }
    // Fusiona los subarreglos
    int h = 0;
    int w = 0;
    int k = l;
    while (h<n1 && w<n2) {
        if (left[h] <= right[w]) {
            a[k]=left[h];
            h = h+1;
        }
        else {
            a[k]=right[w];
            w=w+1;
        }
        k=k+1;
    }
    // Copiar elementos restantes
    while (h<n1) {
        a[k]=left[h];
        h=h+1;
        k=k+1;
    }
    while (w<n2) {
        a[k]=right[w];
        w=w+1;
        k=k+1;
    }
}

// Función Merge-Sort
// Complejidad: Mejor, Promedio y Peor O(n log n)
void ordenaMerge(vector<int> &a, int l, int r) {
  if (l<r) {
    // Encontrar punto medio
    int m = floor((l+r)/2);
    // Ordenar mitades
    ordenaMerge(a, l, m);
    ordenaMerge(a, m+1, r);
    // Fusionar ambas mitades ordenadas
    merge(a,l,m,r);
  }
}

// Función para imprimir vector
void printVector(vector<int> a) {
  int n = a.size();
  for (int i = 0; i<n; i++) {
    cout<<a[i]<<", ";
  }
  cout<<endl;
}

int main(){
  // Declara arreglos a ordenar y buscar
  vector<int> intArray1 = {10, 3, 2, 4, 5, 6, 7, 8, 9, 1 };
  vector<int> intArray2 = {11, 12, 14, 13, 15, 16};
  vector<int> intArray3 = {16, 17, 19, 18, 21, 23, 19, 20};
  vector<int> intArray4 = {1, 5, 9, 6, 7, 8, 10};
  vector<vector<int>> arrayVector = {intArray1, intArray2, intArray3, intArray4};

  // Imprime vectores no ordenados
  cout<<endl<<"Vectores antes del ordenamiento: "<<endl;
  for (int i=0;i<arrayVector.size();i++) {
    cout<<"intArray"<<i+1<<": ";
    printVector(arrayVector[i]);
  }

  cout<<endl<<"Despues del ordenamiento: "<<endl;

  // Imprime vectores ordenados por Bubble-Sort
  cout << endl << "Orden Burbuja: "<<endl;
  for (int i=0;i<arrayVector.size();i++) {
    cout<<"intArray"<<i+1<<": ";
    printVector(ordenBurbuja(arrayVector[i]));
  }

  // Imprime vectores ordenados por Intercambio
  cout << endl << "Orden Intercambio: "<<endl;
  for (int i=0;i<arrayVector.size();i++) {
    cout<<"intArray"<<i+1<<": ";
    printVector(ordenaIntercambio(arrayVector[i]));
  }

  // Imprime vectores ordenados por Merge-Sort
  cout << endl << "Orden Merge-Sort: "<<endl;
  for (int i=0;i<arrayVector.size();i++) {
    ordenaMerge(arrayVector[i], 0, (arrayVector[i].size())-1);
    cout<<"intArray"<<i+1<<": ";
    printVector(arrayVector[i]);
  }

  // Usa busqueda secuencial para buscar indices de valores en los arreglos ordenados
  cout <<endl<< "Busqueda Secuencial: "<<endl<<"Busca indice del número '2' en arreglo ordenado intArray1: ";
  cout << busqSecuencial(arrayVector[0], 2)<<endl;
  cout << "Busca indice del número '11' en arreglo ordenado intArray2: ";
  cout << busqSecuencial(arrayVector[1], 11)<<endl;
  cout << "Busca indice del número '20' en arreglo ordenado intArray3: ";
  cout << busqSecuencial(arrayVector[2], 20)<<endl;
  cout << "Busca indice del número '11' que NO se encuentra en arreglo ordenado intArray4: "; // Devuelve -1
  cout << busqSecuencial(arrayVector[3], 11)<<endl;

  // Usa busqueda binaria para buscar indices de valores en los arreglos ordenados
  cout << endl<< "Busqueda Binaria: "<<endl<<"Busca indice del número '2' en arreglo ordenado intArray1: ";;
  cout << busqBinaria(arrayVector[0], 2)<<endl;
  cout << "Busca indice del número '11' en arreglo ordenado intArray2: ";
  cout << busqBinaria(arrayVector[1], 11)<<endl;
  cout << "Busca indice del número '25' que NO se encuentra en arreglo ordenado intArray3: "; // Devuelve -1
  cout << busqBinaria(arrayVector[2], 25)<<endl;
  cout << "Busca indice del número '6' en arreglo ordenado intArray4: ";
  cout << busqBinaria(arrayVector[3], 6)<<endl;
  cout<<endl;
}
