#include <stdio.h>

float conv(float c);

int main(){
    float c, res;

    scanf("%f", &c);
    res = conv(c);

    printf("%.2fºC em Fahrenheit é %.2fºF\n", c, res);
}

float conv(float c){
    return ((c*9)/5) + 32;
}
