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
