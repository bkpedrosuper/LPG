#include <stdio.h>
#include <stdlib.h>

// estrutura do nó guardando os dados, o nó anterior e o próximo nó da lista
struct nodo {
    int id;
    char nome[10];
    struct nodo *prox;
    struct nodo *ant;
};
typedef struct nodo no;

// estrutura da lista
struct ListaDuplaEncadeada {
    no *inicio;
    no *fim;
    int tamanho;
};
typedef struct ListaDuplaEncadeada lista_dupla;


void insere(lista_dupla *lista, no *novo)
{
    // função q insere um novo dado
    if(lista->tamanho==0){    // se a lista estiver vazia inicia
        lista->inicio = novo;
        lista->fim = novo;
        lista->tamanho++;
    }else{                    // se nao adiciona no fim
        novo->prox = NULL;
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->tamanho++;
    }
}

void insere_depois(lista_dupla *lista, no *antes, no *novo)
{
    // insere o nó novo depois de um determinado nó "antes"
    if(antes==lista->fim) insere(lista, novo); // se este nó for o fim da lista adiciona no fim
    else{
        novo->prox = antes->prox;
        novo->ant = antes;
        antes->prox->ant = novo;
        antes->prox = novo;
        lista->tamanho++;
    }
}

void insere_ordenado(lista_dupla *lista, no *novo){
    // insere um nó mantendo a lista ordenada
    no *i = lista->inicio;
    int x = novo->id;
    // while roda até achar o lugar pra colocar o novo nó
    while(i != NULL  && i->id<x ) i = i->prox;
    // se n achar coloca no fim
    insere_depois(lista, i, novo);
}

void exibe(lista_dupla *lista){
    //printa toda a lista
    no *i = lista->inicio;
    printf("[ ");
    while(i != NULL){
        printf("%i ",i->id);
        i = i->prox;
    }
    printf("]\n");
}

void remover(lista_dupla *lista, no *remover){
    no *no_removido;
    if(remover==lista->inicio){ // remover primeiro nó
        no_removido = lista->inicio;
        lista->inicio = lista->inicio->prox;
        lista->inicio->ant = NULL;
    }else
    if(remover==lista->fim){   // remover ultimo nó
        no_removido = lista->fim;
        lista->fim->ant->prox = NULL;
        lista->fim = lista->fim->ant;
    }else{
        no_removido = remover;
        remover->ant->prox = remover->prox;
        remover->prox->ant = remover->ant;
    }
    free(no_removido);
    lista->tamanho--;
}

int main(){
    int n=4;
    // inicialização da lista
    lista_dupla *lista = (lista_dupla *) malloc(sizeof(lista_dupla));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    no *guarda = (no *) malloc(sizeof(no));
    // adicionando nós como ids
    for(int i=4; i>0; i--){
        no *novo = (no *) malloc(sizeof(no));
        novo->id = i;
        insere_ordenado(lista, novo);
    }

    printf("\n");
    exibe(lista);
}