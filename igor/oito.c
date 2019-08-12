#include <stdio.h>

int media(float nota1,float nota2, float nota3, char tipo);

int main(){
    float res, nota1, nota2, nota3;
    char tipo;

    scanf("%f %f %f %c", &nota1, &nota2, &nota3, &tipo);
    res = media(nota1, nota2, nota3, tipo);

    if (tipo=='A'){
        printf("a meida aritmetica é %.2f\n", res);
    }
    if (tipo=='P'){
        printf("a media ponderada é %.2f\n", res);
    }

}

int media(float nota1,float nota2, float nota3, char tipo){

    float media;
    if (tipo=='A'){
        return (nota1+nota2+nota3)/3;
    }
    if (tipo=='P'){
        return (nota1*5+nota2*3+nota3*2)/10;
    }

}
