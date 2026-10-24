#include <stdio.h>

int min_monete(int monete[], int n, int somma) {

    //Code

    return 1;
}

void calcola_multipli(int monete[][3], int totali[], int num_casi, int n_monete) {
    for (int i = 0; i < num_casi; i++) {
        int risultato = min_monete(monete[i], n_monete, totali[i]);
        printf("%d\n", risultato);
    }
}

int main() {
    int coins[][3] = {
        {1, 6, 4},
        {2, 5, 8},
        {10, 20, 5},
        {3, 7, 2}
    };

    int totals[] = {15, 22, 55, 14};

    int num_casi = sizeof(totals) / sizeof(totals[0]);
    int n_monete = 3;

    calcola_multipli(coins, totals, num_casi, n_monete);

    return 0;
}
