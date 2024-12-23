#include <stdio.h>

// Bubble sort para a ordenação dos números
void troca(int* a, int* b){ // "int*" serve como ponteiro e aloca na memória o valor
    int temp = *a;
    *a = *b;
    *b = temp;
}

//void troca(int* a, int* b);

int particao(int array[], int low, int high){

    int pivot = array[high]; // Define o último elemento como pivô

    int i = low - 1; // Indica o menor elemento

    for(int j = low; j <= high - 1; j++){ // Repetição para a função 
        if(array[j] < pivot){ // Se o vetor for menor que o pivô, ele manda pra "troca()"
            i++; // Incrementa o índice do menor elemento
            troca(&array[i], &array[j]);
        }
    }

    troca(&array[i + 1], &array[high]); // Coloca o pivô no lugar certo
    
    return i + 1;
}

// Função para o quicksort
void quicksort(int array[], int low, int high){
    if(low < high){

        int par = particao(array, low, high); // Chama a função de partição que define um pivô e retorna para esta funcão

        // Recursão para o chamado dos números
        quicksort(array, low, par - 1); // Para números menores
        quicksort(array, par + 1, high); // Para números maiores ou iguais
    }
}

int main(){
    int array[] = {12, 34, 56, 78, 90, 23, 45, 67, 89, 10, 13, 25, 37, 49, 61, 72, 84, 96, 28, 40, 52, 64, 75, 87, 99, 21, 33, 55, 77, 88, 92, 19, 26, 38, 50, 60, 74, 82, 94, 16, 30, 42, 54, 66, 81, 97, 15, 27, 39, 48};
    //int array[] = {10, 5, 6, 9, 2, 4, 3, 1, 6, 23, 12, -9, -6, -3}; // Vetor
    int n = sizeof(array) / sizeof(array[0]); // Guarda o valor do tamanho do vetor
    
    quicksort(array, 0, n -1);

    for(int i = 0; i < n; i++){ // Impressão de todos os números
        printf("%d, ", array[i]);
    }
    printf("\n");

    return 0;
}