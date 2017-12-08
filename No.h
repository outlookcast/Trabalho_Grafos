/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
class No
{

public:

    No();
    ~No();
    int getInfo();
    No* getProx();
    void setInfo(int val);
    void setProx(No *p);

private:

    int info; // informacao
    No *prox; // ponteiro para o proximo

};


#endif // NO_H_INCLUDED
