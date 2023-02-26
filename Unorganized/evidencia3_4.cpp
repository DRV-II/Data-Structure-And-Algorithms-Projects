#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>
#include <stdexcept>

using namespace std;

template <class T> class Node {
    public:
        T data; // The object information
        int key; // key of the value
        Node<T>* left; // Pointer to the left node element
        Node<T>* right; // Pointer to the right node element

        Node(T new_data, int key, Node<T>* left, Node<T>* right){
            this->data = new_data;
            this->key = key;
            this->left = left;
            this->right = right;
        }

        Node(T new_data, int key){
            this->data = new_data;
            this->key = key;
            this->left = NULL;
            this->right = NULL;
        }
};

template <class T> class BinarySearchTree{
    public:
        Node<T> *root;

        BinarySearchTree(){
            this->root = NULL;
        }

        ~BinarySearchTree(){

        }

        void inorder(Node<T>* current_node){
            if(current_node) {
                inorder(current_node->left);
                cout << current_node->key << " ";
                inorder(current_node->right);
            }

            if(this->root == current_node){
                cout << endl;
            }
        }

        void insert(Node<T> * current_node, Node<T> *node_insert){
            // Go to the next node according to the rules;
            Node<T> * next_node = current_node->left;
            bool is_left = true;
            if(node_insert->key > current_node->key){
                next_node = current_node->right;
                is_left = false;
            }

            if(next_node){
                // If exist the next node then, we go for the next
                this->insert(next_node, node_insert);
            }
            else if(is_left){
                // If the node doesn't exist and the node is in the left then we insert in the left side
                current_node->left = node_insert;
            }
            else{
                // If the node doesn't exist and the node is in the left then we insert in the left side
                current_node->right = node_insert;
            }
        }

        void insert(T data, int key){
            Node<T> *node_insert = new Node<T>(data, key);
            if (this->root){
                this->insert(this->root, node_insert);
            }
            else{
                // Insert the first node, if root is NULL.
                this->root = node_insert;
            }

        }
        Node<T>* search(Node<T>* current_node, int key_searched){
            if(!current_node || key_searched == current_node->key){
                return current_node;
            }

            if(key_searched < current_node->key){
                return search(current_node->left, key_searched);
            }
            return search(current_node->right, key_searched);
        }

        Node<T>* search(int key_searched){
            return this->search(this->root, key_searched);
        }

        Node<T>* minimum_element(Node<T>* current_node){
            if(!current_node->left){
                return current_node;
            }
            return minimum_element(current_node->left);
        }

        Node<T>* delete_node(Node<T>* current_node, int key_delete){
            if(!current_node) return NULL;
            // First search for the element to delete
            else if(key_delete < current_node->key){
                current_node->left = this->delete_node(current_node->left, key_delete);
            }
            else if(key_delete > current_node->key){
                current_node->right = this->delete_node(current_node->right, key_delete);
            }
            else{
                if(!current_node->left &&!current_node->right){
                    // If the node is a leaf we just delete it
                    delete current_node;
                    current_node = NULL;
                }
                else if(!current_node->left){
                    // If the node doesn't have left node,
                    // then just replace the current node with the right root
                    Node<T> * right_node = current_node->right;
                    delete current_node;
                    current_node = right_node;
                }
                else if(!current_node->right){
                    // If the node doesn't have right node,
                    // then just replace the current node with the left root
                    Node<T> * left_node = current_node->left;
                    delete current_node;
                    current_node = left_node;
                }
                else{
                    // If the node to delete has both nodes
                    // We search the minimum element in the right side
                    Node<T>* successor  = this->minimum_element(current_node->right);
                    // Replace the data with the minimum element (also the key)
                    Node<T>* new_node_minimum = new Node<T>(
                        successor ->data, successor->key,
                        current_node->left, current_node->right);

                    if(current_node == this->root){
                        this->root = new_node_minimum;
                    }

                    // Delete the current node
                    delete current_node;

                    // Now we recursively delete the minimum element in the right subtree
                    current_node = new_node_minimum;
                    current_node->right = this->delete_node(current_node->right, successor->key);
                }
            }
            return current_node;
        }

        Node<T>* delete_node(int key_delete){
            return this->delete_node(this->root, key_delete);
        }

};

