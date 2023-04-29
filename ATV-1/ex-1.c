#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* insert_at_head(Node* head, int data) {
    Node* new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

Node* insert_at_tail(Node* head, int data){
    Node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    Node* current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
    return head;
}

Node* delete_node(Node* head, int data){
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL)
    {
        if (current->data == data) {
            if (prev == NULL) {
                head = current->next;
            }else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head;
}

void clean_list(Node** head_ref) {
    Node* current = *head_ref;
    Node* next;

    while (current != NULL) {
        next = current-> next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

void print_list(Node* head) {
    printf("Lista: \n");
    Node* current = head;
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("\n");
}

int get_position(Node* head, int data) {
    int pos = 0;

     if (head == NULL) {
        return -1;
    }
    Node* current = head;
    while (current != NULL) {
        if (current-> data) {
            return pos;
        }  
        pos++;
        current = current->next;  
    }
    return -1;
}

void edit_node(Node* head, int old_value, int new_value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == old_value) {
            current->data = new_value;
            return;
        }
        current = current->next;
    }
    printf("O valor (%d) não foi encontrado na lista. \n", old_value);
    return;
}

void display_menu() {
    printf("\n---------------------------\n");
    printf("1. Inserir no início\n");
    printf("2. Inserir no fim\n");
    printf("3. Excluir valor\n");
    printf("4. Editar valor\n");
    printf("5. Buscar posição de valor\n");
    printf("6. Exibir lista\n");
    printf("7. Limpar lista\n");
    printf("8. Sair\n");
    printf("---------------------------\n");
}

int main(){
    int new_data;
    int old_data;
    int choice;
    int data;


    Node* head = NULL;

    do {
        display_menu();
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // inserir no início
                printf("Digite o valor: ");
                scanf("%d", &data);
                head = insert_at_head(head, data);
                printf("%d inserido no início da lista.\n", data);
                break;

            case 2: // inserir no fim
                printf("Digite o valor: ");
                scanf("%d", &data);
                head = insert_at_tail(head, data);
                printf("%d inserido no fim da lista.\n", data);
                break;

            case 3: // excluir valor
                printf("Digite o valor a ser excluído: ");
                scanf("%d", &data);
                head = delete_node(head, data);
                printf("%d removido da lista.\n", data);
                break;

            case 4: // editar valor
                printf("Digite o valor a ser editado: ");
                scanf("%d", &old_data);
                printf("Digite o novo valor: ");
                scanf("%d", &new_data);
                edit_node(head, old_data, new_data);
                break;

            case 5: // exibir posição
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &data);
                int pos = get_position(head, data);
                if (pos == -1) {
                    printf("%d não encontrado na lista.\n", data);
                } else {
                    printf("%d está na posição %d na lista.\n", data, pos);
                }
                break;

            case 6: // exibir lista
                print_list(head);
                break;

            case 7: // limpar lista
                clean_list(&head);
                printf("Lista limpa.\n");
                break;

            case 8: // sair do programa
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (choice != 8);

    return 0;

}
