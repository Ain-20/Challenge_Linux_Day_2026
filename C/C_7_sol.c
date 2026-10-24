#include <stdio.h>
#include <string.h>

int find_occurrences(const char *blob, const char *target, int *indices_dest) {
    int count = 0;
    int target_len = strlen(target);

    // Gestione del caso limite: target vuoto
    if (target_len == 0) return 0;

    const char *current_pos = blob;

    // strstr restituisce un puntatore alla prima occorrenza, oppure NULL
    while ((current_pos = strstr(current_pos, target)) != NULL) {
        // Calcola l'indice tramite l'aritmetica dei puntatori
        indices_dest[count] = current_pos - blob;
        count++;

        // Avanza il puntatore della lunghezza del target per evitare loop infiniti
        // (usare current_pos += 1 se si vogliono contare le occorrenze sovrapposte)
        current_pos += target_len;
    }

    return count;
}

int main() {
    const char blob[] = "Per andare piano piano su questo piano inclinato, bisogna procedere piano.";
    const char target[] = "piano";
    int indices[100];

    // Pulizia preventiva dell'array di destinazione
    memset(indices, 0, sizeof(indices));

    int count = find_occurrences(blob, target, indices);

    printf("Stringa blob : [%s]\n", blob);
    printf("Target       : [%s]\n", target);
    printf("Occorrenze trovate (%d): ", count);

    for(int i = 0; i < count; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");

    return 0;
}
