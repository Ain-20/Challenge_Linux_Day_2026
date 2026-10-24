# Challenge Linux Day 2026 🐧

Raccolta di sfide di programmazione e reverse engineering suddivise in tre categorie principali: **Reverse Engineering (A)**, **Linguaggio C (C)** e **Python (P)**.

---

## 📁 Struttura del Progetto

```text
CHALLENGE_26/
├── A/         # Categoria A: Reverse Engineering (Binari ELF 64-bit Linux x86-64)
├── C/         # Categoria C: Sfide di programmazione in C con test harness
├── P/         # Categoria P: Esercizi algoritmici in Python da completare/debuggare
└── P_sol/     # Categoria P (Soluzioni): Implementazioni di riferimento verificate
```

---

## 🛠️ Requisiti

- **Sistema Operativo**: Linux / WSL (Windows Subsystem for Linux) / macOS con toolchain GNU
- **Compilatore C**: `gcc` con supporto a `-Wall -O2`
- **Python**: Versione `3.10` o superiore
- **Tooling di analisi (opzionale per Cat. A)**: `gdb`, `objdump`, `strings`

---

## 🧩 Categoria A: Reverse Engineering

Contiene 10 binari ELF compilati per x86-64. Ciascun binario richiede una specifica analisi per individuare il flusso di controllo, le chiavi o i parametri corretti:

| Binario | Descrizione |
| :--- | :--- |
| `cassaforte` | Pin vault con cifratura rolling-XOR. |
| `interagisci` | Verifica di integrità di array (interazione tramite debugger/GDB). |
| `massimo_FORSE` | Ricerca del secondo massimo da riga di comando. |
| `operatori` | Jump table e dispatching operazioni aritmetiche. |
| `reverse_compress` | Compressione RLE da linea di comando. |
| `reverse_hash` | Algoritmo di decodifica byte `(c - 7) ^ 0x42`. |
| `reverse_hash_2` | Hash complesso invertibile. |
| `reverse_hash_3` | Funzione di hash a 32-bit su `0xdeadbeef`. |
| `somma` | Algoritmo di shift ciclico casuale e ricalcolo somma. |
| `somma2` | Calcolo combinato di medie aritmetiche su due array. |

Consulta [A/README.md](A/README.md) per i dettagli completi su ciascun binario.

---

## 🧩 Categoria C: Linguaggio C

La cartella include 10 challenge di programmazione (`C_1.c` ... `C_10.c`), le corrispondenti soluzioni di riferimento (`C_1_sol.c` ... `C_10_sol.c`) e la test harness automatizzata `sol.sh`.

### Esecuzione dei Test
Per verificare una soluzione rispetto al riferimento:

```bash
cd C
./sol.sh C_1.c
# oppure per testare tutte le challenge:
for i in {1..10}; do ./sol.sh "C_${i}.c"; done
```

Lo script compila sia il file utente sia la soluzione con `gcc -Wall -O2` e ne confronta l'output.

---

## 🧩 Categoria P & P_sol: Python

La cartella `P/` contiene 10 esercizi algoritmici (problemi di ordinamento, strutture dati, gestione memoria/riferimenti e parsing):

1. **`P_1.py`**: Unione di intervalli sovrapposti (*Merge Intervals*)
2. **`P_2.py`**: Gestione registro contabile e precisione finanziaria (*Bank Ledger*)
3. **`P_3.py`**: Validazione parentesi (*Valid Parentheses*)
4. **`P_4.py`**: Raggruppamento anagrammi (*Group Anagrams*)
5. **`P_5.py`**: Compressione stringhe (*String Compression*)
6. **`P_6.py`**: Attraversamento a spirale di matrici (*Spiral Order*)
7. **`P_7.py`**: Intersezione di array (*Array Intersection*)
8. **`P_8.py`**: Container con il massimo d'acqua (*Container With Most Water*)
9. **`P_9.py`**: Sottoarray con somma massima (*Maximum Subarray*)
10. **`P_10.py`**: Conteggio isole (*Number of Islands*)

### Esecuzione degli Esercizi
```bash
python P/P_1.py
```

### Verifica delle Soluzioni
Tutte le soluzioni complete e testate sono archiviate in `P_sol/`:

```bash
python P_sol/P_1.py
```
