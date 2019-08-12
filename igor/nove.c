#include <stdio.h>

float soma(int x);

int main(){
    int a;
    float res;

    scanf("%d", &a);
    res = soma(a);

    printf("%.2f\n", res);
}

float soma(int x){

    float soma = 0;
    int i,j, fat = 1;
    for(i=1; i<=x; i++){
        
        fat = 1;
        for(j=1; j<=i; j++){
            fat *= j;
        }
        soma += 1/fat;
    }

    return soma;
}
