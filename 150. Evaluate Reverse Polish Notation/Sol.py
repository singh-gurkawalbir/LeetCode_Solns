# This is a classic example of a stack problem. We are given an expression, and we have to evaluate it. Let's see how we can do that.

# Consider the following example:

# Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
# We will take this array and shorten it to get an array of size one. We will use the stack for this problem. Initially, the stack is empty. When iterating over the array "tokens," if tokens[i] is a number, we push it to the stack. If it is an operator, we operate on the last two values in the stack and push the operation's output back to the stack.

# stack<int> s;
# Iterating over the array till "3" and pushing all these elements to stack the stack is s = {10, 6, 9, 3}

# Step 1: ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
# We encountered "+," so we popped the last two elements and performed the operation, which is 9 + 3 = 12. And then push this number back to the stack. s = {10, 6, 12}

# Step 2:  ["10","6","12","-11","*","/","*","17","+","5","+"]
# We pushed "-11" to stack and got the * operator. Again, the same steps pop the last two elements from the stack, apply the operation, and push the result back to the stack. So, 12 * (-11) = -132. Now, s = {10, 6, -132}

# Step 3: ["10","6","-132", "/","*","17","+","5","+"] 
# We get the "/" divide operator. So again, applying the same steps, pop the last two elements from the stack, apply the operation, and push the result back to the stack. So, 6 / (-132) = 0 (As it is given in the problem statement that "The division between two integers always truncates toward zero"). Now, s = {10, 0}

# Step 4: ["10","0","*","17","+","5","+"]
# We get the * multiply operator. Now, after applying the operation, s = {0, 17}

# Step 5: ["0","17","+","5","+"]
# Encountered "+". So, after 0 + 17, stack becomes s = {17, 5}

# Step 6: ["17","5","+"]
# This is the final step; only two elements are left in the stack, and only one operation is to be done. So, After doing this addition, we get 17 + 5 = 22, which is the answer.

# Step 7: ["22"]

class Solution {
public:
    
    int evalRPN(vector<string>& a) {
        stack<int> s;
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] != "+" && a[i] != "-" && a[i] != "/" && a[i] != "*"){
                s.push(stoi(a[i])); //if a[i] is an integer, push to the stack
            }else{ //else apply the operation
                int x = s.top(); s.pop();
                int y = s.top(); s.pop();
                if(a[i] == "+"){
                    s.push(y + x);
                }else if(a[i] == "-"){
                    s.push(y - x);  //Notice that operation is y - x not x - y
                }else if(a[i] == "*"){
                    s.push(y * x);
                }else if(a[i] == "/"){
                    s.push(y / x); //Notice that operation is y/x not x/y
                }
            }
        }
        return s.top();
    }
};
