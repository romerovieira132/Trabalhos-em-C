#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
  char nome[50];
  int nota1[10];
  int nota2[10];
} aluno;

void menu();
void incluir();
void excluir();
aluno pesquisar();
void relatorio(); 

aluno *boletim;
int qtd = 0;
int tam = 10;

int main(void) {
  setlocale(LC_ALL,"portuguese");
  boletim = (aluno *)malloc(tam * sizeof(aluno));
  int op;
  while(1){
    menu(&op);
    if (op == 1){
      incluir();
    } else if (op == 2){
      excluir();
    } else if (op == 3){
        pesquisar();   
    } else if (op == 4){
      relatorio();
    }  else if (op == 5) {
        printf("Obrigado por usar nosso codigo.\n");
        printf("Até a próxima pessoal...");
        break;
    }
    }
  free(boletim);
  return 0;
}

void menu(int *saida){
    printf(
    "Escolha uma opção:\n"
    "1 - Incluir\n"
    "2 - excluir\n"
    "3 - pesquisar\n"
    "4 - relatorio\n"
    "5 - Sair\n"
    );
    scanf("%d", saida);
}

void incluir(){
  aluno a;
  printf("Digite o nome: ");
  scanf("%s", a.nome);
  printf("Digite a nota 1: ");
  scanf("%d", a.nota1);
  printf("Digite a nota 2: ");
  scanf("%d", a.nota2);
  boletim[qtd] = a;
  qtd++;
  printf("Contato inserido com sucesso!\n");
}

aluno pesquisar(){
    int saida;
  for(int i = 0; i < qtd; i++){
    printf("%d Nome: %s\n", i, boletim[i].nome);
  }
  printf("Escolha o aluno: ");
  scanf("%d", &saida);
    printf("Nome: %s\n", boletim[saida].nome);
    printf("Nota 1: %d\n", *boletim[saida].nota1);
    printf("Nota 2: %d\n", *boletim[saida].nota2);
    return boletim[saida];
}

void relatorio(){
  for(int i = 0; i < qtd; i++){
    printf("Aluno %d\n", i+1);
    printf("Nome: %s\n", boletim[i].nome);
    printf("Nota 1: %d\n", *boletim[i].nota1);
    printf("Nota 2: %d\n", *boletim[i].nota2);
    double media = (*boletim[i].nota1 + *boletim[i].nota2)/2;
    printf("%f\n", media);
    if (media >= 6) {
                printf("%s aprovado \n\n", boletim[i].nome);
            } else if (media < 6 && media >= 4) {
                printf("%s em recuperação \n\n", boletim[i].nome); 
            } else if (media < 4 && media > 0) {
                printf("%s reprovado \n\n", boletim[i].nome);
            } else if (media == 0) {
                printf("\n");
            }
  }
  printf("\n");
}

void excluir(){
int saida;
  for(int i = 0; i < qtd; i++){
    printf("%d Nome: %s\n", i, boletim[i].nome);
  }
  printf("Escolha um aluno para excluir da lista: ");
  scanf("%d", &saida);
    printf("Aluno excluido");
    *boletim[saida].nome = 0;
    *boletim[saida].nota1 = 0;
    *boletim[saida].nota2 = 0;
}





