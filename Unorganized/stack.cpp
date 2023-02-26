#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

template <class T> class stack {
public:
  stack() {
    this -> n = 0;
    this -> lista[] = {};
    this -> cont = 0;
  }
  stack(int num) {
    this -> n = num;
    this -> lista[n] = {};
    this -> cont = 0;
  }
  void push(T) {
    this -> top = dato;
    this -> lista[cont] = dato;
    this -> cont++;
  }
  T pop() {
    T temp;
    temp = this -> top;
    delete this -> lista[cont];
    if (this -> cont != 0) {
      this -> cont--;
    }
    return temp;
  }
  int emptyStack() {
    if (this -> cont == 0) {
      return true;
    }
    else {
      return false;
    }
  }
private:
  T lista[];
  int n;
  T top;
  int cont;
};


int main () {
  stack<int> prueba(10);
  cout<<prueba.emptyStack();
  return 0;
}
