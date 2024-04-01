class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int right=s.size()-1;
        while(right>=0){
            if(s[right]!=' '){
                ans++;
            }
            else{
                if(ans>0){
                    return ans;
                }
            }
            right--;
        }

        return ans;
    }
};

//  Here ans = 0 and right = 26 (size-1)
// - Now, it starts at right = 26. Here as s[right]==' ', it checks if ans>0. As ans=0, it decrements right.
// - Now right = 25. Here as s[right]==' ', it checks if ans>0. As ans=0, it decrements right.
// - Right = 24. s[right]=='n', ans++ and right--. Thus, ans = 1 and right = 23.
// - Right = 23. s[right]=='0', ans++ and right--. Thus, ans = 2 and right = 22.
// - Right = 22. s[right]=='0', ans++ and right--. Thus, ans = 3 and right = 21.
// - Right = 21. s[right]=='m', ans++ and right--. Thus, ans = 4 and right = 20.
// - As s[right]==' ', it checks if ans>0. As ans>0, return ans.

// Complexity
// Time complexity:
// The code uses a single while loop that iterates through the characters of the input string from right to left.
// Each iteration involves constant time operations (comparisons and increments).
// The time complexity is O(n), where n is the length of the input string.

// Space complexity:
// The space complexity is constant as the code only uses a constant amount of extra space regardless of the input size.
// The only variables used are ans and right, and their space requirements do not depend on the size of the input.
// The space complexity is O(1).

// traverse from right
// If initially spaces are found , ignore it.
// if any other character found start counting it unlill next space found.
// If space found just return the count
// Complexity
// Time complexity:O(n) , as the whole string can be one sentence

// Space complexity:O(1)

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == ' ' and count == 0:
                continue
            if s[i] == ' ' and count != 0:
                return count
            if s[i] != ' ':
                count += 1
        return count

// Approach
// we can use trim() inbuilt function to remove padding sapces ie on the start and end
// now we have spaces left in the middle only
// let us split them using the space as a seperator
// from them we need to return the last element's length
// thats it 😄😄
// thank you😄😄
// hope you understood if not comment below i will help

// Complexity
// Time complexity:O(N)
// Space complexity:O(N)

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words=s.split()
        return len(words[-1])
