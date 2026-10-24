# Challenge Categoria A: Reverse Engineering (ELF x86-64)

Questa directory contiene 10 eseguibili Linux compilati in formato ELF 64-bit per architettura x86-64.

## Panoramica delle Challenge

| Eseguibile | Tipo di Challenge | Descrizione e Analisi | Soluzione / Input Atteso |
| :--- | :--- | :--- | :--- |
| **`cassaforte`** | String Vault | Richiede una password a 6 caratteri. Applica cifratura rolling-XOR con chiave iniziale `0x5A` confrontando il risultato con i byte attesi `[0x1B, 0x0F, 0x1A, 0x1D, 0x0E, 0x11]`. | `"ANTIGV"` (vedi sorgente di riferimento [1.c](1.c)) |
| **`interagisci`** | Dynamic Patching | Calcola la somma dell'array statico `{1, 1, 1, 1, 2, 1}` (totale 7) e verifica se `sum == 6`. Non accetta input utente. | Modificare il registro `EAX` o la memoria via GDB/debugger (`set $eax = 6`). |
| **`massimo_FORSE`** | Array Search | Cerca il secondo valore massimo nell'array `[7, 42, 5, 0, 90, 83, -12, 10, 63, 106]`. Il massimo è 106, il secondo massimo è 90. | `./massimo_FORSE 90` |
| **`operatori`** | Jump Table | Tabella di puntatori a funzione (`+`, `-`, `*`, `/`). Con operatore `*` (`0x2A`), calcola `15 * 3 = 45`. | `./operatori 45` |
| **`reverse_compress`** | RLE Decompress | Comprime `"AAAABBBCCDAA"` in Run-Length Encoding ottenendo `"A4B3C2D1A2"`. Confronta l'argomento con la stringa compressa. | `"A4B3C2D1A2"` |
| **`reverse_hash`** | Byte Reversal | Algoritmo di decodifica `(char - 7) ^ 0x42` applicato a un buffer di byte per ricostruire la stringa in chiaro. | Stampa ed esige come argomento: `"Flagtrovata!"` |
| **`reverse_hash_2`** | Complex Inversion | Inversione di hash a 4 passaggi: `(((~c ^ 0x13) - 2*i) ^ 0x42)`. | Argomento atteso: `"R]cjifQ"` |
| **`reverse_hash_3`** | 32-bit Hash Reversal | Calcola un hash a 32-bit con rotazioni aritmetiche su `0xdeadbeef` e confronta con `atoi(argv[1])`. | `./reverse_hash_3 1717991547` |
| **`somma`** | Interactive Shift | Stampa la somma iniziale (769), esegue uno shift ciclico casuale a sinistra (`rand() % 8`) e richiede la somma aggiornata da stdin. | Calcolo interattivo post-shift. |
| **`somma2`** | Multi-Arg Mean | Calcola due medie: elementi di indice pari di `arr1` (`124 / 6 = 20`) e media globale di `arr2` (`276 / 6 = 46`). | `./somma2 20 46` |
