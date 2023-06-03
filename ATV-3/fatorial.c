#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    
    return n * factorial(n - 1);
}

int main() {
    int num;
    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("O fatorial nao esta definido para numeros negativos.\n");
    } else {
        int result = factorial(num);
        printf("O fatorial de %d e: %d\n", num, result);
    }
    
    return 0;
}
