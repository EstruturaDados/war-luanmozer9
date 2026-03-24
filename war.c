#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para usar a função strcspn para remover a nova linha do fgets

//definir as constantes para o programa
#define MAX_NOME 30
#define MAX_COR 10

//criar a struct para representar um território
struct territorio
{
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
};

//inicio do programa
int main ()
{
    //criar um array ou vetor de territórios com capacidade para 5 territórios
    struct territorio territorios[5];
    int i;

    for (i = 0; i < 5; i++)//coleta de dados
    {
        printf("==========================================\n");
        printf("Vamos começar cadastrando os territórios \n");
        printf("\n--------Cadastre o território %d--------- \n", i + 1);
        printf("Nome do território: ");
        fgets(territorios[i].nome, MAX_NOME, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; //remover a nova linha

        printf("Cor do território: ");
        fgets(territorios[i].cor, MAX_COR, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0'; //remover a nova linha

        printf("Número de tropas:");
        scanf("%d", &territorios[i].tropas);
        getchar(); //limpar o buffer de entrada
        printf("\n");
    }
    printf("***************\n"); //exibir o mapa do mundo atualizado
    printf("MAPA DO MUNDO - ATUALIZADO\n");
    printf("***************\n");
    for (i = 0; i < 5; i++)
    {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("\n");    
    }

    return 0;
}