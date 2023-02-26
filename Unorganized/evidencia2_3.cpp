//Programa que almacena datos en un vector, ordena la información y lo almacena en un nuevo archivo.
//Autores: David Román Velasco A01639645
//Paulina Lizet Gutiérrez Amezcua A01639948,
//Juan Pablo García Malta A01639025
//Fecha de creación: 11 de octubre del 2021
//Act 2.3 - Actividad Integral estructura de datos lineales.

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <stdexcept>

using namespace std;

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

// Separa por línea el archivo
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

// Divide el vector.
vector<string> dividir(string str, char pattern)
{
  int posInit = 0;
  int posFound = 0;
  string splitted;
  vector<string> results;

  // Divide cada posición mientras que la posición sea mayor o igual a cero.
  while (posFound >= 0)
  {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }

  return results;
}

// Ordena la información por fecha para la realización de las búsquedas.
vector<vector<string>> convertirNumeros(vector<vector<string>> vector)
{
  for (int i = 0; i < vector.size(); i++)
  {
    //Convertimos los meses en números.
    if (vector[i][0] == "Jan")
    {
      //Multiplicamos por 100 para generar un id unico para cada fecha.
      vector[i][0] = "100";
    }
    else if (vector[i][0] == "Feb")
    {
      vector[i][0] = "200";
    }
    else if (vector[i][0] == "Mar")
    {
      vector[i][0] = "300";
    }
    else if (vector[i][0] == "Apr")
    {
      vector[i][0] = "400";
    }
    else if (vector[i][0] == "May")
    {
      vector[i][0] = "500";
    }
    else if (vector[i][0] == "Jun")
    {
      vector[i][0] = "600";
    }
    else if (vector[i][0] == "Jul")
    {
      vector[i][0] = "700";
    }
    else if (vector[i][0] == "Aug")
    {
      vector[i][0] = "800";
    }
    else if (vector[i][0] == "Sep")
    {
      vector[i][0] = "900";
    }
    else if (vector[i][0] == "Oct")
    {
      vector[i][0] = "1000";
    }
    else if (vector[i][0] == "Nov")
    {
      vector[i][0] = "1100";
    }
    else if (vector[i][0] == "Dec")
    {
      vector[i][0] = "1200";
    }
    else
    {
      // En caso de error al convertir.
      cout << "Error en conversión" << endl;
    }
  }
  return vector;
}

// Llama a la función despues de encontrar el valor.
vector<vector<string>> convertirMeses(vector<vector<string>> vector)
{
  for (int i = 0; i < vector.size(); i++)
  {
    //Se convierte el mes de nuevo en su abreviatura para facilitar su lectura.
    if (vector[i][0] == "100")
    {
      vector[i][0] = "Jan";
    }
    else if (vector[i][0] == "200")
    {
      vector[i][0] = "Feb";
    }
    else if (vector[i][0] == "300")
    {
      vector[i][0] = "Mar";
    }
    else if (vector[i][0] == "400")
    {
      vector[i][0] = "Apr";
    }
    else if (vector[i][0] == "500")
    {
      vector[i][0] = "May";
    }
    else if (vector[i][0] == "600")
    {
      vector[i][0] = "Jun";
    }
    else if (vector[i][0] == "700")
    {
      vector[i][0] = "Jul";
    }
    else if (vector[i][0] == "800")
    {
      vector[i][0] = "Aug";
    }
    else if (vector[i][0] == "900")
    {
      vector[i][0] = "Sep";
    }
    else if (vector[i][0] == "1000")
    {
      vector[i][0] = "Oct";
    }
    else if (vector[i][0] == "1100")
    {
      vector[i][0] = "Nov";
    }
    else if (vector[i][0] == "1200")
    {
      vector[i][0] = "Dec";
    }
    else
    {
      // Detecta si hubo un error en la conversion
      cout << "Error en conversión" << endl;
    }
  }
  return vector;
}

