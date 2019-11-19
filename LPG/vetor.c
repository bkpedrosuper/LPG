
// #include "struct.c"
#include <time.h>

pessoa pessoas[100];
int total = 0;

void print(char *s);
void inserir(pessoa nova);
void exibir();
void saveData(pessoa *lista);
void uploadData(pessoa *lista);
void ordena();
void printDados(pessoa printar);

void print(char *s){
    printf("%s\n", s);
}

void inserir(pessoa nova){
    srand(time(0));
    nova.id = 1001 + (rand()%4000);
    pessoas[total] = nova;
    total++;
    ordena();
}

void exibir(){
    int i;
    for (i=0; i<total; i++){
        printf("%d %s %s (%s) %s %s", pessoas[i].id,
                                      pessoas[i].nome,
                                      pessoas[i].telefone.codInternacional,
                                      pessoas[i].telefone.codArea,
                                      pessoas[i].telefone.numero,
                                      pessoas[i].email);
    }
    printf("\n");
}

void exibirTudo(){
    int i;
    for (i=0; i<total; i++){
        printDados(pessoas[i]);
        printf("\n");
    }
}

char *lowercase(char *str){
    int i;
    char *comp = (char*) malloc(strlen(str)*sizeof(char));
    strcpy(comp,str);
    for(i=0;i<strlen(str);i++){
        comp[i] = tolower(comp[i]);
    }
    return comp;
}

void ordena(){
    char aux2[100];
    for(int i=0; i<total; i++){
        int posj=i;
        for(int j=i; j<total; j++){
            if(strcoll(lowercase(pessoas[posj].nome), lowercase(pessoas[j].nome))>0){
                print(lowercase(pessoas[posj].nome));
                print(lowercase(pessoas[j].nome));//quero printar caraio
                posj = j;
            }
        }
        strcpy(aux2, pessoas[i].nome);
        strcpy(pessoas[i].nome,pessoas[posj].nome);
        strcpy(pessoas[posj].nome, aux2);
    }
    saveData(pessoas);
}

void buscaLista(char *busca){
    int i;
    for (i=0; i<total; i++){
        if(strcmp(lowercase(busca), lowercase(pessoas[i].nome))==0){
            printDados(pessoas[i]);
        }
    }
}

void printDados(pessoa printar){
    printf("Nome da Pessoa: ");
    print(printar.nome);
    printf("E-mail: ");
    print(printar.email);
    printf("\n\tEndereço\n\n");
    printf("Rua: ");
    print(printar.endereco.rua);
    printf("Numero: ");
    printf("%i", printar.endereco.numero);
    printf("Complemento: ");
    print(printar.endereco.complemento);
    printf("Bairro: ");
    print(printar.endereco.bairro);
    printf("CEP: ");
    print(printar.endereco.cep);
    printf("Cidade: ");
    print(printar.endereco.cidade);
    printf("Estado: ");
    print(printar.endereco.estado);
    printf("País: ");
    print(printar.endereco.pais);
    printf("\n\tTelvoid saveData(pessoa *lista)efone \n\n");
    printf("Código Internacional: ");
    print(printar.telefone.codInternacional);
    printf("Código de área: ");
    print(printar.telefone.codArea);
    printf("Número: ");
    print(printar.telefone.numero);
    printf("\n\tData de nascimento \n\n");
    printf("Dia: ");
    print(printar.nascimento.dia);
    printf("Mes: ");
    print(printar.nascimento.mes);
    printf("Ano: ");
    print(printar.nascimento.ano);
    printf("\n\tObservações: \n\n");
    print(printar.obs);
}

//le os dados do arquivo
void uploadData(pessoa *lista){
    FILE *save;
    int i;
    if((save=fopen("save.txt", "r+"))==NULL)  printf("Erro para carregar as informações\n");
    else{
        fread(&total,sizeof(int),1,save);
        fread(lista,sizeof(pessoa),total,save);
        // for(i=0;i<total;i++){
        //     fread(&lista[i].id, sizeof(int),1,save);
        //     fread(lista[i].nome, 103*sizeof(char),1,save);
        //     fread(lista[i].email, 103*sizeof(char),1,save);
        //     fread(lista[i].endereco.rua, 103*sizeof(char),1,save);
        //     fread(lista[i].endereco.complemento, 103*sizeof(char),1,save);
        //     fread(lista[i].endereco.bairro, 103*sizeof(char),1,save);
        //     fread(lista[i].endereco.cep, 103*sizeof(char),1,save);
        //     fread(lista[i].endereco.cidade, 103*sizeof(char),1,save);
        //     fread(lista[i].endereco.estado, 103*sizeof(char),1,save);
        //     fread(lista[i].endereco.pais, 103*sizeof(char),1,save);
        //     fread(lista[i].telefone.codInternacional, 103*sizeof(char),1,save);
        //     fread(save, 103*sizeof(char),1,save);
        //     fread(lista[i].telefone.codArea, 103*sizeof(char),1,save);
        //     fread(lista[i].nascimento.dia, 103*sizeof(char),1,save);
        //     fread(lista[i].nascimento.mes, 103*sizeof(char),1,save);
        //     fread(lista[i].nascimento.ano, 103*sizeof(char),1,save);
        //     fread(lista[i].obs, 103*sizeof(char),1,save);
        // }
        fclose(save);
    }
}

//salva os dados no arquivo
void saveData(pessoa *lista){
    FILE *save;
    int i;
    remove("save.txt");
    // if((save=fopen("save.txt", "w+"))==NULL)  printf("Erro para salvar as informações1\n");
    // else{
    //     fprintf(save,"%i",total);
    //     fwrite(lista,sizeof(pessoa),total,save);
    //     fclose(save);
    //
    // }
    // fclose(save);
}
