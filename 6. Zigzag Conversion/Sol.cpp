// Let's go through the code step by step to understand how the conversion is done.

// We start by creating a vector of strings ans with nR empty strings. Each string in the vector represents a row in the zigzag pattern.

// If the number of rows nR is 1, we return the original string s as it is already in zigzag pattern.

// We initialize a boolean variable flag as false. This flag is used to determine whether to move up or down between the rows.

// We iterate over each character ch in the string s.

// We append the character ch to the string at index i in the ans vector. The index i represents the current row.

// If i is the first row (index 0) or the last row (index nR-1), we toggle the value of flag. This ensures that we move up or down between the rows.

// If flag is true, we increment i by 1 to move down to the next row. Otherwise, we decrement i by 1 to move up to the previous row.

// After iterating over all the characters in the string, we concatenate all the strings in the ans vector to form the final converted string res.

// We return the converted string res.


class Solution {
public:
    string convert(string s, int nR) {
        vector<string>ans(nR,"");
        
        if(nR==1) return s;
        
        bool flag=false;
        
        int i=0;
        for(auto ch:s){
            ans[i]+=ch;
            
            if(i==0 || i==nR-1){
                flag=!flag;
            }
            
            if(flag){
                i+=1;
            }
            else{
                i-=1;
            }    
        }
    
    
        string res="";

        for(auto a:ans){
            res+=a;
        } 
        return res;
    }
};
