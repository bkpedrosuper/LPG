#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam=0;


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
    else insere_depois(lista, i, novo);
}
void ordena_primeiro(lista_dupla *lista, no *novo){
    char *aux[50];
    int idaux;
    no *i = lista->inicio;
    char *a=novo->nome;
    while(i != NULL){
        if(strcoll(a,i->nome)<0){
            //atualiza os nomes
            strcpy(*aux,novo->nome);
            strcpy(novo->nome, i->nome);
            strcpy(i->nome, *aux);
            
            //atualiza id
            idaux = novo->id;
            novo->id = i->id;
            i->id = idaux;
        }
        i = i->prox;
    } 
}

void insere_ordenado_nome(lista_dupla *lista, no *novo){
    // insere um nó mantendo a lista ordenada pelo nome
    no *i = lista->inicio;
    char *a=novo->nome;
    while(i != NULL && strcoll(a,i->nome)>=0) i = i->prox;
    // se n achar coloca no fim
    if(i==NULL)insere(lista, novo);
    else insere_depois(lista, i, novo);
    ordena_primeiro(lista,lista->inicio);
}

// void ordena(lista){
//     no *i=lista->inicio;
// }


no *busca_nome(lista_dupla *lista, char *c){
    no *i = lista->inicio;
    while (i != NULL && strcmp(i->nome, c)!=0) i = i->prox;
    if(i==NULL){
        printf("Não achado\n");
        return 0;
    } 
    else return i;
}

void exibe(lista_dupla *lista){
    
    //printa toda a lista
    no *i = lista->inicio;
    while(i != NULL){
        printf("%i %s\n",i->id, i->nome);
        i = i->prox;
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

void inserir(lista_dupla *lista){
    no *novo = (no *) malloc(sizeof(no));
    novo->id = tam;
    
    scanf("%s", novo->nome);
    tam++;
    insere_ordenado_nome(lista, novo);
}

int main(){
    int n=4;
    // inicialização da lista
    lista_dupla *lista = (lista_dupla *) malloc(sizeof(lista_dupla));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;    

    no *primeiro = (no *)malloc(sizeof(no));
    primeiro->id = 0;
    strcpy(primeiro->nome,"aaaa");
    insere_ordenado_nome(lista, primeiro);

    //O QUE ESTÁ DANDO ERRADO É O NO *NOVO = (NO *)... POIS ELE ESTÁ SALVANDO TODOS NO MESMO ENDEREÇO. POR ISSO QUE SÓ ORDENA UM DELES, PORQUE COLOCA ESSE COMO O UNICO E ORDENA
    // adicionando nós como ids
    for(int i=1; i<=4; i++){
        inserir(lista);
    }

    // for(int i=1; i<=4; i++){
    //     no *novo = (no *) malloc(sizeof(no));
    //     novo->id = i;
    //     scanf("%s", novo->nome);
    //     insere_ordenado_nome(lista, novo);
    // }
    exibe(lista);
    remover(lista,lista->inicio);
    printf("\n");
    exibe(lista);
    return 0;

}
