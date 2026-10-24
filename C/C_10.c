#include <stdio.h>
#include <string.h>

// Obiettivo: Implementare la compressione Run-Length Encoding (RLE) di una stringa.
// Esempio: La stringa "AAAABBBCCDAA" deve diventare "A4B3C2D1A2".
// Salvare il risultato nel buffer 'dest' e restituire il puntatore a 'dest'.

char *rle_compress(char *dest, const char *src) {
    char *start = dest;

    //Code

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
