/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#include "Grafo.h"
#include <list>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Grafo::Grafo(bool dig) ///ATUALIZADO DIGRAFO
{
    ordem = 0;
    numArestas = 0;
    digrafo = dig;
    multigrafo = false;
    numTerminais = 0;
    pesoAGM = 0;

}

int Grafo::getOrdem() ///ATUALIZADO DIGRAFO
{
    return ordem;
}

void Grafo::insereVertice(int No) ///ATUALIZADO DIGRAFO
{
    if(listaV.busca(No))
    {
        cout<<"O vertice "<<No<<" ja esta adicionado!"<<endl;
    }
    else
    {
        listaV.insereInicio(No, false); ///Insere o vértice
        ordem++;
    }
}

void Grafo::insere(int No1, int No2, float dist) ///ATUALIZADO DIGRAFO
{
    if(digrafo==false)
    {


        if(No1==No2) ///Self-loop, como estamos em um ambiente de grafo simples, então não inserimos!
        {
            cout<<"Operação inválida!! Self-loop."<<"No1: "<<No1<<"No2: "<<No2<<"Dist: "<<dist<<endl;
        }
        else
        {
            if(listaV.busca(No1)==false||listaV.busca(No2)==false) ///Se um dos dois nós não foi inserido, nós inserimos
            {
                if(listaV.busca(No1)==false)
                {
                    listaV.insereInicio(No1, false);
                    ordem++;
                }
                if(listaV.busca(No2)==false)
                {
                    listaV.insereInicio(No2, false);
                    ordem++;
                }
                Vertice * a = listaV.retornaVertice(No1); ///Pegamos o vertice 1
                Vertice * b = listaV.retornaVertice(No2); ///Pegamos o vertice 2
                ListaAresta * aa = a->getListaAresta(); ///Pegamos a lista de arestas do vertice 1
                ListaAresta * bb = b->getListaAresta(); ///Pegamos a lista de arestas do vertice 2
                aa->insereInicio(No2,dist, false); ///E em seguida adicionamos em ambas
                bb->insereInicio(No1,dist, false);
                numArestas += 1;

            }
            else if(listaV.busca(No1)&&listaV.busca(No2)) ///Se os dois vertices já estiverem no grafo, então só adicionamos suas arestas, mas verificamos se tera aresta paralela!!
            {


                Vertice * a = listaV.retornaVertice(No1);
                Vertice * b = listaV.retornaVertice(No2);
                ListaAresta * aa = a->getListaAresta();
                ListaAresta * bb = b->getListaAresta();
                if(aa->busca(No2)==false&&bb->busca(No1)==false) ///Se os nós nao tiverem sidos adicionados ainda, ou seja, para não adicionar uma aresta paralela :)
                {
                    aa->insereInicio(No2,dist, b->getTerminal());
                    bb->insereInicio(No1,dist, a->getTerminal());
                    numArestas +=1;
                }
                else
                {
                    cout<<"Ja possui uma aresta entre "<<No1<<" e "<<No2<<" portando nao adicionamos!"<<endl;
                }

            }
        }
    }
    else /// Se for dígrafo
    {
        if(No1==No2) ///Self-loop, como estamos em um ambiente de grafo simples, então não inserimos!
        {
            cout<<"Operação inválida!! Self-loop."<<"No1: "<<No1<<"No2: "<<No2<<"Dist: "<<dist<<endl;
        }
        else
        {
            if(listaV.busca(No1)==false||listaV.busca(No2)==false) ///Se um dos dois nós não foi inserido, nós inserimos
            {
                if(listaV.busca(No1)==false)
                {
                    listaV.insereInicio(No1, false);
                    ordem++;
                }
                if(listaV.busca(No2)==false)
                {
                    listaV.insereInicio(No2, false);
                    ordem++;
                }
                Vertice * a = listaV.retornaVertice(No1); ///Pegamos o vertice 1
                ListaAresta * aa = a->getListaAresta(); ///Pegamos a lista de arestas do vertice 1
                aa->insereInicio(No2,dist, false); ///E em seguida adicionamos
                numArestas += 1;

            }
            else if(listaV.busca(No1)&&listaV.busca(No2)) ///Se os dois vertices já estiverem no grafo, então só adicionamos suas arestas, mas verificamos se tera aresta paralela!!
            {
                Vertice * a = listaV.retornaVertice(No1);

                ListaAresta * aa = a->getListaAresta();
                if(aa->busca(No2)==false) ///Se os nós nao tiverem sidos adicionados ainda, ou seja, para não adicionar uma aresta paralela :)
                {
                    aa->insereInicio(No2,dist, false);
                    numArestas +=1;
                }
                else
                {
                    cout<<"Ja possui uma arco entre "<<No1<<" e "<<No2<<" portando nao adicionamos!"<<endl; ///Arco paralelo (multigrafo)
                }
            }
        }
    }
}
void Grafo::imprimeGrafo() ///ATUALIZADO DIGRAFO
{
    Vertice * a = listaV.getPrimeiro();
    while(a!=NULL)
    {
        cout<<a->getVertice()<<" ";
        ListaAresta * aa = a->getListaAresta();
        aa->imprime();
        a=a->getProx();
    }
}


int Grafo::getGrau() ///ATUALIZADO DIGRAFO
///Percorremos vertice e depois pegamos o comprimento da sua lista de adjacencia, e no final retornamos a de maior valor
{
    if(listaV.comprimento()==0)
    {
        cout<<"Grafo vazio!"<<endl;
        return 0;
    }
    else
    {
        int maior=0;
        Vertice * a = listaV.getPrimeiro();
        while(a!=NULL)
        {
            ListaAresta * aa = a->getListaAresta();
            if(aa->getN()>maior)
                maior = aa->getN();
            a = a->getProx();
        }
        return maior;
    }

}

void Grafo::getGrauDeUmVertice(int No) ///ATUALIZADO DIGRAFO
{
    if(digrafo==false)
    {
        if(listaV.busca(No)==false)
        {
            cout<<"Esse vertice nao pertence ao grafo"<<endl;
        }
        else
        {
            Vertice * v = listaV.retornaVertice(No);
            ListaAresta * la = v->getListaAresta();
            cout<<"Grau: "<<la->numElementos()<<endl;
        }
    }
    else
    {
        if(listaV.busca(No)==false)
        {
            cout<<"Esse vertice nao pertence ao grafo"<<endl;
        }
        else
        {
            Vertice * v = listaV.retornaVertice(No);
            ListaAresta * la = v->getListaAresta();
            cout<<"Grau de saida: "<<la->numElementos()<<endl;
            int cont=0;
            Vertice * primeiro = listaV.getPrimeiro();
            while(primeiro!=NULL)
            {
                ListaAresta * la = primeiro->getListaAresta();
                Aresta * a = la->getPrimeiro();
                while(a!=NULL&&primeiro->getVertice()!=No)
                {
                    if(a->getSucessor()==No)
                        cont++;
                    a = a->getProx();
                }
                primeiro = primeiro->getProx();
            }
            cout<<"Grau de entrada: "<<cont<<endl;
        }
    }
}

void Grafo::excluiAresta(int No1, int No2) ///ATUALIZADO DIGRAFO
{
    if(digrafo==false)
    {
        if(listaV.busca(No1)==false||listaV.busca(No2)==false)
        {
            cout<<"Um dos nós (ou os dois) não existem, portanto não podem ser removidos."<<endl;
        }
        else
        {
            Vertice * a = listaV.retornaVertice(No1);
            Vertice * b = listaV.retornaVertice(No2);
            ListaAresta * aa = a->getListaAresta();
            ListaAresta * bb = b->getListaAresta();

            if(aa->busca(No2)==true&&bb->busca(No1)==true) ///Verifica se os nós estão na lista de adjacencia um do outro
            {
                aa->eliminaValor(No2, b->getTerminal());
                bb->eliminaValor(No1, a->getTerminal());
                numArestas -= 1;
            }
            else
            {
                cout<<"Não existe aresta entre os dois vértices"<<endl;
            }
        }
    }
    else
    {
        if(listaV.busca(No1)==false||listaV.busca(No2)==false)
        {
            cout<<"Um dos nós (ou os dois) não existem, portanto não podem ser removidos."<<endl;
        }
        else
        {
            Vertice * a = listaV.retornaVertice(No1);
            Vertice * b = listaV.retornaVertice(No2);
            ListaAresta * aa = a->getListaAresta();

            if(aa->busca(No2)==true) ///Verifica se os nós estão na lista de adjacencia um do outro
            {
                aa->eliminaValor(No2, b->getTerminal());
                numArestas -= 1;
            }
            else
            {
                cout<<"Não existe arco entre os dois vértices"<<endl;
            }
        }
    }
}

void Grafo::removeVertice(int No) ///ATUALIZADO DIGRAFO
{
    if(listaV.busca(No))
    {
        listaV.eliminaValor(No);
        Vertice * a = listaV.getPrimeiro();
        ListaAresta * aa;
        while(a!=NULL)
        {
            aa = a->getListaAresta();
            if(aa->busca(No))
            {
                aa->eliminaValor(No, a->getTerminal());
                numArestas -= 1;
            }
            a = a->getProx();
        }
        ordem--;
    }
    else
        cout<<"Esse Vertice não pertence ao grafo!"<<endl;
}

