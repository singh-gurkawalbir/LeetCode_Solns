# Approach
# Initialize Frequency Maps: Two arrays, map1 and map2, of size 128 are created. These arrays are used to store the frequency of characters encountered in strings s and t, respectively. Since the ASCII character set has 128 characters, these arrays can efficiently store the frequency of each character encountered.

# Iterate Through Characters: The code iterates through each character of the strings s and t simultaneously using a single loop. For each character at position i, it retrieves the characters s_ch and t_ch.

# Mapping Characters:

# If both s_ch and t_ch haven't been encountered before (map1[s_ch] == 0 && map2[t_ch] == 0), it establishes a mapping between them. It sets map1[s_ch] to t_ch and map2[t_ch] to s_ch.
# If there's already a mapping but it doesn't match the current characters, it means the strings are not isomorphic, so it returns false.
# Return: After iterating through all characters, if no inconsistency is found, it returns true, indicating that the strings are isomorphic.

# This approach effectively determines if the given strings s and t are isomorphic by ensuring that each character in one string uniquely maps to a character in the other string, and vice versa, maintaining the isomorphism property. The use of frequency maps allows for efficient tracking of character mappings.

# Complexity
# Time complexity: O(n)O(n)O(n)
# Space complexity: O(1)O(1)O(1)
# Code
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        map1 = [0] * 128  # Stores frequency of s
        map2 = [0] * 128  # Stores frequency of t

        for i in range(len(s)):
            s_ch = s[i]
            t_ch = t[i]

            if map1[ord(s_ch)] == 0 and map2[ord(t_ch)] == 0:
                map1[ord(s_ch)] = ord(t_ch)
                map2[ord(t_ch)] = ord(s_ch)
            elif map1[ord(s_ch)] != ord(t_ch) or map2[ord(t_ch)] != ord(s_ch):
                return False
#         return True
# Now, let's see how this works with the example:

# For the first character 'e' in 'egg', it's not mapped yet. So, 'e' is mapped to 'a' and 'a' is mapped to 'e'.
# For the second character 'g' in 'egg', it's not mapped yet. So, 'g' is mapped to 'd' and 'd' is mapped to 'g'.
# For the third character 'g' in 'egg', it's not mapped yet. So, 'g' is mapped to 'd' and 'd' is mapped to 'g'.
# Since all mappings are consistent, the function returns True.
