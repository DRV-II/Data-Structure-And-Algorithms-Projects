//Programa que almacena datos en un vector, ordena la información y lo almacena en un nuevo archivo.
//Autores: David Román Velasco A01639645
//Paulina Lizet Gutiérrez Amezcua A01639948,
//Juan Pablo García Malta A01639025
//Fecha de creación: 7 de septiembre del 2021
//Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales.

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Abrir el archivo y almacenarlo los datos en un vector.
void leerArchivo(string nombreArchivo,vector<string> &bitacora) {
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
      // Lo vamos imprimiendo
      bitacora.push_back(linea);
    }
}

vector<vector<string>> separar(vector<string> &bitacora) {
  vector<vector<string>> bitacoraAcomodada;
  string spaceDelimiter = " ";
  size_t pos = 0;
  std::string token;
  for (int i=0; i < bitacora.size(); i++) {
    vector<string> vectorTemp;
    string s = bitacora[i];
    while ((pos = s.find(spaceDelimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        vectorTemp.push_back(token);
        s.erase(0, pos + spaceDelimiter.length());
    }
    bitacoraAcomodada.push_back(vectorTemp);
  }
  cout<<bitacoraAcomodada[4][3]<<endl;
  return bitacoraAcomodada;
}

vector<string> dividir(string str, char pattern) {
    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;

    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }

    return results;
}

// Ordena la información por fecha para la realización de las búsquedas.
vector<vector<string>> convertirNumeros(vector<vector<string>> vector) {
  for (int i=0; i < vector.size(); i++) {
    if (vector[i][0]=="Jan") {
      vector[i][0] = "100000000";
    }
    else if (vector[i][0]=="Feb") {
      vector[i][0] = "200000000";
    }
    else if (vector[i][0]=="Mar") {
      vector[i][0] = "300000000";
    }
    else if (vector[i][0]=="Apr") {
      vector[i][0] = "400000000";
    }
    else if (vector[i][0]=="May") {
      vector[i][0] = "500000000";
    }
    else if (vector[i][0]=="Jun") {
      vector[i][0] = "600000000";
    }
    else if (vector[i][0]=="Jul") {
      vector[i][0] = "700000000";
    }
    else if (vector[i][0]=="Aug") {
      vector[i][0] = "800000000";
    }
    else if (vector[i][0]=="Sep") {
      vector[i][0] = "900000000";
    }
    else if (vector[i][0]=="Oct") {
      vector[i][0] = "1000000000";
    }
    else if (vector[i][0]=="Nov") {
      vector[i][0] = "1100000000";
    }
    else if (vector[i][0]=="Dec") {
      vector[i][0] = "1200000000";
    }
    else {
      cout<<"Error en conversión"<<endl;
    }
  }
  return vector;
}

vector<vector<string>> convertirMeses(vector<vector<string>> vector) {
  for (int i=0; i < vector.size(); i++) {
    if (vector[i][0]=="100000000") {
      vector[i][0] = "Jan";
    }
    else if (vector[i][0]=="200000000") {
      vector[i][0] = "Feb";
    }
    else if (vector[i][0]=="300000000") {
      vector[i][0] = "Mar";
    }
    else if (vector[i][0]=="400000000") {
      vector[i][0] = "Apr";
    }
    else if (vector[i][0]=="500000000") {
      vector[i][0] = "May";
    }
    else if (vector[i][0]=="600000000") {
      vector[i][0] = "Jun";
    }
    else if (vector[i][0]=="700000000") {
      vector[i][0] = "Jul";
    }
    else if (vector[i][0]=="800000000") {
      vector[i][0] = "Aug";
    }
    else if (vector[i][0]=="900000000") {
      vector[i][0] = "Sep";
    }
    else if (vector[i][0]=="1000000000") {
      vector[i][0] = "Oct";
    }
    else if (vector[i][0]=="1100000000") {
      vector[i][0] = "Nov";
    }
    else if (vector[i][0]=="1200000000") {
      vector[i][0] = "Dec";
    }
    else {
      cout<<"Error en conversión"<<endl;
    }
  }
  return vector;
}

vector<vector<string>> convertirHoras(vector<vector<string>> lista) {
  vector<string> vectorTemp;
  int suma;
  string resultado;
  for (int i=0; i < lista.size(); i++) {
    vectorTemp = dividir(lista[i][2], ':');
    suma = ((stoi(vectorTemp[0]))*10000)+((stoi(vectorTemp[1]))*100)+stoi(vectorTemp[2]);
    if ((stoi(vectorTemp[0])<10) && (stoi(vectorTemp[0]) != 0)) {
      resultado = "0" + to_string(suma);
    }
    else if (stoi(vectorTemp[0]) == 0) {
      resultado = "00" + to_string(suma);
    }
    else {
      resultado = to_string(suma);
    }
    lista[i][2] = resultado;
  }
  return lista;
}

vector<vector<string>> desconvertirHoras(vector<vector<string>> lista) {
  for (int i=0; i < lista.size(); i++) {
    lista[i][2].insert(2, ":");
    lista[i][2].insert(5, ":");
  }
  return lista;
}

/*
vector<vector<string>> ordenBurbuja(vector<vector<string>> a) {
    int n=a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if((stoi(a[j][0])+stoi(a[j][1]))>(stoi(a[j+1][0])+stoi(a[j+1][1]))) {
                vector<string> tmp_value=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp_value;
            }
        }
    }
    return a;
} */

vector<vector<string>> ordenBurbuja(vector<vector<string>> a) {
    int n=a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if((stoi(a[j][0])+stoi(a[j][1])*1000000+stoi(a[j][2]))>(stoi(a[j+1][0])+stoi(a[j+1][1])*1000000+stoi(a[j+1][2]))) {
                vector<string> tmp_value=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp_value;
            }
        }
    }
    return a;
}

