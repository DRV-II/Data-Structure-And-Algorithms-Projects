#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>
#include <stdexcept>

using namespace std;

template <class T>
class Node
{
public:
  T data;         // Información del objeto
  int key;        // Clave del valor
  Node<T> *left;  // Puntero al elemento del nodo izquierdo
  Node<T> *right; // Puntero al elemento de nodo derecho

  Node(T new_data, int key, Node<T> *left, Node<T> *right)
  {
    this->data = new_data;
    this->key = key;
    this->left = left;
    this->right = right;
  }

  Node(T new_data, int key)
  {
    this->data = new_data;
    this->key = key;
    this->left = NULL;
    this->right = NULL;
  }
};

template <class T>
class BinarySearchTree
{
public:
  Node<T> *root;

  BinarySearchTree()
  {
    this->root = NULL;
  }

  ~BinarySearchTree()
  {
  }

  void inorder(Node<T> *current_node)
  {
    if (current_node)
    {
      inorder(current_node->left);
      cout << current_node->key << " ";
      inorder(current_node->right);
    }

    if (this->root == current_node)
    {
      cout << endl;
    }
  }

  void insert(Node<T> *current_node, Node<T> *node_insert)
  {
    // Pasa siguiente nodo de acuerdo con las reglas
    Node<T> *next_node = current_node->left;
    bool is_left = true;
    if (node_insert->key > current_node->key)
    {
      next_node = current_node->right;
      is_left = false;
    }

    if (next_node)
    {
      // Si existe el siguiente nodo, pasa al siguiente
      this->insert(next_node, node_insert);
    }
    else if (is_left)
    {
      // Si el nodo no existe y el nodo está a la izquierda, se inserta en el lado izquierdo.
      current_node->left = node_insert;
    }
    else
    {
      // Si el nodo no existe y el nodo está a la derecha, lo insertamos en el lado derecha.
      current_node->right = node_insert;
    }
  }

  void insert(T data, int key)
  {
    Node<T> *node_insert = new Node<T>(data, key);
    if (this->root)
    {
      this->insert(this->root, node_insert);
    }
    else
    {
      // Inserta el primer nodo, si la raíz es NULL.
      this->root = node_insert;
    }
  }
  Node<T> *search(Node<T> *current_node, int key_searched)
  {
    if (!current_node || key_searched == current_node->key)
    {
      return current_node;
    }

    if (key_searched < current_node->key)
    {
      return search(current_node->left, key_searched);
    }
    return search(current_node->right, key_searched);
  }

  Node<T> *search(int key_searched)
  {
    return this->search(this->root, key_searched);
  }

  Node<T> *minimum_element(Node<T> *current_node)
  {
    if (!current_node->left)
    {
      return current_node;
    }
    return minimum_element(current_node->left);
  }

  Node<T> *delete_node(Node<T> *current_node, int key_delete)
  {
    if (!current_node)
      return NULL;
    // Busca el elemento a eliminar
    else if (key_delete < current_node->key)
    {
      current_node->left = this->delete_node(current_node->left, key_delete);
    }
    else if (key_delete > current_node->key)
    {
      current_node->right = this->delete_node(current_node->right, key_delete);
    }
    else
    {
      if (!current_node->left && !current_node->right)
      {
        // Si el nodo es una hoja, se elimina.
        delete current_node;
        current_node = NULL;
      }
      else if (!current_node->left)
      {
        // Si el nodo no tiene un nodo izquierdo, se reemplaza el nodo actual con la raíz derecha
        Node<T> *right_node = current_node->right;
        delete current_node;
        current_node = right_node;
      }
      else if (!current_node->right)
      {
        // Si el nodo no tiene el nodo correcto, se reemplaza el nodo actual con la raíz izquierda
        Node<T> *left_node = current_node->left;
        delete current_node;
        current_node = left_node;
      }
      else
      {
        // Si el nodo a eliminar tiene ambos nodos, se busca el elemento mínimo en el lado derecho
        Node<T> *successor = this->minimum_element(current_node->right);
        // Replace the data with the minimum element (also the key)
        Node<T> *new_node_minimum = new Node<T>(
            successor->data, successor->key,
            current_node->left, current_node->right);

        if (current_node == this->root)
        {
          this->root = new_node_minimum;
        }

        // Elimina el nodo actual
        delete current_node;

        // Ahora se elimina de forma recursiva el elemento mínimo en el subárbol derecho
        current_node = new_node_minimum;
        current_node->right = this->delete_node(current_node->right, successor->key);
      }
    }
    return current_node;
  }

  Node<T> *delete_node(int key_delete)
  {
    return this->delete_node(this->root, key_delete);
  }
};

