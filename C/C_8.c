#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *prev;
    struct Node *next;
} Node;

// --- FUNZIONI DI UTILITA' GIA' IMPLEMENTATE ---
Node* create_node(const char *stringa) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->str = (char*)malloc(strlen(stringa) + 1);
    strcpy(new_node->str, stringa);
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void append(Node **head, const char *stringa) {
    Node *new_node = create_node(stringa);
    if (*head == NULL) { *head = new_node; return; }
    Node *temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}

void print_list(Node *head) {
    Node *temp = head;
    printf("Lista: ");
    while (temp != NULL) {
        printf("[%s] <-> ", temp->str);
        temp = temp->next;
    }
    printf("NULL\n");
}
// ----------------------------------------------


// ==============================================
//  TODO 1: IMPLEMENTA LA RIMOZIONE DEI DUPLICATI
// ==============================================
void remove_duplicates(Node **head) {
    //Code
}


// ==============================================
//  TODO 2: IMPLEMENTA IL CAPOVOLGIMENTO (REVERSE)
// ==============================================
void reverse_list(Node **head) {
    //Code
}

// Funzione di utilità per pulire tutta la memoria
void free_list(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->str);
        free(temp);
    }
}

int main() {
    Node *head = NULL;

    append(&head, "mela");
    append(&head, "banana");
    append(&head, "mela");   // Duplicato
    append(&head, "arancia");
    append(&head, "banana"); // Duplicato
    append(&head, "kiwi");

    printf("--- LISTA ORIGINALE ---\n");
    print_list(head);

    printf("\n--- DOPO RIMOZIONE DUPLICATI ---\n");
    remove_duplicates(&head);
    print_list(head);

    printf("\n--- DOPO IL CAPOVOLGIMENTO (REVERSE) ---\n");
    reverse_list(&head);
    print_list(head);

    // Deallocazione finale
    free_list(head);
    return 0;
}
