/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#ifndef ARESTAAUX_H_INCLUDED
#define ARESTAAUX_H_INCLUDED

class ArestaAux
{

public:

    int adjacente;
    float distancia;

    void setElementos(int ad, float dist)
    {
        adjacente = ad;
        distancia = dist;
    }

};

#endif // ARESTAAUX_H_INCLUDED
