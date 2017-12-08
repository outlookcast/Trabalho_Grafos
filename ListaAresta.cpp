/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#include "ListaAresta.h"
#include <stdlib.h>

ListaAresta::ListaAresta()
{

    primeiro=NULL;
    n=0;
    numeroTerminais = 0;

}
ListaAresta::~ListaAresta()
{

    while (primeiro!=NULL)
    {

        Aresta *p = primeiro->getProx();
        delete primeiro;

        primeiro=p;

    }
}
void ListaAresta::insereInicio(int sucessor, float pesso, bool terminal)
{

    Aresta *novaAresta = new Aresta;
    novaAresta->setSucessorPeso(sucessor, pesso);

    if(primeiro!=NULL)  //Lista não esta vazia
    {
        novaAresta->setProx(primeiro);
        primeiro=novaAresta;

    }
    else                //lista vazia
    {

        primeiro = novaAresta;
        primeiro->setProx(NULL);

    }
    n++;

    if(terminal == true)
        numeroTerminais +=1;

}

bool ListaAresta::busca(int sucessor)
{

    if(primeiro!=NULL)
    {
        for(Aresta *p=primeiro; p!=NULL; p=p->getProx())
        {

            if(p->getSucessor()== sucessor)
                return true;
        }

    }
    else
    {

        return false;

    }

    return false;



}

void ListaAresta::imprime()
{

    if(primeiro!=NULL)
    {

        for(Aresta *p=primeiro; p!=NULL; p=p->getProx())
            cout<<p->getSucessor()<<"|"<<p->getPeso()<<" ";

        cout<<endl;
    }
    else
    {

        cout<<" "<<endl; ///Lista vazia


    }

}

int ListaAresta::numElementos ()
{

    if(primeiro!=NULL)    //lista Ñ esta vazia
    {

        Aresta *p=primeiro;
        int n=0;

        while(p!=NULL)
        {

            n++;
            p=p->getProx();

        }

        return n;
    }
    else
    {

        return 0;

    }


}

int ListaAresta :: maiores (int x )
{

    if(primeiro!=NULL)
    {

        int n=0;

        for(Aresta *p=primeiro; p!=NULL; p=p->getProx())
        {

            if(p->getSucessor() > x)
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

bool ListaAresta::igual( ListaAresta *l2 )
{

    if(primeiro!=NULL && l2->primeiro != NULL)
    {

        if(this->numElementos()==l2->numElementos())
        {

            Aresta *p=primeiro;
            Aresta *p2=l2->primeiro;

            while(p!=NULL && p2!=NULL)
            {

                if(p->getSucessor()!=p2->getSucessor())
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

void ListaAresta::eliminaValor (int v, bool terminal)
{
    if(primeiro!=NULL)
    {
        Aresta *p=primeiro;
        Aresta *ant=NULL;

        while(p!=NULL)
        {

            if(p->getSucessor() == v)  //v é o primeiro sucessor
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
        n--;

        if(terminal == true)
            numeroTerminais -= 1;
    }
    else
    {

        cout<<"Erro, lista vazia\n";
        exit(5);

    }

}

int ListaAresta::getNumTerminais()
{

    return numeroTerminais;

}
int ListaAresta::getN()
{
    return n;
}

int ListaAresta::getProx()
{

    if(atual == NULL)
        return -1;

    else
    {

        int n = atual->getSucessor();
        atual = atual->getProx();

        if(atual == NULL)
          ativoProx = false;

        return n;

    }


}

void ListaAresta::setAtivoP(bool estado)
{
    if(estado == true)
    {
      atual = primeiro;
      ativoProx = true;

    }
    else
    {

        atual = NULL;
        ativoProx = false;

    }
}

bool ListaAresta::getEstado()
{
    return ativoProx;
}

Aresta * ListaAresta::getPrimeiro()
{
    return primeiro;
}
