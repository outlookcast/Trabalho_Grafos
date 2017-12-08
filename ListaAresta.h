/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#ifndef LISTAARESTA_H_INCLUDED
#define LISTAARESTA_H_INCLUDED
#include "Aresta.h"
#include <iostream>
#include <cstdlib>

using namespace std;
class ListaAresta
{

public:

    ListaAresta();
    ~ListaAresta();
    void insereInicio(int sucessor, float peso, bool terminal);
    bool busca(int sucessor);
    void imprime();
    int numElementos();
    int maiores (int x );
    bool igual(ListaAresta *l2);
    void eliminaValor (int v, bool terminal);
    int getN();
    int getProx();
    void setAtivoP(bool estado);
    bool getEstado();
    Aresta * getPrimeiro();
    int getNumTerminais();

private:

    Aresta* primeiro; // ponteiro para o primeiro
    int n;
    bool ativoProx;
    Aresta *atual;
    int numeroTerminais;
};


#endif // LISTAARESTA_H_INCLUDED
