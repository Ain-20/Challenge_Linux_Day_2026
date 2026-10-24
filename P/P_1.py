"""
ESERCIZIO DA MODIFICARE 2: Unione di Intervalli Sovrapposti (Merge Intervals)
----------------------------------------------------------------------------
OBIETTIVO:
Data una lista di intervalli chiusi `[start, end]`, unire tutti gli intervalli
sovrapposti e restituire una nuova lista di intervalli non sovrapposti, ordinati
in modo crescente per `start`.

Esempio:
Input:  [[1, 3], [2, 6], [8, 10], [15, 18]]
Output: [[1, 6], [8, 10], [15, 18]]

Esempio 2:
Input:  [[1, 4], [4, 5]]
Output: [[1, 5]] (gli estremi coincidenti si considerano sovrapposti!)

BUG DA RISOLVERE:
1. Il codice presume che la lista sia già ordinata per `start`, ma non lo è sempre!
2. Mutare la lista originale durante l'iterazione causa salti di indici inaspettati.
3. Condizione di sovrapposizione errata: considera sovrapposti solo quelli strettamente
   maggiori (`curr[0] < last[1]`), dimenticandosi del caso in cui gli estremi sono uguali (`<=`).
4. Non gestisce la lista vuota `[]` restituendo un errore `IndexError`.
"""

def merge_intervals(intervals: list[list[int]]) -> list[list[int]]:
    # BUG: IndexError su lista vuota
    # BUG: Non ordina gli intervalli in base a start!

    # Codice difettoso attuale:
    merged = [intervals[0]]

    for i in range(1, len(intervals)):
        current = intervals[i]
        last = merged[-1]

        # BUG: Se current[0] == last[1], dovrebbero essere uniti (es: [1,4] e [4,5])!
        if current[0] < last[1]:
            # BUG: Dovrebbe prendere il massimo tra last[1] e current[1],
            # perche' current potrebbe essere contenuto interamente dentro last!
            last[1] = current[1]
        else:
            merged.append(current)

    return merged


# ==============================================================================
# SUITE DI TEST (Non modificare i test! Devono passare tutti dopo le correzioni)
# Esegui con: python ex2_merge_intervals.py
# ==============================================================================
if __name__ == "__main__":
    print("Verifica ex2_merge_intervals...")

    # Test 1: Lista vuota
    assert merge_intervals([]) == [], "ERRORE: Lista vuota fallita!"

    # Test 2: Lista non ordinata in ingresso
    raw = [[8, 10], [1, 3], [15, 18], [2, 6]]
    expected = [[1, 6], [8, 10], [15, 18]]
    assert merge_intervals(raw) == expected, "ERRORE: Non gestisce liste non ordinate!"

    # Test 3: Estremi coincidenti (es. [1, 4] e [4, 5])
    assert merge_intervals([[1, 4], [4, 5]]) == [[1, 5]], "ERRORE: Estremi coincidenti [1,4] e [4,5] devono fondersi in [1,5]!"

    # Test 4: Intervallo completamente contenuto dentro un altro
    assert merge_intervals([[1, 10], [2, 6], [3, 8]]) == [[1, 10]], "ERRORE: Intervalli contenuti devono fondersi nel più grande!"

    # Test 5: Nessuna sovrapposizione
    assert merge_intervals([[1, 2], [3, 4], [5, 6]]) == [[1, 2], [3, 4], [5, 6]]

    # Test 6: La lista originale in input non deve essere modificata o corrotta
    test_copy = [[3, 5], [1, 2]]
    res = merge_intervals(test_copy)
    assert res == [[1, 2], [3, 5]]

    print("[COMPLIMENTI] Tutti i test di ex2_merge_intervals sono superati!")
