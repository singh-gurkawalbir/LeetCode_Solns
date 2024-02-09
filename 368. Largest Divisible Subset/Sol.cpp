class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> groupSize(n, 1), prevElement(n, -1);
        int maxIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && groupSize[i] < groupSize[j] + 1) {
                    groupSize[i] = groupSize[j] + 1;
                    prevElement[i] = j;
                }
            }
            if (groupSize[i] > groupSize[maxIndex]) {
                maxIndex = i;
            }
        }

        vector<int> result;
        for (int i = maxIndex; i != -1; i = prevElement[i]) {
            result.insert(result.begin(), nums[i]);
        }
        return result;
    }
};

// Common Sense
// In Each group atleast one element would be present, so for size 1 we can have n no. of groups.

// Now let's make some sense, how would you add a number in the group
// Group: [1, 3, 6]
// and you have 9, would you be able to add ?
// Of Course not why because 9 would not be divisble by 6.

// What about 12 ? Yes you can add 12.

// Observation to Add New Number
// Now one more thing to observe here is If I just divide the newly (to be) added number by the maximum element of my group I can make sure the whole group is divided. ( Because the group's LCM is the maximum number )

// Can I add number less than the maximum number in group ?
// Well yes ! Let's see
// Group: [1, 4, 8]
// and now can I add 2 here ? yes ! Now new Group would be [1, 2, 4, 8]

// So I have to handle two things,

// If the number is greater or equal to maximum of group, then it should be divisible by maximum.
// If the number is less than maximum of group, it should divide all the group members.
// We can see that in first point, It is much easy to add I just need to know maximum but in second point I need to traverse the whole group to be able to add new element.

// What If Say, I Can handle both in First Point itself
// Previously we have seen two points by which we can add new number to a group.
// But What if I always make sure that I add new number using first point only. I mean what if I always make sure that the number I am adding is always greater than group ?

// Take a Pause and Think about it , How can we do it ?

// Okay, so basically I will sort the array to make sure the element which I am going to add is always greater.

// Now I don't need to know the group.

// So for current element, I can check all the previous and check divisibility and if it is divisble then it can be added to group so I will increase the group size by 1.

// Now I know the size, but here I also need to know the group element, So I also keep track of the element. So whenever I increase the group size I will add the previous element. So that I can backtrack the origin of the group. ( Group's starting point would be marked as -1 )

// Approach
// Sort the Array ( ascending order )
// For Each Element traverse the previous element
// If element is divisible by any previous element it means it can be part of that group by we also need to make sure it is part of the group with maximum size, So if we found any bigger group we will add it to that group
// If we update the group size, it means we have added new element I will update my previous of the current element with group's maximum till now ( before adding )
// I will also track the index of the last element added in the biggest group
// Now I will backtraverse from that maximum index ( defined in previous point ) using my previous element array and one by one add into my result list
// Complexity
// Time complexity: O(n^2)
// Space complexity: O(n)
