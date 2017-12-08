/*
- - - - - - - GRUPO 6 - - - - - - -
ALmir, Igor e Vinicius
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Grafo.h"
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
using namespace std;

void leArquivo2(char * name, Grafo * a)
{
    FILE * arquivo;
    arquivo = fopen(name,"r");
    if(arquivo == NULL)
    {
        cout<<"Erro, não foi possível abrir o arquivo!"<<endl;
	exit(1);
    }
    else
    {
        cout<<"Lendo instância de "<<name<<endl;

        char frase[999];
        char tipo;
        int no1,no2;
        float dist;
        while( (fscanf(arquivo,"%c %d %d %f\n", &tipo, &no1, &no2,&dist))!=EOF )
        {
            if(tipo=='E')
            {
                a->insere(no1,no2,dist);
            }
            else if(tipo=='T')
            {
                a->setaVerticeTeminal(no1);
            }
        }



        fclose(arquivo);
    }
}



void leArquivo(char * nomeDoArquivo, Grafo * a)
{
    string linha;
    ifstream instancia (nomeDoArquivo);
    cout<<"Lendo de "<<nomeDoArquivo<<endl;
    if(instancia.is_open()==false)
    {
        cout<<"Nao foi possivel abrir o arquivo!"<<endl;
        exit(1);
    }
    else
    {
        getline(instancia,linha);
        while (! instancia.eof() )
        {
            stringstream dados;
            getline(instancia,linha);
            int num1,num2;
            float num3=1;
            dados<<linha;
            dados >> num1 >> num2 >> num3;
            if(linha.size()!=0)
            {
                a->insere(num1, num2, num3);
            }
        }
        instancia.close();
    }
}



int main(int num,char ** args)
{

    if(num!=3)
    {
        cout<<"Numero de argumentos errado!";
        exit(3);
    }
    cout<<"- - - - - - - GRUPO 6 - - - - - - - "<<endl;
    cout<<"Almir, Igor e Vinicius"<<endl;
    Grafo * a = new Grafo(false);
    leArquivo2(args[1],a);
    int opcao;
    cout<<endl;
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout<<"0 - Imprimir grafo (extra)"<<endl;
    cout<<"1 - Adicionar vertice"<<endl;
    cout<<"2 - Adicionar aresta"<<endl;
    cout<<"3 - Remover vertice"<<endl;
    cout<<"4 - Remover aresta"<<endl;
    cout<<"5 - Retornar o grau de um vertice dado"<<endl;
    cout<<"6 - Verificar K-regularidade do grafo"<<endl;
    cout<<"7 - Informar a ordem do grafo"<<endl;
    cout<<"8 - Informar se o grafo e trivial"<<endl;
    cout<<"9 - Informar se o grafo e nulo"<<endl;
    cout<<"10 - Mostrar vizinhança aberta de um vertice"<<endl;
    cout<<"11 - Mostrar a vizinhança fechada de um vertice"<<endl;
    cout<<"12 - Verificar se o grafo é completo"<<endl;
    cout<<"13 - Verificar se o grafo é bipartido"<<endl;
    cout<<"14 - Dijkstra"<<endl;
    cout<<"15 - Floyd"<<endl;
    cout<<"16 - Grau do grafo"<<endl;
    cout<<"17 - Fecho transitivo direto de um vertice"<<endl;
    cout<<"18 - Fecho transitivo indireto de um vertice"<<endl;
    cout<<"19 - Apresentar sequencia de graus"<<endl;
    cout<<"20 - Subgrafo induzido por um conjuto de vertices informados"<<endl;
    cout<<"21 - Apresentar grafo complementar"<<endl;
    cout<<"22 - Numero de componentes conexas."<<endl;
    cout<<"23 - Apresentar vertices de articulaçao"<<endl;
    cout<<"24 - Apresentar arestas de ponte"<<endl;
    cout<<"25 - Raio, diametro, centro e periferia do grafo"<<endl;
    cout<<"26 - AGM"<<endl;
    cout<<"27 - Arvore de busca em profundidade"<<endl;
    cout<<"28 - Arvore de busca em largura"<<endl;
    cout<<"29 - Salvar arquivo txt no formato do GRAPHVIZ (extra)"<<endl;
    cout<<"30 - Verificar se o grafo e euleriano"<<endl;
    cout<<"31 - Obter o grafo reverso"<<endl;
    cout<<"32 - Obter o grafo subjacente"<<endl;
    cout<<"33 - Gerar imagem e abrir automatico (FUNCIONA SOMENTE EM AMBIENTE LINUX COM GRAPHVIZ INSTALADO)"<<endl;
    cout<<"34 - CÓPIA DO GRAFO (extra)"<<endl;
    cout<<"35 - Arvore de Steiner(Guloso)"<<endl;
    cout<<"36 - Arvore de Steiner(Randomizado)"<<endl;
    cout<<"37 - Arvore de Steiner(Reativo)"<<endl;
    cout<<"38 - Imprime vertices terminais"<<endl;
    cout<<"Obs: Se deseja finalizar, digite um valor diferente das opcoes!"<<endl;
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout<<endl;
    cout<<"Digite sua opcao: ";
    cin>>opcao;
    cout<<endl;

    do
    {
        if(opcao==0)
        {
            cout<<"Imprimindo grafo: "<<endl;
            a->imprimeGrafo();
        }
        else if(opcao==1)
        {
            cout<<"Digite o valor do vertice que deseja adicinar: ";
            int vertice;
            cin>>vertice;
            a->insereVertice(vertice);
        }
        else if(opcao==2)
        {
            cout<<"Digite o valor dos dois vertices e da distancia entre eles: "<<endl;
            int vertice1,vertice2;
            float dist;
            cout<<"Vertice 1: ";
            cin>>vertice1;
            cout<<"Vertice 2: ";
            cin>>vertice2;
            cout<<"Distancia: ";
            cin>>dist;
            a->insere(vertice1,vertice2,dist);
        }
        else if(opcao==3)
        {
            cout<<"Digite o vertice que deseja remover: ";
            int vertice;
            cin>>vertice;
            a->removeVertice(vertice);
        }
        else if(opcao==4)
        {
            cout<<"Digite os dois vertices que deseja remover aresta entre eles"<<endl;
            cout<<"Vertice 1: ";
            int vertice1,vertice2;
            cin>>vertice1;
            cout<<"Vertice 2: ";
            cin>>vertice2;
            a->excluiAresta(vertice1,vertice2);
        }
        else if(opcao==5)
        {
            cout<<"Digite o valor do vertice que deseja saber seu grau: ";
            int vertice;
            cin>>vertice;
            a->getGrauDeUmVertice(vertice);
        }
        else if(opcao==6)
        {
            cout<<"Digite o valor de K para verificar a K-regularidade do grafo: ";
            int k;
            cin>>k;
            cout<<" O grafo e "<<k<<"-regular? : "<<a->verificaKRegularidade(k)<<endl;
        }
        else if(opcao==7)
        {
            cout<<"Ordem do grafo: "<<a->getOrdem()<<endl;
        }
        else if(opcao==8)
        {
            cout<<"O grafo e trivial? : "<<a->verificaTrivial()<<endl;
        }
        else if(opcao==9)
        {
            cout<<"O grafo e nulo? : "<<a->verificaGrafoNulo()<<endl;
        }
        else if(opcao==10)
        {
            cout<<"Digite o valor do vertice que deseja verificar a vizinhança aberta: ";
            int vertice;
            cin>>vertice;
            cout<<"Vizinhança aberta: ";
            a->vizinhancaAberta(vertice);
            cout<<endl;
        }
        else if(opcao==11)
        {
            cout<<"Digite o valor do vertice que deseja verificar a vizinhança fechada: ";
            int vertice;
            cin>>vertice;
            cout<<"Vizinhança aberta: ";
            a->vizinhancaFechada(vertice);
            cout<<endl;
        }
        else if(opcao==12)
        {
            cout<<"O grafo e completo? : "<<a->verificaGrafoCompleto()<<endl;
        }
        else if(opcao==13)
        {
            cout<<"O grafo e bipartido? : "<<a->bipartido()<<endl;
        }
        else if(opcao==14)
        {
            cout<<"Digite o valor dos dois vertices para encontrar o menor caminho entre os dois!"<<endl;
            cout<<"Vertice 1: ";
            int vertice1,vertice2;
            cin>>vertice1;
            cout<<"Vertice 2: ";
            cin>>vertice2;
            a->dijkstra(vertice1,vertice2);
        }
        else if(opcao==15)
        {
            cout<<"Matriz de floyd: "<<endl;
            MatrizLin * mat = a->floyd();
            mat->imprime();
            delete mat;
        }
        else if(opcao==16)
        {
            cout<<"Grau do grafo: "<<a->getGrau()<<endl;
        }
        else if(opcao==17)
        {
            cout<<"Digite o valor do vertice no qual deseja o fecho transitivo direto: ";
            int vertice;
            cin>>vertice;
            a->fechoTransitivoDireto(vertice);
        }
        else if(opcao==18)
        {
            cout<<"Digite o valor do vertice no qual deseja o fecho transitivo indireto: ";
            int vertice;
            cin>>vertice;
            a->fechoTransitivoIndireto(vertice);
        }
        else if(opcao==19)
        {
            cout<<"Sequencia de graus do grafo: "<<endl;
            a->imprimeSequencia();
        }
        else if(opcao==20)
        {
            cout<<"Digite o numero de vertices que deseja: "<<endl;
            int num;
            cin>>num;
            int * vet = new int[num];
            for(int i=0; i<num; i++)
            {
                cout<<"Digite o vertice["<<i<<"]=";
                cin>>vet[i];
            }
            Grafo * b = a->subgrafoInduzido(vet,num);
            if(b != NULL)
            {
                b->imprimeGrafo();
                delete b;
            }

            delete []vet;
        }
        else if(opcao==21)
        {
            Grafo * b = a->retornaComplementar();  ///VERIFICAR ESSA FUNÇÃO, PARECE QUE APRESENTA ERRO!
            cout<<"O grafo complementar e: "<<endl;
            b->imprimeGrafo();
            delete b;
        }
        else if(opcao==22)
        {
            cout<<"Num componentes: "<<a->numComponenteConexa()<<endl;
        }
        else if(opcao==23)
        {
            cout<<"Vertices de articulacao: "<<endl;
            a->verticeArticulacao();
            cout<<endl;
        }
        else if(opcao==24)
        {
            cout<<"Arestas ponte: ";
            a->arestaPonte();
        }
        else if(opcao==25)
        {
            cout<<"Raio, diametro, centro e periferia do grafo: "<<endl;
            a->raioDiametroCentroPeriferia();
        }
        else if(opcao==26)
        {
            cout<<"AGM :"<<endl;
            Grafo * b = a->Agm();
            cout<<"Peso: "<<b->getPesoAGM()<<endl;
            b->imprimeGrafo();
            delete b;
        }
        else if(opcao==27)
        {
            cout<<"Digite o vertice inicial:"<<endl;
            int vert;
            cin>>vert;
            cout<<"Arvore de busca e profundidade: "<<endl;
            Grafo * b = a->buscaProfundidade(vert);
            b->imprimeGrafo();
            delete b;
        }
        else if(opcao==28)
        {
            cout<<"Digite o vertice inicial:"<<endl;
            int vert;
            cin>>vert;

            cout<<"Arvore de busca e largura: "<<endl;
            Grafo * b = a->buscaLargura(vert);
            b->imprimeGrafo();
            delete b;
        }
        else if(opcao==29)
        {
            cout<<"Digite o nome do arquivo (com .txt) em que deseja salvar o arquivo do GRAPHVIZ: ";
            char nome[999];
            cin>>nome;
            a->graphviz(nome);
        }
        else if(opcao==30)
        {
            cout<<"O grafo e euleriano? : "<<a->euleriano()<<endl;
        }
        else if(opcao==31)
        {
            cout<<"Grafo reverso: "<<endl;
            Grafo * grafoReverso = a->grafoReverso();
            grafoReverso->imprimeGrafo();
            delete grafoReverso;
        }
        else if(opcao==32)
        {
            cout<<"Grafo subjacente: "<<endl;
            Grafo * grafoSub = a->subjacente();
            grafoSub->imprimeGrafo();
            delete grafoSub;
        }
        else if(opcao==33)
        {
            cout<<"Executando.."<<endl;
            a->graphviz("img.dot");
            system("dot -Tpng img.dot -o img.png && xdg-open img.png");
        }
        else if(opcao==34)
        {
            cout<<"Copia do grafo:"<<endl;
            Grafo * copia = a->copiaGrafo();
            copia->imprimeGrafo();
            delete copia;
        }
        else if(opcao==35)
        {
            cout<<"Arvore de Steiner(Guloso)\n";
            Grafo * arv = a->arvoreDeSteiner();
            cout<<"Peso: "<<arv->getPesoAGM();
            arv->salvar(args[2]);

            delete arv;

        }

        else if(opcao == 37)
        {
            float alfa;
            Grafo* reativo = a->reativo(&alfa);
            cout<<"Peso: "<<reativo->getPesoAGM()<<endl;
            cout<<"Melhor alfa: "<<alfa<<endl;

            FILE *arquivo = fopen("reativoResultado.txt", "w");
            fprintf(arquivo, "Alfa = %f \nPeso = %f", alfa, reativo->getPesoAGM());
            fclose(arquivo);

            reativo->salvar(args[2]);
            delete reativo;
        }
        else if(opcao==38)
        {
            a->imprimeVerticesTerminais();

        }
        else if(opcao == 36)
        {
            float alfa;

            cout<<"Digite o alfa:"<<endl;
            cin>>alfa;

            while(!(alfa >= 0 && alfa <= 1))
            {
                cout<<"Digite novamente:\n";
                cin>>alfa;
            }

            Grafo *melhor = a->randomizado(alfa, true);
            cout<<"Peso da melhor solucao: "<< melhor->getPesoAGM()<<endl;
            melhor->salvar(args[2]);

            delete melhor;
        }
        cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
        cout<<"Digite sua opcao: ";
        cin>>opcao;
    }while(opcao>=0&&opcao<=38);
    cout<<"Saindo do menu..."<<endl;
    delete a;

    return 0;
}
