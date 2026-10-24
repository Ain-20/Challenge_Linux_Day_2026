from collections import Counter

def intersect(nums1, nums2):
    # Contiamo le occorrenze nella prima lista
    counts = Counter(nums1)
    res = []

    for num in nums2:
        # Se il numero esiste nel contatore con frequenza > 0
        if counts.get(num, 0) > 0:
            res.append(num)
            counts[num] -= 1 # Riduciamo la frequenza

    return res

# Test
print(intersect([4, 9, 5], [9, 4, 9, 8, 4])) # [4, 9] (o [9, 4])