bool Grafo::verificaVetMinimo(int *vetMinimo, int tam)
{

    for(int i=0; i < tam; ++i)
    {

        if(vetMinimo[i] == 0)
            return true;

    }

    return false;
}

bool Grafo::verificaKRegularidade(int k) ///ATUALIZADO DIGRAFO
{
    Vertice * a = listaV.getPrimeiro();
    ListaAresta * aa;
    bool continua=true;
    if(k==0&&a==NULL)
        return true;
    if(k!=0&&a==NULL)
        return false;
    else
    {
        while(a!=NULL&&continua==true)
        {
            aa=a->getListaAresta();
            if(aa->getN()==k)
                continua = true;
            else
                return false;
            a = a->getProx();
        }
        return true;
    }
}

bool Grafo::verificaTrivial() ///ATUALIZADO DIGRAFO
{
    if(ordem==1)
        return true;
    else
        return false;
}

bool Grafo::verificaGrafoCompleto() ///ATUALIZADO DIGRAFO
{
    ListaAresta * aa;
    int num,cont=0;
    if(ordem==0)
        return true;
    else
    {
        Vertice * a = listaV.getPrimeiro();
        while(a!=NULL)
        {
            aa= a->getListaAresta();
            if(cont==0)
            {
                num = aa->getN();
                if(num!=ordem-1)
                    return false;
            }
            else
            {
                if(aa->getN()!=num)
                    return false;
            }
            a=a->getProx();
        }
        return true;
    }
}

Grafo * Grafo::retornaComplementar()
{
    Grafo * a = new Grafo(digrafo);
    if(verificaGrafoNulo())
        return a;
    else
    {
        int * vet = new int[listaV.comprimento()]; ///Cria um vetor para colocas os vertices
        Vertice * tst = listaV.getPrimeiro();
        for(int i=0; i<listaV.comprimento(); i++)
        {
            vet[i] = tst->getVertice();
            tst = tst->getProx();
        }
        Vertice * v = listaV.getPrimeiro();
        while(v!=NULL)
        {
            ListaAresta * la = v->getListaAresta();
            for(int i=0; i<listaV.comprimento(); i++)
            {
                if(la->busca(vet[i])==false&&a->verificaAresta(vet[i],v->getVertice())==false&&vet[i]!=v->getVertice())
                    a->insere(vet[i],v->getVertice(),1);
            }
            v = v->getProx();
        }
        delete [] vet;
        return a;
    }
}

Grafo * Grafo::copiaGrafo() ///ATUALIZADO DIGRAFO
{
    ListaVertice *listaVert = &listaV;
    Vertice *vert1 = listaVert->getPrimeiro();

    Grafo *copiaG = new Grafo(digrafo);


    while(vert1 != NULL)
    {

        if(!copiaG->listaV.busca(vert1->getVertice()))
            copiaG->insereVertice(vert1->getVertice());

        ListaAresta *Lista1 = vert1->getListaAresta();
        Aresta *aresta1 = Lista1->getPrimeiro();

        while(aresta1 != NULL)
        {

            if(copiaG->verificaAresta(vert1->getVertice(),aresta1->getSucessor())==false)
                copiaG->insere(vert1->getVertice(), aresta1->getSucessor(), aresta1->getPeso());

            aresta1 = aresta1->getProx();

        }


        vert1 = vert1->getProx();

    }

    return copiaG;


}

bool Grafo::verificaAresta(int No1, int No2) ///ATUALIZADO DIGRAFO
{
    if(digrafo==false)
    {

        if(listaV.busca(No1)&&listaV.busca(No2)==false)
        {
            return false;
        }
        else
        {
            Vertice * v = listaV.getPrimeiro();
            while(v!=NULL)
            {
                ListaAresta * la = v->getListaAresta();
                Aresta * a = la->getPrimeiro();
                if(v->getVertice()==No1)
                {
                    while(a!=NULL)
                    {
                        if(a->getSucessor()==No2)
                            return true;
                        a = a->getProx();
                    }
                }
                if(v->getVertice()==No2)
                {
                    while(a!=NULL)
                    {
                        if(a->getSucessor()==No1)
                            return true;
                        a = a->getProx();
                    }
                }
                v = v->getProx();
            }
            return false;
        }

    }

    else
    {

        if(listaV.busca(No1)&&listaV.busca(No2)==false)
        {
            return false;
        }
        else
        {
            Vertice * v = listaV.getPrimeiro();
            while(v!=NULL)
            {
                ListaAresta * la = v->getListaAresta();
                Aresta * a = la->getPrimeiro();
                if(v->getVertice()==No1)
                {
                    while(a!=NULL)
                    {
                        if(a->getSucessor()==No2)
                            return true;
                        a = a->getProx();
                    }
                }
                v = v->getProx();
            }
            return false;
        }



    }
}

void Grafo::salvar(char * nomeDoArquivo)
{
    Grafo * b = copiaGrafo();
    FILE * arquivo = fopen(nomeDoArquivo,"w+");
    Vertice * v = b->listaV.getPrimeiro();
    fprintf(arquivo,"%d\n",b->getOrdem());
    while(v!=NULL)
    {
        ListaAresta * la = v->getListaAresta();
        Aresta * a = la->getPrimeiro();
        while(a!=NULL)
        {
            fprintf(arquivo,"%d %d %.0f\n",v->getVertice(),a->getSucessor(),a->getPeso());
            Aresta * aux = a->getProx();
            b->excluiAresta(v->getVertice(),a->getSucessor());
            a = aux;
        }
        v = v->getProx();
    }
    fclose(arquivo);
}

bool Grafo::verificaGrafoNulo() ///Verifica se a ordem é 0
{
    if (listaV.getPrimeiro() == NULL)
        return true;
    else
        return false;
}
void Grafo::vizinhancaAberta(int no) ///A vizinhança aberta de um nó é ele mesmo e seus adjacentes
{
    Vertice * a = listaV.getPrimeiro();
    while (a != NULL)
    {
        if (a->getVertice()==no)
        {
            cout<<no<<" ";
            for(Aresta *p=a->getListaAresta()->getPrimeiro(); p!=NULL; p=p->getProx())
                cout<<p->getSucessor()<<" ";
            break;
        }
        a=a->getProx();
    }
    if(a==NULL)
    {
        cout<<"Vertice "<< no <<" nao existe no grafo"<<endl;
    }
}
void Grafo::vizinhancaFechada(int no) ///A vizinhança fechada de um nó é ele mesmo se ele estiver no grafo
{
    Vertice * a = listaV.getPrimeiro();
    while(a != NULL)
    {
        if(a->getVertice()==no)
        {
            cout<<no<<endl;
            break;
        }
        a=a->getProx();
    }
    if (a == NULL)
    {
        cout<<"Vertice "<< no <<" nao existe no grafo"<<endl;
    }
}

void Grafo :: raioDiametroCentroPeriferia()
{
    if(verificaGrafoNulo() != 1)
    {
        float diametro, raio;
        MatrizLin *matriz = floyd();
        Vertice *v = listaV.getPrimeiro();
        int *vet = new int[listaV.comprimento()];
        float exentricidade = matriz->get(1,2);
        for (int i=0; i<listaV.comprimento(); i++)
        {
            vet[i]=v->getVertice();
            v=v->getProx();
        }
        for(int i=0; i<listaV.comprimento(); i++)
        {
            exentricidade = matriz->get(i,0);
            for(int j=0; j<listaV.comprimento(); j++)
            {
                if(matriz->get(i,j)!=0 && matriz->get(i,j)!=HUGE_VAL && matriz->get(i,j)>exentricidade)
                {
                    exentricidade = matriz->get(i,j);
                }
            }
            if(i==0)
            {
                raio = exentricidade;
                diametro = exentricidade;
            }
            if(exentricidade < raio)
            {
                raio = exentricidade;
            }
            if(exentricidade > diametro)
            {
                diametro = exentricidade;
            }
        }
        cout<<endl<<"Raio: "<<raio<< endl;
        cout<<"Diametro: "<<diametro<<endl;
        cout<<"Centro: ";
        for(int i=0; i<listaV.comprimento(); i++)
        {
            exentricidade=matriz->get(i,0);
            for(int j=0; j<listaV.comprimento(); j++)
            {
                if (matriz->get(i,j)>exentricidade)
                    exentricidade=matriz->get(i,j);
            }
            if(exentricidade==raio)
                cout<<" "<<vet[i];
        }
        cout<<endl<<"Periferia: ";
        for(int i=0; i<listaV.comprimento(); i++)
        {
            exentricidade=matriz->get(i,0);
            for(int j=0; j<listaV.comprimento(); j++)
            {
                if (matriz->get(i,j)>exentricidade)
                    exentricidade=matriz->get(i,j);
            }
            if(exentricidade==diametro)
                cout<<" "<<vet[i];
        }
        delete []vet;
    }
    if(verificaGrafoNulo()==1)
    {
        cout<<"Grafo Nulo";
    }
}

