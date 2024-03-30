Intuition

Approach

This code implements a solution to find the number of subarrays in an array nums that contain exactly k distinct elements. Here's a brief explanation of the algorithm:

checkSubarrayAtmostK: This function calculates the number of subarrays with at most k distinct elements. It uses a sliding window approach with two pointers, i and j, to maintain a window of elements. It also uses an unordered map mpp to keep track of the count of each element within the current window.

i and j are initialized to 0.
Iterate through the array with the j pointer.
Increment the count of nums[j] in the map mpp.
While the number of distinct elements in the window (mpp.size()) is greater than k, move the i pointer forward and decrement the count of nums[i] in mpp. If the count becomes 0, remove nums[i] from mpp.
Update the count by adding the length of the current subarray (j - i) + 1.
Increment j to expand the window.
subarraysWithKDistinct: This function calculates the number of subarrays with exactly k distinct elements by subtracting the count of subarrays with at most k-1 distinct elements from the count of subarrays with at most k distinct elements.

Calls checkSubarrayAtmostK(nums, k) to get the count of subarrays with at most k distinct elements.
Calls checkSubarrayAtmostK(nums, k-1) to get the count of subarrays with at most k-1 distinct elements.
Returns the difference between the counts.
Overall, this algorithm efficiently finds the number of subarrays with exactly k distinct elements by leveraging the count of subarrays with at most k distinct elements and those with at most k-1 distinct elements.

Complexity

Time complexity:O(N)
Space complexity:O(N)
Code

class Solution {
public:

    int checkSubarrayAtmostK(vector<int>& nums, int k){
        int n=nums.size();
        int i=0,j=0,count=0;
        unordered_map<int , int> mpp;

        while(j<n){
            mpp[nums[j]]++;


            while(i<=j && mpp.size()>k ){

                mpp[nums[i]]--;

                if( mpp[nums[i]] == 0 )  mpp.erase(nums[i]);

                i++;
            }

            count+=(j-i)+1;
            j++;
        }

        return count;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return checkSubarrayAtmostK(nums, k)-checkSubarrayAtmostK(nums , k-1);
    }
};
