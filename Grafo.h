
/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#include <list>
#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "Solucao.h"
#include "ListaVertice.h"
#include "PilhaEncad.h"
#include "math.h"
#include "ArestaAux.h"
#include "MatrizLin.h"
#include "AuxAresta.h"
#include "FilaEncad.h"

class Grafo
{

private:

    bool multigrafo;
    bool digrafo;
    int ordem;
    int numTerminais;
    int numArestas; /// numero de arestas
    ListaVertice listaV;
    float pesoAGM;
    void auxBuscaProfundidade(Grafo *aux, Vertice *elementoAnterior, int *marcacao, int *vertices);
    void ordenaSolucao(Solucao vetSolucao[], int inicio, int fim);
    void intercalaSolucao(Solucao vetSolucao[], int inicio, int fim, int meio);
    bool verificaVetMinimo(int *vetMinimo, int tam);          /// retorna true se existir um vertice aberto, e false se não existir
    int menorDistancia(float *vetDistancia, int *vetMinimo, int tam);
    ArestaAux *intercessao(int *vertices, ListaAresta *lista, int *tamVetAA, int *vetMinimo);
    void intercala(AuxAresta aresta[], int inicio, int fim, int meio);
    void ordenaArestas(AuxAresta aresta[], int inicio, int fim);
    int retornaIndice(int * vet,int tam, int val);
    bool auxBusca(int *vet,int tam, int val);
    void auxComponente(int ini, int * marcacao,int * vertices, int m);
    bool verificaVetor(int * vet);
    int indice(int * marca,int * vet);
    void auxBipartido(int ini, int * marcacao,int * vertices, int m);
    bool verificaArestaPonte(int no1, int no2);
    bool verificaTeste(int * vet);
    int numTerminaisAdjacentes(Aresta *a, int *vertT, int tam);
public:
    float getPesoAGM(void);
    void imprimeVerticesTerminais();
    void setaVerticeTeminal(int no);
    Grafo * grafoReverso();
    bool euleriano();
    bool verificaDigrafo();
    bool bipartido();
    void insere(int No1, int No2, float dist);
    void insereVertice(int No);
    void excluiAresta(int No1, int No2);
    int getOrdem();
    void imprimeGrafo();
    void removeVertice(int No);
    void getGrauDeUmVertice(int No);
    int getGrau(); ///Retorna o grau do vertice de maior grau do grafo
    Grafo* buscaProfundidade(int numVert);
    bool verificaKRegularidade(int k); /// FAZER ESSA
    bool verificaTrivial();
    bool verificaGrafoCompleto();
    Grafo * retornaComplementar(); ///Retorna grafo complementar
    Grafo * copiaGrafo(); ///Retorna a cópia do grafo
    bool verificaAresta(int No1, int No2);
    void salvar(char * nomeDoArquivo);
    void dijkstra(int no1, int no2);
    int componenteConexa(void);
    bool verificaGrafoNulo();
    void vizinhancaAberta(int no);///Imprime o vértice se ele estiver no grafo e seus adjacentes
    void vizinhancaFechada(int no);///Imprime o vértice se ele estiver no grafo
    void raioDiametroCentroPeriferia(); ///Impreme o Diâmetro, centro e Periferia
    MatrizLin *floyd(); ///Retorna a matriz de caminhos mínimos de Floyd
    void graphviz(char * nomeDoArquivo); ///Gera o arquivo txt para visualizar no graphviz
    void imprimeSequencia();
    Grafo* Agm(void);
    Grafo* buscaLargura(int noInicial);
    void fechoTransitivoDireto(int n);
    void fechoTransitivoIndireto(int n);
    Grafo * subgrafoInduzido(int * vet, int tam);
    void auxVerticeArticulacao();
    void verticeArticulacao();
    int numComponenteConexa(void);
    void auxArestaPonte();
    void arestaPonte();
    Grafo * subjacente(); ///Retorna grafo subjacente (sem orientação)
    Grafo * arvoreDeSteiner();
    Grafo* randomizado(float alfa, bool porct);
    int calculaProbabilidade(float *pesoMelhorSolucao, int tamPesoM, float *probabilidade, float *vetorAlfa);
    Grafo* reativoAux(Grafo *newGrafo, float alfa, Solucao *vetSolucao, int tam);
    Grafo* reativo(float *alfa);

    Grafo(bool dig);




};


#endif // GRAFO_H_INCLUDED