MatrizLin* Grafo::floyd()
{
    MatrizLin * matriz = new MatrizLin(listaV.comprimento(),listaV.comprimento());
    Vertice *v = listaV.getPrimeiro();
    Vertice * vv = listaV.getPrimeiro();
    Aresta *a = v->getListaAresta()->getPrimeiro();
    if(verificaGrafoNulo())
    {
        MatrizLin *mat = new MatrizLin(0,0);
        return mat;
    }
    int * vet  = new int[listaV.comprimento()]; ///Vetor no qual armazena os valores dos vértices
    for(int cont = listaV.comprimento()-1; cont>=0; cont--)
    {
        vet[cont] = vv->getVertice();
        vv = vv->getProx();
    }
    for(int i=0; i<listaV.comprimento(); i++)
    {
        for(int j=0; j<listaV.comprimento(); j++)
        {
            if(i==j)
                matriz->set(i,j,0);
            else
                matriz->set(i,j,HUGE_VAL);
        }

    }
    while(v != NULL)
    {
        a=v->getListaAresta()->getPrimeiro();
        while (a != NULL)
        {
            matriz->set(retornaIndice(vet,listaV.comprimento(),v->getVertice()),retornaIndice(vet,listaV.comprimento(),a->getSucessor()), a->getPeso());
            a = a->getProx();
        }
        v=v->getProx();
    }

    for(int k=0; k<listaV.comprimento(); k++)
    {
        for(int i=0; i<listaV.comprimento(); i++)
        {
            for(int j=0; j<listaV.comprimento(); j++)
            {
                if(i!=j && matriz->get(i,j)>(matriz->get(k,j)+matriz->get(k,i)))
                {
                    matriz->set(i,j,matriz->get(k,j)+matriz->get(k,i));
                }
            }
        }
    }
    for(int i = 0 ; i<listaV.comprimento() ; i++) ///Imprime os indices da matriz correspondentes ao vértices
    {
//       cout<<i<<" = "<<vet[i]<<endl;
    }
    delete [] vet;
    return matriz;
}


void Grafo::graphviz(char * nomeDoArquivo) ///ATUALIZADO DIGRAFO
///A função faz uma cópia do grafo, e vai removendo as arestas e adicionando no arquivo de texto
{
    /// funciona parecido com a de gerar arquivo de saída, a diferença é a forma como é impresso a saída
    if(digrafo==false)
    {
        Grafo * b = copiaGrafo();
        FILE * arquivo = fopen(nomeDoArquivo,"w+");
        Vertice * v = b->listaV.getPrimeiro();
        fprintf(arquivo,"graph {\n",b->getOrdem());
        while(v!=NULL)
        {
            ListaAresta * la = v->getListaAresta();
            Aresta * a = la->getPrimeiro();
            while(a!=NULL)
            {
                fprintf(arquivo,"%   d--%d [ label =%f ];\n",v->getVertice(),a->getSucessor(),a->getPeso());
                Aresta * aux = a->getProx();
                b->excluiAresta(v->getVertice(),a->getSucessor());
                a = aux;
            }
            v = v->getProx();
        }
        fprintf(arquivo,"}");
        fclose(arquivo);
        delete b;
    }
    else
    {
        Grafo * b = copiaGrafo();
        FILE * arquivo = fopen(nomeDoArquivo,"w+");
        Vertice * v = b->listaV.getPrimeiro();
        fprintf(arquivo,"digraph {\n",b->getOrdem());
        while(v!=NULL)
        {
            ListaAresta * la = v->getListaAresta();
            Aresta * a = la->getPrimeiro();
            while(a!=NULL)
            {
                fprintf(arquivo,"%   d->%d [ label =%f ];\n",v->getVertice(),a->getSucessor(),a->getPeso());
                Aresta * aux = a->getProx();
                b->excluiAresta(v->getVertice(),a->getSucessor());
                a = aux;
            }
            v = v->getProx();
        }
        fprintf(arquivo,"}");
        fclose(arquivo);
        delete b;
    }
}

int Grafo::menorDistancia(float *vetDistancia, int *vetMinimo, int tam)  /// Retorna o indice.
{

    int indice = 0;
    float menor = HUGE_VAL;

    for(int i=0; i < tam; ++i)
    {

        if(vetMinimo[i] == 0 && vetDistancia[i] <= menor)
        {
            indice = i;
            menor = vetDistancia[i];

        }
    }

    return indice;
}

ArestaAux * Grafo::intercessao( int *vertices, ListaAresta *lista, int *tamVetAA, int *vetMinimo)
{

    ArestaAux *vetAA = new ArestaAux[lista->getN()];

    Aresta *aresta = lista->getPrimeiro();

    *tamVetAA = 0;
    while(aresta != NULL)
    {

        int indiceAresta = retornaIndice(vertices, ordem, aresta->getSucessor());

        if(vetMinimo[indiceAresta] == 0)
        {
            vetAA[*tamVetAA].setElementos(aresta->getSucessor(), aresta->getPeso());
            *tamVetAA = *tamVetAA + 1;

        }

        aresta = aresta->getProx();

    }

    return vetAA;
}

void Grafo::dijkstra(int no1, int no2)   /// Sem alteração, aparentemente funciona para digrafo.
{

    if(listaV.busca(no1) && listaV.busca(no2))
    {

        float vetDistancia[ordem];    ///armazena as distancias do no1 a todos os demais verdices
        int vetMinimo[ordem];      ///armazena 0 para os vertices que não se conhece caminho minimo e 1 para os vertices que se conhece
        int caminho[ordem];             ///armazena o caminho que foi utilizado para chegar a determinado vertice
        int *vertices = new int [ordem];     /// Contem os vértices

        Vertice *v = listaV.getPrimeiro();

        for(int i=0; i < ordem; ++i)
        {

            vetDistancia[i] = HUGE_VALF;
            vetMinimo[i] = 0;
            caminho[i] = -1;
            vertices[i] = v->getVertice();

            v = v->getProx();
        }

        int indNo1 = retornaIndice(vertices, ordem, no1);

        caminho[indNo1] = 0;
        vetDistancia[indNo1] = 0;

        while( verificaVetMinimo(vetMinimo, ordem) )
        {

            int verticeMenor = menorDistancia(vetDistancia, vetMinimo, ordem);

            vetMinimo[verticeMenor] = 1;

            ///os vertices que estão abertos e que são adjacentes a verdiceMenor

            int tamVetAA;

            Vertice *vert = listaV.retornaVertice(vertices[verticeMenor]);
            ListaAresta *listaL = vert->getListaAresta();
            ArestaAux *vetAA = intercessao(vertices, listaL, &tamVetAA, vetMinimo);

            for(int i=0; i < tamVetAA; ++i)
            {

                float distancia = vetDistancia[verticeMenor] + vetAA[i].distancia;
                int indiceAdijacente = retornaIndice(vertices, ordem, vetAA[i].adjacente);

                if(distancia < vetDistancia[indiceAdijacente])
                {
                    vetDistancia[indiceAdijacente] = distancia;
                    caminho[indiceAdijacente] = vertices[verticeMenor];


                }

            }

            delete []vetAA;
            vetAA = NULL;


        }

        int indNo2 = retornaIndice(vertices, ordem, no2);

        if(vetDistancia[indNo2] != HUGE_VALF)
        {

            cout<<"Menor caminho eh: "<< vetDistancia[indNo2]<<endl;
            cout<<"Sequencia de Vertices: \n";

            PilhaEncad pilha;

            int indice = indNo2;

            while(caminho[indice] != 0)
            {

                pilha.empilha(vertices[indice]);

                indice = retornaIndice(vertices, ordem, caminho[indice]);

            }

            pilha.empilha(no1);

            while(!pilha.vazia())
                cout<<pilha.desempilha()<<" ";

            cout<<endl;
        }
        else
        {
            cout<<"Nao existe caminho entre os Vertices : "<<no1<<" e "<<no2<<endl;
        }



    }
    else
    {
        cout<<"Pelo menos um dos vertices não estão no grafo."<<endl;
    }

}


bool verificaVetComponente(int *vet, int tam)   /// retorna true se existir 0 no vetor e false se não existir
{

    for(int i=0; i < tam; ++i)
    {
        if(vet[i] == 0)
            return true;
    }

    return false;

}

void Grafo::imprimeSequencia()
{
    cout<<"S = { ";
    Vertice * v = listaV.getPrimeiro();
    while(v!=NULL)
    {
        ListaAresta * la = v->getListaAresta();
        cout<<la->numElementos()<<" ";
        v = v->getProx();
    }
    cout<<"}"<<endl;
}

