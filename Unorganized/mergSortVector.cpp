#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
void merge(vector<int>&a, int l, int m, int r) {
  // Para ciclos
  int elementsLeft = m-l + 1;
  int elementsRight = r-m;

  // Tamaño de subarreglos a fusionar
  int left[elementsLeft];
  int right[elementsRight];

  // Copiar datos en subarreglos temporales
  for(int i=0; i<elementsLeft;i++) {
    left[i] = a[l+i];
  }
  for(int j=0; j<elementsRight; j++) {
    right[j] = a[m+1+j];
  }

  // Variables para while
  int h = 0;
  int w = 0;
  int k = l;

  // Fusionar valores de los dos vectores
  while(h<elementsLeft && w<elementsRight) {
    // Si el elemento del lado izquierdo es menor
    if (left[h] <= right[w]) {
      a[k] = left[h];
      h=h+1;
    }
    // Si no
    else {
      a[k] = right[w];
      w=w+1;
    }
    k=k+1;
  }

  // Copiar elementos restantes
  while (h<elementsLeft) {
    a[k]=left[h];
    h=h+1;
    k=k+1;
  }

  while (w<elementsRight) {
    a[k]=right[w];
    w=w+1;
    k=k+1;
  }
}

void ordenaMerge(vector<int>&a, int l, int r) {
  // Busca si el lado izquierdo es mayor que el derecho ya que es recursiva
  if (l < r) {
    // Ordenar mitades
    int m = floor((r + l)/2);
    ordenaMerge(a, l, m);
    ordenaMerge(a, m+1, r);
    merge(a, l, m, r);
  }
}
*/

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

void printVector(vector<int> a) {
  int n = a.size();
  for (int i = 0; i<n; i++) {
    cout<<a[i]<<", ";
  }
  cout<<endl;
}

int main() {
  vector<int> intArray4 = {1, 5, 9, 6, 7, 8, 10};
  vector<int> intArray1 = {10, 3, 2, 4, 5, 6, 7, 8, 9, 1};
  ordenaMerge(intArray4, 0, intArray4.size()-1);
  printVector(intArray4);
  ordenaMerge(intArray1, 0, intArray1.size()-1);
  printVector(intArray1);
}
