#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
  T data;
  Node<T> *left;
  Node<T> *right;
  int altura;
  Node();
  Node(T);
};

template <class T>
Node<T>::Node()
{
  left = nullptr;
  right = nullptr;
  altura = 1;
}
template <class T>
Node<T>::Node(T val)
{
  data = val;
  left = nullptr;
  right = nullptr;
  altura = 1;
}

template <class T>
class AVL
{
private:
  Node<T> *root;
  void preOrder(Node<T> *nodo);
  void postOrder(Node<T> *nodo);
  void inOrder(Node<T> *nodo);

  int max(int a, int b);
  Node<T> *rightRotate(Node<T> *y);
  Node<T> *leftRotate(Node<T> *x);
  int getBalance(Node<T> *N);

public:
  AVL();

  void clear(Node<T> *p);
  bool search(T valor);
  void insert(T valor);
  Node<T> *insertRec(Node<T> *r, T valor);
  void callPreorder();
  void callPostorder();
  void callInorder();
  int height(Node<T> *N);
};

template <class T>
AVL<T>::AVL()
{
  cout << "Arbol vacio " << this << endl;
  root = nullptr;
}


template <class T>
void AVL<T>::clear(Node<T> *p)
{
  if (p != NULL)
  {
    clearMemory(p->left);
    clearMemory(p->right);
    delete p;
    p = NULL;
  }
}

template <class T>
bool AVL<T>::search(T valor)
{
  Node<T> *p = root;
  while (p != nullptr)
  {
    if (p->data == valor)
    {
      return true;
    }
    else
    {
      p = (valor < p->data ? p->left : p->right);
    }
  }
  return false;
}
template <class T>
int AVL<T>::height(Node<T> *N)
{
  if (N == nullptr)
    return 0;
  return N->altura;
}

template <class T>
int AVL<T>::max(int a, int b)
{
  return (a > b) ? a : b;
}

template <class T>
Node<T> *AVL<T>::rightRotate(Node<T> *y)
{
  Node<T> *x = y->left;
  Node<T> *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->altura = max(height(y->left), height(y->right)) + 1;
  x->altura = max(height(x->left), height(x->right)) + 1;
  return x;
}

template <class T>
Node<T> *AVL<T>::leftRotate(Node<T> *x)
{
  Node<T> *y = x->right;
  Node<T> *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->altura = max(height(x->left), height(x->right)) + 1;
  return y;
}

template <class T>
int AVL<T>::getBalance(Node<T> *N)
{
  if (N == nullptr)
    return 0;
  return height(N->left) - height(N->right);
}

template <class T>
Node<T> *AVL<T>::insertRec(Node<T> *node, T key)
{
  if (node == NULL)
    return (new Node<T>(key));

  if (key < node->data)
    node->left = insertRec(node->left, key);
  else if (key > node->data)
    node->right = insertRec(node->right, key);
  else
    return node;

  node->altura = 1 + max(height(node->left),
                         height(node->right));

  int balance = getBalance(node);

  if (balance > 1 && key < node->left->data)
    return rightRotate(node);

  if (balance < -1 && key > node->right->data)
    return leftRotate(node);

  if (balance > 1 && key > node->left->data)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->data)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

template <class T>
void AVL<T>::insert(T valor)
{
  root = insertRec(root, valor);
}

template <class T>
void AVL<T>::preOrder(Node<T> *nodo)
{
  if (nodo != nullptr)
  {
    cout << nodo->data << " ";
    preOrder(nodo->left);
    preOrder(nodo->right);
  }
}

template <class T>
void AVL<T>::inOrder(Node<T> *nodo)
{
  if (nodo != nullptr)
  {
    inOrder(nodo->left);
    cout << nodo->data << " ";
    inOrder(nodo->right);
  }
}

template <class T>
void AVL<T>::postOrder(Node<T> *nodo)
{
  if (nodo != nullptr)
  {
    postOrder(nodo->left);
    postOrder(nodo->right);
    cout << nodo->data << " ";
  }
}
template <class T>
void AVL<T>::callPostorder()
{
  postOrder(root);
  cout << std::endl;
}

template <class T>
void AVL<T>::callInorder()
{
  inOrder(root);
  cout << std::endl;
}

template <class T>
void AVL<T>::callPreorder()
{
  preOrder(root);
  cout << std::endl;
}

int main() {
  cout << "Arbol AVL"<<endl;
  AVL<int> avl;

  avl.insert(10);
  avl.insert(20);
  avl.insert(30);
  avl.insert(40);
  avl.insert(50);
  avl.insert(25);

  avl.callPreorder();



}
