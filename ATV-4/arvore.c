#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Função para imprimir a árvore em ordem
void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Função para imprimir a árvore em pré-ordem
void printPreOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Função para imprimir a árvore em pós-ordem
void printPostOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

// Função para encontrar o nó mínimo na subárvore direita
Node* findMinNode(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Função para remover um nó da árvore
Node* removeNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = removeNode(root->left, data);
    } else if (data > root->data) {
        root->right = removeNode(root->right, data);
    } else {
        // Caso 1: Nó sem filhos
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Caso 2: Nó com um filho
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        // Caso 3: Nó com dois filhos
        else {
            Node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = removeNode(root->right, temp->data);
        }
    }
    return root;
}

// Função para liberar a memória ocupada pela árvore
void clearTree(Node* root) {
    if (root == NULL) {
        return;
    }
    clearTree(root->left);
    clearTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n");
        printf("Selecione uma opcao:\n");
        printf("1. Inserir um no na arvore\n");
        printf("2. Listar a arvore (ordem, pre e pos)\n");
        printf("3. Remover um no da arvore\n");
        printf("4. Esvaziar a arvore\n");
        printf("5. Sair\n");
        printf("Opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Arvore em ordem: ");
                printInOrder(root);
                printf("\n");
                printf("Arvore em pre-ordem: ");
                printPreOrder(root);
                printf("\n");
                printf("Arvore em pos-ordem: ");
                printPostOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &data);
                root = removeNode(root, data);
                break;
            case 4:
                clearTree(root);
                root = NULL;
                printf("A arvore foi esvaziada.\n");
                break;
            case 5:
                clearTree(root);
                printf("Encerrando o programa.\n");
                exit(0);
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}
