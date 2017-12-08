/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#include "Vertice.h"
#include <stdlib.h>

Vertice::Vertice(bool t)
{
    listaA = new ListaAresta();
    terminal = t;
}

Vertice::~Vertice()
{
    delete listaA;
}

int Vertice::getVertice()
{

    return vertice;


}

Vertice* Vertice::getProx()
{

    return prox;

}

void Vertice::setVertice(int v)
{

    vertice = v;

}

void Vertice::setProx(Vertice *p)
{

    prox = p;

}

ListaAresta * Vertice::getListaAresta()
{
    return listaA;
}

void Vertice::setTerminal(bool t)
{
    terminal = t;
}

bool Vertice::getTerminal()
{
    return terminal;
}

