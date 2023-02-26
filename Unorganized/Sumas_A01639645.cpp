#include <iostream>
using namespace std;

// Alumno: David Román Velasco
// Matrícula: A01639645

int sumaIterativa(int n){ // Suma iterativa
    int resultado = 0;
    cout<<"Suma iterativa de: "<<n<<endl;
    for(int i=1;i<=n;i++){
        resultado += i; // Operación basica, cuesta uno
        // La operación se repite "n" veces ya que la sumatoria de unos de i=1 hasta "n" es igual a "n"
        // Por lo que pertenece a O(n)
    }
    return resultado;
}

int sumaRecursiva(int n){ // Suma recursiva
    if (n == 0) {
        return 0;
    }
    else {
        //cout<<n<<endl;
        return (n + sumaRecursiva(n-1)); // Operación basica, cuesta uno
        // La operación se repite "n" veces, por lo que pertenece a O(n)
        // Para demostrarlo puede descomentar la linea antes de la operación
    }
}

int sumaDirecta(int n){  // Suma directa
    cout<<"Suma directa de: "<<n<<endl;
    return ((n*(n+1))/2); // Operación basica, cuesta uno
    // Solo es ejecutada una vez ya que es una formula directa, por lo que su complejidad pertenece a O(1)
}

int main(){
    cout<<"Suma Iterativa: su costo es O(n)"<<endl;

    cout<<sumaIterativa(100)<<endl;
    cout<<sumaIterativa(50)<<endl;
    cout<<sumaIterativa(10)<<endl;
    cout<<sumaIterativa(5)<<endl;

    cout<<endl;

    cout<<"Suma Recursiva: su costo es O(n)"<<endl;

    cout<<"Suma recursiva de: 100"<<endl;
    cout<<sumaRecursiva(100)<<endl;
    cout<<"Suma recursiva de: 50"<<endl;
    cout<<sumaRecursiva(50)<<endl;
    cout<<"Suma recursiva de: 10"<<endl;
    cout<<sumaRecursiva(10)<<endl;
    cout<<"Suma recursiva de: 5"<<endl;
    cout<<sumaRecursiva(5)<<endl;

    cout<<endl;

    cout<<"Suma Recursiva: su costo es O(1)"<<endl;

    cout<<sumaDirecta(100)<<endl;
    cout<<sumaDirecta(50)<<endl;
    cout<<sumaDirecta(10)<<endl;
    cout<<sumaDirecta(5)<<endl;
}
