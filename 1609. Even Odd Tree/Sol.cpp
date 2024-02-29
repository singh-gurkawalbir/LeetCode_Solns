// Intuition
// First thought that came in mind by seeing tree questions are bfs or dfs .Then as we have to checke a strictly increasing or decreasing order in levels so breadth first search would be a good approach to start .After that make an approach and implement it.

// Approach
// Here's the explanation of the code:

// 1-Breadth-First Search (BFS): The code uses BFS to traverse the tree level by level. It utilizes a queue to keep track of the nodes at each level.

// 2- Flag for Alternating Levels: It uses a boolean flag flag to determine whether the current level should have odd or even values.

// 3-Conditions Checking: Inside the BFS loop, the code checks the following conditions for each node:

// 4- If the current level is odd (flag is true), then the node value should be odd, and it should be strictly greater than the previous node's value.

// 5- If the current level is even (flag is false), then the node value should be even, and it should be strictly less than the previous node's value.

// 6- If any of these conditions are not met, the function returns false immediately.

// 7- Updating Queue: The code enqueues the left and right children of each node (if they exist) into the queue for the next level.

// 8- Updating Previous Value: The variable prev is updated with the value of the current node, ensuring it's used in the next iteration for comparison.

// 9- Alternating Levels: After processing each level, the flag is toggled to switch between odd and even levels.

// 10- Returning Result: If the BFS completes without encountering any violation of conditions, the function returns true, indicating that the tree is an Even-Odd Tree.

// Complexity
// Time complexity:0(n) because each node traversed once
// Space complexity:0(n)because of queue

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        queue<TreeNode*>q;
        bool flag=true;
      
        q.push(root);
        while(!q.empty()){
            int x = q.size() ;
            int prev = flag ? INT_MIN : INT_MAX;
            for(int i=0; i< x; i++){
                TreeNode* frontNode = q.front();
                q.pop();  
                if(flag){
                    if(frontNode->val %2==0 || frontNode->val <=  prev){
                     return false;
                    }
                }
                else{
                    if(frontNode->val %2!=0  || frontNode->val  >= prev){
            
                        return false;
                    }
                }

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
                prev= frontNode->val;
            }
            flag=!flag;
        }
        return true;
    }
};
