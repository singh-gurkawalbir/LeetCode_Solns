class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0;
        int size = 0;
        int ans = 0;

        unordered_map<int, int> map;

        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
            while (map[s[i]] > 1)
            {
                if (s[l] != s[i])
                {
                    map.erase(s[l]);
                }
                else
                    map[s[i]]--;
                l++;
            }

            size = map.size();
            ans = max(size, ans);
        }
        return ans;
    }
};


```
// Let's perform a dry run of the `lengthOfLongestSubstring` function using the input string `"pwwkep"`.

// ### Initial Setup:
// - `l = 0` (left pointer)
// - `size = 0` (current size of the substring without repeating characters)
// - `ans = 0` (maximum size found so far)
// - `map = {}` (hash map to track character frequency)

// ### Iteration over the string:

// 1. **i = 0, s[i] = 'p'**
//    - Update map: `map = {'p': 1}`
//    - No repetition, so calculate size: `size = i - l + 1 = 1`
//    - Update ans: `ans = max(ans, size) = 1`

// 2. **i = 1, s[i] = 'w'**
//    - Update map: `map = {'p': 1, 'w': 1}`
//    - No repetition, so calculate size: `size = i - l + 1 = 2`
//    - Update ans: `ans = max(ans, size) = 2`

// 3. **i = 2, s[i] = 'w'**
//    - Update map: `map = {'p': 1, 'w': 2}`
//    - Repetition detected (`'w'`), adjust `l`:
//      - `s[l] = 'p'`, not equal to `s[i]`, remove `p`: `map = {'w': 2}`
//      - Increment `l`: `l = 1`
//      - `s[l] = 'w'`, equal to `s[i]`, decrement `w`: `map = {'w': 1}`
//      - Increment `l`: `l = 2`
//    - Calculate size: `size = i - l + 1 = 1`
//    - Update ans: `ans = max(ans, size) = 2`

// 4. **i = 3, s[i] = 'k'**
//    - Update map: `map = {'w': 1, 'k': 1}`
//    - No repetition, so calculate size: `size = i - l + 1 = 2`
//    - Update ans: `ans = max(ans, size) = 2`

// 5. **i = 4, s[i] = 'e'**
//    - Update map: `map = {'w': 1, 'k': 1, 'e': 1}`
//    - No repetition, so calculate size: `size = i - l + 1 = 3`
//    - Update ans: `ans = max(ans, size) = 3`

// 6. **i = 5, s[i] = 'p'**
//    - Update map: `map = {'w': 1, 'k': 1, 'e': 1, 'p': 1}`
//    - No repetition, so calculate size: `size = i - l + 1 = 4`
//    - Update ans: `ans = max(ans, size) = 4`

// ### Final Result:
// - The length of the longest substring without repeating characters is `4`, corresponding to the substring `"wkep"`.
