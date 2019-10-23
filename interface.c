#include "main.c"

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
