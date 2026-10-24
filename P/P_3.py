def is_valid_parentheses(s):

    mapping = {")": "(", "}": "{", "]": "["}



# Test
print(is_valid_parentheses("{[()]}")) # True
print(is_valid_parentheses("{[(])}")) # False
print(is_valid_parentheses("{[(())]}")) # True
print(is_valid_parentheses("{[()]}}")) # False
print(is_valid_parentheses("{[]()[]]}")) # False
True
False
False
