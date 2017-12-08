/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#include "PilhaEncad.h"

PilhaEncad::PilhaEncad()
{

    topo=NULL;
    n=0;

}

PilhaEncad::~PilhaEncad()
{

    if(topo!=NULL)
    {

        No *p=topo;
        while(p!=NULL)
        {

            p=p->getProx();
            delete topo;
            if(p!=NULL)
              topo = p;
        }

    }

}

int PilhaEncad::getTopo()
{

    if(!vazia())
    {

        return topo->getInfo();

    }
    else
    {

        cout<<"Erro pilha vazia\n";
        exit(1);

    }

}

void PilhaEncad::empilha(int val)
{

    No *p=new No;
    p->setInfo(val);
    p->setProx(topo);

    topo = p;
    ++n;


}

int PilhaEncad::desempilha()
{

    No *p = topo;
    if(!vazia())
    {

        int val = topo->getInfo();
        topo=topo->getProx();
        delete p;
        --n;
        return val;

    }
    else
    {

        cout<<"Erro pilha vazia.\n";
        exit(2);

    }


}

bool PilhaEncad::vazia()
{

    if(topo==NULL)
      return true;

    else
      return false;

}
int PilhaEncad::quantdadeNos()
{

    return n;
}

bool PilhaEncad::verificaElemento(int n)
{
    No *p = topo;

    while(p != NULL)
    {
        if(p->getInfo() == n)
          return true;

        p = p->getProx();
    }

    return false;
}