void Grafo::intercala(AuxAresta aresta[], int inicio, int fim, int meio)
{

    int posLivre,inicio_vetor1, inicio_vetor2, i;
    AuxAresta *aux = new AuxAresta[fim+1];
    inicio_vetor1 = inicio;
    inicio_vetor2 = meio+1;
    posLivre = inicio;
    while(inicio_vetor1 <= meio && inicio_vetor2 <= fim)
    {
        if (aresta[inicio_vetor1].peso <= aresta[inicio_vetor2].peso)
        {
            aux[posLivre] = aresta[inicio_vetor1];
            inicio_vetor1++;
        }
        else
        {
            aux[posLivre] = aresta[inicio_vetor2];
            inicio_vetor2++;
        }
        posLivre++;
    }

    for (int i = inicio_vetor1; i <= meio; ++i)
    {
        aux[posLivre] = aresta[i];
        posLivre++;
    }

    for (int i = inicio_vetor2; i <= fim; ++i)
    {
        aux[posLivre] = aresta[i];
        posLivre++;
    }

    for (int i = inicio; i <=fim; ++i)
    {
        aresta[i] = aux[i];
    }

    delete []aux;
}
void Grafo::ordenaArestas(AuxAresta aresta[], int inicio, int fim)
{

    int meio;
    if (inicio < fim)
    {
        meio = (inicio+fim)/2;
        ordenaArestas (aresta,inicio, meio);
        ordenaArestas (aresta,meio+1, fim);
        intercala(aresta,inicio, fim, meio);

    }

}
///Correto para digrafo.
Grafo* Grafo::Agm(void)
{

    Grafo *newGrafo = copiaGrafo();

    Vertice *vertice = newGrafo->listaV.getPrimeiro();

    if(vertice != NULL)
    {
        if(numArestas > 0)
        {
            newGrafo->pesoAGM = 0;

            int *vertices = new int[ordem];            /// Para termos uma relação entre o vertice e um indice

            /// Coloca todas as arestas do grafo em um vetor

            AuxAresta *vetArestas = new AuxAresta[newGrafo->numArestas];        /// AuxAresta possui no1, no2 e peso; ou seja, armazena uma aresta
            int posicaoLivre = 0;                                                /// Numero total de arestas

            int j = 0;

            while(vertice != NULL)                                              /// Coloca todas as arestas em um vetor
            {
                ListaAresta *listaA = vertice->getListaAresta();
                Aresta *aresta = listaA->getPrimeiro();


                while(aresta != NULL)
                {

                    vetArestas[posicaoLivre].no1 = vertice->getVertice();
                    vetArestas[posicaoLivre].no2 = aresta->getSucessor();
                    vetArestas[posicaoLivre].peso = aresta->getPeso();
                    Aresta * arestaAux = aresta->getProx();
                    newGrafo->excluiAresta(vertice->getVertice(), aresta->getSucessor());

                    posicaoLivre += 1;
                    aresta = arestaAux;
                }

                vertices[j] = vertice->getVertice();
                vertice = vertice->getProx();
                ++j;
            }

            /// Ordena o vetor
            ordenaArestas(vetArestas, 0, posicaoLivre-1);

            int posicao = 0;                                                  /// para percorrer vetArestas
            int *v = new int [ordem];                          /// Verifica a existencia de ciclos no grafo

            for(int i=0; i < ordem; ++i)
            {
                v[i] = vertices[i];
            }


            while(newGrafo->numArestas <= numArestas - 1 && posicao < posicaoLivre)               /// Verifica se o número de arestas da AGM é menor do que o grafo atual e verifica se ainda podemos continiar a percorer vetArestas
            {

                int indiceNo1 = retornaIndice(vertices, ordem, vetArestas[posicao].no1);
                int indiceNo2 = retornaIndice(vertices, ordem, vetArestas[posicao].no2);

                if(v[indiceNo1] != v[indiceNo2])                                           /// Verifica a existencia de ciclo
                {

                    newGrafo->insere(vetArestas[posicao].no1, vetArestas[posicao].no2, vetArestas[posicao].peso);   /// adiciona aresta
                    newGrafo->pesoAGM += vetArestas[posicao].peso;

                    int ind2 = v[indiceNo2];

                    for(int i=0; i < ordem; ++i)                             /// muda o valor de todos os v[i] que é igual a v[indiceNo2], ou seja do No2
                    {
                        if(v[i] ==ind2)
                            v[i] = v[indiceNo1];
                    }



                }

                posicao += 1;
            }

            delete []v;
            delete []vetArestas;

            return newGrafo;

        }
        else
            return NULL;

    }
    else
        return NULL;

}

int Grafo::retornaIndice(int * vet, int tam, int val)
{
    for(int i = 0; i<tam ; i++)
    {
        if(vet[i]==val)
            return i;
    }
    cout<<"Indice nao encontrado!"<<" val=" <<val<<endl;
    exit(1);
}

void Grafo::fechoTransitivoDireto(int id)
{
    MatrizLin * matriz = floyd();
    Vertice *v=listaV.getPrimeiro();
    int *vetorV=new int[listaV.comprimento()];
    for(int i=0; i<listaV.comprimento(); i++)
    {
        vetorV[i]= v->getVertice();
        v=v->getProx();
    }
    v=listaV.getPrimeiro();
    while(v!=NULL && v->getVertice()!= id)
    {
        v=v->getProx();
    }
    if (v==NULL)
    {
        cout<<"Vertice de id "<<id<<" nao esta no grafo";
    }
    if (v->getVertice()==id)
    {
        cout<<"Indices dos vertices que fazem parte do fecho transitivo direto de "<<id<<": "<<endl;
        for (int i=0; i<listaV.comprimento(); i++)
        {
            if (matriz->get(i, id)!=HUGE_VAL)
                cout<<vetorV[i]<<" ";
        }
    }
    cout<<endl;
    delete vetorV;
}

void Grafo::fechoTransitivoIndireto(int id)
{
    MatrizLin * matriz = floyd();
    Vertice *v=listaV.getPrimeiro();
    int *vetorV=new int[listaV.comprimento()];
    for(int i=0; i<listaV.comprimento(); i++)
    {
        vetorV[i]= v->getVertice();
        v=v->getProx();
    }
    v=listaV.getPrimeiro();
    while(v!=NULL && v->getVertice()!= id)
    {
        v=v->getProx();
    }
    if (v==NULL)
    {
        cout<<"Vertice de id "<<id<<" nao esta no grafo";
    }
    if (v->getVertice()==id)
    {
        cout<<"Indices dos vertices que fazem parte do fecho transitivo indireto de "<<id<<": "<<endl;
        for (int i=0; i<listaV.comprimento(); i++)
        {
            if (matriz->get(id, i)!=HUGE_VAL)
                cout<<vetorV[i]<<" ";
        }
    }

    delete vetorV;

}
Grafo* Grafo::buscaProfundidade(int numVert)
{

    if(ordem > 0 && listaV.busca(numVert))
    {

        int *vertices = new int[ordem];            /// Para termos uma relação entre o vertice e um indice
        int *marcacao = new int[ordem];            /// Marca os vertices que já foram visitados

        int j = 0;


        Grafo *newGrafo = copiaGrafo();
        newGrafo->digrafo = digrafo;

        Vertice *vertice = newGrafo->listaV.getPrimeiro();

        while(vertice != NULL)
        {
            ListaAresta *listaAresta = vertice->getListaAresta();
            Aresta *aresta = listaAresta->getPrimeiro();

            while(aresta != NULL)
            {
                newGrafo->excluiAresta(vertice->getVertice(), aresta->getSucessor());

                aresta = aresta->getProx();
            }

            vertices[j] = vertice->getVertice();
            vertice = vertice->getProx();
            marcacao[j] = 0;
            ++j;
        }

        vertice = listaV.retornaVertice(numVert);

        int indAux = retornaIndice(vertices, ordem, vertice->getVertice());
        if(marcacao[indAux] == 0)
        {
            marcacao[indAux] = 1;
            auxBuscaProfundidade(newGrafo, vertice, marcacao, vertices);
        }

        vertice = newGrafo->listaV.getPrimeiro();

        while(vertice != NULL)
        {

            int indAux = retornaIndice(vertices, ordem, vertice->getVertice());
            if(marcacao[indAux] == 0)
            {
                marcacao[indAux] = 1;
                auxBuscaProfundidade(newGrafo, vertice, marcacao, vertices);
            }

            vertice = vertice->getProx();
        }




        delete []marcacao;
        delete []vertices;
        return newGrafo;

    }
    else
        return NULL;



}

void Grafo::auxBuscaProfundidade(Grafo *aux, Vertice *elementoAnterior, int *marcacao, int *vertices)
{

    if(elementoAnterior != NULL)
    {

        ListaAresta *ListaAresta = elementoAnterior->getListaAresta();
        Aresta *aresta = ListaAresta->getPrimeiro();

        while(aresta != NULL)
        {

            int indAux = retornaIndice(vertices, ordem, aresta->getSucessor());
            if(marcacao[indAux] == 0 && !aux->verificaAresta(elementoAnterior->getVertice(), aresta->getSucessor()))
            {

                marcacao[indAux] = 1;
                aux->insere(elementoAnterior->getVertice(), aresta->getSucessor(), aresta->getPeso());
                cout<<"Aresta entre: "<<elementoAnterior->getVertice()<<" "<<aresta->getSucessor()<<endl;

                auxBuscaProfundidade(aux, listaV.retornaVertice(aresta->getSucessor()), marcacao, vertices);

            }

            aresta = aresta->getProx();
        }

    }


}


