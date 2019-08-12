#include <stdio.h>
#include <math.h>

int pot(float a);

int main(){

    int a, res;
    scanf("%d", &a);

    res = pot(a);
    printf("%d\n",res);

    return 0;
}

int pot(float a){
    return pow(a,2);
}
