/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
class Aresta
{

public:

    Aresta();
    ~Aresta();
    int getSucessor();
    Aresta* getProx();
    void setSucessorPeso(int v, float peso);
    void setProx(Aresta *p);
    float getPeso();

private:

    int sucessor; // sucessor
    float peso;   // para arestas ponderadas
    Aresta *prox; // ponteiro para o proximo


};


#endif // NO_H_INCLUDED
