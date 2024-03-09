class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0 , j = 0;
        int n = nums1.size();
        int m = nums2.size();
        while(i < n && j < m){
            if(nums1[i] == nums2[j])
                return nums1[i];
            else if(nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return -1;
    }
};

// Approach
// We can initialize two pointers, one for each array, and iterate through both arrays simultaneously. At each step, we compare 
// the elements pointed to by the pointers. If the elements are equal, we return that element. If the element in the first array is 
// greater than the element in the second array, we increment the pointer for the second array, and vice versa. We continue this p
// rocess until we find a common element or exhaust one of the arrays.

// Complexity
// Time complexity: O(n+m)O(n + m)O(n+m), where nnn and mmm are the sizes of the two input arrays, respectively. We traverse through both arrays once.
// Space complexity: O(1)O(1)O(1), as we are not using any extra space that scales with the input size.

// Let's dry run the code with the given test case:

// Given: nums1 = [1,2,3,6], nums2 = [2,3,4,5]

// Initialize i = 0 and j = 0.
// Compare nums1[0] (which is 1) with nums2[0] (which is 2). Since 1 is less than 2, increment i.
// Now compare nums1[1] (which is 2) with nums2[0] (which is 2). They are equal, so return 2.
// The common element is 2.
