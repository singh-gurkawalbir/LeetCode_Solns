class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int exchange=0;
        int emptyBottles=numBottles;

        while(emptyBottles>=numExchange){
            numBottles=emptyBottles/numExchange;
            emptyBottles=numBottles+(emptyBottles%numExchange);
            ans+=numBottles;
        }

        return ans;
    }
};
