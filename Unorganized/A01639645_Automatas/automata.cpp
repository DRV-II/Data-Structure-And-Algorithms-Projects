#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

/*
Se consulto el video de Youtube
Programando con Pablo. (2016). Automata c++ - Programando con Pablo. Recuperado de: https://youtu.be/_0qRnEbMtdk
*/

// Define espacios para formato de tabla
#define espacios 35

// Estados de automata de operadores
#define enterosQ0 0
#define enterosQ1 1
#define enterosQ2 2

// Estados de automata de variables
#define variablesQ0 0
#define variablesQ1 1
#define variablesQ2 2

// Estados de automata de operadores
#define operadoresQ0 0
#define operadoresQ1 1
#define operadoresQ2 2
#define operadoresQ3 3
#define operadoresQ4 4
#define operadoresQ5 5
#define operadoresQ6 6
#define operadoresQ7 7

// Estados de automata de especiales
#define especialesQ0 0
#define especialesQ1 1
#define especialesQ2 2
#define especialesQ3 3

// Estados de automata de comentarios
#define comentariosQ0 0
#define comentariosQ1 1
#define comentariosQ2 2
#define comentariosQ3 3
#define comentariosQ4 4
#define comentariosQ5 5

// Estados de automata de flotantes
#define flotantesQ0 0
#define flotantesQ1 1
#define flotantesQ2 2
#define flotantesQ3 3
#define flotantesQ4 4
#define flotantesQ5 5
#define flotantesQ6 6
#define flotantesQ7 7
#define flotantesQ8 8
#define flotantesQ9 9

// Función para calcular espacios en tabla
string calculaEspacio(int n) {
  string space = " ";
  for (int j=n; j<espacios; j++) {
      space = space + " ";
    }
  return space;
}

// Función para determinar si es número
bool esNumero(char cadChar) {
  if(cadChar == '0' || cadChar == '1' || cadChar == '2' || cadChar == '3' || cadChar == '4' || cadChar == '5' || cadChar == '6' || cadChar == '7' || cadChar == '8' || cadChar == '9'){
    return true;
  }
  else {
    return false;
  }
}

// Función para determinar si es letra
bool esLetra(char cadChar) {
  if(cadChar == 'a' || cadChar == 'b' || cadChar == 'c' || cadChar == 'd' || cadChar == 'e' || cadChar == 'f' || cadChar == 'g' || cadChar == 'h' || cadChar == 'i' || cadChar == 'j' || cadChar == 'k' || cadChar == 'l' || cadChar == 'm' || cadChar == 'n' || cadChar == 'o' || cadChar == 'p' || cadChar == 'q' || cadChar == 'r' || cadChar == 's' || cadChar == 't' || cadChar == 'u' || cadChar == 'v' || cadChar == 'w' || cadChar == 'x' || cadChar == 'y' || cadChar == 'z'){
    return true;
  }
  else {
    return false;
  }
}

// A continuación se muestran funciones reutilizadas de proyecto de semestre pasado
// Abre el archivo y almacena los datos en un vector.
void leerArchivo(string nombreArchivo, vector<string> &bitacora)
{
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtiene la  línea de archivo, y la almacena el contenido en "linea"
  while (getline(archivo, linea))
  {
    // Se imprime
    bitacora.push_back(linea);
  }
}

vector<vector<string>> separar(vector<string> &bitacora)
{
  vector<vector<string>> bitacoraAcomodada;
  string spaceDelimiter = " ";
  size_t pos = 0;
  std::string token;

  // Recorre cada elemento de la bitácora.
  for (int i = 0; i < bitacora.size(); i++)
  {
    vector<string> vectorTemp;
    string s = bitacora[i];
    // Separa cada que encuentre un espacio y lo guarda en el vector.
    while ((pos = s.find(spaceDelimiter)) != std::string::npos)
    {
      token = s.substr(0, pos);
      vectorTemp.push_back(token);
      s.erase(0, pos + spaceDelimiter.length());
    }
    // El vector se guarda en la bitácora acomodada.
    vectorTemp.push_back(s);
    bitacoraAcomodada.push_back(vectorTemp);
  }
  return bitacoraAcomodada;
}
// Aqui termina funciones reutilizadas

