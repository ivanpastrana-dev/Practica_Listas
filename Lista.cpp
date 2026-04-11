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

void lista::espejarLista() {
    Nodo* cabeza = espejarListaRec(head);
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        std::cout<<actual->valor<<"->";
        actual = actual->next;
    }
    std::cout<<"NULL"<<std::endl;
}

int  lista::mitadLista() {
    return mitadListaIt(head);
}

int lista::enesimoDesdeFinal(int n ) {
    return enesimoDesdeFinalIt(head, n);
}

int lista::eliminarValor( int n) {
    return eliminarValorRec(head, n);
}

int lista::sumarNodos() {
    return sumarNodosRec(head);
}

bool lista::contiene(int buscado) {
    return contieneRec(head,buscado);
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

Nodo* lista::espejarListaRec(Nodo* actual) {
    if (actual == nullptr || actual->next == nullptr) return actual;

    Nodo* nuevaCabeza = espejarListaRec(actual->next);

    actual->next->next = actual;
    actual->next = nullptr;

    return nuevaCabeza;
}

int lista::mitadListaIt(Nodo* nodo) {
    Nodo* slow = nodo;
    Nodo* fast = nodo;

    while (fast != nullptr && fast->next != nullptr) {
         slow = slow->next;
         fast = fast->next->next;
    }
    return slow->valor;
}

int lista::enesimoDesdeFinalIt(Nodo* nodo,int n) {
    Nodo* primero = nodo;
    Nodo* segundo = nodo;

    for (int i = 0; i < n ; i++) {
        primero = primero->next;
    }

    while (primero != nullptr) {
        primero = primero->next;
        segundo = segundo->next;
    }

    return segundo->valor;
}

int lista::eliminarValorRec(Nodo* nodo , int n) {
    if (nodo == nullptr) return -1;
    if (nodo->next == nullptr) return -1;

    if (nodo->next->valor == n) {
        int nro = nodo->next->valor;
        Nodo* temp = nodo->next;
        nodo->next = temp->next;
        delete temp;
        return nro;
    }

    return eliminarValorRec(nodo->next,n);
}

int lista::sumarNodosRec(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return 1+sumarNodosRec(nodo->next);
}

bool lista::contieneRec(Nodo* nodo , int buscado) {
    if (nodo == nullptr) return false;
    if (nodo->valor == buscado) return true;

    return contieneRec(nodo->next,buscado);
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

    std::cout<<"Lista espejada"<<std::endl;
    l3.espejarLista();

    std::cout<<std::endl;
    std::cout<<"Encontrar mitad de la lista"<<std::endl;
    lista l4;
    l4.addNodo(2);
    l4.addNodo(4);
    l4.addNodo(5);
    l4.addNodo(7);
    l4.addNodo(9);

    std::cout<<"La mitad de la lista el: "<<l4.mitadLista()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"Encontrar el enesimo nodo desde el final"<<std::endl;
    lista l5;
    l5.addNodo(2);
    l5.addNodo(4);
    l5.addNodo(5);
    l5.addNodo(7);
    l5.addNodo(9);

    std::cout<<"El enesimo desde el final es el: "<<l5.enesimoDesdeFinal(2)<<std::endl;

    std::cout<<"El valor eliminado es: "<<l5.eliminarValor(9)<<std::endl;
    l5.imprimirLista();
    std::cout<<"La lista tiene: "<<l5.sumarNodos()<<" nodos"<<std::endl;
    l5.contiene(7)? std::cout<<"Si contiene 7, anda bien" : std::cout<<"Si contiene 7, anda mal";
    std::cout<<std::endl;
    l5.contiene(10)? std::cout<<"No contiene 10, anda mal" : std::cout<<"No contiene 10, anda bien";
    std::cout<<std::endl;

    return 0;
}