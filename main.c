#include <stdio.h>
#include <stdlib.h>
#include "struct.c"

void menu();
void inserirPessoa();
void removerPessoa();
void imprimirAgenda();
void buscarPorNome();
void imprimirMes();
void buscarDataAniversario();

pessoa pessoas[100];

int main(){

    menu();

    return 0;
}

void menu(){    
    printf("\nEscolha a ação desejada:\n\n");
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

void print(char *s){
    printf("%s\n", s);
}

void inserirPessoa(){

    pessoa nova;

    flush_in();
    printf("Nome da Pessoa: ");
    ler_string(nova.nome);
    print(nova.nome);
    flush_in();
    printf("E-mail: ");
    ler_string(nova.email);
    // print(nova.email);
    flush_in();
    printf("\n\tEndereço\n\n");
    printf("Rua: ");
    ler_string(nova.endereco.rua);
    flush_in();
    printf("Numero: ");
    scanf("%i", &nova.endereco.numero);
    flush_in();
    printf("Complemento: ");
    ler_string(nova.endereco.complemento);
    flush_in();
    printf("Bairro: ");
    ler_string(nova.endereco.bairro);
    flush_in();
    printf("CEP: ");
    ler_string(nova.endereco.cep);
    flush_in();
    printf("Cidade: ");
    ler_string(nova.endereco.cidade);
    flush_in();
    printf("Estado: ");
    ler_string(nova.endereco.estado);
    flush_in();
    printf("País: ");
    ler_string(nova.endereco.pais);
    flush_in();
    printf("\n\tTelefone \n\n");
    printf("Código Internacional: ");
    ler_string(nova.telefone.codInternacional);
    flush_in();
    printf("Código de área: ");
    ler_string(nova.telefone.codArea);
    flush_in();
    printf("Número: ");
    flush_in();
    printf("\n\tData de nascimento \n\n");
    printf("Dia: ");
    ler_string(nova.nascimento.dia);
    flush_in();
    printf("Mes: ");
    ler_string(nova.nascimento.mes);
    flush_in();
    printf("Ano: ");
    ler_string(nova.nascimento.ano);
    flush_in();
    printf("\n\tObservações: \n\n");
    ler_string(nova.obs);

    printf("\n\tPessoa adicionada com sucesso--------\n\n");

    menu();
}

void removerPessoa(){
    char nome[100];
    flush_in();
    printf("Nome da pessoa a ser excluida da lista: ");
    ler_string(nome);

}

void imprimirAgenda(){

}

void buscarPorNome(){

}

void imprimirMes(){

}

void buscarDataAniversario(){

}