// Convierte las horas y los dias en enteros para sumarlas a la fecha.
vector<vector<string>> convertirHoras(vector<vector<string>> lista)
{
  vector<string> vectorTemp;
  int suma;
  string resultado;
  for (int i = 0; i < lista.size(); i++)
  {
    vectorTemp = dividir(lista[i][2], ':');
    suma = ((stoi(vectorTemp[0])) * 10000) + ((stoi(vectorTemp[1])) * 100) + stoi(vectorTemp[2]); //Crea un id único para cada fecha
    // Se utiliza para dar formato y evitar errores al buscar una fecha específica.
    if ((stoi(vectorTemp[0]) < 10) && (stoi(vectorTemp[0]) != 0))
    {
      resultado = "0" + to_string(suma);
    }
    else if (stoi(vectorTemp[0]) == 0)
    {
      resultado = "00" + to_string(suma);
    }
    else
    {
      resultado = to_string(suma);
    }
    lista[i][2] = resultado; // Id para cada entrada.
  }
  return lista;
}

// Formato a la hora para facilitar su lectura.
vector<vector<string>> desconvertirHoras(vector<vector<string>> lista)
{
  for (int i = 0; i < lista.size(); i++)
  {
    lista[i][2].insert(2, ":");
    lista[i][2].insert(5, ":");
  }
  return lista;
}

// Ordena en forma ascendente los datos con el método Burbuja.
// Complejidad: Mejor O(n), Promedio y Peor O(n²)
// Valor de retorno: el vector<int> con los datos ya ordenados.

vector<vector<string>> ordenBurbuja(vector<vector<string>> a, vector<vector<string>> &posiciones)
{
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (stof(to_string(stoi(a[j][0]) + stoi(a[j][1])) + "." + a[j][3]) >= stof(to_string(stoi(a[j + 1][0]) + stoi(a[j + 1][1])) + "." + a[j + 1][3])) //se usa el id que creamos para buscar el valor
      {
        vector<string> tmp_value = a[j];
        vector<string> tmp_posi = posiciones[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp_value;
        posiciones[j] = posiciones[j + 1];
        posiciones[j + 1] = tmp_posi;
      }
    }
  }
  return a;
}

void pruebaError(vector<vector<string>> a, int i)
{
  vector<string> prueba;
  if (i < a.size())
  {
    prueba = a[i];
  }
  else
  {
    throw invalid_argument(" ");
  }
}

// Utilizamos busqueda secuencial de arreglos ordenados para encontrar las fechas en específico dentro del vector.
// Complejidad: Mejor O(1), Promedio O(n/2), Peor O(n)
int busqSecuencialOrd(vector<vector<string>> a, int k)
{
  int n = a.size();
  int interruptor = 0;
  vector<string> prueba;
  for (int i = 0; i < n; i++)
  {

    try
    {
      pruebaError(a, i + 1); //cause an exception to throw
    }

    catch (invalid_argument &e)
    {
      interruptor = 1;
      cerr << e.what() << endl;
      //return -1;
    }

    if ((k <= (stoi(a[i][0]) + stoi(a[i][1]))) || (((k == (stoi(a[i][0]) + stoi(a[i][1])) + 1) && ((k == 131) || (k == 228) || (k == 331) || (k == 430) || (k == 531) || (k == 630) || (k == 730) || (k == 831) || (k == 930) || (k == 1031) || (k == 1130) || (k == 1231))) && ((interruptor == 1) || (k != ((stoi(a[i + 1][0]) + stoi(a[i + 1][1])) + 1)))))
    {
      if (k == (stoi(a[i][0]) + stoi(a[i][1])))
      {
        return i;
      }
      else
      {
        if (k == (stoi(a[i][0]) + stoi(a[i][1])) + 1)
        { // Porque bitacora a veces no tiene los ultimos días del mes
          return i;
        }
        else
        {
          return -1;
        }
      }
    }
  }
  return -1;
}

