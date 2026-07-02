#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
    float salario;
}funcionario;

int menu();
void cadastro();
void listar();
void buscar();
void atualizar();
void excluir();

int main(){

    int op;

    do{
        op = menu();
        switch(op){
            case 1:{
                cadastro();
                break;
            }
            case 2:{
                listar();
                break;
            }
            case 3:{
                buscar();
                break;
            }
            case 4:{
                atualizar();
                break;
            }
            case 5:{
                excluir();            
                break;
            }
            case 6:{
                printf("\nFinalizando o Programa!!\n\n");
                break;
            }
            default:{
                printf("Opcao invalida\n");
                break;
            }
        }
    }while(op != 6);   
    
    return 0;
}

int menu(){
    int aux = 0;

    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Buscar\n");
    printf("4 - Atualizar\n");
    printf("5 - Excluir\n");
    printf("6 - Sair\n");
    printf("ESCOLHA UMA OPCAO\n");
    scanf("%d", &aux);

    return (aux);
};

void cadastro(){

    FILE *arq;
    funcionario *p;
    int num = 0, id = 0;
    float salario = 0.0;

    printf("Quantas pessoas quer cadastrar?\n");
    scanf("%d", &num);

    getchar();

    p = malloc(num * sizeof(funcionario));
    if(p == NULL){
        printf("Erro na alocacao de memoria\n");
        return;
    }
    arq = fopen("funcionarios.txt", "a");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    printf("DADOS PARA CADASTROS\n");
    for(int i=0; i<num; i++){

        printf("ID do %d funcionario\n", i+1);
        scanf("%d", &p[i].id);

        getchar();

        printf("Nome do %d funcionario\n", i+1);
        fgets(p[i].nome, 50, stdin);
        p[i].nome[strcspn(p[i].nome, "\n")] = '\0';

        printf("Salario do %d funcionario\n", i+1);
        scanf("%f", &p[i].salario);

        getchar();
    }

    for(int i=0; i<num; i++){
        fprintf(arq, "\n%d;%s;%.2f", p[i].id, p[i].nome, p[i].salario);
    }

    free(p);
    fclose(arq);
}

void listar(){
    FILE *arq;
    char linha[50];
    
    arq = fopen("funcionarios.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    while(fgets(linha, sizeof(linha), arq) != NULL){
        printf("%s", linha);
    }
    printf("\n");
    
    fclose(arq);
}

