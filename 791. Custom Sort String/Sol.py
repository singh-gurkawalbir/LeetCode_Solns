class Solution(object):
    def customSortString(self, order, s):
        char_count = {char: 0 for char in order}
        for char in s:
            if char in char_count:
                char_count[char] += 1
    
        sorted_s = ''
        for char in order:
            sorted_s += char * char_count[char]
    
        for char in s:
            if char not in order:
                sorted_s += char

        return sorted_s
        
# 1. It initializes a dictionary `char_count` with characters from `order` as keys and initial count 0.
# 2. It then iterates through the characters in string `s` and increments the count in `char_count` for each character that is in `order`.
# 3. It creates an empty string `sorted_s` and iterates through the characters in `order`, appending each character multiplied by its count in `char_count` to `sorted_s`.
# 4. Finally, it iterates through the characters in `s` and appends any character that is not in `order` to `sorted_s`.
# 5. The method returns the final sorted string `sorted_s` based on the order specified in the `order` parameter.
