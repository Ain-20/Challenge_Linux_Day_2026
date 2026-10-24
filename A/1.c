#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

/**
 * ==============================================================================
 * Challenge 1: The Vault PIN (Implementazione C Completa)
 * ==============================================================================
 * Algoritmo di validazione:
 * 1. La stringa deve essere lunga esattamente 8 caratteri.
 * 2. Viene applicata una cifratura Rolling-XOR con chiave iniziale prev = 0x5A.
 * 3. Ogni carattere cifrato viene confrontato con i valori attesi in 'expected'.
 *
 * Password corretta: "Roma2LUG"
 * ==============================================================================
 */

int check_vault_pin(const char *input) {
    if (!input) return 0;

    // 1. Verifica che la lunghezza sia esattamente di 8 caratteri
    if (strlen(input) != 8) {
        return 0;
    }

    // Tabella dei byte cifrati attesi per "Roma2LUG"
    const uint8_t expected[8] = {0x08, 0x3D, 0x02, 0x0C, 0x53, 0x7E, 0x19, 0x12};
    uint8_t prev = 0x5A; // Chiave iniziale

    // 2. Loop di verifica con Rolling-XOR
    for (int i = 0; i < 8; i++) {
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
