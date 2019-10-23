#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int cont;
    struct nodo *prox;
};
typedef struct nodo nodo;

void insere (nodo *nova, nodo *anterior)
{
    nova->prox = anterior->prox;
    anterior->prox = nova;
}

int insere_ordenado(nodo *novo, nodo *raiz)
{
    int x = novo->cont;
    nodo *p;
    p = raiz;
    while (p != NULL && p->cont>x){
        p = p->prox; 
    } 
    insere(novo, p);
}

void imprima (nodo *le) {
    nodo *p;
    for (p = le->prox; p != NULL; p = p->prox)
        printf ("%d\n", p->cont);
}

int main(){
    int n=4;
    nodo *raiz = malloc(sizeof(nodo));
    raiz->prox = NULL;

    for(int i=4; i>0; i--){
        nodo *novo = (nodo *) malloc(sizeof(nodo));
        novo->cont = i;
        insere(novo,raiz);
    }
    nodo *outro = (nodo *) malloc(sizeof(nodo));
    outro->cont = 2;
    insere_ordenado(outro, raiz);
    imprima(raiz);
}