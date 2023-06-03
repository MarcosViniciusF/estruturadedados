#include <stdio.h>

void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mova o disco 1 da torre %c para a torre %c\n", origem, destino);
        return;
    }
    
    hanoi(n - 1, origem, auxiliar, destino);
    printf("Mova o disco %d da torre %c para a torre %c\n", n, origem, destino);
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int num_discos;
    printf("Digite o número de discos: ");
    scanf("%d", &num_discos);
    
    printf("Passos para resolver a Torre de Hanoi com %d discos:\n", num_discos);
    hanoi(num_discos, 'A', 'C', 'B');
    
    return 0;
}
