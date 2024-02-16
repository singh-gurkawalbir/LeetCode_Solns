class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int& x : arr) {
            mp[x]++;
        }
        
        vector<int> freq;
        for (auto& pair : mp) {
            freq.push_back(pair.second);
        }
        
        sort(begin(freq), end(freq));
        
        int count = 0;
        for (int& f : freq) {
            if (k >= f) {
                k -= f;
                count++;
            } else {
                break;
            }
        }
        
        return freq.size() - count;
    }
};

Intuition
Approach
Count frequencies: First, we need to count the frequency of each integer in the array. We can use a hash map (dictionary in Python) to store the frequency of each integer.

Sort frequencies: Next, we sort the frequencies in ascending order. This step allows us to consider removing integers with the lowest frequencies first.

Remove elements: We iterate through the sorted frequencies. For each frequency, if the remaining number of elements to remove (k) is greater than or equal to the current frequency, we remove all occurrences of the integer with that frequency. 
We update k accordingly. If k becomes less than the current frequency, we stop the iteration because we cannot remove more elements without violating the condition.

Count remaining unique integers: Finally, we count the number of unique integers remaining after removals. This count represents the least number of unique integers after removing k elements.
Complexity
Time complexity:
O(nlogn)

Space complexity:
O(n)
