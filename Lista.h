//
// Created by ivan on 5/4/26.
//

#ifndef PRACTICALISTAS_LISTA_H
#define PRACTICALISTAS_LISTA_H



#include <iostream>


struct Nodo {
    int valor ;
    Nodo* next;
    Nodo(int v): valor(v) , next(nullptr){}
};

class lista {
public:
    void addNodo(int valor);
    void imprimirLista();
    void eliminarDuplicados();
    bool esAscendente();
    void espejarLista();
    int  mitadLista();
    int enesimoDesdeFinal(int n );
    int eliminarValor( int n);
    int sumarNodos();
    bool contiene(int buscado);

private:
    Nodo* head = nullptr;
    void addNodoRec(Nodo*& nodo , int valor);
    void eliminarDuplicadosRec(Nodo* nodo);
    bool esAscendenteRec(Nodo* nodo);
    Nodo* espejarListaRec(Nodo* nodo);
    int mitadListaIt(Nodo* nodo);
    int enesimoDesdeFinalIt(Nodo* nodo,int n );
    int eliminarValorRec(Nodo* nodo , int n);
    int sumarNodosRec(Nodo* head);
    bool contieneRec(Nodo* nodo, int buscado);
};



#endif //PRACTICALISTAS_LISTA_H
