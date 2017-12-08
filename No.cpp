/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#include"No.h"

No::No() { }

No::~No() { }

int No::getInfo()
{

return info;

}

No* No::getProx()
{

return prox;

}

void No::setInfo(int val)
{

info = val;

}

void No::setProx(No *p)
{

prox = p;

}