/// Falta arrumar.
Grafo* Grafo::buscaLargura(int noInicial)
{
    if(ordem > 0)
    {
        int anterior = -1;

        int *vertices = new int[ordem];            /// Para termos uma relação entre o vertice e um indice
        int *marcacao = new int[ordem];            /// Marca os vertices que já foram visitados

        int j = 0;


        Grafo *newGrafo = copiaGrafo();
        Vertice *vertice = newGrafo->listaV.getPrimeiro();

        while(vertice != NULL)
        {
            ListaAresta *listaAresta = vertice->getListaAresta();
            Aresta *aresta = listaAresta->getPrimeiro();

            while(aresta != NULL)
            {
                newGrafo->excluiAresta(vertice->getVertice(), aresta->getSucessor());

                aresta = aresta->getProx();
            }

            vertices[j] = vertice->getVertice();
            marcacao[j] = 0;
            ++j;
            vertice = vertice->getProx();
        }

        FilaEncad fila;

        while(verificaVetMinimo(marcacao, ordem))                /// verifica se existem vertices que ainda não foram visitados
        {

            int indice;
            for(int i=0; i < ordem; ++i)
            {
                if(marcacao[i] == 0)
                {
                    indice = i;
                    break;
                }
            }

            Vertice *v = listaV.retornaVertice(vertices[indice]);
            anterior = v->getVertice();

            marcacao[retornaIndice(vertices, ordem, v->getVertice())] = 1;

            ListaAresta *listaA = v->getListaAresta();
            Aresta *aresta = listaA->getPrimeiro();

            while(aresta != NULL)                               ///Inicializa a fila
            {
                if(marcacao[retornaIndice(vertices, ordem, aresta->getSucessor())] == 0)
                    fila.enfileira(aresta->getSucessor());

                aresta = aresta->getProx();

            }

            while(!fila.vazia())
            {

                int n = fila.desenfileira();

                if( marcacao[retornaIndice(vertices, ordem, n)] == 0)
                {


                    marcacao[retornaIndice(vertices, ordem, n)] = 1;

                    if(!verificaVetMinimo(marcacao, ordem))             /// Se existe somente um vertice que ainda não foi marcado
                    {

                        v = listaV.retornaVertice(n);
                        ListaAresta *lista = v->getListaAresta();
                        Aresta *aresta = lista->getPrimeiro();

                        if(aresta != NULL)
                        {
                            newGrafo->insere(v->getVertice(), aresta->getSucessor(), aresta->getPeso());
                        }

                        break;


                    }




                    float peso;
                    if(anterior != -1)
                    {

                        v = listaV.retornaVertice(anterior);

                        ListaAresta *lista = v->getListaAresta();
                        Aresta *aresta = lista->getPrimeiro();

                        while(aresta != NULL)
                        {
                            if(aresta->getSucessor()==n)
                            {
                                peso = aresta->getPeso();
                                break;

                            }

                            aresta = aresta->getProx();
                        }

                        if(verificaAresta(n, anterior))
                            newGrafo->insere(n, anterior,peso);                          /// visito o no

                        else
                            marcacao[retornaIndice(vertices, ordem, n)] = 0;

                    }

                    v = listaV.retornaVertice(n);
                    ListaAresta *listaA = v->getListaAresta();
                    aresta = listaA->getPrimeiro();

                    while(aresta != NULL)                               /// empilha os vertices que são adjasentes ao no n e se eles ainda não foram visitados eles entram na pilha
                    {

                        int indAux = retornaIndice(vertices, ordem, aresta->getSucessor());
                        if(marcacao[indAux] == 0 && !fila.verificaElemento(aresta->getSucessor()))
                            fila.enfileira(aresta->getSucessor());

                        aresta = aresta->getProx();

                    }

                    anterior = n;

                }
            }



        }

        delete []marcacao;
        delete []vertices;
        return newGrafo;

    }
    else
        return NULL;



}

bool Grafo::auxBusca(int * vet, int tam, int val)///ATUALIZADO DIGRAFO
{
    for(int i=0; i<tam; i++)
    {
        if(vet[i]==val)
            return true;
    }
    return false;
}

Grafo * Grafo::subgrafoInduzido(int * vet, int tam) ///ATUALIZADO DIGRAFO
{
    int *vetorVerificacao = new int[ordem];
    int *vertices = new int[ordem];
    Grafo * a = new Grafo(digrafo);
    Vertice *vertice = listaV.getPrimeiro();

    for(int i=0; i < ordem; ++i)
    {

        vetorVerificacao[i] = 0;
        vertices[i] = vertice->getVertice();


        vertice = vertice->getProx();
    }

    for(int i = 0; i < tam; ++i)
    {
        if(!listaV.busca(vet[i]))
        {
            cout<<"Elemento nao pertence ao grafo. Não eh possivel gerar o subGrafo induzido."<<endl;

            delete vetorVerificacao;
            delete vertices;
            return NULL;
        }
        if(a->listaV.busca(vet[i])==false)
        {
            a->insereVertice(vet[i]);
        }
        int ind = retornaIndice(vertices, ordem, vet[i]);

        if(vetorVerificacao[ind] == 0)
        {

            vetorVerificacao[ind] = 1;

        }
        else
        {
            cout<<"Elementos repetidos no vetor."<<endl;
            delete vetorVerificacao;
            delete vertices;
            return NULL;
        }

        Vertice * v = listaV.retornaVertice(vet[i]);
        ListaAresta * la = v->getListaAresta();
        for(int j=0; j<tam; j++)
        {
            if(vet[i]!=vet[j])
            {
                if(la->busca(vet[j]))
                {
                    if(a->verificaAresta(vet[i],vet[j])==false)
                    {
                        Aresta * aa = la->getPrimeiro();
                        while(aa!=NULL)
                        {
                            if(aa->getSucessor()==vet[j])
                            {
                                a->insere(vet[i],vet[j],aa->getPeso());
                            }
                            aa = aa->getProx();
                        }
                    }
                }
            }
        }
    }

    delete vetorVerificacao;
    delete vertices;

    return a;
}

int Grafo::numComponenteConexa(void)
{

    if(ordem > 0)
    {
        int comp = listaV.comprimento();  ///Cria um vetor de vertices e de marcação e preenche
        Vertice * v = listaV.getPrimeiro();
        int * vertices = new int [comp];
        int * marca = new int [comp];
        for(int i=0; i<comp; i++)
        {
            vertices[i] = v->getVertice();
            marca[i] = 0;
            v = v->getProx();
        }
        int cont = 1;

        while(verificaVetor(marca)==false)
        {
            auxComponente(indice(marca,vertices),marca,vertices,cont);
            cont++;
        }

        int maior = marca[0];
        for(int i=0; i < comp; ++i)
        {
            if(marca[i] > maior)
                maior = marca[i];
        }

        delete [] vertices;
        delete [] marca;

        return maior;
    }
}

void Grafo::auxComponente(int ini, int * marcacao,int * vertices, int m)
{
    marcacao[retornaIndice(vertices,listaV.comprimento(),ini)] = m;
    Vertice * v = listaV.retornaVertice(ini);
    ListaAresta * la = v->getListaAresta();
    Aresta * a = la->getPrimeiro();
    while(a!=NULL)
    {
        int sucessor = a->getSucessor();
        int ind = retornaIndice(vertices,listaV.comprimento(),sucessor);
        if(marcacao[ind]==0)
        {
            auxComponente(sucessor,marcacao,vertices,m);
        }
        a = a->getProx();
    }
}

bool Grafo::verificaVetor(int * vet) ///ATUALIZADO DIGRAFO
{
    for(int i=0; i<listaV.comprimento(); i++)
    {
        if(vet[i]==0)
            return false;
    }
    return true;
}

int Grafo::indice(int * marca,int * vet) ///ATUALIZADO DIGRAFO
{
    for(int i=0; i<listaV.comprimento(); i++)
    {
        if(marca[i]==0)
            return vet[i];
    }
    cout<<"Nao encontrado!"<<endl;
    exit(1);
}


void Grafo::verticeArticulacao() ///ATUALIZADO DIGRAFO
{
    if(digrafo==false)
    {
        auxVerticeArticulacao();
    }
    else
    {
        Grafo * sub = subjacente();
        sub->auxVerticeArticulacao();
    }
}

void Grafo::auxVerticeArticulacao() ///ATUALIZADO DIGRAFO
{
    Grafo * a = copiaGrafo();
    int num = numComponenteConexa();
    int * vertices = new int [listaV.comprimento()];
    Vertice * v = listaV.getPrimeiro();
    int k=0;
    while(v!=NULL)
    {
        vertices[k] = v->getVertice();
        v = v->getProx();
        k++;
    }
    int testa =0;
    v = listaV.getPrimeiro();
    for(int i=0; i<listaV.comprimento(); i++)
    {
        ListaAresta * la = (listaV.retornaVertice(vertices[i]))->getListaAresta();
        int * arestas = new int [la->getN()];
        int comp=la->getN();
        Aresta * aa = la->getPrimeiro();
        for(int j=0; j<comp; j++)
        {
            arestas[j] = aa->getSucessor();
            aa = aa->getProx();
        }
        a->removeVertice(vertices[i]);
        if(a->numComponenteConexa()>num)
        {
            testa++;
            cout<<vertices[i]<<" ";
        }
        for(int j=0; j<comp; j++)
        {
            a->insere(vertices[i],arestas[j],1);
        }
        delete [] arestas;
    }
    if(testa==0)
        cout<<"Nao existem vertices de articulacao!";
    cout<<endl;

    delete [] vertices;
}



