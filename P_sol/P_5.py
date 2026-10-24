def compress_string(s):
    if not s: return ""

    result = []
    count = 1

    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            count += 1
        else:
            result.append(s[i-1] + str(count))
            count = 1

    # Aggiunge l'ultimo gruppo
    result.append(s[-1] + str(count))
    compressed = "".join(result)

    return compressed if len(compressed) < len(s) else s

# Test
print(compress_string("aabcccccaaa")) # a2b1c5a3
print(compress_string("abc"))         # abc (la compressa a1b1c1 sarebbe più lunga)
