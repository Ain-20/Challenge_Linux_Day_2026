#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definizione del nodo con una stringa e due puntatori
typedef struct Node {
    char *str;
    struct Node *prev;
    struct Node *next;
} Node;

// Funzione di utilità per creare un nuovo nodo
Node* create_node(const char *stringa) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return NULL;

    new_node->str = (char*)malloc(strlen(stringa) + 1);
    if (!new_node->str) {
        free(new_node);
        return NULL;
    }
    strcpy(new_node->str, stringa);

    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Funzione di utilità per aggiungere in coda
void append(Node **head, const char *stringa) {
    Node *new_node = create_node(stringa);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// 1. Rimuove i nodi con stringhe duplicate
void remove_duplicates(Node **head) {
    if (*head == NULL) return;

    Node *current = *head;

    while (current != NULL) {
        Node *runner = current->next;

        while (runner != NULL) {
            if (strcmp(current->str, runner->str) == 0) {
                Node *duplicate = runner;
                // Avanziamo il runner prima di distruggere il nodo corrente
                runner = runner->next;

                // Aggiorniamo i collegamenti dei nodi adiacenti
                if (duplicate->prev != NULL) {
                    duplicate->prev->next = duplicate->next;
                }
                if (duplicate->next != NULL) {
                    duplicate->next->prev = duplicate->prev;
                }

                // Deallochiamo memoria (prima la stringa, poi il nodo)
                free(duplicate->str);
                free(duplicate);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// 2. Capovolge la lista doppiamente concatenata
void reverse_list(Node **head) {
    if (*head == NULL || (*head)->next == NULL) return;

    Node *current = *head;
    Node *temp = NULL;

    // Scambiamo 'prev' e 'next' per ogni nodo
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Attenzione: avendo scambiato i puntatori, il nodo "successivo" è ora in 'prev'
        current = current->prev;
    }

    // Aggiorniamo la testa della lista (temp->prev punta all'ultimo nodo valido)
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Funzione di utilità per la stampa
void print_list(Node *head) {
    Node *temp = head;
    printf("Lista: ");
    while (temp != NULL) {
        printf("[%s] <-> ", temp->str);
        temp = temp->next;
    }
    printf("NULL\n");
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