bool automataEnteros(string cad){
    int n = cad.length();
    string space=calculaEspacio(n);
    int qActual = enterosQ0;
    char *cadChar = strdup(cad.c_str()); // Convierte string en vector de chars
    for(int i = 0;i < n;i++){
        switch(qActual){
            case enterosQ0:
                if(esNumero(cadChar[i])){
                    qActual = enterosQ1;
                }
                else{
                    qActual = enterosQ2;
                }
                break;
            case enterosQ1:
                if(esNumero(cadChar[i])){
                    qActual = enterosQ1;
                }
                else{
                    qActual = enterosQ2;
                }
                break;
            case enterosQ2:
                //cout << "no mames wey" << endl; // Se quitara
                i = n + 1; // Salimos del for
        }
    }
    if(qActual == enterosQ1) {
        cout <<"\t\t"<< cad << space <<"entero" << endl;
        return true;
    }
    else {
        return false;
    }
}

bool automataVariables(string cad){
    int n = cad.length();
    string space=calculaEspacio(n);
    int qActual = variablesQ0;
    string cad2;
    for(int i = 0;i < n;i++){
        cad2[i] = towlower(cad[i]);
    }
    char *cadChar = strdup(cad2.c_str());
    for(int i = 0;i < n;i++){
        switch(qActual){
            case variablesQ0:
                if(esLetra(cadChar[i])){
                    qActual = variablesQ1;
                }
                else{
                    qActual = variablesQ2;
                }
                break;
            case variablesQ1:
                if(esLetra(cadChar[i]) || esNumero(cadChar[i]) || cadChar[i] == '_'){
                    qActual = variablesQ1;
                }
                else{
                    qActual = variablesQ2;
                }
                break;
            case variablesQ2:
                //No es variable
                i = n + 1; // Salimos del for
        }
    }
    if(qActual == variablesQ1){
        cout <<"\t\t"<< cad << space <<"variable" << endl;
        return true;
    }
    else {
        return false;
    }

}

bool automataOperadores(string cad) {
    int n = cad.length();
    string space=calculaEspacio(n);
    int qActual = operadoresQ0;
    char *cadChar = strdup(cad.c_str());
    for(int i = 0;i < n; i++){
        switch(qActual){
            case operadoresQ0:
                if(cadChar[i] == '='){
                    qActual = operadoresQ1;
                }
                else if(cadChar[i] == '+'){
                    qActual = operadoresQ2;
                }
                else if(cadChar[i] == '-'){
                    qActual = operadoresQ3;
                }
                else if(cadChar[i] == '*'){
                    qActual = operadoresQ4;
                }
                else if(cadChar[i] == '/'){
                    qActual = operadoresQ5;
                }
                else if(cadChar[i] == '^'){
                    qActual = operadoresQ6;
                }
                else{
                    qActual = operadoresQ7;
                }
                break;
            case operadoresQ1:
                qActual = operadoresQ7;
                break;
            case operadoresQ2:
                qActual = operadoresQ7;
                break;
            case operadoresQ3:
                qActual = operadoresQ7;
                break;
            case operadoresQ4:
                qActual = operadoresQ7;
                break;
            case operadoresQ5:
                qActual = operadoresQ7;
                break;
            case operadoresQ6:
                qActual = operadoresQ7;
                break;
            case operadoresQ7:
                //No es operador
                i = n + 1; // Salimos del for
        }
    }

    if(qActual == operadoresQ1){
        cout <<"\t\t"<< cad << space <<"asignacion" << endl;
        return true;
    }
    else if(qActual == operadoresQ2){
        cout <<"\t\t"<< cad << space <<"suma" << endl;
        return true;
    }
    else if(qActual == operadoresQ3){
        cout <<"\t\t"<< cad << space <<"resta" << endl;
        return true;
    }
    else if(qActual == operadoresQ4){
        cout <<"\t\t"<< cad << space <<"multiplicacion" << endl;
        return true;
    }
    else if(qActual == operadoresQ5){
        cout <<"\t\t"<< cad << space <<"division" << endl;
        return true;
    }
    else if(qActual == operadoresQ6){
        cout <<"\t\t"<< cad << space <<"potencia" << endl;
        return true;
    }
    else {
        //No es operador
        return false;
    }
}

