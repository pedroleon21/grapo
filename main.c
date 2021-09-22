#include <stdlib.h>
#include <stdio.h>
// vertices e nós são a mesma coisas
int *vetor_nos;
int sizeArestas = 100;
int qtdNos = 0;
char *nomeDoArquivo;

typedef struct Lista;

typedef struct registro
{
    int visitado;
    

}registro;

typedef struct No
{
    int val;
    struct List *prx;
} No;

typedef struct Lista
{
    struct No *inicio;
} Lista;

void verifica_size_vet(int a, int b)
{
    if (a >= sizeArestas || b >= sizeArestas || qtdNos >= sizeArestas)
    {
        int mem = sizeArestas;
        if (a >= sizeArestas)
        {
            sizeArestas = a + 1;
        }
        if (b >= sizeArestas)
        {
            sizeArestas = b + 1;
        }
        if (qtdNos >= sizeArestas)
        {
            sizeArestas += 101;
        }
        vetor_nos = (int *)realloc(vetor_nos, sizeArestas * sizeof(int));
        for (int i = mem; i < sizeArestas; i++)
        {
            vetor_nos[i] = 0;
        }
    }
}


void push(No * no, int index){
    
}

int main()
{
    FILE *arq;
    arq = fopen(nomeDoArquivo, "r");
    int a, b;
    vetor_nos = (int *)calloc(sizeArestas, sizeof(int));
    while (fscanf(arq, "%d:%d", &a, &b))
    {
        printf("\n A: %d , B: %d", a, b);

        //realloca o vetor se maior que o ja alocado
        verifica_size_vet(a, b);

        if (!vetor_nos[a])
        {
            qtdNos++;
            vetor_nos[a] = 1;
        }
        if (!vetor_nos[b])
        {
            qtdNos++;
            vetor_nos[b] = 1;
        }
        push(&vetor_nos[a], b);
        push(&vetor_nos[b], a);
    }
}