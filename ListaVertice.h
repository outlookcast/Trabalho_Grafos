/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#ifndef LISTAVERTICE_H_INCLUDED
#define LISTAVERTICE_H_INCLUDED
#include "Vertice.h"
#include <iostream>
#include <cstdlib>

using namespace std;
class ListaVertice
{

public:

    ListaVertice();
    ~ListaVertice();
    void insereInicio(int val, bool terminal);
    bool busca(int val);
    void imprime();
    int comprimento ();
    int maiores (int x );
    bool igual(ListaVertice *l2);
    void eliminaValor (int v);
    Vertice * retornaVertice(int v);
    Vertice * getPrimeiro();

private:

    Vertice* primeiro; // ponteiro para o primeiro
    int n;

};


#endif // LISTAENC_H_INCLUDED
