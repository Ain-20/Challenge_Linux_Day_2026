#include <stdio.h>
#include <string.h>

char *rle_compress(char *dest, const char *src) {
    char *start = dest;
    int i = 0;
    int dest_idx = 0;

    // Gestione stringa vuota o nulla
    if (src == NULL || src[0] == '\0') {
        dest[0] = '\0';
        return start;
    }

    while (src[i] != '\0') {
        char current_char = src[i];
        int count = 1;

        // Conta le ripetizioni consecutive del carattere corrente
        while (src[i + 1] == current_char) {
            count++;
            i++;
        }

        // Scrive il carattere e il suo conteggio convertito in stringa
        dest_idx += sprintf(&dest[dest_idx], "%c%d", current_char, count);
        i++;
    }

    dest[dest_idx] = '\0';

    return start;
}

int main() {
    const char sorgente[] = "AAAABBBCCDAA";
    char destinazione[100];

    // Pulizia preventiva del buffer di destinazione
    memset(destinazione, 0, sizeof(destinazione));

    char *risultato = rle_compress(destinazione, sorgente);

    printf("Stringa originale : [%s]\n", sorgente);
    printf("Stringa compressa : [%s]\n", risultato != NULL ? risultato : "NULL");

    return 0;
}