void buscar(){
    
    int op = 0;
    
    printf("Qual metodo de Busca?\n");
    printf("1 - ID\n");
    printf("2 - Nome\n");
    printf("Escolha 1 opcao\n");
    scanf("%d", &op);
    getchar();

    FILE *arq;
    arq = fopen("funcionarios.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int id;
    int encontrado = 0;
    char linha[100];
    char nome[50];
    float salario;

    switch(op){
        case 1:{

            int idProcurado;
        
            printf("Digite o Id do Funcionario\n");
            scanf("%d", &idProcurado);
            getchar();
            
            while(fgets(linha, sizeof(linha), arq) != NULL){
                    
                sscanf(linha, "%d;%[^;];%f", &id, nome, &salario);
            
                if(idProcurado == id){
                    printf("ID: %d\n", id);
                    printf("Nome: %s\n", nome);
                    printf("Salario: %.2f\n\n", salario);   
                    encontrado = 1;
                }
            }
            if(encontrado == 0){
                printf("ID NAO ENCONTRADO\n\n");
            }
            break;
        }
        case 2:{

            char nomeProcurado[50];

            printf("Digite o nome do Funcionario\n");
            fgets(nomeProcurado, 50, stdin);
            nomeProcurado[strcspn(nomeProcurado,"\n")] = '\0';

            while(fgets(linha, sizeof(linha), arq) != NULL){
                sscanf(linha, "%d;%[^;];%f", &id, nome, &salario);

                if(strcmp(nomeProcurado, nome) == 0){
                    printf("ID: %d\n", id);
                    printf("Nome: %s\n", nome);
                    printf("Salario: %.2f\n\n", salario);   
                    encontrado = 1;
                }
            }
            if(encontrado == 0){
                printf("NOME NAO ENCONTRADO\n\n");
            }
            
            break;
        }
        default:{
            printf("Opcao invalida\n");
        }
    }
    fclose(arq);
    
}

void atualizar(){
    
    int idProcurado;
    
    printf("Digite o id para atualizar\n");
    scanf("%d", &idProcurado);
    getchar();
    
    FILE *arq;
    arq = fopen("funcionarios.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    
    FILE *temp;
    temp = fopen("temp.txt", "w");
    if(temp == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    
    int encontrado = 0;
    int id;
    char nome[50];
    float salario;
    char linha[100];
    
    
    while(fgets(linha, sizeof(linha), arq) != NULL){
        sscanf(linha, "%d;%[^;];%f", &id, nome, &salario);
        
        if(idProcurado != id){
            fprintf(temp, "%d;%s;%.2f\n", id, nome, salario);    
        }
        
        else{
            encontrado = 1;
            int op;
            
            printf("Dados Atuais\n");
            printf("ID: %d\n", id);
            printf("Nome: %s\n", nome);
            printf("Salario: %.2f\n", salario);
            
            printf("O que deseja alterar?\n");
            printf("1 - Nome\n");
            printf("2 - Salario\n");
            printf("3 - Nome e Salario\n");
            scanf("%d", &op);
            getchar();
            
            switch(op){
                case 1:{
                    char novoNome[50];
                    
                    printf("Digite o Nome\n");
                    fgets(novoNome, 50, stdin);
                    novoNome[strcspn(novoNome, "\n")] = '\0';
                    
                    int i = 0;
                    while(novoNome[i] != '\0'){
                        nome[i] = novoNome[i];
                        i++;
                    }
                    nome[i] = '\0';
                    break;
                }
                case 2:{
                    float novoSalario = 0.0;
                    
                    printf("Digite o novo salario\n");
                    scanf("%f", &novoSalario);
                    
                    salario = novoSalario;
                    getchar();
                    
                    break;
                }
                case 3:{
                    char novoNome[50];
                    float novoSalario = 0.0;
                    
                    printf("Digite o Nome\n");
                    fgets(novoNome, 50, stdin);
                    novoNome[strcspn(novoNome, "\n")] = '\0';
                    
                    int i = 0;
                    while(novoNome[i] != '\0'){
                        nome[i] = novoNome[i];
                        i++;
                    }
                    nome[i] = '\0';
                    
                    printf("Digite o novo salario\n");
                    scanf("%f", &novoSalario);
                    
                    salario = novoSalario;
                                       
                    break;
                }
                default:{
                    printf("Opcao invalida\n");
                    break;
                }
            }
            fprintf(temp, "%d;%s;%.2f\n", id, nome, salario);
        }
    }
    if(encontrado != 0){
        printf("\nUsuario encontrado\n");
    }
    else{
        printf("Usuario nao encontrado\n");
    }
    
    fclose(arq);
    fclose(temp);
    
    if(remove("funcionarios.txt") != 0){
        printf("Erro na Remocao\n");
    }
    if(rename("temp.txt", "funcionarios.txt") != 0){
        printf("Erro na Renomeacao\n");
    }
    return;
}

void excluir(){
    
    int idProcurado = 0;
    int encontrado = 1;
    char linha[100];
    
    FILE *arq;
    arq = fopen("funcionarios.txt", "r");
    
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    
    FILE *temp;
    temp = fopen("temp.txt", "w");
    if(temp == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    
    printf("Digite o id da pessoa\n");
    scanf("%d", &idProcurado);
    getchar();
    
    int id;
    char nome[50];
    float salario;
    
    while(fgets(linha, sizeof(linha), arq) != NULL){
        sscanf(linha, "%d;%[^;];%f", &id, nome, &salario);
        
        if(idProcurado == id){
            encontrado = 0;
        }
        else{
            fprintf(temp, "%d;%s;%.2f\n", id, nome, salario);
        }
    }
    if(encontrado == 0){
        printf("Usuario encontrado e removido\n");
    }
    else{
        printf("Usuario nao encontrado\n");
    }
    
    fclose(arq);
    fclose (temp);
    
    if(remove("funcionarios.txt") != 0){
        printf("Erro ao remover\n");
        return;
    }
    
    if(rename("temp.txt", "funcionarios.txt") != 0){
        printf("Erro ao renomear\n");
        return;
    }
    
    return;
}