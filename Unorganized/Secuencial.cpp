#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int get_array_size(int arr[]){
    return sizeof arr/sizeof arr[0];
}

void busqSecuencial(string a[]) { //
  int n = get_array_size(a);
  string prueba;
  int tamano;
  string temp;
  for (int j=0; j<n; j++) {
    prueba = a[j];
    tamano = prueba.length();
    int i=0;
    while (i!=tamano) {
      temp=prueba[i];
      i = i+1;
      if (temp != prueba[i]) {
        cout << temp << i<<endl;
      }
      else {
        cout << "No se pudo master"<<endl;
      }
    }
  }
}

int main(){
    int n;
    cin>>n;
    string cadena[n];
    string k;
    for (int j=0; j < n; j++) {
      cin>>k;
      cadena[j]=k;
    }
    busqSecuencial(cadena);
}
