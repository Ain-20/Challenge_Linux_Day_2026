#include <stdio.h>
#include <string.h>

char *reverse_complex_hash(char *dest, const unsigned char *src) {
    char *start = dest;
    int i = 0;

    while (src[i] != '\0') {
        unsigned char c = src[i];

        // Applica le operazioni inverse procedendo dall'ultimo step al primo:
        // 4 (Inverso). Ripeti lo XOR con 0x13 (lo XOR è l'inverso di sé stesso)
        c = c ^ 0x13;

        // 3 (Inverso). Ripeti il NOT bit a bit per riottenere il valore originale prima del NOT
        c = ~c;

        // 2 (Inverso). Sottrai il doppio dell'indice
        c = c - (i * 2);

        // 1 (Inverso). Ripeti lo XOR con 0x42
        c = c ^ 0x42;

        // Salva il carattere decodificato e avanza
        dest[i] = (char)c;
        i++;
    }

    dest[i] = '\0';

    return start;
}

int main() {
    const unsigned char sorgente[] = { 0x95, 0xCD, 0xC9, 0xC2, 0xDF, 0xA4, 0xF3, 0x00 };
    char destinazione[100];

    // Pulizia preventiva del buffer di destinazione
    memset(destinazione, 0, sizeof(destinazione));

    char *risultato = reverse_complex_hash(destinazione, sorgente);

    printf("Stringa decifrata   : [%s]\n", risultato != NULL ? risultato : "NULL");

    return 0;
}