bool Grafo::bipartido() ///ATUALIZADO DIGRAFO
{
    if(ordem>0)
    {
        int comp = listaV.comprimento();  ///Cria um vetor de vertices e de marcação e preenche
        Vertice * v = listaV.getPrimeiro();
        int * vertices = new int [comp];
        int * marca = new int [comp];
        for(int i=0; i<comp; i++)
        {
            vertices[i] = v->getVertice();
            marca[i] = 0;
            v = v->getProx();
        }
        int cont = 1;
        while(verificaVetor(marca)==false)
        {
            auxBipartido(indice(marca,vertices),marca,vertices,cont);
        }

        for(int i=0; i<comp; i++)
        {
            int mm = marca[i];
            Vertice * v = listaV.retornaVertice(vertices[i]);
            ListaAresta * la = v->getListaAresta();
            Aresta * a = la->getPrimeiro();
            while(a!=NULL)
            {
                int mm2 = marca[retornaIndice(vertices,listaV.comprimento(),a->getSucessor())];
                if(mm==mm2)
                    return false;
                a = a->getProx();
            }
        }
        return true;

        delete [] vertices;
        delete [] marca;
    }
}

void Grafo::auxBipartido(int ini, int * marcacao,int * vertices, int m) ///ATUALIZADO DIGRAFO
{
    marcacao[retornaIndice(vertices,listaV.comprimento(),ini)] = m;
    Vertice * v = listaV.retornaVertice(ini);
    ListaAresta * la = v->getListaAresta();
    Aresta * a = la->getPrimeiro();
    while(a!=NULL)
    {
        int sucessor = a->getSucessor();
        int ind = retornaIndice(vertices,listaV.comprimento(),sucessor);
        if(marcacao[ind]==0)
        {
            if(m==1)
            {
                auxBipartido(sucessor,marcacao,vertices,2);
            }
            if(m==2)
            {
                auxBipartido(sucessor,marcacao,vertices,1);
            }
        }
        a = a->getProx();
    }
}

void Grafo::auxArestaPonte() ///ATUALIZADO DIGRAFO
{
    int num = numComponenteConexa();
    Grafo * newGrafo = copiaGrafo();
    Vertice * vertice = newGrafo->listaV.getPrimeiro();
    AuxAresta *vetArestas = new AuxAresta[newGrafo->numArestas];        /// AuxAresta possui no1, no2 e peso; ou seja, armazena uma aresta
    int posicaoLivre = 0;                                                /// Numero total de arestas
    int j = 0;

    while(vertice != NULL)                                              /// Coloca todas as arestas em um vetor
    {
        ListaAresta *listaA = vertice->getListaAresta();
        Aresta *aresta = listaA->getPrimeiro();

        while(aresta != NULL)
        {

            vetArestas[posicaoLivre].no1 = vertice->getVertice();
            vetArestas[posicaoLivre].no2 = aresta->getSucessor();
            vetArestas[posicaoLivre].peso = aresta->getPeso();
            Aresta * arestaAux = aresta->getProx();
            newGrafo->excluiAresta(vertice->getVertice(), aresta->getSucessor());
            posicaoLivre += 1;
            aresta = arestaAux;
        }
        vertice = vertice->getProx();
        j++;
    }
    int testa = 0;
    for(int i=0; i<numArestas; i++)
    {
        excluiAresta(vetArestas[i].no1,vetArestas[i].no2);
        if(num<numComponenteConexa())
        {
            testa++;
            cout<<"("<<vetArestas[i].no1<<","<<vetArestas[i].no2<<")"<<" ";
        }
        insere(vetArestas[i].no1,vetArestas[i].no2,vetArestas[i].peso);
    }
    if(testa==0)
        cout<<"Nao existem arestas de ponte no grafo!";
    cout<<endl;
}

void Grafo::arestaPonte() ///ATUALIZADO DIGRAFO
{
    if(digrafo==true)
    {
        Grafo * sub = subjacente();
        sub->auxArestaPonte();
    }
    else
    {
        auxArestaPonte();
    }
}

bool Grafo::verificaArestaPonte(int no1, int no2) ///ATUALIZADO DIGRAFO
{
    float peso;
    Vertice * v = listaV.getPrimeiro();
    while(v!=NULL)
    {
        if(v->getVertice()==no1)
        {
            ListaAresta * la = v->getListaAresta();
            Aresta * a = la->getPrimeiro();
            while(a!=NULL)
            {
                if(a->getSucessor()==no2)
                {
                    peso = a->getPeso();
                }
                a = a->getProx();
            }
        }
        v = v->getProx();
    }
    int num = numComponenteConexa();
    bool resultado;
    excluiAresta(no1,no2);
    if(numComponenteConexa()>num)
        resultado = true;
    else
        resultado = false;
    insere(no1,no2,peso);

    return resultado;
}

bool Grafo::verificaTeste(int * vet)
{
    for(int i=0; i<ordem; i++)
    {
        if(vet[i] == HUGE_VAL)
            return false;
    }
    return true;
}

