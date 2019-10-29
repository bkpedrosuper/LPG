#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
}string;

string v[4];

int main(void){
    // char nome1[10]="bb";
    // char nome2[10]="aa";
    // printf("%d\n", strcoll("aa","zz"));


    for(int i=0; i<4; i++){
        scanf("%s", v[i].nome);
    }

    // ta funcionando o select sort
    for(int i=0; i<4; i++){
        int posj=i;
        for(int j=i; j<4; j++){
            if(strcoll(v[posj].nome, v[j].nome)>0){
                posj = j;
            }    
        }
        string aux2;
        strcpy(aux2.nome, v[i].nome);
        strcpy(v[i].nome,v[posj].nome);
        strcpy(v[posj].nome, aux2.nome);
    }

    for(int i=0; i<4; i++){
        printf("%s\n", v[i].nome);
    }

}
