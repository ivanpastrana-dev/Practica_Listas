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
    Nodo* eliminarDuplicadosRec();

private:
    Nodo* head = nullptr;
    void addNodoRec(Nodo*& nodo , int valor);
    Nodo* eliminarDuplicadosRec(Nodo* nodo);
    bool esAscendenteRec(Nodo* nodo);
};



#endif //PRACTICALISTAS_LISTA_H
