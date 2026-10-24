#include <stdio.h>
#include <string.h>

char *reverse_hash(char *dest, const char *src) {
    char *start = dest;

    while (*src != '\0') {
        // Applica le operazioni inverse: prima sottrazione, poi XOR
        *dest = (*src - 7) ^ 0x42;
        dest++;
        src++;
    }

    *dest = '\0';

    return start;
}

int main(int argc, char **argv)  {
    const char sorgente[] = { 11, 53, 42, 44, 105, 61, 55, 52, 59, 42, 61, 42, 106, '\0' };
    char destinazione[100];

    // Pulizia preventiva del buffer di destinazione
    memset(destinazione, 0, sizeof(destinazione));

    char *risultato = reverse_hash(destinazione, sorgente);

    printf("Stringa decifrata   : [%s]\n", risultato != NULL ? risultato : "NULL");

    return 0;
}
