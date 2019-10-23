#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(){
    printf("ola caralho\n");
}

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
    if(antes->prox==NULL) insere(lista, novo); // se este nó for o fim da lista adiciona no fim
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
    while(i != NULL && i->id<x) i = i->prox;
    // se n achar coloca no fim
    if(i==NULL)insere(lista, novo);
    else insere_depois(listissoa, i, novo);
}

void insere_ordenado_nome(lista_dupla *lista,no *novo){
    // insere um nó mantendo a lista ordenada
    no *i = lista->inicio;
    char *a=novo->nome;
    while(i != NULL && strcmp(a,i->nome)>0) i = i->prox;

}


void buscar_nome(lista_dupla *lista, char *c){
    no *i = lista->inicio;
    while (i != NULL && strcmp(i->nome, c)!=0) i = i->prox;
    if(i==NULL) printf("Não achado\n");
    else printf("id com o nome buscado: %i\n", i->id);
}

void exibe(lista_dupla *lista){
    //printa toda a lista
    no *i = lista->inicio;
    while(i != NULL){
        printf("%i %s\n",i->id, i->nome);
        i = i->prox;isso
    }
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
    lista_dupla *lista = (llistaista_dupla *) malloc(sizeof(lista_dupla));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    no *guarda = (no *) malloc(sizeof(no));
    // adicionando nós como ids
    for(int i=1; i<=4; i++){
        no *novo = (no *) malloc(sizeof(no));
        novo->id = i;
        scanf("%s", novo->nome);
        insere(lista, novo);
    }
    exibe(lista);

    no *outro = (no *) malloc(sizeof(no));
    outro->id = 9;
    //outro->
    char nomezi[10];
    scanf("%s", nomezi);
    buscar_nome(lista,nomezi);
    exibe(lista);

}
