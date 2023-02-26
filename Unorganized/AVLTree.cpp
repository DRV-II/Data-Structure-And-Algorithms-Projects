/*
Alumno: David Román Velasco
Matrícula: A01639645

Hecho colaborativamente con:
Paulina Lizet Gutiérrez Amezcua - A01639948

Fecha: 23/10/2021
Act 3.3 - Árbol Desplegado: Implementando un AVL Tree
*/

/*
Complejidad:

Complejidad de tiempo
"the insertion, deletion and search operations take O(logn) in both the average and the worst cases." (Edpresso Team, s.f., seccion de Time Complexity, parr. 1)

Complejidad de espacio
"The space complexity of an AVL tree is O(n) in both the average and the worst case." (Edpresso Team, s.f., seccion de Space Complexity, parr. 1)

Referencias
Edpresso Team. (s.f.). What is an AVL tree?. Recuperado de: https://www.educative.io/edpresso/what-is-an-avl-tree
*/

#include<iostream>
using namespace std;

// Clase Node para el AVL
template <class T> class Node {
  private:
    T datos; // Datos
    int key; // Llave
    Node<T>* left; // Apuntador a nodo izquierdo
    Node<T>* right; // Apuntador a nodo izquierdo
    int height; // Altura de nodo
  public:
    // Constructor completo
    Node(T data, int k, Node<T>* l, Node<T>* r) {
      datos = data;
      key = k;
      left = l;
      right = r;
      height = 1;
    }
    // Constructor de llave y datos
    Node(T data, int k) {
      datos = data;
      key = k;
      left = NULL;
      right = NULL;
      height = 1;
    }

    // Getters y Setters
    void setDatos(T data) {
      datos = data;
    }
    void setKey(int k) {
      key = k;
    }
    void setLeft(Node<T>* l) {
      left = l;
    }
    void setRight(Node<T>* r) {
      right = r;
    }
    void setHeight(int h) {
      height = h;
    }
    T getDatos() {
      return datos;
    }
    int getKey() {
      return key;
    }
    Node<T>* getLeft() {
      return left;
    }
    Node<T>* getRight() {
      return right;
    }
    int getHeight() {
      return height;
    }
};