bool automataEspeciales (string cad) {
    int n = cad.length();
    string space=calculaEspacio(n);
    int qActual = especialesQ0;
    char *cadChar = strdup(cad.c_str()); // Convierte string en vector de chars
    for(int i = 0;i < n;i++){
      switch(qActual) {
        case especialesQ0:
          if (cadChar[i] == '(') {
            qActual = especialesQ1;
          }
          else if (cadChar[i] == ')') {
            qActual = especialesQ2;
          }
          else {
            qActual = especialesQ3;
          }
          break;
        case especialesQ1:
          qActual = especialesQ3;
          break;
        case especialesQ2:
          qActual = especialesQ3;
          break;
        case especialesQ3:
          //No es especial
          i = n + 1;
      }
    }
  if(qActual == especialesQ1){
     cout <<"\t\t"<< cad << space <<"Parentesis izquierdo" << endl;
     return true;
  }
  else if(qActual == especialesQ2){
    cout <<"\t\t"<< cad << space <<"Parentesis derecho" << endl;
     return true;
  }
  else{
     //No es especial
      return false;
  }
}

// Automata para determinar flotantes
bool automataFlotantes(string cad) {
    int n = cad.length();
    string space=calculaEspacio(n);
    int qActual = flotantesQ0;
    char *cadChar = strdup(cad.c_str()); // Convierte string en vector de chars
    for(int i = 0;i < n;i++){
        switch(qActual){
            case flotantesQ0:
                if(esNumero(cadChar[i])){
                    qActual = flotantesQ1;
                }
                else if (cadChar[i] == '.') {
                    qActual = flotantesQ7;
                }
                else if (cadChar[i] == '-') {
                    qActual = flotantesQ8;
                }
                else if (cadChar[i] == 'E') {
                    qActual = flotantesQ9;
                }
                else{
                    qActual = flotantesQ9;
                }
                break;

            case flotantesQ1:
                if(esNumero(cadChar[i])){
                    qActual = flotantesQ1;
                }
                else if (cadChar[i] == '.') {
                    qActual = flotantesQ2;
                }
                else{
                    qActual = flotantesQ9;
                }
                break;

            case flotantesQ2: // Caso final
                if(esNumero(cadChar[i])) {
                    qActual = flotantesQ3;
                }

                else{
                    qActual = flotantesQ9;
                }
                break;

          case flotantesQ3: // Caso final
                if(esNumero(cadChar[i])) {
                    qActual = flotantesQ3;
                }
                /*
                else if (cadChar[i] == '.') {
                    qActual = flotantesQ7;
                }
                */
                else if (cadChar[i] == 'E') {
                    qActual = flotantesQ4;
                }
                else{
                    qActual = flotantesQ9;
                }
                break;

            case flotantesQ4:
                if(esNumero(cadChar[i])) {
                qActual = flotantesQ6;
                }
                else if (cadChar[i] == '-') {
                    qActual = flotantesQ5;
                }
                else{
                    qActual = flotantesQ9;
                }
                break;

            case flotantesQ5:
                if(esNumero(cadChar[i])) {
                    qActual = flotantesQ6;
                }
                else{
                    qActual = flotantesQ9;
                }
                break;

            case flotantesQ6: // Caso final
                if(esNumero(cadChar[i])) {
                    qActual = flotantesQ6;
                }
                else {
                    qActual = flotantesQ9;
                }
                break;

            case flotantesQ7:
                if(esNumero(cadChar[i])) {
                qActual = flotantesQ3;
                }
                else{
                    qActual = flotantesQ9;
                }
                break;

            case flotantesQ8:
                if(esNumero(cadChar[i])) {
                qActual = flotantesQ1;
                }
                else if (cadChar[i] == '.') {
                    qActual = flotantesQ7;
                }
                else{
                    qActual = flotantesQ9;
                }
                break;

            case flotantesQ9:
                //No es flotante
                i = n + 1; // Salimos del for
        }
    }

    if(qActual == flotantesQ2 || qActual == flotantesQ3 || qActual == flotantesQ6) {
        cout <<"\t\t"<< cad << space << "flotante" << endl;
        return true;
    }
    else {
        return false;
    }
}


