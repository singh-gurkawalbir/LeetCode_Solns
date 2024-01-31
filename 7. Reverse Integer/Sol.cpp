// Approach
// First we decleare a variable r and initilise it to 0
// Then each time find remainder Using modulus Operator
// Then add remainder to r Lets Understand with example

// Then compare The value of r to check it is inside the 32-bit integer range [-2^31, 2^31 - 1] Then return r
// // Otherwise return 0;
// Time complexity:
// O(log10(x)) - The time complexity is proportional to the number of digits in the input integer.
// Space complexity:
// O(1) - The algorithm uses a constant amount of space, regardless of the input size.

class Solution {                      
public:
    int reverse(int x) {
        int r=0;      // decleare r 
        while(x){
         if (r>INT_MAX/10 || r<INT_MIN/10) return 0; // check 32 bit range if r is outside the range then return 0 
         r=r*10+x%10; // find remainder and add its to r
         x=x/10;     // Update the value of x
        } 
        return r;  // if r in the 32 bit range then return r
    }
}; 
