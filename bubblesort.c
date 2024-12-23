#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num[5], i, j;

    printf("Digite 5 números: \n");
    for (i=0;i<=4;i++){
        scanf("%d",&num[i]); // Alocação dos números
    }    

    //Código de ordenação 
    for(i=0;i<=4;i++){ // Vai rodar o for 4 vezes
        for(j=0;j<=4;j++){ // O for roda verificando a ordem 
            if(num[i]<num[j]){ // O if pega os números e reorganiza
                int aux = num[j];
                num[j] = num[i];
                num[i] = aux;          
            }        
        }
    }

    printf("Números ordenados: ");
    for (i=0;i<=4;i++){ // Impressão de todos os números
        printf("%d, ",num[i]);    
    }
}
