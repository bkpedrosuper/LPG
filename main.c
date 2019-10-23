#include <stdio.h>
#include <stdlib.h>
#include "struct.c"
// #include "lista_biencadeada.c"

void menu();
void inserirPessoa();
void removerPessoa();
void imprimirAgenda();
void buscarPorNome();
void imprimirMes();
void buscarDataAniversario();

int main(){

    menu();

    return 0;
}

void menu(){
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
    printf("\t5.Imprimir relatório das pessoas com aniversário no mesmo mês.\n");
    //item l
    printf("\t6.Buscar pessoa por dia e mês e imprimir os dados.\n");
    printf("\n");
    fflush(stdin);
    int res;
    scanf("%i", &res);
    switch (res) {
        case 1:
            inserirPessoa();
            break;
        case 2:
            removerPessoa();
            break;
        case 3:
            imprimirAgenda();
            break;
        case 4:
            buscarPorNome();
            break;
        case 5:
            imprimirMes();
            break;
        case 6:
            buscarDataAniversario();
        default:
            printf("\nDigite um número válido!\n\n");
            menu();
            break;
    }
}

// limpar o buffer do stdin
void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

// ler string
void ler_string(char *s){
    scanf("%[^\n]s", s);
}

void inserirPessoa(){
    pessoa nova;
    pessoa *nov = (pessoa *) malloc(sizeof(pessoa));
    flush_in();
    printf("\n\tEndereco \n\n");
    printf("Nome da Pessoa: ");
    ler_string(nov->nome);
    // printf("%s \n", nova.nome);
    flush_in();
    printf("E-mail: ");
    ler_string(nova.email);
    // printf("%s \n", nova.email);
    flush_in();
    printf("\n\tEndereco \n\n");
    printf("Rua: ");
    ler_string(nova.ende.rua);
    flush_in();
    printf("Numero: ");
    scanf("%i", &nova.ende.numero);
    flush_in();
    printf("Complemento: ");
    ler_string(nova.ende.complemento);
    flush_in();
    printf("Bairro: ");
    ler_string(nova.ende.bairro);
    flush_in();
    printf("CEP: ");
    ler_string(nova.ende.cep);
    flush_in();
    printf("Cidade: ");
    ler_string(nova.ende.cidade);
    flush_in();
    printf("Estado: ");
    ler_string(nova.ende.estado);
    flush_in();
    printf("País: ");
    ler_string(nova.ende.pais);

    printf("Essa pessoa foi adicionada com Sucesso!\n\n ");

    menu();
}

void removerPessoa(){

    menu();
}

void imprimirAgenda(){
    int i;
    // for(int i=0;i<)

    menu();
}

void buscarPorNome(){

    menu();
}

void imprimirMes(){

    menu();
}

void buscarDataAniversario(){

    menu();
}
