#include <stdio.h>
#include <string.h>

// Obiettivo: Reversare l'algoritmo di hash per ottenere la stringa originale.
// La stringa nascosta è stata offuscata applicando questa formula a ogni carattere:
// char_offuscato = (char_originale ^ 0x42) + 7

char *reverse_hash(char *dest, const char *src) {
    char *start = dest;

    //Code

    return start;
}

int main() {
    // Array offuscato (rappresenta la stringa nascosta e il terminatore \0)
    const char sorgente[] = { 11, 53, 42, 44, 105, 61, 55, 52, 59, 42, 61, 42, 106, '\0' };
    char destinazione[100];

    // Pulizia preventiva del buffer di destinazione
    memset(destinazione, 0, sizeof(destinazione));

    char *risultato = reverse_hash(destinazione, sorgente);

    printf("Stringa decifrata   : [%s]\n", risultato != NULL ? risultato : "NULL");

    return 0;
}
