#include "sumaT.h"
#include <iostream>

using namespace std;

int main(){
    cout<<"Suma Iterativa: costo O(n)"<<endl;

    cout<<sumaT::sumIterativa(100)<<endl; 
    cout<<sumaT::sumIterativa(200)<<endl;
    cout<<sumaT::sumIterativa(80)<<endl;
    cout<<sumaT::sumIterativa(150)<<endl;

    cout<<endl;

    cout<<"Suma Recursiva: costo O(n)"<<endl;

    cout<<sumaT::sumRecursiva(100)<<endl; 
    cout<<sumaT::sumRecursiva(200)<<endl;
    cout<<sumaT::sumRecursiva(80)<<endl;
    cout<<sumaT::sumRecursiva(150)<<endl;

    cout<<endl; 

    cout<<"Suma Recursiva: costo O(1)"<<endl;

    cout<<sumaT::sumDirecta(100)<<endl;
    cout<<sumaT::sumDirecta(200)<<endl;
    cout<<sumaT::sumDirecta(80)<<endl;
    cout<<sumaT::sumDirecta(150)<<endl;
}