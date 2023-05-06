#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *data;
    int top;
    int size;
} Pilha;

void inserir(Pilha *pilha, int value){
    if ( pilha->top == pilha->size - 1){
        pilha->size *= 2;
        pilha->data = realloc(pilha->data, pilha->size * sizeof(int));
    }
    pilha->top++;
    pilha->data[pilha->top] = value;
}

int remover(Pilha *pilha){
    if (pilha->top == -1){
        printf("pilha vazia\n");
        return -1;
    }
    int value = pilha->data[pilha->top];
    pilha->top--;
    return value;
}

void printpilha(Pilha *pilha) {
    printf("pilha: ");
    for (int i = pilha->top; i >=0; i--){
        printf("%d ", pilha->data[i]);
    }
    printf("\n");
}

void clearpilha(Pilha *pilha){
    pilha->top = -1;
}

void menu(){
    Pilha pilha;
    pilha.top = -1;
    pilha.size = 1;
    pilha.data = malloc(sizeof(int));
    int escolha, value;
    do{
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Imprimir pilha\n");
        printf("4. Limpar pilha\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha){
        case 1:
            printf("Digite o valor para inserir: ");
            scanf("%d", &value);
            inserir(&pilha, value);
            break;
        case 2:
            printf("Valor removido %d\n", remover(&pilha));
            break;
        case 3:
            printpilha(&pilha);
            break;
        case 4:
            clearpilha(&pilha);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Escolha invalida\n");
        }
    }while (escolha != 0);    
}

int main(){
    menu();
    return 0;
}
