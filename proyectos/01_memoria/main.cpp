#include <iostream>

int main(){

    int* x = new int;
    *x = 42;
    std::cout<<"Hola desde la memoria! El valor es: "<<*x<<std::endl;
    std::cout<<"La direccion de memoria es: "<<x<<std::endl;
    delete x;
    std::cout<<"Memoria Liberada correctamente"<<std::endl;
    return 0;

}