#include <iostream>

using namespace std;
/*
bool isPalindrome(int n) {
    if(n < 0 || (n % 10 == 0 && n != 0)) {
        return false;
    }
    int reverse = 0;
    while(n > reverse) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return n == reverse || n == reverse/10;
}*/


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
