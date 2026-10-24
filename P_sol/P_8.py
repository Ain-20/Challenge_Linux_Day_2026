def max_area(height):
    left, right = 0, len(height) - 1
    max_water = 0

    while left < right:
        # L'area è determinata dall'altezza minore tra le due linee
        width = right - left
        current_water = min(height[left], height[right]) * width
        max_water = max(max_water, current_water)

        # Sposta il puntatore della linea più bassa sperando di trovarne una più alta
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return max_water

# Test
print(max_area([1,8,6,2,5,4,8,3,7])) # 49
