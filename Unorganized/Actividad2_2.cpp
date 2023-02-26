/*
Actividad 2.2
Entrega de Alumno: David Román Velasco A01639645
Hecho con colaboración de:
Paulina Lizet Gutiérrez Amezcua A01639948,
Juan Pablo García Malta A01639025
Fecha de creación: 24 de septiembre del 2021
*/

#include <iostream>
#include <climits>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

// Palindrome
// Función que dado un entero x, devuelve verdadero si es un entero palíndromo.
bool palindrome(int n) {
  // Verificamos que el valor no sea menor a 0.
  if(n < 0){
      return false;
  }

  // Se usa el divisor para calcular la cantidad de dígitos en el número.
  int divisor = 1;
  // Se multiplica el divisor por 10 hasta que n / divisor sea mayor o igual a 10.
  while(n/divisor >= 10){
      divisor *= 10;
  }
  // Se comprueba que el primer y último número no sean iguales.
  while(n != 0){
      if (n / divisor != n % 10) {
          return false;
      }
      // Se elimina el primer número.
      n %= divisor;
      // Se elimina el último número.
      n /= 10;
      // Se divide el divisor entre 100.
      divisor /= 100;
  }
  return true;
}

void printPalindrome(int n) {
  cout<<"n = "<<n<<endl; // Imprime número
  bool pali = palindrome(n); // Resultado si es o no palindromo
  if (pali == true) {
    cout<<"True"<<endl; // Verdadero si es palindromo
  }
  else {
    cout<<"False"<<endl; // Falso si es palindromo
  }
  cout<<endl;
}

// Reverse integer
// Función que devuelve el número entero al revés.
int reverse(int x) { //una funcion que recibe un entero.
        long int temp=0; //creamos un numero temporal de largo rango
        while(x != 0){
            temp = temp * 10 + x % 10;
            x /= 10;//vamos iterando hasta que que se le de la vuelta
        }
        if ( temp < INT_MIN ||  temp > INT_MAX) return 0;//comparamos con los valores maximos de un entero y regresamos el resultado.
        return temp;
    }

// Merge Two Sorted Lists
// Función que combina dos listas vinculadas ordenadas y las devuelve como una lista ordenada.

// Link list node
class Node
{
    public:
    int data;
    Node* next;
};

//Retira el nodo frontal de la fuente.
void moveNode(Node** destRef, Node** sourceRef);

// Toma dos listas ordenadas  y empalma sus nodos.
Node* mergeSortedLists(Node* a, Node* b)
{
    // Primer nodo.
    Node dummy;

    // tail apunta al último nodo de resultado
    Node* tail = &dummy;

    // tail->next para agregar nuevos nodos al resultado.
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            // Si se acaba la lista, se usa otra.
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            moveNode(&(tail->next), &a);
        else
            moveNode(&(tail->next), &b);

        tail = tail->next;
    }
    return(dummy.next);
}

// Toma el nodo desde el frente de la fuente, y lo mueve al frente del destino.
void moveNode(Node** destRef, Node** sourceRef)
{
    // Nodo fuente frontal.
    Node* newNode = *sourceRef;
    assert(newNode != NULL);

    // Avanza el puntero de la fuente.
    *sourceRef = newNode->next;

    // Vincula el destino antiguo al nuevo nodo
    newNode->next = *destRef;

    // Mover dest para apuntar al nuevo nodo.
    *destRef = newNode;
}

//Función para insertar un nodo en el comienzo de la lista enlazada.
void push(Node** head_ref, int new_data)
{
    // Asignar nodo
    Node* new_node = new Node();
    new_node->data = new_data;
    // Vincular la lista anterior del nuevo nodo
    new_node->next = (*head_ref);

    // Apunta al nuevo nodo
    (*head_ref) = new_node;
}

// Función para imprimir nodos
void printArray(Node *node)
{
    while (node!=NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

// Valid Parentheses
// Función que dada una cadena determina si es válida.
bool validParentheses(string str)
{
    // Se crea un stack de char.
    stack<char> sc;
    int size = 0;
    // Bucle para cada carácter de la cadena.
    for (auto x : str)
    {
        // Los condicionales verifican parentesis.
        if (x == '(' || x == '{' || x == '[')
            sc.push(x);
        else if (x == ')' && !sc.empty() && sc.top() == '(')
            sc.pop(), size += 2;
        else if (x == ']' && !sc.empty() && sc.top() == '[')
            sc.pop(), size += 2;
        else if (x == '}' && !sc.empty() && sc.top() == '{')
            sc.pop(), size += 2;
    }
    // En caso que se encuentre el símbolo.
    if (size == str.length())
        return true;
    // En caso que no se encuentre el símbolo.
    else
        return false;
}

void printParentheses(string s) {
  cout<<"s = "<<s<<endl; // Imprime string
  bool valido = validParentheses(s); // Resultado si es valido o no
  if (valido == true) {
    cout<<"True"<<endl; // Verdadero si es valido
  }
  else {
    cout<<"False"<<endl; // Falso si no es valido
  }
  cout<<endl;
}

int main() {
  // Palindromo
  cout<<"PALINDROMO"<<endl;
  int n1=10;
  int n2 = 121;
  // Caso de prueba uno
  cout<<"Caso 1: "<<endl;
  printPalindrome(n1);
  // Caso de prueba dos
  cout<<"Caso 2: "<<endl;
  printPalindrome(n2);

  // Entero inverso
  cout<<"ENTERO INVERSO"<<endl;
  int n3=112234; // Valor numerico
  cout<<"Número entero: "<<endl;
  cout<<n3<<endl; // Imprime número
  int revern=reverse(n3); // Número al reves
  cout<<"Número entero al reves: "<<endl;
  cout<<revern<<endl<<endl; // Imprime número

  // Unir dos listas ordenadas
  cout<<"UNIR DOS LISTAS ORDENADAS"<<endl;
  // Listas vacías
  Node* resultado = NULL;
  Node* l1 = NULL;
  Node* l2 = NULL;

  // Creamos la lista uno
  push(&l1, 15);
  push(&l1, 10);
  push(&l1, 5);
  cout<<"Lista ordenada uno"<<endl;
  printArray(l1);

  // Creamos la lista dos
  push(&l2, 20);
  push(&l2, 3);
  push(&l2, 2);
  cout<<"Lista ordenada dos"<<endl;
  printArray(l2);

  // Eliminar duplicados de la lista
  resultado = mergeSortedLists(l1, l2);

  // Imprime lista combinada y ordenada
  cout << "Lista unida:"<<endl;
  printArray(resultado);
  cout<< endl;

  // Validación de parentesis
  cout <<"VALIDACIÓN DE PARENTESIS"<<endl;
  string p1="(]"; // Variable string uno
  string p2 = "([])"; // Variable string dos
  printParentheses(p1); // Imprime resultado
  printParentheses(p2); // Imprime resultado

  return 0;
}
