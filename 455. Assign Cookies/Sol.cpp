class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the greed factor array and the cookie size array
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int childIndex = 0;  // Index for children (g array)
        int cookieIndex = 0; // Index for cookies (s array)
        int numChildren = g.size();
        int numCookies = s.size();

        // Try to find a cookie for each child starting from the smallest
        while (childIndex < numChildren && cookieIndex < numCookies) {
            // If the cookie can satisfy the child
            if (s[cookieIndex] >= g[childIndex]) {
                childIndex++;  // Move to the next child
            }
            // Move to the next cookie regardless (either given or too small)
            cookieIndex++;
        }

        // Return the number of content children
        return childIndex;
    }
};

This solution runs in O(n log n + m log m) due to the sorting step, where n is the number of children and m is the number of cookies.
