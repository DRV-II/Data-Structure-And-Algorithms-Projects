#include <iostream>
#include <vector>

using namespace std;

//Imprime cada linea del vector.
void printVector(vector<int> a)
{
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  int n = -1;
  cout<<n<<endl;
  vector<int> soda1;
  soda1.push_back(1);
  soda1.push_back(2);
  soda1.push_back(3);
  soda1.push_back(4);
  vector<int> soda2 = soda1;
  soda2.push_back(5);
  soda2.push_back(6);
  printVector(soda1);
  printVector(soda2);
  return 0;
}
