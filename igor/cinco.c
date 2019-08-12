#include <stdio.h>

void conv(int horas, int min, int sec);

int main(){
    int horas, min, sec;

    scanf("%d %d %d", &horas, &min, &sec);
    conv(horas,min,sec);
}

void conv(int horas, int min, int sec){
    float total = 0;

    total += horas * 3600;
    total += min * 60;
    total += sec;

    printf("em segundos %.2f s\n", total);
}
