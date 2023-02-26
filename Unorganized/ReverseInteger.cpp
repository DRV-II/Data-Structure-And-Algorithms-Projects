/*
Programa que devuelve el reverso de un número
Alumno: David Román Velasco A01639645
Hecho en colaboración de:
Paulina Lizet Gutiérrez Amezcua A01639948,
Juan Pablo García Malta A01639025
echa de creación: 9 de septiembre del 2021
*/

#include <iostream>
#include <climits>

using namespace std;

int reverse(int x) {
        long int ans=0;
        while(x != 0){
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if ( ans < INT_MIN ||  ans > INT_MAX) return 0;
        return ans;
    }


int main() {
  int n=112234;
  cout<<n<<endl;
  int nrev=reverse(n);
  cout<<nrev<<endl;

  return 0;
}
