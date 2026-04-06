//
// Created by ivan on 5/4/26.
//

#include "Lista.h"
#include <iostream>

void lista::addNodo(int valor){
    addNodoRec(head, valor);
}

void lista::imprimirLista(){
    Nodo* actual = head;

    while(actual != nullptr){
        std::cout<<actual->valor<<"->";

        actual = actual->next;
    }

    std::cout << "NULL" << std::endl;
}

//-------------------metodos privados-------------------------------------------

void lista::addNodoRec(Nodo*& nodo, int valor){
    if(nodo == nullptr){
        nodo = new Nodo(valor);
    }
    else {
        addNodoRec(nodo->next, valor);
    }

}

int main()
{
    std::cout<<"Practica de listas"<<std::endl;

    lista l1;
    l1.addNodo(3);
    l1.addNodo(4);
    l1.addNodo(5);
    l1.imprimirLista();

    return 0;
}