// Abre el archivo y almacena los datos en un vector.
void leerArchivo(string nombreArchivo, vector<string> &bitacora)
{
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtiene la  línea de archivo, y la almacena el contenido en "linea"
  /*
  while(input >> current) {
    always_next_struct val = always_next_struct(next);
    if (current == L' '  current == L'\n'  current == L'\t' || current == L'\r') {
        continue;
    }
    if (current == L'/') {
        input >> current;
        if (current == L'/') {
            // explicitly empty while loop
            while(input.get(current) && current != L'\n');
            continue;
        }
      }
    }
    */

  while (getline(archivo, linea))
  {
    /*
    // Se imprime
    if (linea == "\n")
    {
      break;
    }
    else
    {
    */
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

/*
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
*/

// Utilizamos busqueda secuencial de arreglos ordenados para encontrar las fechas en específico dentro del vector.
// Complejidad: Mejor O(1), Promedio O(n/2), Peor O(n)
int busqSecuencialOrd(vector<string> a, float k)
{
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    if (k <= (stol(a[i])))
    {
      if (k == (stol(a[i])))
      {
        return i;
      }
      else
      {
        return -1;
      }
    }
  }
  return -1;
}

int busquedaSecuencial(vector<string> arreglo, long buscar)
{
    int izq = 0;
    int tam = arreglo.size();
    int pos = -1;
    int der = tam - 1;

    // Ejecuta del 0 a la derecha.
    for(izq = 0; izq <= der;){
        //Si se encuentra el elemento se pasa a la izquierda.
        if (stol(arreglo[izq]) == buscar){
            pos = izq;
            cout << "\n\nBusqueda Secuencial: \nElemento encontrado en el arreglo en la posición: "<< pos<<endl;
            return pos;
        }

        // Si no se queda en el subarreglo derecho.
        if(stol(arreglo[der]) == buscar){
            pos = der;
            cout << "\n\nBusqueda Secuencial: \nElemento encontrado en el arreglo en la posición: "<< pos<<endl;
            return pos;
        }
        izq++;
        der--;
    }

    // Si no se encuentra el elemento retorna -1.
    if (pos == -1) {
        cout << "\nBusqueda Secuencial:\n-1 Elemento no encontrado en el arreglo"<<endl;
    }
    return pos;
}

int busqueda_Binaria(vector<string> a, long k)//Complejidad de O(logn)
{
    int n = a.size();
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = floor((l + r) / 2);
        if (k == stol(a[m]))
        {
            return m;
        }
        else if (k < stol(a[m]))
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
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
  mayor=v[0]; //tomamos el primer elemento como mayor
  //bv++;        //avanzamos hasta el segundo elemento del vector
  for(int i=1;i<v.size();i++)
  {
     if(v[i] > mayor) //si el elemento actual es mayor que el mayor actual
     {
         mayor=v[i]; //se toma como mayor
     }
     // v++; //siguiente elemento del vector
  }

  return mayor; //se devuelve el mayor
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
  /*
  int mes;
  int dia;
  int fecha1;
  int fecha2;
  int indice1 = -1;
  int indice2 = -1;
  */

  cout << "Compilando..." << endl;
  leerArchivo("BitacoraResultado.txt", bitacora);

  vectorSeparado = separar(bitacora);   // ip se encuentra en el indice 3
  cout << "Leyendo archivo..." << endl;
  for (int i = 0; i < vectorSeparado.size();i++) {
    cout<<vectorSeparado[i][3]<<endl;
  }
  cout<<"Pasa impresión"<<endl;
  vectorConvertido = convertirIPS(vectorSeparado, posiciones);
  cout << "Pasa IPS1"<<endl;
  vectorConvertido = convertirIPS2(vectorConvertido);
  cout << "Pasa IPS2"<<endl;

  // Guardar ip que se repiten
  for (int i = 0; i < vectorSeparado.size(); i++) //-1
  {

    if (i-1==-1) {
      continue;
    }
    // cout<<vectorConvertido[i][3]<<endl; // Imprime linea
    else
    {
      if (vectorSeparado[i][3] == vectorSeparado[i-1][3])
      {
        cout<<"encuentra ip que se repite: "<<vectorSeparado[i][3]<<endl;
        iptemp = vectorSeparado[i][3];
        counter++;
        if (i == vectorSeparado.size()-1) {
          if (counter > 1)
          {
            cout<<"Inserta ip que se repite: "<< counter<<" veces: "<<vectorSeparado[i][3]<<endl;
            ipLista.push_back(iptemp);
            counterLista.push_back(counter);
            //cout<<iptemp<<" se repitio: "<<to_string(counter)<<endl;
          }
          counter = 1;
          cout<<vectorSeparado[i][3]<<endl;
        }
      }
      else
      {
        if (counter > 1)
        {
          cout<<"Inserta ip que se repite: "<< counter<<" veces: "<<vectorSeparado[i][3]<<endl;
          ipLista.push_back(iptemp);
          counterLista.push_back(counter);
          //cout<<iptemp<<" se repitio: "<<to_string(counter)<<endl;
        }
        counter = 1;
        cout<<vectorSeparado[i][3]<<endl;
      }
    }
  }
  cout<<"Salgo de contar ips"<<endl;

  ipLista = convertirIPS3(ipLista, posicionesIp);
  cout << "Pasa IPS3"<<endl;
  ipLista = convertirIPS4(ipLista);
  cout << "Pasa IPS4"<<endl;

  for (int i = 0; i < ipLista.size();i++) {
    cout<<ipLista[i]<< " : "<< counterLista[i]<<endl;
  }
 //122236644536 == 122236644536
 // Busca ip que se repiten en la lista de vector Separado para insertar en bst
  for (int i=0; i < vectorSeparado.size(); i++)
  {
    cout<<endl<<vectorConvertido[i][3]<<endl;
    int encuentra = busquedaSecuencial(ipLista, stol(vectorConvertido[i][3]));
    cout<<"Encuentra indice: "<<encuentra<<endl;
    bool condicion;
    if (encuentra >= 0)
    {
        condicion = true;
        cout<<"Encuentra: Si"<<endl;
    }
    else
    {
        condicion = false;
        cout<<"Encuentra: No"<<endl;
    }
    if (condicion)
    {
      if (i-1 == -1) {
        cout<<endl;
        bst.insert(vectorSeparado[i][3],counterLista[encuentra]);
        cout<<"Ip que se repite: "<<vectorSeparado[i][3]<<endl;
        cout<<ipLista[encuentra]<<endl;
        cout<<endl;
      }
      else
      {
        if (vectorSeparado[i][3]!=vectorSeparado[i-1][3]) {
          cout<<endl;
          bst.insert(vectorSeparado[i][3],counterLista[encuentra]);
          cout<<"Ip que se repite: "<<vectorSeparado[i][3]<<endl;
          cout<<ipLista[encuentra]<<endl;
          cout<<endl;
        }
      }
    }
    else
    {
      bst.insert(vectorSeparado[i][3],1);
      cout<<vectorSeparado[i][3]<<endl;
    }
  }

  vector<int> top5;
  vector<int> copiaCounter = counterLista;
  int max;
  int cont=1;
  for (int i = 0; i < counterLista.size(); i++) {
    max = mayor(copiaCounter);
    if (cont<6) {
      top5.push_back(max);
    }
    cont++;
    copiaCounter.erase(std::remove(copiaCounter.begin(), copiaCounter.end(), max), copiaCounter.end());
  }
  printVectorInt(top5);

  bst.inorder(bst.root);
  cout << endl;

  // Node<string>* prueba = bst.search(top5[0]);
  // string valor = prueba->data;
  // cout<<valor;

  // Imprime el Top 5 ip que mas se repiten
  cout<<"--------- TOP 5 IP ---------"<<endl;
  for (int i = 0; i < top5.size(); i++)
  {
    cout<<bst.search(top5[i])->data<< " : "<<top5[i]<< " veces."<<endl;
  }
    /*
  bst.delete_node(50);


  cout << endl;
  bst.inorder(bst.root);


  bst.delete_node(70);
  cout << endl;
  bst.inorder(bst.root);


  bst.delete_node(20);
  cout << endl;
  bst.inorder(bst.root);
  */
  return 0;
}
