#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dest, const char *src) {
    char *start = dest;

    //Code

    return start;
}

int main() {
    const char sorgente[] = "Challenge completata con successo!";
    char destinazione[100];

    // Pulizia preventiva del buffer di destinazione
    memset(destinazione, 0, sizeof(destinazione));

    char *risultato = my_strcpy(destinazione, sorgente);

    printf("Stringa originale   : [%s]\n", sorgente);
    printf("Stringa destinazione: [%s]\n", risultato != NULL ? risultato : "NULL");

    return 0;
}
