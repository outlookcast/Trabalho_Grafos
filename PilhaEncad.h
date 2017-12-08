/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#ifndef PILHAENCAD_H_INCLUDED
#define PILHAENCAD_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include "No.h"
using namespace std;

class PilhaEncad

{

public:

    PilhaEncad();
    ~PilhaEncad();
    int getTopo();
    void empilha(int val);
    int desempilha();
    bool vazia();
    int quantdadeNos();
    bool verificaElemento(int n);

private:

    No * topo;
    int n;

};


#endif // PILHAENCAD_H_INCLUDED
