/* Programa que analiza 5 archivos de texto para ver si contienen código malicioso.

Autores:
David Román Velasco A01639645
Paulina Lizet Gutiérrez Amezcua A01639948
Juan Pablo García Malta A01639025
Fecha de creación: 25 de septiembre del 2022
E1. Actividad Integradora 1
*/
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sum = 0;
int fin = 0;
int sum2 = 0;
int fin2 = 0;

// Función que busca patrones con el algoritmo KMP
void calculaPatron(char *pat, int M, int *lps);

// Función para imprimir ocurrencias en los archivos
// Complejidad: O(n)
void BusquedaKMP(char *patron, char *txt, string nombre, string nombreMalo) {
  int M = strlen(patron);
  int N = strlen(txt);

  // Guarda el substring más largo del patrón
  int substringLargo[M];

  // Procesa el patrón
  calculaPatron(patron, M, substringLargo);
  int i = 0; // índice para txt[]
  int j = 0; // índice para patron[]

  while ((N - i) >= (M - j)) {
    if (patron[j] == txt[i]) {
      j++;
      i++;
    }

    if (j == M) {
      cout << "(True) Patrón encontrado en el indice " << i - j
           << " del archivo " << nombre << ", malware: " << patron
           << " del archivo " << nombreMalo << endl;
      
      if(nombre=="transmission1.txt"){
      if (i - j > sum) {
        sum = i - j;
        fin = i;
      }
        }
      if(nombre=="transmission2.txt"){
      if (i - j > sum2) {
        sum2 = i - j;
        fin2 = i;
      }
        }
      cout << endl;
      j = substringLargo[j - 1];
    }

    // Cuando ya no coincida el patrón
    else if (i < N && patron[j] != txt[i]) {
      if (j != 0)
        j = substringLargo[j - 1];
      else
        i = i + 1;
    }
  }
  cout << "(False) Patrón no encontrado "
           << " en el archivo " << nombre << ", de malware: " << patron
           << " del archivo " << nombreMalo << endl<<endl;
}

// Función para buscar el patrón
void calculaPatron(char *patron, int M, int *substringLargo) {
  // Variable para la longitud del string más largo anterior
  int longitud = 0;

  substringLargo[0] = 0; // Siempre va a ser 0

  // Ciclo para calcular el string más largo de 1 a M-1
  int i = 1;
  while (i < M) {
    if (patron[i] == patron[longitud]) {
      longitud++;
      substringLargo[i] = longitud;
      i++;
    }
    // En caso que no coincida la longitud
    else 
    {
      // Búsqueda
      if (longitud != 0) {
        longitud = substringLargo[longitud - 1];
      } 
      // En caso que la longitud sea 0
      else 
      {
        substringLargo[i] = 0;
        i++;
      }
    }
  }
}

// Imprime el patrón de los archivos txt
int BusquedaKMP(char* patron, char* txt)
{
    int M = strlen(patron);
    int N = strlen(txt);
    int substringLargo[M];
 
    calculaPatron(patron, M, substringLargo);
 
    int i = 0; 
    int j = 0;
    // Mientras el patrón coincida con el txt va aumentando 1 a las dos variables
    while ((N - i) >= (M - j)) {
        if (patron[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            return i-j;
            j = substringLargo[j - 1];
        }
 
        // Cuando ya no coincidan
        else if (i < N && patron[j] != txt[i]) {
            if (j != 0)
                j = substringLargo[j - 1];
            else
                i = i + 1;
        }
    }
    return -1;
}

// Función para encontrar el substring más largo.
// Complejidad: O(m*n) 
// Retorna el substring más largo 
string substring(string X, string Y)
{
    // Longitud de las dos variables
    int m = X.length();
    int n = Y.length();
    
    int resultado = 0; // Para almacenar el substring más largo
    int final; // Variable para almacenar el final del substring
    int len[2][n + 1]; // Matriz para almacenar el resultado
    int fila = 0; // Fila de la matriz actual
 
    // Ciclo para buscar el substring más largo
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                len[fila][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1]) {
                len[fila][j] = len[1 - fila][j - 1] + 1;
                if (len[fila][j] > resultado) {
                    resultado = len[fila][j];
                    final = i - 1;
                }
            }
            else {
                len[fila][j] = 0;
            }
        }
 
        // Hace la fila actual como la anterior y la fila anterior como la actual.
        fila = 1 - fila;
    }
 
    // Si no encuentra un patrón
    if (resultado == 0) {
        return "No hay substring comun";
    }
 
    // Retorna el substring más largo 
    return X.substr(final - resultado + 1, resultado);
}

