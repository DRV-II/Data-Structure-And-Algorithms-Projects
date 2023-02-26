#ifndef SUMAT_H
#define SUMAT_H

#include <iostream>
using namespace std;

class sumaT {
    public:
        static int sumIterativa(int); //metodo de suma iterativa
        static int sumRecursiva(int); //metodo de suma recursiva
        static int sumDirecta(int); //metodo de suma directa
};

int sumaT::sumIterativa(int val){ //O(n)
    int resultado = 0;

    for(int i=1;i<=val;i++){
        resultado += i;
    }
    return resultado;
}

int sumaT::sumRecursiva(int val){ //O(n)
    if (val == 0)
        return 0;

    else
        return (val + sumRecursiva(val-1));
}

int sumaT::sumDirecta(int val){  //O(1)
    return ((val+1)*(val/2));
}

#endif
