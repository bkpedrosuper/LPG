#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int dia,mes,ano;
}data;

typedef struct telefone {
    char codInternacional[3];
    char codArea[3];
    char numero[9];
}telefone;

typedef struct endereco {
    char rua[200];
    int numero;
    char complemento[100];
    char bairro[100];
    int cep[100];
    char cidade[100];
}endereco;

typedef struct pessoa {
    char nome[100];
    char email[100];
    endereco ende;
    telefone tele;
    data nascimento;
    char obs[500];
}pessoa;

#define teste 1000

int main(){

    pessoa pessoas[100];

    // scanf("%[A-Z a-z]s", pessoas[0].nome);
    // printf("%s\n", pessoas[0].nome);

    return 0;
}