// Automata de comentarios
bool automataComentarios(string cad) {
  int n = cad.length();
  string space=calculaEspacio(n);
  int qActual = comentariosQ0;
  char *cadChar = strdup(cad.c_str());
  for(int i = 0; i < n; i++){
    switch(qActual){
      case comentariosQ0:
        if(cadChar[i] == '/'){
          qActual = comentariosQ1;
        }
        else{ // salto de linea y cualquier caracter
          qActual = comentariosQ3;
        }
        break;
      case comentariosQ1:
        if(cadChar[i] == '/'){
          qActual = comentariosQ2;
        }
        else{
          qActual = comentariosQ3;
        }
        break;
      case comentariosQ2:
        qActual = comentariosQ2;
        break;
      case comentariosQ3:
        //No es comentario
        i = n + 1; // Salimos del for
    }
  }
  if(qActual == comentariosQ2) {
      return true;
    }
    else {
      return false;
    }
}

// A continuación se reuso una parte de la función que sigue
// de un proyecto del semestre pasado
void procesoAutomata(vector<string> a) {
  int j;
  int n = a.size();
  int qActual = 0;
  for (int i = 0; i < n; i++)
  {
    switch(qActual){
      case 0:
        if ( automataEnteros(a[i]) == true) {
          qActual = 0;
        }
        else {
          qActual = qActual + 1;
          i = i-1;
        }
        break;
      case 1:
        if ( automataVariables(a[i]) == true) {
          qActual = 0;
        }
        else {
          qActual = qActual + 1;
          i = i-1;
        }
        break;
      case 2:
        if ( automataOperadores(a[i]) == true) {
          qActual = 0;
        }
        else {
          qActual = qActual + 1;
          i = i-1;
        }
        break;
      case 3:
        if ( automataEspeciales(a[i]) == true) {
          qActual = 0;
        }
        else {
          qActual = qActual + 1;
          i = i-1;
        }
        break;
      case 4:
        if ( automataFlotantes(a[i]) == true) {
          qActual = 0;
        }
        else {
          qActual = qActual + 1;
          i = i-1;
        }
        break;
      case 5:
        if ( automataComentarios(a[i]) == true) {
          qActual = 5;
          j = i;
          i = n + 1; // Salimos del for
        }
        else {
          qActual = qActual + 1;
          i = i-1;
        }

        break;
      case 6:
        qActual = 0;
        break;
    }
  }
  if (qActual == 5) {
    for (int k = j; k < n; k++)
    {
      cout << a[k] << " ";
    }
    cout << "\t comentario"<<endl;
    }
}

int main(){
    // Declaramos cada variable que vamos a necesitar
    vector<string> bitacora;
    vector<vector<string>> vectorSeparado;
    cout << "\t\t\t" << "token"<<"\t\t"<<"tipo" << endl;
    cout << "_______________________________________________________________" << endl;
    leerArchivo("demostracion.txt", bitacora);
    vectorSeparado = separar(bitacora);

    for (int i = 0; i < vectorSeparado.size(); i++)
    {
      procesoAutomata(vectorSeparado[i]);
    }

    return 0;
}
