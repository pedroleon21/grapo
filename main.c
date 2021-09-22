#include <stdlib.h>
#include <stdio.h>
// vertices e nós são a mesma coisas

int *vetor_nos;

int sizeArestas = 100;
int qtdNos = 0;
char *nomeDoArquivo;

typedef struct No
{
    int val;
    struct List *prx;
} No;

typedef struct Lista
{
    struct No *inicio;
} Lista;

typedef struct Registro
{
    int visitado;
    struct Lista *lista;

} Registro;
Registro *registros;
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
            sizeArestas += (qtdNos - sizeArestas) + 100;
        }

        vetor_nos = (int *)realloc(vetor_nos, sizeArestas * sizeof(int));
        registros = (Registro *)realloc(registros, sizeArestas * sizeof(Registro));
        for (int i = mem; i < sizeArestas; i++)
        {
            registros[i].visitado = 0;
            registros[i].lista = 0;
            vetor_nos[i] = 0;
        }
    }
}

No *novoNo(int valor)
{
    No *no = (No *)calloc(1, sizeof(No));
    no->val = valor;
    return no;
}

Lista *NovaLista()
{
    return (Lista *)calloc(1, sizeof(Lista));
}

void inserir_ordenado(Lista *lista, int valor)
{
    if (lista->inicio)
    {
        No *no = lista->inicio;
        if (no->val > valor)
        {
            lista->inicio = novoNo(valor);
            No *temp = lista->inicio;
            temp->prx = no;
        }
        else
        {
            while (no->prx && no->val > valor)
            {
                no = no->prx;
            }
            No *temp = no->prx;
            no->prx = novoNo(valor);
            no = no->prx;
            no->prx = temp;
        }
    }
    else
    {
        lista->inicio = novoNo(valor);
    }
}

void push(Registro * registro, int index)
{
    if (!registro->lista)
    {
        registro->lista = NovaLista();
    }
    inserir_ordenado(registro->lista, index);
}

int main()
{
    int a, b, v;
    registros = (Registro *)calloc(sizeArestas, sizeof(Registro));
    vetor_nos = (int *)realloc(vetor_nos, sizeArestas * sizeof(int));
    scanf("%d", &v);
    for (int i = 0; i < v; i++)
    {
        scanf("%d:%d", &a, &b);
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
        push(&registros[a], b);
        push(&registros[b], a);
    }
    return 0;
}