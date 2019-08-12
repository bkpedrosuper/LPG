#include <stdio.h>

int conv(int horas, int min, int sec);

int main(){
    int res,horas, min, sec;

    scanf("%d %d %d", &horas, &min, &sec);
    res = conv(horas,min,sec);

    printf("em segundos %d s\n", res);
}

int conv(int horas, int min, int sec){
    int total = 0;

    total += horas * 3600;
    total += min * 60;
    total += sec;

    return total;
}