// Clase de Arbol AVL
template <class T> class AVL
{
  public:
    // Nodo raiz del arbol
    Node<T>* root;

    // Constructor del arbol
    AVL(){
      this->root = NULL;
    }

    // Destructor del arbol
    ~AVL() {

    }

    // Funcion que actualiza altura del nodo ingresado
    void heightUpdt(Node<T>* node) {
      if(node) {
        this->heightUpdt(node->getRight());
        this->heightUpdt(node->getLeft());
        node->setHeight(this->height(node));
      }
    }

    // Funcion que calcula altura del nodo ingresado
    int height(Node<T>* node) {
      int h = 0;
      if (node != NULL) {
          int l_height = height(node->getLeft());
          int r_height = height(node->getRight());
          int max_height = max(l_height, r_height);
          h = max_height + 1;
      }
      return h;
    }

    // funcion que calcula el factor de balance del nodo
    int difference(Node<T>* node) {
      int l_height = height(node->getLeft());
      int r_height = height(node->getRight());
      int b_factor = l_height - r_height;
      return b_factor;
    }

    // Rotación derecha de arbol
    Node<T>* rightRotate(Node<T>* parent) {
      Node<T>* node;
      node = parent->getRight();
      parent->setRight(node->getLeft());
      node->setLeft(parent);
      //cout << "Right Rotation" << endl;
      return node;
    }

    // Rotación izquierda de arbol
    Node<T>* leftRotate(Node<T>* parent) {
      Node<T>* node;
      node = parent->getLeft();
      parent->setLeft(node->getRight());
      node->setRight(parent);
      //cout << "Left Rotation" << endl;
      return node;
    }

    // Rotación izquierda-derecha de arbol
    Node<T>* lr_rotat(Node<T>* parent) {
        Node<T>* node;
        node = parent->getLeft();
        parent->setLeft(rightRotate(node));
        //cout << "Left-Right Rotation" << endl;
        return leftRotate(parent);
    }

    // Rotación derecha-izquierda de arbol
    Node<T>* rl_rotat(Node<T>* parent) {
        Node<T>* node;
        node = parent->getRight();
        parent->setRight(leftRotate(node));
        //cout << "Right-Left Rotation" <<endl;
        return rightRotate(parent);
    }

    // Calcula valor minimo de subarbol
    Node<T> * minValueNode(Node<T>* node)
    {
      Node<T>* current = node;

      /* Ciclo para encontrar el nodo más pequeño de la izquierda */
      while (current->getLeft() != NULL)
          current = current->getLeft();

      return current;
    }

    // funcion que calcula el factor de balance del nodo
    int getBalance(Node<T>* current){
      if (current == NULL){
        return 0;
      }
      else{
        return height(current->getLeft()) - height(current->getRight());
      }
    }

    // Funcion de balance de arbol
    Node<T>* balance(Node<T>* node) {
    int bal_factor = difference(node);
    if (bal_factor > 1) {
        if (difference(node->getleft()) > 0)
            node = leftRotate(node);
        else
            node = lr_rotat(node);
    }
    else if (bal_factor < -1) {
        if (difference(node->getRight()) > 0)
            node = rl_rotat(node);
        else
            node = rightRotate(node);
    }
    return node;
    }

    // Funcion recursiva de inserción de nodos
    Node<T> *insert(Node<T> * current, Node<T> *insert){
      Node<T> * next = current->getLeft();
      bool is_left = true;
      if(insert->getKey() > current->getKey()){
        next = current->getRight();
        is_left = false;
      }
      if(next){
        if(is_left){
          current->setLeft(this->insert(next, insert));
        }
        else{
          current->setRight(this->insert(next, insert));
        }
      }
      else if(is_left){
        current -> setLeft(insert);
      }
      else{
        current->setRight(insert);
      }
      current = this->balance_tree(current);
      return current;
    }

    // Funcion para balancear Arbol AVL
    Node<T> * balance_tree(Node<T> * current){
      if (!current) {
        return NULL;
      }
      // Empezamos operaciones de AVL
      current->setHeight(this->height(current));

      int balanceFactor = this->getBalance(current); // Revisar factor de balance de nodo

      if(balanceFactor == 2 && this->getBalance(current->getLeft())==1) {
        current = this->leftRotate(current);
      }

      else if (balanceFactor == -2 && this->getBalance(current->getRight())==-1) {
        current = this->rightRotate(current);
      }

      else if (balanceFactor == -2 && this->getBalance(current->getRight())==1) {
        current = this->rl_rotat(current);
      }

      else if (balanceFactor == 2 && this->getBalance(current->getLeft())==-1) {
        current = this->lr_rotat(current);
      }
      else if (balanceFactor == 2 || balanceFactor == -2) {
        cout << "bug" <<endl;
      }
      return current;
    }

    // Función de insertar datos y llave para creacion de nuevo nodo
    void insert(T datos, int k){
      Node<T> *insert = new Node<T>(datos,k);
      if (this->root){
        this->root = this->insert(this->root,insert); // Utiliza funcion recursiva
        this->heightUpdt(this->root);
      }
      else{
        this->root = insert;
        insert->setHeight(1);
      }
    }

    // Función para borrar nodo de arbol
    Node<T>* deleteNode(Node<T>* current, int k) {
      if (!current) {
        return NULL;
      }
      // Busca elemento para eliminar
      else if (k < current->getKey()) {
        current->setLeft(this->deleteNode(current->getLeft(), k));
      }
      else if (k > current->getKey()) {
        current->setRight(this->deleteNode(current->getRight(), k));
      }

      else {
        if (!current->getLeft() && !current->getRight()) {
          // Si el nodo es hoja, borremoslo
          delete current;
          current = NULL;
        }
        else if (!current->getLeft()) {
          // Si no hay nodo izquierdo
          // Remplacemos con el nodo derecho
          Node<T>* nodeRight = current->getRight();
          delete current;
          current = nodeRight;
        }
        else if (!current->getRight()) {
          // Si no hay nodo izquierdo
          // Remplacemos con el nodo derecho
          Node<T>* nodeLeft = current->getLeft();
          delete current;
          current = nodeLeft;
        }
        else {
          // Si el nodo a borrar tiene dos nodos hijos
          // Buscamos el minimo del lado derecho
          Node<T>* siguiente = this->minValueNode(current->getRight()); // revisar minimum_element
          // Remplazar datos con el valor minimo
          Node<T>* nuevoMin = new Node<T>(siguiente->getDatos(), siguiente->getKey(), current->getLeft(), current->getRight());

          if(current == this->root) {
            this->root = nuevoMin;
          }

          // Borramos nodo
          delete current;

          // Borramos recursivamente el elemento minimo del subarbol derecho
          current = nuevoMin;
          current->setRight(this->deleteNode(current->getRight(), siguiente->getKey()));
        }
      }
      current = this->balanceTreeDel(current);
      return current;
    }

    // Función para borrar nodo de arbol en el main
    // Solo ingresa llave
    void deleteNode(int k) {
      this->root = this->deleteNode(this->root, k); // Usa función recursiva
      this->heightUpdt(this->root);
    }


    // Función para balancear arbol despues de borrar un nodo
    Node<T>* balanceTreeDel(Node<T>* current) {
      if (!current) {
        return NULL;
      }
      // Empezamos operaciones de AVL
      current->setHeight(this->height(current));

      int balanceFactor = this->getBalance(current); // Revisar balance de nodo

      if(balanceFactor == 2 && this->getBalance(current->getLeft())==1) {
        current = this->leftRotate(current);
      }

      else if (balanceFactor == 2 && this->getBalance(current->getLeft())==-1) {
        current = this->lr_rotat(current);
      }

      else if (balanceFactor == 2 && this->getBalance(current->getLeft())==0 && current->getLeft()) {
        current = this->leftRotate(current);
      }

      else if (balanceFactor == -2 && this->getBalance(current->getRight())==-1) {
        current = this->rightRotate(current);
      }

      else if (balanceFactor == -2 && this->getBalance(current->getRight())==1) {
        current = this->rl_rotat(current);
      }

      else if (balanceFactor == -2 && this->getBalance(current->getRight())==0 && current->getRight()) {
        current = this->rightRotate(current);
      }

      else if (balanceFactor == -2 || balanceFactor==2) {
        cout << "bug" <<endl;
      }
      return current;
    }

    // Calcula tamaño de arbol
    int size(Node<T>* r)
    {
    if (r == NULL)
        return 0;
    else
        return(size(r->getLeft()) + 1 + size(r->getRight()));
    }

    // Imprime arbol
    void print(Node<T>* p, int l) {
      int i;
      if (p != NULL) {
          print(p->getRight(), l + 1);
          cout << " ";
          if (p == this->root)
              cout << "Root -> ";
          for (i = 0; i < l && p != this->root; i++)
              cout << " ";
          cout << p->getKey();
          print(p->getLeft(), l + 1);
        }
      }

      // Inmprime datos de arbol en orden de llaves
      void printData(Node<T>* p, int l) {
        int i;
        if (p != NULL) {
            printData(p->getRight(), l + 1);
            cout << " ";
            if (p == this->root)
                cout << "Root -> ";
            for (i = 0; i < l && p != this->root; i++)
                cout << " ";
            cout << p->getDatos();
            printData(p->getLeft(), l + 1);
          }
        }

      // Busca un nodo y devuelve un valor booleano si lo
      // encuentra o no lo encuentra
      bool find(int valor)
      {
        Node<T>* p = this->root;
        while (p != nullptr)
        {
          if (p->getKey() == valor)
          {
            return true;
          }
          else
          {
            p = (valor < p->getKey() ? p->getLeft() : p->getRight());
          }
        }
        return false;
      }

};

