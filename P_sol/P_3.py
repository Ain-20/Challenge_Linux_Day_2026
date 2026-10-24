def is_valid_parentheses(s):
    stack = []
    mapping = {")": "(", "}": "{", "]": "["}

    for char in s:
        if char in mapping:
            # Estrae l'ultimo elemento o un dummy se lo stack è vuoto
            top_element = stack.pop() if stack else '#'
            if mapping[char] != top_element:
                return False
        else:
            stack.append(char)

    # Se lo stack è vuoto alla fine, tutte le parentesi sono state chiuse
    return not stack

# Test
print(is_valid_parentheses("{[()]}")) # True
print(is_valid_parentheses("{[(])}")) # False
print(is_valid_parentheses("{[(())]}")) # True
print(is_valid_parentheses("{[()]}}")) # False
print(is_valid_parentheses("{[]()[]]}")) # False
True
False
False
