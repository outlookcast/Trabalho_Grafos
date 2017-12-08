/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#ifndef FILAENCAD_H_INCLUDED
#define FILAENCAD_H_INCLUDED
#include<iostream>
#include<cstdlib>
#include"No.h"

using namespace std;

class FilaEncad

{

private:

    No *c; // ponteiro para No do comeco
    No *f; // ponteiro para No do fim
    int n;

public:

    FilaEncad();
    ~FilaEncad();
    int getInicio(); // retorna No do inicio
    void enfileira(int val); // insere No no fim
    int desenfileira(); // elimina No do inicio
    bool vazia(); // verifica se esta vazia
    int numeroNos();   //retorna o numero de nos da fila
    bool verificaElemento(int n)
    {
        No *p = c;

        while(p != NULL)
        {

            if(p->getInfo() == n)
            {

                return true;

            }

            p = p->getProx();
        }



        return false;
    }

};


#endif // FILAENCAD_H_INCLUDED
