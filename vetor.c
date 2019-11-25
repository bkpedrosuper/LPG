
// #include "struct.c"
#include <time.h>

pessoa pessoas[100];
int total = 0;

void print(char *s);
void buscaMes(char *s);
void inserir(pessoa nova);
void exibir();
void ordena();
void printDados(pessoa printar);
void printParcial(pessoa print);
void uploadData(pessoa *lista);
void saveData(pessoa *lista);

void buscaMes(char *s){
    int i;
    printf("Pessoas que nasceram no mes %s:\n", s);
    for (i=0; i<total; i++){
        if(pessoas[i].nascimento.mes==s){
            printDados(pessoas[i]);
        }
    }
}

void print(char *s){
    printf("%s\n", s);
}

void inserir(pessoa nova){
    srand(time(0));
    nova.id = 1001 + (rand()%4000);
    pessoas[total] = nova;
    total++;
    ordena();
    saveData(pessoas);

}

void exibir(){

    printf("\n\t-------------Lista Telefonica:-------------\n\n");
    int i;
    for (i=0; i<total; i++){ 
        printParcial(pessoas[i]);
    }
    printf("\n");
}

void printParcial(pessoa printar){
    printf("%d %s %s (%s) %s %s\n", printar.id, 
                                    printar.nome, 
                                    printar.telefone.codInternacional, 
                                    printar.telefone.codArea, 
                                    printar.telefone.numero, 
                                    printar.email);
}

void exibirTudo(){
    int i;
    for (i=0; i<total; i++){ 
        printDados(pessoas[i]);
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
    pessoa aux2;

    for(int i=0; i<total; i++){
        int posj = i;
    
        for(int j=i; j<total; j++){
            if(strcoll(lowercase(pessoas[posj].nome), lowercase(pessoas[j].nome))>0){

                posj = j;
            }
        }
        aux2 = pessoas[i];
        pessoas[i] = pessoas[posj];
        pessoas[posj] = aux2;
    }
    saveData(pessoas);
}

int buscaLista(char *nome){
    int i,flag = 0;

    printf("\n\tPessoas achadas com esse nome:\n\n");
    for (i=0; i<total; i++){
        if(strcmp(lowercase(nome), lowercase(pessoas[i].nome))==0){
            printParcial(pessoas[i]);
            flag = 1;
        }
    }
    if (!flag){
        printf("Pessoa não encontrada nos registros!\n");
        return 0;
    }
}

void excluirPessoa(char *nome){
    int i,id_remover;
    buscaLista(nome);
    printf("Digite o id da pessoa a ser excluida\n");
    scanf("%i", &id_remover);
    
    for (i=0; i<total; i++){
        if(pessoas[i].id==id_remover){
            break;
        }
    }
    
    int j;
    total--;
    for(j=i; j<total-1; j++){
        pessoas[i] = pessoas[i+1];
    }
    saveData(pessoas);
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
    printf("\n\tTelefone \n\n");
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
    if((save=fopen("save.txt", "r"))==NULL)  printf("Erro para carregar as informações\n");
    else{
        fread(&total,sizeof(int),1,save);
        fread(lista,sizeof(pessoa),total,save);
        fclose(save);
    }
}

//salva os dados no arquivo
void saveData(pessoa *lista){
    FILE *save;
    int i;
    remove("save.txt");
    if((save=fopen("save.txt", "w"))==NULL)  printf("Erro para salvar as informações1\n");
    else{
        fwrite(&total,sizeof(int),1,save);
        fwrite(lista,total*sizeof(pessoa),total,save);
        // fprintf(save,"%i",total);
        // fwrite(lista,sizeof(pessoa),total,save);
        // fclose(save);
    }
    fclose(save);
}
