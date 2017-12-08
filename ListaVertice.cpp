/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#include "ListaVertice.h"
#include <stdlib.h>

ListaVertice::ListaVertice()
{

    primeiro=NULL;
    n=0;


}
ListaVertice::~ListaVertice()
{

    while (primeiro!=NULL)
    {

        Vertice *p = primeiro->getProx();
        delete primeiro;

        primeiro=p;

    }
}
void ListaVertice::insereInicio(int v, bool terminal)
{

    Vertice *novoVertice = new Vertice(terminal);
    novoVertice->setVertice(v);

    if(primeiro!=NULL)  //Lista não esta vazia
    {
        novoVertice->setProx(primeiro);
        primeiro=novoVertice;

    }
    else                //lista vazia
    {

        primeiro = novoVertice;
        primeiro->setProx(NULL);

    }

    n++;


}

bool ListaVertice::busca(int val)
{

    if(primeiro!=NULL)
    {
        for(Vertice *p=primeiro; p!=NULL; p=p->getProx())
        {

            if(p->getVertice()== val)
                return true;
        }

    }
    else
    {

        return false;

    }

    return false;



}

void ListaVertice::imprime()
{

    if(primeiro!=NULL)
    {

        for(Vertice *p=primeiro; p!=NULL; p=p->getProx())
            cout<<p->getVertice()<<" ";

        cout<<endl;
    }
    else
    {

        cout<<"Erro, lista vazia\n";
        exit(2);


    }

}

int ListaVertice::comprimento ()
{

    if(primeiro!=NULL)    //lista Ñ esta vazia
    {

        return n;
    }
    else
    {

        return 0;

    }


}

int ListaVertice :: maiores (int x )
{

    if(primeiro!=NULL)
    {

        int n=0;

        for(Vertice *p=primeiro; p!=NULL; p=p->getProx())
        {

            if(p->getVertice() > x)
                ++n;

        }

        return n;


    }
    else
    {

        cout<<"Erro, lista vazia\n";
        exit(4);

    }


}

bool ListaVertice::igual( ListaVertice *l2 )
{

    if(primeiro!=NULL && l2->primeiro != NULL)
    {

        if(this->comprimento()==l2->comprimento())
        {

            Vertice *p=primeiro;
            Vertice *p2=l2->primeiro;

            while(p!=NULL && p2!=NULL)
            {

                if(p->getVertice()!=p2->getVertice())
                    return false;

                p=p->getProx();
                p2=p2->getProx() ;

            }

            return true;


        }
        else
            return false;


    }
    else
        return false;


}

void ListaVertice::eliminaValor (int v)
{

    if(primeiro!=NULL)
    {
        Vertice *p=primeiro;
        Vertice *ant=NULL;

        while(p!=NULL)
        {

            if(p->getVertice()==v)
            {
                if(ant==NULL)
                {
                    primeiro = p->getProx();
                    delete p;
                    p = NULL;
                    break;
                }


                else
                {

                    ant->setProx(p->getProx());
                    delete p;
                    p = NULL;
                    break;

                }

            }


            ant=p;
            p=p->getProx();

        }

    }
    else
    {

        cout<<"Erro, lista vazia\n";
        exit(5);

    }

    n--;

}

Vertice * ListaVertice::retornaVertice(int v)
{
    Vertice * a = primeiro;
    while(a!=NULL)
    {
        if(a->getVertice()==v)
            return a;
        a = a->getProx();
    }
    cout<<"Vertice não encontrado!!"<<endl;
    exit(1);
}

Vertice * ListaVertice::getPrimeiro()
{
    return primeiro;
}
