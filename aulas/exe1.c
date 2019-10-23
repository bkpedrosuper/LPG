#include <stdio.h>

typedef struct ponto{
    int x,y;
}ponto;

int main(){

    ponto p1;
    scanf("%i",&p1.x);
    scanf("%i",&p1.y);

    ponto ver1,ver2;
    scanf("%i",&ver1.x);
    scanf("%i",&ver1.y);
    scanf("%i",&ver2.x);
    scanf("%i",&ver2.y);

    if((p1.x>=ver1.x && p1.x<=ver2.x) && (p1.y>=ver1.y && p1.y<=ver2.y)){
        printf("ta dentro\n");
        return 0;
    }
    printf("ta fora\n");


    return 0;
}