// Función para imprimir si encontro un valor en el AVL
// o si no lo encontro
void encuentra(bool b, int valor){
  cout<<"\nValor a buscar: "<<valor;
  if (b==true) {
    cout<<"\nValor encontrado \n";
  }
  else {
    cout<<"\nValor no encontrado \n";
  }
}

// Inicia main
int main()
{
  // Inicio de Caso 1
  cout << "\n----  ----  ---- CASO 1 ----  ----  ----\n" << endl;
  AVL<string> avl; // crear avl
  // insertar llave y datos de avl
  avl.insert("hola", 3);
  avl.insert("como", 6);
  avl.insert("estas", 7);
  avl.insert("soy", 5);
  avl.insert("yo", 9);

  // Imprimir y calcular tamaño de avl
  cout << "-------Arbol AVL Balanceado-------" << endl;
  avl.print(avl.root, 1);
  cout << endl;
  cout << "Tamaño del arbol: " << avl.size(avl.root);
  cout<<endl;

  // Enocntrar llave en AVL
  encuentra(avl.find(6), 6);

  cout<<endl;

  // Eliminar llave de AVL
  cout<<"\tKey a eliminar: 6"<<endl;
  avl.deleteNode(6);
  // Imprimir de nuevo para ver si se elimino
  cout << "-------Arbol AVL Balanceado-------" << endl;
  avl.print(avl.root, 1);
  cout << endl;

  // Calcular tamaño nuevo
  cout << "Nuevo tamaño de arbol: " << avl.size(avl.root);
  cout<<endl;

  // Verificar si encuentra o no encuentra llave eliminada
  encuentra(avl.find(6), 6);

  // Inicio de Caso 2, repite el procedimiento
  // con nuevo arbol y diferentes valores para la llave
  cout<<endl;
  cout << "\n----  ----  ---- CASO 2 ----  ----  ----\n" << endl;
  AVL<string> avl2;
  avl2.insert("hola", 4);
  avl2.insert("estas", 8);
  avl2.insert("soy", 6);
  avl2.insert("yo", 10);

  cout << "-------Arbol AVL Balanceado-------" << endl;
  avl2.print(avl2.root, 1);
  cout << endl;
  cout << "Tamaño del arbol: " << avl2.size(avl2.root);
  cout<<endl;

  encuentra(avl2.find(4), 4);

  cout<<endl;

  cout<<"\tKey a eliminar: 4"<<endl;
  avl2.deleteNode(4);
  cout << "-------Arbol AVL Balanceado-------" << endl;
  avl2.print(avl2.root, 1);
  cout << endl;

  cout << "Nuevo tamaño de arbol: " << avl2.size(avl2.root);
  cout<<endl;

  encuentra(avl2.find(4), 4);

  cout<<endl;

  // Inicio de Caso 3, repite el procedimiento
  // con nuevo arbol y diferentes valores para la llave
  cout << "\n----  ----  ---- CASO 3 ----  ----  ----\n" << endl;
  AVL<string> avl3;
  avl3.insert("hola", 6);
  avl3.insert("como", 11);
  avl3.insert("estas", 14);
  avl3.insert("soy", 12);
  avl3.insert("yo", 16);
  avl3.insert("yo", 10);

  cout << "-------Arbol AVL Balanceado-------" << endl;
  avl3.print(avl3.root, 1);
  cout << endl;
  cout << "Tamaño del arbol: " << avl3.size(avl3.root);
  cout<<endl;

  encuentra(avl3.find(12), 12);

  cout<<endl;

  cout<<"\tKey a eliminar: 12"<<endl;
  avl3.deleteNode(12);
  cout << "-------Arbol AVL Balanceado-------" << endl;
  avl3.print(avl3.root, 1);
  cout << endl;

  cout << "Nuevo tamaño de arbol: " << avl3.size(avl3.root);
  cout<<endl;

  encuentra(avl3.find(12), 12);

  cout<<endl;

  // Inicio de Caso 4, repite el procedimiento
  // con nuevo arbol y diferentes valores para la llave y datos
  // Esta vez tambien vamos a imprimir los datos correspondientes a las
  // llaves de los nodos
  cout << "\n----  ----  ---- CASO 4 ----  ----  ----\n" << endl;
  AVL<string> avl4;
  avl4.insert("soy", 2);
  avl4.insert("estas", 4);
  avl4.insert("como", 8);
  avl4.insert("NOOOO", 12);
  avl4.insert("yo", 1);
  avl4.insert("Hola", 18);

  cout << "-------Arbol AVL Balanceado-------" << endl;
  avl4.print(avl4.root, 1);
  cout << endl;
  cout << "Tamaño del arbol: " << avl4.size(avl4.root);
  cout<<endl;
  encuentra(avl4.find(12), 12);
  cout<<endl;
  // Imrimimos los datos correspondientes a las llaves de los nodos del AVL
  cout << "-------Impresión de datos-------" << endl;
  avl4.printData(avl4.root, 1);

  cout<<endl<<endl;

  cout<<"\tKey a eliminar: 12"<<endl;
  avl4.deleteNode(12);
  cout << "-------Arbol AVL Balanceado-------" << endl;
  avl4.print(avl4.root, 1);
  cout << endl;

  cout << "Nuevo tamaño de arbol: " << avl4.size(avl4.root);
  cout<<endl;
  encuentra(avl4.find(12), 12);
  cout<<endl;
  // Volvemos a imprimir los datos correspondientes a las llaves de los nodos del AVL
  // despues de borrar el nodo de la llave 12
  cout << "-------Impresión de datos-------" << endl;
  avl4.printData(avl4.root, 1);
  cout<<endl<<endl;

  return 0;
}
