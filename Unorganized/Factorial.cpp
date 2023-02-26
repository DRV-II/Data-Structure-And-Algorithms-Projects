#include <iostream>

using namespace std;

int Factorial(int x) {
  if (x == 0) return 1;

  return Factorial(x-1) * x;
}

int main() {
  cout<<"Factorial of 5: " << Factorial(5)<<endl;
  return 0;
}
