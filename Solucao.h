class Solucao
{
private:



public:

    int vertice;
    float valor;
    bool visitado;
    Solucao(int vet, float val)
    {
        vertice = vet;
        valor = val;
        visitado = false;
    }
    Solucao()
    {

    }

    bool getVisitado()
    {
        return visitado;
    }

    void setVisitado()
    {
        visitado = true;
    }

    int getVertice()
    {
        return vertice;
    }

    float getValor()
    {
        return valor;
    }


};