// Abre el archivo y almacena los datos en un vector.
void leerArchivo(string nombreArchivo, vector<string> &bitacora)
{
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtiene la  línea de archivo, y la almacena el contenido en "linea"

  while (getline(archivo, linea))
  {

    bitacora.push_back(linea);
    //}
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

// Convierte las ip´s a lista.
vector<string> convertirIPS3(vector<string> lista, vector<vector<string>> &posiciones)
{
  vector<string> vectorTemp;
  string suma;
  // Separa las ip´s por punto y las junta.
  for (int i = 0; i < lista.size(); i++)
  {
    vectorTemp = dividir(lista[i], '.');
    suma = (vectorTemp[0]) + (vectorTemp[1]) + (vectorTemp[2]) + (vectorTemp[3]);
    posiciones.push_back(vectorTemp);
    lista[i] = suma;
  }
  return lista;
}

vector<string> convertirIPS4(vector<string> lista)
{
  vector<string> vectorTemp;
  string suma;
  // Convierte la última parte de la ip que tiene signo diferente a una lista.
  for (int i = 0; i < lista.size(); i++)
  {
    vectorTemp = dividir(lista[i], ':');
    suma = (vectorTemp[0] + vectorTemp[1]);
    lista[i] = suma;
  }
  return lista;
}

// Buscar con la busqueda secuencial un dato entero dentro del vector.
// Complejidad: O(n)
// Valor de retorno: El índice donde se encuentra el dato o -1 en caso de que no se localice.
int busquedaSecuencial(vector<string> arreglo, long buscar)
{
  int izq = 0;
  int tam = arreglo.size();
  int pos = -1;
  int der = tam - 1;

  // Ejecuta del 0 a la derecha.
  for (izq = 0; izq <= der;)
  {
    // Si se encuentra el elemento se pasa a la izquierda.
    if (stol(arreglo[izq]) == buscar)
    {
      pos = izq;
      return pos;
    }

    // Si no se queda en el subarreglo derecho.
    if (stol(arreglo[der]) == buscar)
    {
      pos = der;
      return pos;
    }
    izq++;
    der--;
  }

  // Si no se encuentra el elemento retorna -1.
  return pos;
}


// Buscar con la busqueda binaria un dato entero dentro del vector.
// Complejidad: O(log n).
// Valor de retorno: El índice donde se encuentra el dato o -1 en caso de que no se localice.
int busqueda_Binaria(vector<string> a, long k)
{
  int n = a.size();
  int l = 0;
  int r = n - 1;
  while (l <= r)
  {
    int m = floor((l + r) / 2);
     // Busca si el elemento esta en el medio.
    if (k == stol(a[m]))
    {
      return m;
    }
    // Si el elemento es mas pequeño que el de en medio
    else if (k < stol(a[m]))
    {
      r = m - 1;
    }
    else
    {
      l = m + 1;
    }
  }
  //Cuando no encuentra el numero se retorna -1
  return -1;
}

// Imprime cada linea del vector string.
void printVector(vector<string> a)
{
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

// Imprime cada linea del vector entero.
void printVectorInt(vector<int> a)
{
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

int mayor(vector<int> v) // v contiene la direccion de inicio del vector
{
  int mayor;
  // Tomamos el primer elemento como mayor
  mayor = v[0];
  // Avanzamos hasta el segundo elemento del vector
  for (int i = 1; i < v.size(); i++)
  {
    if (v[i] > mayor) // si el elemento actual es mayor que el mayor actual
    {
      mayor = v[i]; // se toma como mayor
    }
  }
  // Devuelvd el mayor
  return mayor;
}

int main()
{
  // Declaramos cada variable que vamos a necesitar
  vector<string> bitacora;
  vector<vector<string>> vectorSeparado;
  vector<vector<string>> vectorConvertido;
  vector<vector<string>> posiciones;
  vector<vector<string>> posicionesIp;
  int counter = 1;
  string iptemp;
  vector<string> ipLista;
  vector<int> counterLista;
  BinarySearchTree<string> bst;

  cout << "Compilando..." << endl;
  leerArchivo("BitacoraResultado.txt", bitacora);

  vectorSeparado = separar(bitacora); // Ip se encuentra en el indice 3
  cout << "Leyendo archivo..." << endl;

  vectorConvertido = convertirIPS(vectorSeparado, posiciones);

  vectorConvertido = convertirIPS2(vectorConvertido);

  // Guarda las ip´s que se repiten
  for (int i = 0; i < vectorSeparado.size(); i++) //-1
  {

    if (i - 1 == -1)
    {
      continue;
    }
    else
    {
      if (vectorSeparado[i][3] == vectorSeparado[i - 1][3])
      {

        iptemp = vectorSeparado[i][3];
        counter++;
        if (i == vectorSeparado.size() - 1)
        {
          if (counter > 1)
          {

            ipLista.push_back(iptemp);
            counterLista.push_back(counter);
          }
          counter = 1;
        }
      }
      else
      {
        if (counter > 1)
        {

          ipLista.push_back(iptemp);
          counterLista.push_back(counter);
        }
        counter = 1;
      }
    }
  }

  ipLista = convertirIPS3(ipLista, posicionesIp);

  ipLista = convertirIPS4(ipLista);

  //  Busca las ip´s que se repiten en la lista de vector separado para insertarlas en bst
  for (int i = 0; i < vectorSeparado.size(); i++)
  {

    int encuentra = busquedaSecuencial(ipLista, stol(vectorConvertido[i][3]));
    bool condicion;
    // En caso de que las encuentre.
    if (encuentra >= 0)
    {
      condicion = true;
    }
    // En caso de que no las encuentre.
    else
    {
      condicion = false;
    }
    if (condicion)
    {
      if (i - 1 == -1)
      {

        bst.insert(vectorSeparado[i][3], counterLista[encuentra]);
      }
      else
      {
        if (vectorSeparado[i][3] != vectorSeparado[i - 1][3])
        {

          bst.insert(vectorSeparado[i][3], counterLista[encuentra]);
        }
      }
    }
    else
    {
      bst.insert(vectorSeparado[i][3], 1);
    }
  }

  vector<int> top5;
  vector<int> copiaCounter = counterLista;
  int max;
  int cont = 1;
  for (int i = 0; i < counterLista.size(); i++)
  {
    max = mayor(copiaCounter);
    if (cont < 6)
    {
      top5.push_back(max);
    }
    cont++;
    copiaCounter.erase(std::remove(copiaCounter.begin(), copiaCounter.end(), max), copiaCounter.end());
  }
  cout << endl;

  // Imprime las 5 ip´s que mas se repiten.
  cout << "--------- TOP 5 IP ---------" << endl;
  for (int i = 0; i < top5.size(); i++)
  {
    cout << bst.search(top5[i])->data << " : " << top5[i] << " veces." << endl;
  }

  return 0;
}
