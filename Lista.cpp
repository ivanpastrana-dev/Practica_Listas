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

void lista::eliminarDuplicados() {
    return eliminarDuplicadosRec(head);
}

bool lista::esAscendente() {
    return esAscendenteRec(head);
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


void lista::eliminarDuplicadosRec(Nodo* nodo) {
    if (nodo == nullptr) return ;
    if (nodo->next == nullptr) return ;

    if (nodo->valor == nodo->next->valor) {
        Nodo* temp = nodo->next;
        nodo->next = temp->next;
        delete temp;
        eliminarDuplicadosRec(nodo);
    }
    else {
        eliminarDuplicadosRec(nodo->next);
    }

}
bool lista::esAscendenteRec(Nodo* nodo) {
    if (nodo == nullptr) return true;
    if (nodo->next == nullptr ) return true;

    if (nodo->valor > nodo->next->valor) return false;
    return esAscendenteRec(nodo->next);
}

int main()
{
    std::cout<<"Practica de listas"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Prueba de listas con elementos duplicados"<<std::endl;
    std::cout<<"Lista con duplicados"<<std::endl;
    lista l1;
    l1.addNodo(2);
    l1.addNodo(2);
    l1.addNodo(4);
    l1.addNodo(4);
    l1.addNodo(4);
    l1.addNodo(5);
    l1.addNodo(5);
    l1.addNodo(5);
    l1.imprimirLista();
    std::cout<<std::endl;

    std::cout<<"lista con numeros duplicados eliminados"<<std::endl;
    l1.eliminarDuplicados();
    l1.imprimirLista();
    std::cout<<std::endl;

    std::cout<<"Prueba de listas ascendentes"<<std::endl;
    std::cout<<"Listas que no es ascendente"<<std::endl;

    lista l2;
    l2.addNodo(3);
    l2.addNodo(4);
    l2.addNodo(2);
    l2.addNodo(5);

    l2.esAscendente()? std::cout<<"Test fallado":std::cout<<"Test pasado";
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Listas que si es ascendente"<<std::endl;

    lista l3;
    l3.addNodo(2);
    l3.addNodo(4);
    l3.addNodo(5);
    l3.addNodo(7);

    l3.esAscendente()? std::cout<<"Test pasado" : std::cout<<"Test fallado";
    std::cout<<std::endl;

    return 0;
}