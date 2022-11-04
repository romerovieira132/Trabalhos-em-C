#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubbleSort();
void selectionSort();
void insertionSort();

int main() {
    int v = 100;
    int i = 0, j, igual, op;
    int num0[v], num1[v], num2[v], num3[v];

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
        printf("Numeros ordenação pelo insertionSort.");
        printf("\n\n");
    }    else if (op == 5) {
        printf("A arvore vai aparecer aqui");
    } else if (op == 6) {
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
