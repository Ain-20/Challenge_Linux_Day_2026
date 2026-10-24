#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int find_primes(int min, int max, int *primes_dest) {
    int count = 0;

    // Ciclo esterno per scorrere i numeri nel range (min < x < max)
    for (int i = min + 1; i < max; i++) {
        int is_prime = 1;

        if (i <= 1) {
            is_prime = 0;
        } else {
            // Ciclo interno ingenuo per verificare la primalità (O(n) per ogni numero, totale O(n^2))
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    is_prime = 0;
                    break;
                }
            }
        }

        // Se è primo, lo salva nell'array e incrementa il contatore
        if (is_prime) {
            primes_dest[count] = i;
            count++;
        }
    }

    return count;
}

int main() {

    srand(time(NULL));

    int min = 9;
    int max = 23;
    int primes[100];

    // Pulizia preventiva dell'array di destinazione
    memset(primes, 0, sizeof(primes));

    int count = find_primes(min, max, primes);

    printf("Range di ricerca : %d < x < %d\n", min, max);
    printf("Primi trovati (%d): ", count);

    for(int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    return 0;
}