int main() {
  
  // Se abren los 3 archivos de códigos maliciosos
  ifstream mCode1;
  mCode1.open("mcode1.txt", ios::in); // Modo lectura

  if (mCode1.fail()) {
    cout << "No se pudo abrir archivo" << endl; // En caso de error
    return 0;
  }

  ifstream mCode2;
  mCode2.open("mcode2.txt", ios::in); 

  if (mCode2.fail()) {
    cout << "No se pudo abrir archivo" << endl;
    return 0;
  }

  ifstream mCode3;
  mCode3.open("mcode3.txt", ios::in);

  if (mCode3.fail()) {
    cout << "No se pudo abrir archivo" << endl;
    return 0;
  }

  // Se abren los 2 archivos de transmisiones
  ifstream transm1;
  transm1.open("transmission1.txt", ios::in); 

  if (transm1.fail()) {
    cout << "No se pudo abrir archivo" << endl;
    return 0;
  }

  ifstream transm2;
  transm2.open("transmission2.txt", ios::in);

  if (transm2.fail()) {
    cout << "No se pudo abrir archivo" << endl;
    return 0;
  }

  int n = 5; // Cantidad de archivos
  ifstream *archivo[] = {&mCode1, &mCode2, &mCode3, &transm1, &transm2};

  string texto;
  // Arreglo para almacenar el contenido de los archivos de transmission
  string textoAux[] = {
      "",
      ""}; 
  // Arreglo para almacenar el contenido de los archivos de malware
  string patronAux[] = {
      "", "",
      ""}; 

  // Obtenemos lo que contienen los txt
  for (int i = 0; i < n; i++) {
    while (getline(*archivo[i], texto)) {

      // Se guardan las transmisiones como texto
      if (i == 3) {
        textoAux[0].append(texto);
        textoAux[0].append("$");
      } else if (i == 4) {
        textoAux[1].append(texto);
        textoAux[1].append("$");
      }
      // Se guarda el malware como patron
      else {
        patronAux[i].append(texto);
        patronAux[i].append("$");
      }
    }
  }
  
  // Contenido del archivo de transmision 1 en arreglo de chars
  char txt1[textoAux[0].length() + 1];
  strcpy(txt1, textoAux[0].c_str());

  // Contenido del archivo de transmision 2 en arreglo de chars
  char txt2[textoAux[1].length() + 1];
  strcpy(txt2, textoAux[1].c_str());

  cout<< "----Indicaciones del output----" << endl 
  << "Los simbolos '$' simbolizan saltos de linea con el fin "<<endl
  <<"de representarlos, asimismo si un indice aparece negativo "<<endl
  <<"significa que no lo encontro"<<endl<<endl;


  // Parte 1
  cout << "--------- Parte 1 (Detección de malware en transmisiones) --------- " << endl;

  for (int i = 0; i < n - 2; i++) {
    // Se busca los malwares
    string nombreMalo;
    char pat[patronAux[i].length() + 1];
    strcpy(pat, patronAux[i].c_str());
    if (i == 0) {
      nombreMalo = "mCode1.txt";
    } else if (i == 1) {
      nombreMalo = "mCode2.txt";
    } else {
      nombreMalo = "mCode3.txt";
    }
    BusquedaKMP(pat, txt1, "transmission1.txt", nombreMalo);
  }

  for (int i = 0; i < n - 2; i++) {

    string nombreMalo;
    char pat[patronAux[i].length() + 1];
    strcpy(pat, patronAux[i].c_str());

    if (i == 0) {
      nombreMalo = "mCode1.txt";
    } else if (i == 1) {
      nombreMalo = "mCode2.txt";
    } else {
      nombreMalo = "mCode3.txt";
    }

    BusquedaKMP(pat, txt2, "transmission2.txt", nombreMalo);
  }

  cout<<endl;

  // Parte 2
  cout << "--------- Parte 2 (Palindromo -Malware- más largo) --------- "<<endl;
  cout<<"Posición inicial "<<sum<<", posición final "<<fin-2<<" en transmission1"<<endl;
  cout<<"posición inicial "<<sum2<<", posición final "<<fin2-2<<" en transmission2"<<endl;
  cout << endl;

  // Parte 3
  cout << "--------- Parte 3 (Substring comun más largo) --------- "<<endl;
  cout << "El substring comun más largo encontrado en ambas transmisiones es: ";
  string substringComun = substring(textoAux[0], textoAux[1]);
  cout << substringComun <<endl;

  char patComun[substringComun.length() + 1];
  strcpy(patComun, substringComun.c_str());
  
  int indiceTemp = BusquedaKMP(patComun, txt1);
  int finalIndiceAux = substringComun.length() - 1;
  
  cout<< "Inicia en índice "<<indiceTemp<<" y termina en índice "<<indiceTemp + finalIndiceAux<<" en la transmisión 1"<<endl;
  
  indiceTemp = BusquedaKMP(patComun, txt2);
  
  cout<< "Inicia en índice "<<indiceTemp<<" y termina en índice "<<indiceTemp + finalIndiceAux<<" en la transmisión 2"<<endl;
 
  cout << endl;
  return 0;
}