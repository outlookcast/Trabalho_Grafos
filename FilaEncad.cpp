/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#include"FilaEncad.h"

FilaEncad::FilaEncad()
{
    c=NULL;
    f=NULL;
    n=0;

}

FilaEncad::~FilaEncad()
{

    No *p=c;
    while(p!=NULL)
    {

        if(p->getProx()!=NULL)
        {
            p=p->getProx();
        }
        else
          p=NULL;
        delete c;
        c = p;
    }

}

int FilaEncad::getInicio() // retorna No do inicio
{

    if(!vazia())
    {
        return c->getInfo();
    }
    else
    {
        cout<<"Lista vazia\n";
        exit(1);
    }

}

void FilaEncad::enfileira(int val) // insere No no fim
{
    No *novoNo = new No;
    novoNo ->setInfo(val);

    if(!vazia())
    {

        f->setProx(novoNo);
        f=novoNo;
        f->setProx(NULL);

    }
    else
    {
        c=novoNo;
        f=novoNo;
    }


    ++n;

}

int FilaEncad::desenfileira() // elimina No do inicio
{

    if(!vazia())
    {

        No *p=c;
        if(c==f)
        {
            int a = c->getInfo();
            delete c;
            c=f=NULL;
            return a;
        }
        c=c->getProx();
        int a = p->getInfo();
        delete p;
        p=NULL;
        --n;
        return a;

    }
    else
    {
        cout<<"Erro, fila vazia\n";
        exit(2);
    }

}

bool FilaEncad::vazia() // verifica se esta vazia
{

    if(c==NULL)
        return true;

    else
        return false;

}

int FilaEncad::numeroNos()
{

    return n;

}
