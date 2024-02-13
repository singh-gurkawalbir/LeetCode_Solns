class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            string s=i;
            reverse(s.begin(),s.end());
            if(s==i){
                return s;
            }
        }
        return "";
    }
};

// Objective: Find the first palindrome in a vector of strings.

// For Loop: Iterates through each string in the vector.

// String Reversal: Reverses the string using the reverse() function.

// Palindrome Check: Compares the reversed string with the original.

// Result Handling: Returns the first palindrome or an empty string.

// Time Complexity-O(n⋅max_len)
// n= size of vector
// max_len=max len of the string
