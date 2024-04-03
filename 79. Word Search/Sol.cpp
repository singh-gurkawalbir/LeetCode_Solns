// Algo
// Depth-First Search (DFS):

// Perform a DFS on the grid starting from each cell.
// At Each Cell (i, j) in the Grid:

// Check if the character at (i, j) matches the first character of the word.
// If it matches:
// Proceed to search for the remaining characters of the word recursively by exploring adjacent cells.
// Continue this process until all characters of the word are found or until reaching the end of the grid.
// During the DFS:

// Use a recursive DFS function that takes the current cell (i, j), the word to search for, and the index of the current character being searched in the word.
// Update the index to search for the next character in the word as traversing the grid.
// Backtrack if the character at the current cell does not match the expected character in the word.
// If All Characters of the Word Are Found:

// Return true.
// If the Word Is Not Found in the Grid:

// Return false.
// Found here : https://leetcode.com/problems/word-search/solutions/4965284/easily-explained-with-visualization-c-java-python/?envType=daily-question&envId=2024-04-03
class Solution {
public:
    bool dfs(int i,int j,int count,vector<vector<char>>& board,string word)
    {
        // if we have found the whole string then count will become (word.length()==count) so return true
        if(word.length()==count) return true;
        
        // check for boundary                                  // curr char is not same with word char
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[count])
            return false;
        
        
        
        char temp = board[i][j];                    // curr char
        board[i][j] = ' ';                          // mark as visited
        
        
        // up , down , left , right (possible moves)
        bool ans = dfs(i-1,j,count+1,board,word) || 
                   dfs(i+1,j,count+1,board,word) ||
                   dfs(i,j-1,count+1,board,word) ||
                   dfs(i,j+1,count+1,board,word);
        
        board[i][j] = temp;                         // make board as it is for the upcoming calls
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();                   // rows
        int m = board[0].size();                // cols
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && dfs(i,j,0,board,word))                // whenever we found first letter of word start searching from there
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
