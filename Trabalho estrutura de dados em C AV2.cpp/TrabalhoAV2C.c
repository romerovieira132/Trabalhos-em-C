#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubbleSort(int *arra, int tam);
void selectionSort(int *arra, int tam);
void insertionSort(int *arra, int tam);
void menu(int *saida);
void arvorePrint();
void arvoreFree();

struct item{
    int cod;
};

typedef struct item Item;

struct no {
    Item item;
    struct no *esquerda;
    struct no *direita;
};

typedef struct no No;

No *arvoreInicializar(){
    return NULL;
}

Item itemCriador(int cod){
    Item item;
    item.cod = cod;
    return item;
}

No *arvoreInserir(No *raiz, Item x){
    if (raiz == NULL ) {
        No *aux = (No *)malloc(sizeof(No));
        aux -> item = x;
        aux -> esquerda = NULL;
        aux -> direita = NULL;
        return aux;
    } else {
        if (x.cod > raiz -> item.cod){
            raiz -> direita = arvoreInserir(raiz -> direita, x);
        } else if(x.cod < raiz -> item.cod) {
            raiz -> esquerda = arvoreInserir(raiz -> esquerda, x);
        }
    }
    return raiz;
}
void arvorePrint(No *raiz){
    if (raiz != NULL){
        printf("%d", raiz -> item.cod);
        arvorePrint(raiz -> esquerda);
        arvorePrint(raiz -> direita);    
    }
}

void arvoreFree(No *raiz){
    if (raiz != NULL){
        arvoreFree(raiz -> esquerda);
        arvoreFree(raiz -> direita);
        free(raiz);
    }
}

int main(){
    int v = 100;
    int i = 0, j, igual;
    int num0[v], num1[v], num2[v], num3[v];
    int op;

    srand(time(NULL));

    do{
        num0[i] = rand() % 1001;
        igual = 0;
        for(j = 0; j < i; j++){
            if(num0[j] == num0[i])
                igual = 1;
        }
        if(igual == 0)
            i++;
    }while(i < 100);

    for(i = 0; i < 100; i++){
      num3[i] = num2[i] = num1[i] = num0[i];
    }

    while(1){
        
        printf("Qual codigo de ordenação você deseja usar");
        menu(&op);
        if (op == 1) {
            for(i = 0; i < 100; i++){
                printf("[%d]: %d\n", i, num0[i]);
            }
            printf("Numeros alearios sem ordenação.");
            printf("\n\n");

        } else if (op == 2) {
            bubbleSort(num1, v);

        } else if (op == 3) {  
            selectionSort(num2, v);

        } else if (op == 4) {
            insertionSort(num3, v);

        } else if (op == 5) {
            for(i = 0; i < 100; i++){
            No *raiz = arvoreInicializar();
            raiz = arvoreInserir(raiz, itemCriador(num0[i]));
            arvorePrint(raiz);
            printf("\n");
            arvoreFree(raiz);
            }
            printf("Arvore binária \n");

        }else if (op == 6) {
            printf("Obrigado por usar nosso codigo.\n");
            printf("Saindo...\n");
            break; 
        }
    }
    return 0;
}

void menu(int *saida){
    printf(
    "Escolha uma opção:\n"
    "1 - Mostrar código desordenado\n"
    "2 - bubbleSort\n"
    "3 - selectionSort\n"
    "4 - insertionSort\n"
    "5 - Arvore Binária\n"
    "6 - Sair\n"
    );
    scanf("%d", saida);
}

void bubbleSort(int *arra, int tam){
    int i, j, aux, cont = 0;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j ++){
            if(arra[j] > arra[j + 1]){
                cont++;
                aux = arra[j];
                arra[j] = arra[j + 1];
                arra[j + 1 ] = aux;
            }
        }
    }
    for(i = 0; i < 100; i++){
        printf("[%d]: %d\n", i, arra[i]);
    }
    printf("Numeros ordenação pelo bubbleSort.\n");
    printf("Quantidades de comprações %d", cont);
    printf("\n\n");
}

void selectionSort(int *arra, int tam) {
int i, cont = 0;
 for (i = 0; i < tam - 1; i++){
    int min = i;
    for (int j = i + 1; j < tam; j++)
      if (arra[j] < arra[min]) min = j;

    if (min != i){
        cont++;
      int temp = arra[i];
      arra[i] = arra[min];
      arra[min] = temp;
    }
  }
    for(i = 0; i < 100; i++){

        printf("[%d]: %d\n", i, arra[i]);
    }
    printf("Numeros ordenação pelo selectionSort.\n");
    printf("Quantidades de comprações %d", cont);
    printf("\n\n");
} 

void insertionSort(int *arra, int tam){
    int i, j, aux, cont = 0;
    for(i = 1; i < tam; i++){
        aux = arra[i];
        for(j = i - 1; j >= 0 && arra[j] > aux; j--){
            cont++;
            arra[j+1] = arra[j];
        }
        arra[j+1] = aux;        
    }
    for(i = 0; i < 100; i++){
        printf("[%d]: %d\n", i, arra[i]);
    }
    printf("Numeros ordenação pelo insertionSort.\n");
    printf("Quantidades de comprações %d", cont);
    printf("\n\n");
}