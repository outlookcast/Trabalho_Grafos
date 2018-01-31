/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/


#include "Aresta.h"
#include <stdlib.h>


Aresta::Aresta() { }

Aresta::~Aresta() { }

int Aresta::getSucessor()
{

    return sucessor;

}

Aresta* Aresta::getProx()
{

    return prox;

}

void Aresta::setSucessorPeso(int sucessor, float peso)
{

    this->sucessor = sucessor;
    this->peso = peso;

}

void Aresta::setProx(Aresta *p)
{

    prox = p;

}

float Aresta::getPeso()
{

    return peso;

}
//teste