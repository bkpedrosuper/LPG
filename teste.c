#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
//#include "vetor.c"

void print(char *s){
    printf("%s\n", s);
}
char *lowercase(char *str){
    int i;
    char *comp = (char*) malloc(strlen(str)*sizeof(char));
    strcpy(comp,str);
    for(i=0;i<strlen(str);i++){
        comp[i] = tolower(comp[i]);
    }
    print(comp);
    return comp;
}

int n = 4;
typedef struct
{
    char nome[50];
}string;


string v[4];
void ler_string(char *s){
    scanf("%[^\n]s", s);
}

int main(void){
    srand(time(0));

    printf("%d\n", strcoll("za", "zo"));
    print(lowercase("ZAAAAAROLHO"));
    int a=01;
    int b=1;
    if(a==b)    printf("True");


    // for(int i=0; i<4; i++){
    //     scanf("%s", v[i].nome);
    // }

    // for(int i=0; i<4; i++){
    //     printf("%s\n", v[i].nome);
    // }

}
