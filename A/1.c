#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/**
 * ==============================================================================
 * Challenge 1: The Vault PIN (Implementazione C Completa)
 * ==============================================================================
 * Algoritmo di validazione:
 * 1. La stringa deve essere lunga esattamente 6 caratteri.
 * 2. Viene applicata una cifratura Rolling-XOR con chiave iniziale prev = 0x5A.
 * 3. Ogni carattere cifrato viene confrontato con i valori attesi in 'expected'.
 *
 * Password corretta: "ANTIGV"
 * ==============================================================================
 */

int check_vault_pin(const char *input) {
    if (!input) return 0;

    // 1. Verifica che la lunghezza sia esattamente di 6 caratteri
    if (strlen(input) != 6) {
        return 0;
    }

    // Tabella dei byte cifrati attesi
    const uint8_t expected[6] = {0x1B, 0x0F, 0x1A, 0x1D, 0x0E, 0x11};
    uint8_t prev = 0x5A; // Chiave iniziale

    // 2. Loop di verifica con Rolling-XOR
    for (int i = 0; i < 6; i++) {
        uint8_t curr = (uint8_t)input[i];

        // Ogni byte cifrato è il risultato di (curr ^ prev)
        if ((curr ^ prev) != expected[i]) {
            return 0; // Carattere errato
        }

        prev = curr; // Il carattere corrente diventa la nuova chiave per il successivo
    }

    return 1; // Tutte le condizioni soddisfatte: password corretta!
}

int main(void) {
    char user_input[64];
    printf("=== CHALLENGE 1: The Vault PIN (Codice C) ===\n");
    printf("Inserisci la password segreta per aprire la cassaforte: ");

    if (scanf("%63s", user_input) == 1) {
        if (check_vault_pin(user_input)) {
            printf("\n[ACCESS GRANTED] Congratulazioni! Hai sbloccato la cassaforte: %s\n", user_input);
        } else {
            printf("\n[ACCESS DENIED] Password errata!\n");
        }
    }
    return 0;
}
