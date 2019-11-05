#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct.c"
#include "vetor.c"

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
            exit(0);
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

    flush_in();
    printf("Nome da Pessoa: ");
    ler_string(nova.nome);
    // print(nova.nome);
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
    ler_string(nova.telefone.numero);
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

    inserir(nova);

    printf("\n\t--------Pessoa adicionada com sucesso--------\n\n");

    menu();
}

void removerPessoa(){
    char nome[100];
    flush_in();
    printf("Nome da pessoa a ser excluida da lista: ");
    ler_string(nome);
    excluirPessoa(nome);

    menu();
}

void imprimirAgenda(){
    printf("\nImprimir:");
    printf("\n\t1. Nome, Telefone e E-mail");
    printf("\n\t2. Todos os dados\n\n");
    int n;
    flush_in();
    scanf("%i",&n);
    switch (n)
    {
    case 1:
        exibir();
        break;
    case 2:
        exibirTudo();
        break;

    default:
        break;
    }
    printf("Aperte enter para outra operação.\n");
    flush_in();
    getchar();

    menu();
}

void buscarPorNome(){
    printf("Digite o nome q deseja buscar na lista: ");
    flush_in();
    char busca[100];
    ler_string(busca);
    buscaLista(busca);

    menu();
}

void imprimirMes(){
    printf("Digite o mês que quer imprimir o relatório de aniversariantes: ");
    flush_in();
    char n[4];
    ler_string(n);

    menu();
}

void buscarDataAniversario(){
    printf("Digite a data de aniversário a ser pesquisada: ");
    flush_in();
    char dia[4], mes[4], ano[4];
    printf("Dia: ");
    flush_in();
    ler_string(dia);
    printf("Mes: ");
    flush_in();
    ler_string(mes);
    printf("Ano: ");
    flush_in();
    ler_string(ano);

    menu();
}