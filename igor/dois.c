#include <stdio.h>

void calendario(int dia, int mes, int ano);

int main(){
    int dia, mes, ano;

    scanf("%i %i %i", &dia, &mes, &ano);
    calendario(dia,mes,ano);

}

void calendario(int dia, int mes, int ano){
    printf("%i/%i/%i\n", dia, mes,ano);
}
