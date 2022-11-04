#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubbleSort();
void selectionSort();
void insertionSort();

int main() {
    int v = 100;
    int i = 0, j, igual;
    int num0[v];
    int num1[v];
    int num2[v];
    int num3[v];

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

    for(i = 0; i < 100; i++){
        printf("[%d]: %d\n", i, num0[i]);
    }
    printf("Numeros alearios sem ordenação.");
    printf("\n\n");

    printf("Qual codigo de ordenação você deseja usar");
    bubbleSort(num1, v);
    for(i = 0; i < 100; i++){
        printf("[%d]: %d\n", i, num1[i]);
    }
    printf("Numeros ordenação pelo bubbleSort.");
    printf("\n\n");


    selectionSort(num2, v);
    for(i = 0; i < 100; i++){
        printf("[%d]: %d\n", i, num2[i]);
    }
    printf("Numeros ordenação pelo selectionSort.");
    printf("\n\n");


    insertionSort(num3, v);
    for(i = 0; i < 100; i++){
        printf("[%d]: %d\n", i, num3[i]);
    }
    printf("Numeros ordenação pelo insertionSort.");
    printf("\n\n");

    return 0;
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

/*#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int val;
    int ate;
    printf("EScolha quantos espaços voce deseja no vetor: ");
    scanf("%d", &val);
    printf("Ate qual numero voce deseja ter no vetor: ");
    scanf("%d", &ate);
    int num[99];
    int numAle = 0;

    srand(time(NULL));

    for (i = 0; i < 100; i++) {
        num[i] = (rand()% 1000);
        if (num[i] > 0) {
            numAle += 1;
        }
    }
    for (i = 0; i < 100; i++) {
        printf("[%d]: %d\n", i, num[i]);
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i = 0, j, igual, num[99];

    srand(time(NULL));

    do{
        num[i] = rand() % 1000;
        igual = 0;
        for(j = 0; j < i; j++){
            if(num[j] == num[i])
                igual = 1;
        }
        if(igual == 0)
            i++;
    }while(i < 100);

    for(i = 0; i < 100; i++){
        printf("[%d]: %d\n", i, num[i]);
    }
    
    return 0;
}
*/
