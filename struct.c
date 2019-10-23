typedef struct{
    int dia,mes,ano;
} data;

typedef struct {
    char codInternacional[3];
    char codArea[3];
    char numero[9];
}telefone;

typedef struct {
    char rua[200];
    int numero;
    char complemento[100];
    char bairro[100];
    char cep[100];
    char cidade[100];
    char estado[100];
    char pais[100];
}endereco;

typedef struct {
    char nome[100];
    char email[100];
    endereco ende;
    telefone tele;
    data nascimento;
    char obs[500];
}pessoa;
