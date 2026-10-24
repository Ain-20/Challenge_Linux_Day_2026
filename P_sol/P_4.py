def group_anagrams(strs):
    anagrams = {}

    for s in strs:
        # Usiamo una tupla dei caratteri ordinati come chiave del dizionario
        # Le tuple sono immutabili, quindi possono essere chiavi!
        key = tuple(sorted(s))
        if key not in anagrams:
            anagrams[key] = []
        anagrams[key].append(s)

    return list(anagrams.values())

# Test
parole = ["eat", "tea", "tan", "ate", "nat", "bat"]
print(group_anagrams(parole))
