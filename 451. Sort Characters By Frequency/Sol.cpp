string frequencySort(string s) {
	
    priority_queue<pair<int , char>>q;
    unordered_map<char , int>mpp;
    
    for(int i=0 ; i<s.length() ; i++)
    {
       mpp[s[i]]++;
    }
    
    
    for(auto p: mpp)
    {
        q.push({p.second , p.first});
    }
    string ans = "";
    while(!q.empty())
    {
        int n = q.top().first;
        while(n--)
        ans.push_back(q.top().second);
        q.pop();
    }
    
    return ans;
        
}

// Heap Approach
// Counting Frequencies: Similar to Solution 1, we start by counting the frequency of each character in the string s using an unordered map mp.

// Pushing to Priority Queue (Heap): Instead of using a vector, we use a priority queue (max heap) pq to store character-frequency pairs. This automatically sorts elements based on their frequencies, with higher frequencies coming first due to the nature of max heaps.

// Building the Result String: We pop elements from the priority queue one by one and append characters to the final answer string according to their frequencies until the priority queue is empty.

// Complexity
// Time complexity: O(N)
// count frequency : O(N)
// push to heap : O(62 * log(62)) = O(1)
// Build ans string: O(N)
// Space complexity: O(1)
// unordered_map size : O(62) = O(1)
// priority_queue size : O(62) = O(1)

// Optimization
// We know that a frequency array performs better than an unordered_map. Let's just convert the unordered_map we have used to a frequency array.

// We need to be careful doing this as the string contains Lowercase, Uppercase and Digits too.

// Our frequency array will look something like this.

// Which index represents which character is shown below.

// Index: 0  1 ... 25  26  27 ... 51  52  53 ... 61
// Char:  A  B     Z   a   b      z   0   1      9
// The Time and Space Complexity will still remain the same.
// Optimized Heap Approach
class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(62, 0);
        priority_queue<pair<int, char>> pq;
        string ans = "";

        // count character frequency
        for(auto ch: s){
            // is Digit
            if(ch < 'A') freq[52 + ch - '0']++;
            // is Uppercase
            else if(ch <= 'Z') freq[ch - 'A']++;
            // is Lowercase
            else freq[26 + ch - 'a']++;
        }

        // push from map to vector 
        for(int i=0; i<freq.size(); i++){
            if(freq[i] == 0) continue;
            // Uppercase
            if(i < 26) pq.push({freq[i], char(65 + i)});
            // Lowercase
            else if(i < 52) pq.push({freq[i], char(97 + (i - 26))});
            // Digit
            else pq.push({freq[i], char(48 + (i - 52))});
        }

        // add to final answer string
        while(!pq.empty()){
            pair<int, char> cur = pq.top();
            pq.pop();
            while(cur.first--) ans += cur.second;
        }
        return ans;
    }
};
