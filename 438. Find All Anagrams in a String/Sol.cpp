class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp1, mp2;
        for(auto ch : p)    mp1[ch]++;
        int i =0,j=0,k = s.size(),n = p.size();
        vector<int> ans;
        while(j<k){
            mp2[s[j++]]++;
            if(j-i == n){
                if(mp1 == mp2)  ans.push_back(i);
                mp2[s[i]]--;
                if(mp2[s[i]] == 0)  mp2.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};

Time complexity: O(N)
Space complexity: O(Sizeofthestring)
Overall Complexity:The overall time complexity of the algorithm is (O(n + k)), where (n) is the length of p and (k) is the length of s. 
The (O(n)) comes from initializing mp1, and (O(k)) comes from the sliding window loop over s.

// This C++ code snippet defines a class `Solution` with a public member function `findAnagrams`. The purpose of this function is to find all the starting indices of the anagrams of a string `p` within another string `s`. Here's a breakdown of how the code works:

// 1. **Data Structures**:
//    - Two unordered maps `mp1` and `mp2` are used to store the frequency of characters. `mp1` is used for the string `p`, and `mp2` is used for the current window of characters in `s`.

// 2. **Initialization**:
//    - The function iterates over each character in `p` and populates `mp1` with the frequency of each character.

// 3. **Sliding Window Technique**:
//    - The function uses two pointers, `i` and `j`, to represent the current window in `s`. Initially, both are set to 0.
//    - `k` is the length of `s`, and `n` is the length of `p`.

// 4. **Main Loop**:
//    - The loop continues until `j` reaches the end of `s`.
//    - For each character `s[j]`, it increments its count in `mp2` and then increments `j`.
//    - If the current window size (`j - i`) equals `n` (the length of `p`), it checks if `mp1` and `mp2` are equal. If they are, it means the current window is an anagram of `p`, and the starting index `i` is added to the result vector `ans`.
//    - The character at the start of the window `s[i]` is decremented in `mp2`. If its count becomes zero, it is removed from `mp2` to keep the map clean.
//    - The start of the window `i` is then incremented to slide the window forward.

// 5. **Return Value**:
//    - The function returns the vector `ans`, which contains all the starting indices of the anagrams of `p` found in `s`.

// This algorithm efficiently finds all anagrams using the [sliding window technique](https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/) and hash maps to keep track of character frequencies, ensuring that the solution is optimal for large strings.
        
