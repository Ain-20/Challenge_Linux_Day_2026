"""
SOLUZIONE CHALLENGE 1: Unione di Intervalli Sovrapposti (Merge Intervals)
----------------------------------------------------------------------------
OBIETTIVO:
Data una lista di intervalli chiusi `[start, end]`, unire tutti gli intervalli
sovrapposti e restituire una nuova lista di intervalli non sovrapposti, ordinati
in modo crescente per `start`.
"""

def merge_intervals(intervals: list[list[int]]) -> list[list[int]]:
    if not intervals:
        return []

    # 1. Ordina la lista per start per non dipendere dall'ordine di input
    sorted_intervals = sorted(intervals, key=lambda x: x[0])
    # Copia il primo intervallo per non mutare l'input originale
    merged = [[sorted_intervals[0][0], sorted_intervals[0][1]]]

    for current in sorted_intervals[1:]:
        last = merged[-1]

        # 2. Gestisce anche estremi coincidenti (<=)
        if current[0] <= last[1]:
            # 3. Considera intervalli completamente contenuti prendendo il massimo
            last[1] = max(last[1], current[1])
        else:
            merged.append([current[0], current[1]])

    return merged


# ==============================================================================
# SUITE DI TEST
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
