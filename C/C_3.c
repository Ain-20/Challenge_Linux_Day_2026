#include <stdio.h>
#include <string.h>

char *my_strtok(char *str, const char *delim) {
    static char *last_pos = NULL;
    char *token_start = NULL;

    return token_start;
}

int main() {
    char testo[] = "Cha llen, ge!  comple,t,a,t,a";
    const char *delim = " ,!_";

    char *token = my_strtok(testo, delim);
    while (token != NULL) {
        printf("Token: [%s]\n", token);
        token = my_strtok(NULL, delim);
    }

    return 0;
}
