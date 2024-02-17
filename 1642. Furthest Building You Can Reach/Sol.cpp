class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        
        priority_queue<int> p;
    
        int i=0, diff =0; 
        for(i=0; i<h.size()-1; i++){ 
            
            diff = h[i+1]-h[i];

            if(diff <= 0){
                continue;
            }
            b -= diff; 
            p.push(diff); 

            if(b < 0){
                b += p.top(); 
                p.pop(); 
                l--;
            }
            if(l < 0) break;
        }
        return i;
    }
};

// Approaches
// Priority Queue Setup:

// The code defines a function furthestBuilding that takes a vector h representing the heights of buildings, an integer b representing the initial number of bricks, and an integer l representing the maximum number of steps you can use ladders.
// Inside the function, a priority queue p is created to store the bricks used in each step in decreasing order. This queue is a max heap, meaning the largest element is at the top.
// Iterating Through Buildings:

// The code iterates through each pair of adjacent buildings using a for loop, starting from the first building (i=0) and ending at the second-to-last building (i<h.size()-1).
// Calculating Height Difference:

// At each step, the code calculates the height difference (diff) between the current building and the next building.
// Checking Bricks and Ladders:

// If the height difference (diff) is less than or equal to 0, it means no additional bricks are required to climb to the next building, so the loop continues to the next iteration.
// If the height difference (diff) is greater than 0, it means additional bricks are required to climb to the next building. These bricks are deducted from the available bricks (b) and added to the priority queue (p).
// If the remaining number of bricks (b) becomes negative after deducting the required bricks, it means the available bricks are not sufficient to climb to the next building. In this case, the code uses a ladder from the priority queue (p) by adding the largest previously deducted number of bricks to the available bricks and reducing the number of available ladders (l) by 1.
// If the remaining number of ladders (l) becomes negative, it means there are no ladders left, and the loop breaks.
// Returning Furthest Building:

// The function returns the index (i) of the furthest building that can be reached with the given number of bricks and ladders.
// Complexity
// Time complexity:
// O(nlogk)

// Space complexity:
// O(min(n,l))
