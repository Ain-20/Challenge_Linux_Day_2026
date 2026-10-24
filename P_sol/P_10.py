def num_islands(grid):
    if not grid: return 0

    islands = 0
    rows, cols = len(grid), len(grid[0])

    def dfs(r, c):
        # Se usciamo dai bordi o troviamo acqua, ci fermiamo
        if r < 0 or c < 0 or r >= rows or c >= cols or grid[r][c] == "0":
            return
        # "Affondiamo" l'isola visitata per non contarla due volte
        grid[r][c] = "0"
        dfs(r+1, c)
        dfs(r-1, c)
        dfs(r, c+1)
        dfs(r, c-1)

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == "1":
                islands += 1
                dfs(r, c)

    return islands

# Test
griglia = [
  ["1","1","0"],
  ["1","0","0"],
  ["0","0","1"]
]
print(num_islands(griglia)) # 2