bool Grafo::euleriano()
{
    if(ordem>0)
    {
        if(numComponenteConexa()==1)
        {
            Vertice * v = listaV.getPrimeiro();
            while(v!=NULL)
            {
                ListaAresta * la = v->getListaAresta();
                if(la->getN()%2!=0)
                    return false;
                v = v->getProx();
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool Grafo::verificaDigrafo() ///ATUALIZADO DIGRAFO
{
    return digrafo;
}

Grafo * Grafo::grafoReverso() ///ATUALIZADO DIGRAFO
{
    if(digrafo==false)
    {
        Grafo * a = copiaGrafo();
        return a;
    }
    else
    {
        Grafo * a = new Grafo(digrafo);
        Vertice * v = listaV.getPrimeiro();
        while(v!=NULL)
        {
            ListaAresta * la = v->getListaAresta();
            Aresta * aa = la->getPrimeiro();
            while(aa!=NULL)
            {
                a->insere(aa->getSucessor(),v->getVertice(),aa->getPeso());
                aa = aa->getProx();
            }
            v = v->getProx();
        }
        return a;
    }
}

Grafo * Grafo::subjacente() ///ATUALIZADO DIGRAFO
{
    if(digrafo==false) ///Se o grafo não é orientado então retornamos uma cópia dele
        return copiaGrafo();
    else
    {
        Grafo * copia = new Grafo(false);
        Vertice * v = listaV.getPrimeiro();
        while(v!=NULL)
        {
            ListaAresta * la = v->getListaAresta();
            Aresta * a = la->getPrimeiro();
            while(a!=NULL)
            {
                if(verificaAresta(v->getVertice(),a->getSucessor()))
                    copia->insere(v->getVertice(),a->getSucessor(),a->getPeso());
                a = a->getProx();
            }
            v = v->getProx();
        }
        return copia;
    }
}

void Grafo::setaVerticeTeminal(int no)
{

    Vertice *v = listaV.retornaVertice(no);
    v->setTerminal(true);

    numTerminais += 1;

}

int Grafo::numTerminaisAdjacentes(Aresta *a, int *vertT, int tam)
{

    int terminais = 0;
    while(a != NULL)
    {
        for(int i = 0; i < tam; ++i)
        {
            if(a->getSucessor() == vertT[i])
            {
                terminais += 1;
            }
        }

        a = a->getProx();

    }

    return terminais;

}

Grafo * Grafo::arvoreDeSteiner()
{

    if(numTerminais > 0)
    {


        /// Cria o vetor de solução. Ou seja vertices não termnais
        int tam = ordem - numTerminais;
        Solucao *vetSolucao = new Solucao[tam];
        int *vertTerminais = new int[numTerminais];

        ///Inicializa o vetor.
        Vertice *v = listaV.getPrimeiro();

        int contS = 0;
        int contT = 0;

        while(v != NULL)
        {

            if(v->getTerminal())
            {

                vertTerminais[contT] = v->getVertice();
                contT += 1;

            }

            v = v->getProx();

        }

        v = listaV.getPrimeiro();

        ///Calcula o parametro dos vertices não terminais
        while(v != NULL)
        {


            if(v->getTerminal() == false)
            {
                ListaAresta *listaA = v->getListaAresta();
                vetSolucao[contS].vertice = v->getVertice();

                int termAdij = numTerminaisAdjacentes(listaA->getPrimeiro(), vertTerminais, numTerminais);
                vetSolucao[contS].valor = (float)termAdij / listaA->getN();
                vetSolucao[contS].visitado = false;
                contS +=1;
            }

            v = v->getProx();
        }


        ordenaSolucao(vetSolucao, 0, tam-1);
        Grafo *newGrafo = subgrafoInduzido(vertTerminais, numTerminais);


        int atual = 0;



        ///Verifica se o grafo é conexo, e adiciona um vertice ao grafo até que o seja.
        while(newGrafo->numComponenteConexa() != 1 && atual < tam)
        {

            Vertice *v = listaV.retornaVertice(vetSolucao[atual].getVertice());

            ListaAresta *listaA = v->getListaAresta();
            Aresta *aresta = listaA->getPrimeiro();

            while(aresta != NULL)
            {
                if( !newGrafo->verificaAresta(v->getVertice(), aresta->getSucessor()) )
                {
                    newGrafo->insere(v->getVertice(), aresta->getSucessor(), aresta->getPeso());
                }

                aresta = aresta->getProx();
            }

            atual += 1;
        }




        Grafo *grafoAgm = newGrafo->Agm();
        delete newGrafo;

        ///Faz uma busca no grafo por vertices simples que possuem grau 1

        Vertice *d = grafoAgm->listaV.getPrimeiro();
        while(d != NULL)
        {

            ListaAresta *listaA = d->getListaAresta();

            if(listaA->numElementos() == 1)
            {
                Vertice *aux = listaV.retornaVertice(d->getVertice());

                if(!aux->getTerminal())
                {
                    grafoAgm->pesoAGM -= listaA->getPrimeiro()->getPeso();
                    grafoAgm->removeVertice(d->getVertice());
                }
            }

            d = d->getProx();

        }



        delete vertTerminais;
        vertTerminais = NULL;

        delete vetSolucao;
        vetSolucao = NULL;

        return grafoAgm;

    }

    else
        return NULL;
}

void Grafo::intercalaSolucao(Solucao vetSolucao[], int inicio, int fim, int meio)
{

    int posLivre,inicio_vetor1, inicio_vetor2, i;
    Solucao *aux = new Solucao[fim+1];
    inicio_vetor1 = inicio;
    inicio_vetor2 = meio+1;
    posLivre = inicio;
    while(inicio_vetor1 <= meio && inicio_vetor2 <= fim)
    {
        if (vetSolucao[inicio_vetor1].valor >= vetSolucao[inicio_vetor2].valor)
        {
            aux[posLivre].valor = vetSolucao[inicio_vetor1].valor;
            aux[posLivre].vertice = vetSolucao[inicio_vetor1].vertice;
            aux[posLivre].visitado = vetSolucao[inicio_vetor1].visitado;

            inicio_vetor1++;
        }
        else
        {
            aux[posLivre].valor = vetSolucao[inicio_vetor2].valor;
            aux[posLivre].vertice = vetSolucao[inicio_vetor2].vertice;
            aux[posLivre].visitado = vetSolucao[inicio_vetor2].visitado;
            inicio_vetor2++;
        }
        posLivre++;
    }

    for (int i = inicio_vetor1; i <= meio; ++i)
    {
        aux[posLivre].valor = vetSolucao[i].valor;
        aux[posLivre].vertice = vetSolucao[i].vertice;
        aux[posLivre].visitado = vetSolucao[i].visitado;

        posLivre++;
    }

    for (int i = inicio_vetor2; i <= fim; ++i)
    {
        aux[posLivre].valor = vetSolucao[i].valor;
        aux[posLivre].vertice = vetSolucao[i].vertice;
        aux[posLivre].visitado = vetSolucao[i].visitado;

        posLivre++;
    }

    for (int i = inicio; i <=fim; ++i)
    {
        vetSolucao[i].valor = aux[i].valor;
        vetSolucao[i].vertice = aux[i].vertice;
        vetSolucao[i].visitado = aux[i].visitado;
    }

    delete []aux;
}
void Grafo::ordenaSolucao(Solucao vetSolucao[], int inicio, int fim)
{

    int meio;
    if (inicio < fim)
    {
        meio = (inicio+fim)/2;
        ordenaSolucao (vetSolucao,inicio, meio);
        ordenaSolucao (vetSolucao,meio+1, fim);
        intercalaSolucao(vetSolucao,inicio, fim, meio);

    }

}


void Grafo::imprimeVerticesTerminais()
{
    Vertice * v = listaV.getPrimeiro();
    cout<<"Vertices Terminais: ";
    while(v!=NULL)
    {
        if(v->getTerminal())
            cout<<v->getVertice()<<" ";
        v = v->getProx();
    }
    cout<<endl;
}

float Grafo::getPesoAGM(void) /// Só funciona com o grafo que é retornado pela função AGM().
{

    return pesoAGM;



}

Grafo * Grafo::randomizado(float alfa, bool porct) /// porct informa se é para apresentar ou não o progresso do algoritmo
{

    if(numTerminais > 0)
    {


        srand(time(NULL));

        /// Cria o vetor de solução. Ou seja vertices não termnais
        int tam = ordem - numTerminais;
        Solucao *vetSolucao = new Solucao[tam];
        int *vertTerminais = new int[numTerminais];

        ///Inicializa o vetor com os vertices terminais
        Vertice *v = listaV.getPrimeiro();

        int contS = 0;
        int contT = 0;

        while(v != NULL)
        {

            if(v->getTerminal())
            {

                vertTerminais[contT] = v->getVertice();
                contT += 1;

            }

            v = v->getProx();

        }

        v = listaV.getPrimeiro();

        contS = 0;
        ///Calcula o parametro dos vertices não terminais
        while(v != NULL)
        {


            if(v->getTerminal() == false)
            {
                ListaAresta *listaA = v->getListaAresta();
                vetSolucao[contS].vertice = v->getVertice();

                int termAdij = numTerminaisAdjacentes(listaA->getPrimeiro(), vertTerminais, numTerminais);
                vetSolucao[contS].valor = (float)termAdij / listaA->getN();
                vetSolucao[contS].visitado = false;

                contS +=1;
            }

            v = v->getProx();
        }


        ordenaSolucao(vetSolucao, 0, tam-1);
        Grafo *newGrafo = subgrafoInduzido(vertTerminais, numTerminais); /// grafo induzido pelo vetor de vertices terminais

        Solucao *vetorAux = new Solucao[tam];
        for(int i=0; i < tam; ++i)
        {
            vetorAux[i] = vetSolucao[i];
        }


        Grafo *melhorSol = arvoreDeSteiner();  /// salva a melhor solução

        int atual = 0;

        int tamA = tam;
        Grafo *grafoOriginal = newGrafo->copiaGrafo();  /// Garda uma copia do subgrafo induzido, para as outra interações

        for(int q = 0; q < 100; ++q) /// faz 100 soluções
        {

            ///Verifica se o grafo é conexo, e adiciona um vertice ao grafo até que o seja.
            while(newGrafo->numComponenteConexa() != 1)
            {

                int d = (int)(alfa * tamA);

                int escolha;

                if(d == 0)
                {
                    escolha = 0;

                }
                else
                {
                    escolha = rand() % (int)(alfa * tamA);
                }


                Vertice *v = listaV.retornaVertice(vetorAux[escolha].getVertice());

                ListaAresta *listaA = v->getListaAresta();
                Aresta *aresta = listaA->getPrimeiro();

                ///adiciona as arestas do verice escolhido ao grafo
                while(aresta != NULL)
                {
                    if( !newGrafo->verificaAresta(v->getVertice(), aresta->getSucessor()) )
                    {
                        newGrafo->insere(v->getVertice(), aresta->getSucessor(), aresta->getPeso());
                    }

                    aresta = aresta->getProx();
                }

                atual += 1;

                if(tamA == 1)
                    break;

                /// Faz uma copia do vetor eliminando o vertice escolhido.
                Solucao *t = new Solucao[tamA-1];

                int a = 0;

                for(int j=0; j < tamA; ++j)
                {
                    if(j != escolha)
                    {
                        t[a] = vetorAux[j];
                        a++;
                    }

                }

                delete vetorAux;
                vetorAux = t;
                tamA -= 1;

            }


            Grafo *grafoAgm = newGrafo->Agm();
            delete newGrafo;

            ///Faz uma busca no grafo por vertices simples que possuem grau 1 e elimina esse vertice.

            Vertice *d = grafoAgm->listaV.getPrimeiro();
            while(d != NULL)
            {

                ListaAresta *listaA = d->getListaAresta();

                if(listaA->numElementos() == 1)
                {
                    Vertice *aux = listaV.retornaVertice(d->getVertice());

                    if(!aux->getTerminal())
                    {
                        grafoAgm->pesoAGM -= listaA->getPrimeiro()->getPeso();
                        grafoAgm->removeVertice(d->getVertice());
                    }
                }

                d = d->getProx();

            }


            if(melhorSol != NULL)
            {

                if(grafoAgm->getPesoAGM() < melhorSol->getPesoAGM()) ///verifica se a sulução atual é melhor que a melhor sulução.
                {
                    delete melhorSol;
                    melhorSol = grafoAgm;
                    grafoAgm = NULL;
                }
                else
                {
                    delete grafoAgm;
                }

            }
            else
            {

                melhorSol = grafoAgm;
                newGrafo = NULL;

            }


            if(vetorAux != NULL)
                delete vetorAux;

            ///cria um vetor e copia os elementos do vetSolução para ele.
            vetorAux = new Solucao[tam];
            for(int i=0; i < tam; ++i)
            {
                vetorAux[i] = vetSolucao[i];
            }

            ///Faz uma copia do grafo induzido, para uma nova interação
            newGrafo = grafoOriginal->copiaGrafo();
            tamA = tam;

            if((q==30 || q== 50 || q==70 || q==80 || q==90 || q== 99) && porct) ///informa o progresso do algoritimo
                cout<<q<<" % concluido.\n";

        }

        delete vertTerminais;
        vertTerminais = NULL;

        delete vetSolucao;
        vetSolucao = NULL;

        return melhorSol;



    }

    else
        return NULL;
}

Grafo* Grafo::reativo(float *alfa)
{

    if(numTerminais > 0)
    {

        srand(time(NULL));

        float vetorAlfa[19];

        vetorAlfa[0] = 0.1;
        for(int i=1; i < 19; ++i) ///Inicializa o vetor de alfas, de 0.1 a 1 , granulado de 0.05
        {
            vetorAlfa[i] = 0.1 + i*0.05;
        }

        float pesoMelhorSolucao[19];      /// Armazena as melhores soluções, mesmo indice do vetor de alfas

        int tam = ordem - numTerminais;
        Solucao *vetSolucao = new Solucao[tam];
        int *vertTerminais = new int[numTerminais];

        ///Inicializa o vetor de vertices terminais
        Vertice *v = listaV.getPrimeiro();

        int contS = 0;
        int contT = 0;

        while(v != NULL)
        {

            if(v->getTerminal())
            {

                vertTerminais[contT] = v->getVertice();
                contT += 1;

            }

            v = v->getProx();

        }

        v = listaV.getPrimeiro();

        contS = 0;
        ///Calcula o parametro dos vertices não terminais
        while(v != NULL)
        {


            if(v->getTerminal() == false)
            {
                ListaAresta *listaA = v->getListaAresta();
                vetSolucao[contS].vertice = v->getVertice();

                int termAdij = numTerminaisAdjacentes(listaA->getPrimeiro(), vertTerminais, numTerminais);
                vetSolucao[contS].valor = (float)termAdij / listaA->getN();
                vetSolucao[contS].visitado = false;

                contS +=1;
            }

            v = v->getProx();
        }


        ordenaSolucao(vetSolucao, 0, tam-1);
        ///Subigrafo induzido pelo vetor de vertices termnais.
        Grafo *newGrafo = subgrafoInduzido(vertTerminais, numTerminais);

        ///Guardamos o melhor resultado, e o alfa que o gerou.
        Grafo *best = reativoAux(newGrafo->copiaGrafo(), vetorAlfa[0], vetSolucao, tam);
        pesoMelhorSolucao[0] = best->getPesoAGM();

        float melhorAlfa = vetorAlfa[0];


        ///Chama uma vez a função auxReativo(), para cada alfa.
        for(int i=1; i < 19; ++i)
        {
            Grafo *aux = reativoAux(newGrafo->copiaGrafo(), vetorAlfa[i], vetSolucao, tam);
            pesoMelhorSolucao[i] = aux->getPesoAGM();

            if(aux->getPesoAGM() < best->getPesoAGM())
            {
                delete best;
                best = aux;
                aux = NULL;

                melhorAlfa = vetorAlfa[i];


            }
            else
             delete aux;


        }

        float probabilidade[100];

        int tamProb = calculaProbabilidade(pesoMelhorSolucao, 19, probabilidade, vetorAlfa);/// Calcula a probabilidade

        cout<<"Inicio.\n";

        for(int i = 0; i < 1000; ++i)
        {

            if(i == 10 || i == 100 || i == 300 || i == 500 || i == 700 || i == 800 || i == 900 || i == 990) ///Informa o progresso.
            {
                cout<<i/10<<" % concluido.\n";
            }


            int aleatorio = rand() % tamProb;  /// indice da interação

            int j;
            for(j=0; j < 19; ++j)
            {
                if(probabilidade[aleatorio] == vetorAlfa[j])     /// Encontra o indce no vetor de alfa
                    break;
            }


            ///Solução com o alfa escolhido
            Grafo *intermediario = reativoAux(newGrafo->copiaGrafo(), vetorAlfa[j], vetSolucao, tam);


            if(intermediario->getPesoAGM() < pesoMelhorSolucao[j])  ///Verifica se a silução atual é melhor que a ultima.
            {

                pesoMelhorSolucao[j] = intermediario->getPesoAGM();

                if(intermediario->getPesoAGM() < best->getPesoAGM())   ///verifica se a solução atual é a melhor de todas
                {

                    delete best;
                    best = intermediario;
                    intermediario = NULL;

                    melhorAlfa = vetorAlfa[j];

                }
                else
                {

                    delete intermediario;
                    intermediario = NULL;

                }

                ///Recalcula a probabilidade, pq exite uma mudança no vetor de melhores soluções.
                tamProb = calculaProbabilidade(pesoMelhorSolucao, 19, probabilidade, vetorAlfa);

            }
            else
            {
                delete intermediario;
                intermediario = NULL;
            }
        }

        *alfa = melhorAlfa;

        delete newGrafo;
        delete vetSolucao;
        delete vertTerminais;

        return best;



    }
    else
    {
        cout<<"Nao existe vertices terminais.";
        return NULL;
    }

}

Grafo* Grafo::reativoAux(Grafo *newGrafo, float alfa, Solucao *vetSolucao, int tam) ///A função deve fazer uma copia do vetor de solução
{

    srand(time(NULL));  ///Inicializa a semente

    Solucao *vetorAux = new Solucao[tam];
    for(int i=0; i < tam; ++i)   ///copia o vetor
    {
        vetorAux[i] = vetSolucao[i];
    }


    ///Verifica se o grafo é conexo, e adiciona um vertice ao grafo até que o seja.
    while(newGrafo->numComponenteConexa() != 1)
    {

        int d = (int)(alfa * tam);  ///calcula o tamnho a ser considerado do vetor

        int escolha;

        if(d == 0)  ///Devido a float exeption quando o alfa é zero.
        {
            escolha = 0;

        }
        else
        {
            escolha = rand() % (int)(alfa * tam);
        }


        Vertice *v = listaV.retornaVertice(vetorAux[escolha].getVertice());

        ListaAresta *listaA = v->getListaAresta();
        Aresta *aresta = listaA->getPrimeiro();

        ///Insere as arestas do vertice escolhido no grafo auxiliar.
        while(aresta != NULL)
        {
            if( !newGrafo->verificaAresta(v->getVertice(), aresta->getSucessor()) )
            {
                newGrafo->insere(v->getVertice(), aresta->getSucessor(), aresta->getPeso());
            }

            aresta = aresta->getProx();
        }


        if(tam == 1)
            break;


        /// Faz uma copia do vetor eliminando o vertice escolhido.
        Solucao *t = new Solucao[tam-1];

        int a = 0;

        for(int j=0; j < tam; ++j)
        {
            if(j != escolha)
            {
                t[a] = vetorAux[j];
                a++;
            }

        }

        delete vetorAux;
        vetorAux = t;
        tam -= 1;

    }


    Grafo *grafoAgm = newGrafo->Agm();
    delete newGrafo;

    ///Faz uma busca no grafo por vertices simples que possuem grau 1
    Vertice *d = grafoAgm->listaV.getPrimeiro();
    while(d != NULL)
    {

        ListaAresta *listaA = d->getListaAresta();

        if(listaA->numElementos() == 1)
        {
            Vertice *aux = listaV.retornaVertice(d->getVertice());

            if(!aux->getTerminal())
            {
                grafoAgm->pesoAGM -= listaA->getPrimeiro()->getPeso();
                grafoAgm->removeVertice(d->getVertice());
            }
        }

        d = d->getProx();

    }

    return grafoAgm;

}

int Grafo::calculaProbabilidade(float *pesoMelhorSolucao, int tamPesoM, float *probabilidade, float *vetorAlfa)
{

    float maior = pesoMelhorSolucao[0];

    float vetorAux[19];

    /// Acha a sulução com o maior peso.
    for(int i = 0; i < tamPesoM; ++i)
    {

        if(pesoMelhorSolucao[i] > maior)
            maior = pesoMelhorSolucao[i];

    }

    int soma = 0;

    ///inicializa o vetorAux com a diferença do maior elemento - peso da sulução.
    for(int i = 0; i < tamPesoM; ++i)
    {

        if(pesoMelhorSolucao[i] != maior)
        {

            vetorAux[i] = maior - pesoMelhorSolucao[i];

        }
        else
        {

            vetorAux[i] = 1;

        }

        soma += vetorAux[i];  ///calcula a soma dos elementos do vetor.
    }


    int posicaoL = 0;
    /// calcula a porcentagem, e escreve no vetor de probabilidade os alfas.
    for(int i = 0; i < 19; ++i)
    {

        float parcial = vetorAux[i]/ soma;

        int p = (int)100 * parcial;

        if(p == 0)
            continue;

        int j = posicaoL;
        posicaoL = j + p;

        for(; j < posicaoL; ++j )
        {

            probabilidade[j] = vetorAlfa[i];

        }


    }

    return posicaoL;


}