/*
int busqBinaria(vector<vector<string>> a, int k) { //
    int n = a.size();
    int l=0;
    int r = n-1;
    while (l <= r) {
      int m=floor((l+r)/2);
      if (k==(stoi(a[m][0])+stoi(a[m][1]))) {
          return m;
      }
      else if (k < (stoi(a[m][0])+stoi(a[m][1]))) {
          r = m-1;
      }
      else {
          l = m+1;
      }
    }
    return -1;
}
*/

int busqSecuencialOrd(vector<vector<string>> a, int k) {
  int n = a.size();
  for (int i = 0; i<n; i++) {
    if (k<=(stoi(a[i][0])+stoi(a[i][1]))) {
      if (k==(stoi(a[i][0])+stoi(a[i][1]))) {
        return i;
      }
      else {
        return -1;
      }
    }
  }
  return -1;
}

void printVector(vector<string> a) {
  int n = a.size();
  for (int i = 0; i<n; i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

int main() {
  //CustomLinkedList<int> bitacoraAcomodada;
  vector<string> bitacora;
  vector<vector<string>> vectorConvertido;
  vector<vector<string>> vectorSeparado;
  vector<vector<string>> vectorOrdenado;
  int mes;
  int dia;
  int fecha1;
  int fecha2;
  int indice1=-1;
  int indice2=-1;
  leerArchivo("bitacora.txt", bitacora);
  cout<<bitacora[2]<<endl;
  vectorSeparado=separar(bitacora);
  printVector(vectorSeparado[2]);
  vectorConvertido=convertirNumeros(vectorSeparado);
  cout<<vectorConvertido[0][1]<<endl;
  printVector(vectorConvertido[2]);
  vectorConvertido=convertirHoras(vectorConvertido);
  printVector(vectorConvertido[2]);
  vectorOrdenado = ordenBurbuja(vectorConvertido);
  printVector(vectorOrdenado[2]);
  //printVector(vectorOrdenado);
  cout<<"Ingresa el mes de inicio (numero de mes): ";
  cin>>mes;
  cout<<endl<<"Ingresa el día de inicio: ";
  cin>>dia;
  fecha1=((mes)*100000000)+(dia);
  cout<<endl<<"Ingresa el mes de fin (numero de mes): ";
  cin>>mes;
  cout<<endl<<"Ingresa el día de fin: ";
  cin>>dia;
  if (dia != 31) {
    fecha2=(mes*100000000)+(dia+1);
  }
  else {
    fecha2=((mes+1)*100000000)+1;
  }
  indice1=busqSecuencialOrd(vectorOrdenado,fecha1);
  indice2=busqSecuencialOrd(vectorOrdenado,fecha2);
  while ( (indice1 == -1) || (indice2 == -1) ) {
    cout<<endl<<"Fechas no validas, reingrese fechas"<<endl;
    cout<<"Ingresa el mes de inicio (numero de mes): ";
    cin>>mes;
    cout<<endl<<"Ingresa el día de inicio: ";
    cin>>dia;
    fecha1=((mes)*100000000)+(dia);
    cout<<endl<<"Ingresa el mes de fin (numero de mes): ";
    cin>>mes;
    cout<<endl<<"Ingresa el día de fin: ";
    cin>>dia;
    if (dia != 31) {
      fecha2=(mes*100000000)+(dia+1);
    }
    else {
      fecha2=((mes+1)*100000000)+1;
    }
    cout<<endl;
    fecha2=(mes*100000000)+(dia+1);
    indice1=busqSecuencialOrd(vectorOrdenado,fecha1);
    indice2=busqSecuencialOrd(vectorOrdenado,fecha2);
  }

  //cout<<indice1<<endl;
  //cout<<vectorOrdenado[indice1][0]<<" "<<vectorOrdenado[indice1][1]<<endl;
  vectorOrdenado=convertirMeses(vectorOrdenado);
  vectorOrdenado=desconvertirHoras(vectorOrdenado);

  for (int i = indice1; i <= indice2-1; i++) {
      printVector(vectorOrdenado[i]);
  }

  // Creación del archivo
  ofstream bitacoraOrdenada;

 // Apertura y comprobación

  if ( std::ofstream bitacoraOrdenada{"BitacoraResultado.txt"} ) {
    for (int i = indice1; i <= indice2-1; i++) {
      for (int j=0; j < vectorOrdenado[i].size(); j++) {
        bitacoraOrdenada << vectorOrdenado[i][j] << " ";
      }
      bitacoraOrdenada<<endl;
    }
  }
  else {
    cout << "Error al intentar abrir el archivo BitacoraResultado" << endl;
  }
  bitacoraOrdenada.close();
}