//Imprime cada linea del vector.
void printVector(vector<string> a)
{
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

// Convierte las ip´s a lista.
vector<vector<string>> convertirIPS(vector<vector<string>> lista, vector<vector<string>> &posiciones)
{
  vector<string> vectorTemp;
  string suma;
  // Separa las ip´s por punto y las junta.
  for (int i = 0; i < lista.size(); i++)
  {
    vectorTemp = dividir(lista[i][3], '.');
    suma = (vectorTemp[0]) + (vectorTemp[1]) + (vectorTemp[2]) + (vectorTemp[3]);
    posiciones.push_back(vectorTemp);
    lista[i][3] = suma;
  }
  return lista;
}

vector<vector<string>> convertirIPS2(vector<vector<string>> lista)
{
  vector<string> vectorTemp;
  string suma;
  // Convierte la última parte de la ip que tiene signo diferente a una lista.
  for (int i = 0; i < lista.size(); i++)
  {
    vectorTemp = dividir(lista[i][3], ':');
    suma = (vectorTemp[0] + vectorTemp[1]);
    lista[i][3] = suma;
  }
  return lista;
}

// Se regresa al formato original de las ip´s.
vector<vector<string>> desconvertirIps(vector<vector<string>> lista, vector<vector<string>> &posiciones)
{
  for (int i = 0; i < lista.size(); i++)
  {
    string p0 = posiciones[i][0];
    string p1 = posiciones[i][1];
    string p2 = posiciones[i][2];
    string p3 = posiciones[i][3];
    string ip = p0 + "." + p1 + "." + p2 + "." + p3;
    lista[i][3] = ip;
  }
  return lista;
}

int main()
{
  // Declaramos cada variable que vamos a necesitar
  vector<string> bitacora;
  vector<vector<string>> vectorConvertido;
  vector<vector<string>> posiciones;
  vector<vector<string>> vectorSeparado;
  vector<vector<string>> vectorOrdenado;
  int mes;
  int dia;
  int fecha1;
  int fecha2;
  int indice1 = -1;
  int indice2 = -1;

  cout << "Compilando..." << endl;
  leerArchivo("bitacora.txt", bitacora);

  vectorSeparado = separar(bitacora);   // ip se encuentra en el indice 3
  cout << "Leyendo archivo..." << endl;

  vectorConvertido = convertirNumeros(vectorSeparado);

  // Convierte las ip´s a enteros
  vectorConvertido = convertirIPS(vectorConvertido, posiciones);
  cout << "Procesando archivo..." << endl;

  vectorConvertido = convertirIPS2(vectorConvertido);

  cout << "Ordenando... Tiempo de espera aproximado de 6 min" << endl;

  vectorOrdenado = ordenBurbuja(vectorConvertido, posiciones);
  cout<<endl;
  //Se ingresa el primer valor a buscar.
  cout << endl<< "Ingresa el mes de inicio (numero de mes): ";
  cin >> mes;
  cout << endl<< "Ingresa el día de inicio: ";
  cin >> dia;
  fecha1 = ((mes)*100) + (dia);
  cout << endl<< "Ingresa el mes de fin (numero de mes): "; //Se ingresa el ultimo valor a imprimir.
  cin >> mes;
  cout << endl<< "Ingresa el día de fin: ";
  cin >> dia;
  if ((((mes == 1) || (mes == 3) || (mes == 5) || (mes == 6) || (mes == 8) || (mes == 10) || (mes == 12)) && (dia != 31)) || (((mes == 4) || (mes == 7) || (mes == 9) || (mes == 11)) && (dia != 30)) || ((mes == 2) && (dia != 28)))
  {
    fecha2 = (mes * 100) + (dia + 1); //Se transforma la entrada del usuario en un id.
  }
  else
  {
    fecha2 = ((mes + 1) * 100) + 1;
  }
  cout<<endl;
  cout << "Buscando... Tiempo de espera aproximado de 6 min" << endl;
  //Se guardan ambas fechas para buscarlas después.
  indice1 = busqSecuencialOrd(vectorOrdenado, fecha1);
  indice2 = busqSecuencialOrd(vectorOrdenado, fecha2);
  while ((indice1 == -1) || (indice2 == -1))
  {
    cout << endl<< "Fechas no validas, reingrese fechas" << endl; //En caso de no encontrar la fecha.
    cout << "Ingresa el mes de inicio (numero de mes): ";
    cin >> mes;
    cout << endl<< "Ingresa el día de inicio: ";
    cin >> dia;
    fecha1 = ((mes)*100) + (dia);
    cout << endl<< "Ingresa el mes de fin (numero de mes): ";
    cin >> mes;
    cout << endl<< "Ingresa el día de fin: ";
    cin >> dia;
    // Verifica si es el último día del mes ingresado
    if ((((mes == 1) || (mes == 3) || (mes == 5) || (mes == 6) || (mes == 8) || (mes == 10) || (mes == 12)) && (dia != 31)) || (((mes == 4) || (mes == 7) || (mes == 9) || (mes == 11)) && (dia != 30)) || ((mes == 2) && (dia != 28)))
    {
      fecha2 = (mes * 100) + (dia + 1);
    }
    else
    {
      fecha2 = ((mes + 1) * 100) + 1;
    }
    cout<<endl;
    cout << "Buscando... Tiempo de espera aproximado de 6 min" << endl;
    indice1 = busqSecuencialOrd(vectorOrdenado, fecha1);
    indice2 = busqSecuencialOrd(vectorOrdenado, fecha2);
  }

  //Se regresan los valores a su formato original para facilitar lectura
  vectorOrdenado = convertirMeses(vectorOrdenado);

  cout << "Completado: " << endl;
  int counter = 0;
  string iptemp;
  vector<string> ipLista;
  vector<int> counterLista;
  vectorOrdenado = desconvertirIps(vectorOrdenado, posiciones);
  // Verifica si la fecha final ingresada no corresponde al ultimo día del mes
  if ((fecha2 == 131) || (fecha2 == 228) || (fecha2 == 331) || (fecha2 == 430) || (fecha2 == 531) || (fecha2 == 630) || (fecha2 == 730) || (fecha2 == 831) || (fecha2 == 930) || (fecha2 == 1031) || (fecha2 == 1130) || (fecha2 == 1231))
  {
    for (int i = indice1; i < indice2; i++)
    {
      printVector(vectorOrdenado[i]); // Imprime linea
      if (vectorOrdenado[i + 1][3] == vectorOrdenado[i][3])
      {
        iptemp = vectorOrdenado[i][3];
        counter++;
      }
      else
      {
        if (counter > 0)
        {
          ipLista.push_back(iptemp);
          counterLista.push_back(counter);
          //cout<<iptemp<<" se repitio: "<<to_string(counter)<<endl;
        }
        counter = 0;
      }
    }
  }
  else
  {
    for (int i = indice1; i <= indice2 - 1; i++)
    {
      printVector(vectorOrdenado[i]); // Imprime linea
      if (vectorOrdenado[i + 1][3] == vectorOrdenado[i][3])
      {
        iptemp = vectorOrdenado[i][3];
        counter++;
      }
      else
      {
        if (counter > 0)
        {
          ipLista.push_back(iptemp);
          counterLista.push_back(counter);
          //cout<<iptemp<<" se repitio: "<<to_string(counter)<<endl;
        }
        counter = 0;
      }
    }
  }

  for (int i = 0; i < ipLista.size(); i++)
  {
    cout << endl;
    cout << ipLista[i] << "se repitio: " << to_string(counterLista[i]) << " veces en el rango a buscar." << endl;
  }

  // Creación del archivo
  ofstream bitacoraOrdenada;

  // Apertura y comprobación
  if (std::ofstream bitacoraOrdenada{"BitacoraResultado.txt"}) //Se guarda el resultado en un archivo de texto
  {
    if ((fecha2 == 131) || (fecha2 == 228) || (fecha2 == 331) || (fecha2 == 430) || (fecha2 == 531) || (fecha2 == 630) || (fecha2 == 730) || (fecha2 == 831) || (fecha2 == 930) || (fecha2 == 1031) || (fecha2 == 1130) || (fecha2 == 1231))
    {
      for (int i = indice1; i < indice2; i++)
      {
        for (int j = 0; j < vectorOrdenado[i].size(); j++)
        {
          bitacoraOrdenada << vectorOrdenado[i][j] << " ";
        }
        bitacoraOrdenada << endl;
      }
    }
    else
    {
      for (int i = indice1; i <= indice2 - 1; i++)
      {
        for (int j = 0; j < vectorOrdenado[i].size(); j++)
        {
          bitacoraOrdenada << vectorOrdenado[i][j] << " ";
        }
        bitacoraOrdenada << endl;
      }
    }

    for (int i = 0; i < ipLista.size(); i++)
    {
      bitacoraOrdenada << endl;
      bitacoraOrdenada << ipLista[i] << "se repitio: " << to_string(counterLista[i]) << " veces en el rango a buscar." << endl;
    }
  }
  else
  {
    cout << "Error al intentar abrir el archivo BitacoraResultado" << endl; //En caso de error.
  }
  bitacoraOrdenada.close();
}
