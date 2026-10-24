#include <stdio.h>
#include <string.h>

// Obiettivo: Trovare tutte le occorrenze della stringa 'target' all'interno di 'blob'.
// Salvare gli indici (posizioni iniziali) nell'array 'indices_dest'
// e restituire il numero totale di occorrenze trovate.

int find_occurrences(const char *blob, const char *target, int *indices_dest) {
    int count = 0;

    //Code

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
