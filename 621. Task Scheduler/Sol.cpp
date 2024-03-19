// Intuition
// find the maximum occurence of any character store in mx,find how many characters have the same maximum(mx) occurence store in cnt.

// Approach
// if cnt is less than (n+1) then idle might exist in between which can be filled if there exist characters with occurence less than mx.
// so total time with these cnt characters with mx occurence need atleast ((mx-1)(n+1) + cnt) ignore the last idle which we need not count if it exists.
// Now since there can exist other characters which might fill up the idle spaces in between with characters whose occurence is less 
// than mx which might exceed the ((mx-1) n+1) + cnt) but anyway it cannot be more than tn (the number of tasks) So taking max of ((mx-1)*(n+1) + cnt) and tn.
// Complexity
// Time complexity:
// O(n)

// Space complexity:
// // O(1)
// The formula (mx-1)*(n+1) + cnt accurately determines the minimum number of intervals needed for task execution with cooldown periods by considering the 
// maximum frequency of a task (mx), the cooldown period (n), and the count of tasks that have the maximum frequency (cnt). This formula ensures that tasks 
// are executed efficiently with the cooldown period taken into account.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int tn=tasks.size();
        int arr[26]={0};
        for(auto e: tasks){
            arr[e-65]++;
        }
        int mx=0;
        for(int i=0; i<26; i++){
            mx = max(mx, arr[i]);
        }

        int cnt=0;
        for(int i=0; i<26; i++){
            if (arr[i]==mx){
                cnt++;
            }
        }

        return max((mx-1)*(n+1) +cnt, tn);
    }
};

