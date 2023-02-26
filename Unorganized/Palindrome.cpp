/*
Programa que verifica palindromo
Alumno: David Román Velasco A01639645
Hecho en colaboración de:
Paulina Lizet Gutiérrez Amezcua A01639948,
Juan Pablo García Malta A01639025
echa de creación: 9 de septiembre del 2021
*/

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
  if(x < 0){
      return false;
  }

  int divisor = 1;
  while(x/divisor >= 10){
      divisor *= 10;
  }

  while(x != 0){
      if (x / divisor != x % 10) {
          return false;
      }
      x %= divisor;
      x /= 10;
      divisor /= 100;
  }

  return true;
}

int main() {
  int x=10;
  cout<<x<<endl;
  bool Palindrome = isPalindrome(x);
  cout<<Palindrome<<endl;
  return 0;
}
