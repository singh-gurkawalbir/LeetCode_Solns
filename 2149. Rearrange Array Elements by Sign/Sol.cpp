// Approach:
// Here we are directly putting values in the ans vector with the help of 2 pointer approach where initially both the indexes pos and neg are 0 and 1.
// If we encounter positive element then will put values in the ans vector with the help of ans[pos] = nums[i] and if found negative element then ans[neg] = nums[i].

// Here, we can't use ans.push_back() to add elements because
//  we're not appending values sequentially. Instead, we're placing
//  values at specific indexes based on the element we have.

// The number 1....6 are the order in which the elements where
//  pushed into the ans vector.

// Complexity
// Time complexity:
// O(n)

// Space complexity:
// O(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        
        
        int pos=0,neg=1;
        

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[pos] = nums[i];
                pos+=2;
            }else{
                ans[neg] = nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};


