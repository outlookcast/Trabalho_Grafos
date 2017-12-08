/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED

#include "ListaAresta.h"

class Vertice
{

public:

    Vertice(bool t);
    ~Vertice();
    int getVertice();
    Vertice* getProx();
    void setVertice(int v);
    void setProx(Vertice *p);
    ListaAresta * getListaAresta();
    void setTerminal(bool t);
    bool getTerminal();


private:

    int vertice; // informacao
    Vertice *prox; // ponteiro para o proximo
    ListaAresta * listaA;
    bool terminal;

};


#endif // NO_H_INCLUDED
