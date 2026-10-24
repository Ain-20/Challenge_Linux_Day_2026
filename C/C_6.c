#include <stdio.h>
#include <string.h>

// Obiettivo: Implementare un algoritmo O(n^2) per trovare i numeri primi
// strettamente compresi tra 'min' e 'max' (min < x < max).
// Salvare i risultati nell'array 'primes_dest' e restituire il numero di primi trovati.

int find_primes(int min, int max, int *primes_dest) {
    int count = 0;

    //Code

    return count;
}

int main() {
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
