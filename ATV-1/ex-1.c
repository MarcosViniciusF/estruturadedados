#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int head;
    int tail;
    int size;
} Fila;

void inserir_fila(Fila *fila, int value) {
    if (fila->tail == fila->size) {
        fila->size *= 2;
        fila->data = realloc(fila->data, fila->size * sizeof(int));
    }
    fila->data[fila->tail] = value;
    fila->tail++;
}

int Remover_fila(Fila *fila) {
    if (fila->head == fila->tail) {
        printf("fila underflow\n");
        return -1;
    }
    int value = fila->data[fila->head];
    fila->head++;
    return value;
}

void printfila(Fila *fila) {
    printf("fila: ");
    for (int i = fila->head; i < fila->tail; i++) {
        printf("%d ", fila->data[i]);
    }
    printf("\n");
}

void clearfila(Fila *fila) {
    free(fila->data);
    fila->head = 0;
    fila->tail = 0;
    fila->size = 1;
    fila->data = malloc(sizeof(int));
}

void menu() {
    Fila fila;
    fila.head = 0;
    fila.tail = 0;
    fila.size = 1;
    fila.data = malloc(sizeof(int));
    int escolha, value;
    do {
        printf("1. Fila\n");
        printf("2. Remover fila\n");
        printf("3. Print fila\n");
        printf("4. Clear fila\n");
        printf("0. Sair\n");
        printf("DIgite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Inserir valor na fila: ");
                scanf("%d", &value);
                inserir_fila(&fila, value);
                break;
            case 2:
                printf("Remover valor da fila: %d\n", Remover_fila(&fila));
                break;
            case 3:
                printfila(&fila);
                break;
            case 4:
                clearfila(&fila);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha invalida\n");
        }
    } while (escolha != 0);
}

int main() {
    menu();
    return 0;
}
