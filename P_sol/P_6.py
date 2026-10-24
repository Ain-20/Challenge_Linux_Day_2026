def spiral_order(matrix):
    result = []
    while matrix:
        # Prende la prima riga
        result += matrix.pop(0)

        # Prende l'ultimo elemento delle righe rimanenti (colonna destra)
        if matrix and matrix[0]:
            for row in matrix:
                result.append(row.pop())

        # Prende l'ultima riga al contrario
        if matrix:
            result += matrix.pop()[::-1]

        # Prende il primo elemento delle righe rimanenti dal basso verso l'alto (colonna sinistra)
        if matrix and matrix[0]:
            for row in matrix[::-1]:
                result.append(row.pop(0))

    return result

# Test
matrice = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(spiral_order(matrice))
