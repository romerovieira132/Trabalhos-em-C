#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubbleSort(int *arra, int tam);
void selectionSort(int *arra, int tam);
void insertionSort(int *arra, int tam);
void menu(int *saida);
void treePrint();
void treeFree();

struct item{
    int cod;
};

typedef struct item Item;

struct node {
    Item item;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *treeInicialize(){
    return NULL;
}

Item itemCreate(int cod){
    Item item;
    item.cod = cod;
    return item;
}

Node *treeInsert(Node *root, Item x){
    if (root == NULL ) {
        Node *aux = (Node *)malloc(sizeof(Node));
        aux -> item = x;
        aux -> left = NULL;
        aux -> right = NULL;
        return aux;
    } else {
        if (x.cod > root -> item.cod){
            root -> right = treeInsert(root -> right, x);
        } else if(x.cod < root -> item.cod) {
            root -> left = treeInsert(root -> left, x);
        }
    }
    return root;
}

void treePrint(Node *root){
    if (root != NULL){
        printf("%d", root -> item.cod);
        treePrint(root -> left);
        treePrint(root -> right);
    }
}

void treeFree(Node *root){
    if (root != NULL){
        treeFree(root -> left);
        treeFree(root -> right);
        free(root);
    }
}

int main(){
    int v = 100;
    int i = 0, j, igual;
    int num0[v], num1[v], num2[v], num3[v];
    int op;
    int c = 0;

    srand(time(NULL));

    do{
        num0[i] = rand() % 1000;
        igual = 0;
        for(j = 0; j < i; j++){
            if(num0[j] == num0[i])
                igual = 1;
        }
        if(igual == 0)
            i++;
    }while(i < 100);

    for(i = 0; i < 100; i++){
        num1[i] = num0[i];
        num2[i] = num0[i];
        num3[i] = num0[i];
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
            for(i = 0; i < 100; i++){
                printf("[%d]: %d\n", i, num1[i]);
            }
            printf("Numeros ordenação pelo bubbleSort.");
            printf("\n\n");

        } else if (op == 3) {  
            selectionSort(num2, v);
            for(i = 0; i < 100; i++){
                printf("[%d]: %d\n", i, num2[i]);
            }
            printf("Numeros ordenação pelo selectionSort.");
            printf("\n\n");

        } else if (op == 4) {
            insertionSort(num3, v);
            for(i = 0; i < 100; i++){
                printf("[%d]: %d\n", i, num3[i]);
            }
            printf("Numeros ordenação pelo insertionSort.\n");
            printf("\n\n");

        } else if (op == 5) {
            for(i = 0; i < 100; i++){
            Node *root = treeInicialize();
            root = treeInsert(root, itemCreate(num0[i]));
            treePrint(root);
            printf("\n");
            treeFree(root);
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
    int i, j, aux;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j ++){
            if(arra[j] > arra[j + 1]){
                aux = arra[j];
                arra[j] = arra[j + 1];
                arra[j + 1 ] = aux;
            }
        }
    }
}

void selectionSort(int *arra, int tam) {
 for (int i = 0; i < tam - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < tam; j++)
      if (arra[j] < arra[min]) min = j;

    if (min != i)
    {
      int temp = arra[i];
      arra[i] = arra[min];
      arra[min] = temp;
    }
  }
} 

void insertionSort(int *arra, int tam){
    int x, y, value;
    for(x = 1; x < tam; x++){
        value = arra[x];
        for(y = x - 1; y >= 0 && arra[y] > value; y--){
            arra[y+1] = arra[y];
        }
        arra[y+1] = value;
        
    }
}


