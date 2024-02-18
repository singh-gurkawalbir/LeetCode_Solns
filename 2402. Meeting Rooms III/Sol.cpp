// Intuition
// The intuition behind the solution is to simulate the scheduling of meetings in rooms, keeping track of the end times and available rooms.

// Approach
// use a priority queue to track the end times of ongoing meetings (min heap based on end times).

// Use a set to store available rooms.

// Sort the meetings based on their start times.

// Iterate through the sorted meetings:

// Release rooms whose meetings have ended.

// If no available rooms, delay the meeting with the same duration.

// Assign the meeting to the lowest available room.

// Update the priority queue and set accordingly.

// Count the number of meetings in each room and find the room with the maximum meetings.

// Complexity
// Time complexity:
// O(m log m), where m is the number of meetings (due to sorting).

// Space complexity:
// O(n)
#define ll long long
#define pi pair<ll,ll>

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& A) {
        vector<int> roomcnt(n,0);
        set<int> s;
        priority_queue<pi,vector<pi>,greater<pi>> q;
        sort(A.begin(),A.end());
        int m=A.size();
        // store available rooms
        for(int i=0;i<n;i++){
            s.insert(i);
        }
        for(int i=0;i<m;i++){
            ll start=A[i][0];
            ll end=A[i][1];
            // storing available room in set 
            while(q.size()>0 && q.top().first<=start){
                int room=q.top().second;
                q.pop();
                s.insert(room);
            }
            // delaying the current meeting
            if(s.size()==0){
                pair<ll,ll> p=q.top();
                q.pop();
                ll dif=end-start;
                start=p.first;
                end=start+dif;
                s.insert(p.second);
            }
            // lowest number of unsed room available
            auto it=s.begin(); 
            roomcnt[*it]++;
            // assign meeting to lowest avaible room
            q.push({end,*it});
            s.erase(*it);
        }
        int ans=0;
        int maxi=0;
        // find room with maximum meetings
        for(int i=0;i<n;i++){
            if(maxi<roomcnt[i]){
                maxi=roomcnt[i];
                ans=i;
            }
        }
        return ans;
    }
};
