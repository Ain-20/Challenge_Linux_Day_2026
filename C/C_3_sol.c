#include <stdio.h>
#include <string.h>

char *my_strtok(char *str, const char *delim) {
    // Variabile statica per ricordare la posizione tra una chiamata e l'altra
    static char *last_pos = NULL;
    char *token_start;

    // 1. Se str non è NULL, iniziamo a elaborare una nuova stringa
    if (str != NULL) {
        last_pos = str;
    }

    // 2. Se non c'è una stringa da elaborare o siamo arrivati alla fine
    if (last_pos == NULL || *last_pos == '\0') {
        return NULL;
    }

    // 3. Salta eventuali delimitatori iniziali
    while (*last_pos != '\0' && strchr(delim, *last_pos) != NULL) {
        last_pos++;
    }

    // 4. Se dopo aver saltato i delimitatori siamo alla fine, non ci sono token
    if (*last_pos == '\0') {
        return NULL;
    }

    // 5. Segna l'inizio del token valido
    token_start = last_pos;

    // 6. Avanza fino a trovare il prossimo delimitatore (o la fine della stringa)
    while (*last_pos != '\0' && strchr(delim, *last_pos) == NULL) {
        last_pos++;
    }

    // 7. Se abbiamo trovato un delimitatore, tronchiamo la stringa con '\0'
    //    e avanziamo il puntatore per la prossima chiamata
    if (*last_pos != '\0') {
        *last_pos = '\0';
        last_pos++;
    }

    return token_start;
}

int main() {
    char testo[] = "Cha llen, ge!  comple,t,a,t,a";
    const char *delim = " ,!'";

    char *token = my_strtok(testo, delim);
    while (token != NULL) {
        printf("Token: [%s]\n", token);
        token = my_strtok(NULL, delim);
    }

    return 0;
}
