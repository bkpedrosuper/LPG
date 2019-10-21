#include <stdio.h>
#include <stdlib.h>

void menu();
void inserir();
void remover();
void imprimir();
void buscar();
void imprimirMes();
void buscarDiaMes();

struct data {
    int dia,mes,ano;
};
typedef struct data data;

typedef struct telefone {
    char codInternacional[3];
    char codArea[3];
    char numero[9];
};
typedef struct telefone telefone;

typedef struct endereco {
    char rua[200];
    int numero;
    char complemento[100];
    char bairro[100];
    int cep[100];
    char cidade[100];
};
typedef struct endereco endereco;

struct pessoa {
    char nome[100];
    char email[100];
    endereco ende;
    telefone tele;
    data nascimento;
    char obs[500];
};
typedef struct pessoa pessoa;

pessoa pessoas[100];

int main(){


    menu();

    // scanf("%[A-Z a-z]s", pessoas[0].nome);
    // printf("%s\n", pessoas[0].nome);

    return 0;
}

void menu(){

    int res=0;
    printf("Escolha a ação desejada:\n\n");
    //item g
    printf("\t1.Inserir Pessoa.\n");
    //item h
    printf("\t2.Remover Pessoa.\n");
    //item i
    printf("\t3.Imprimir agenda.\n");
    //item j
    printf("\t4.Buscar pessoa por primeiro nome e imprimir os dados.\n");
    //item k
    printf("\t4.Imprimir relatório das pessoas com aniversário no mesmo mês.\n");
    //item l
    printf("\t4.Buscar pessoa por dia e mês e imprimir os dados.\n");
    printf("\n");
    scanf("%i", &res);

}

void inserir(){
    
}
