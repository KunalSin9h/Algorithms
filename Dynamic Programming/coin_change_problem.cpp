class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // using DP-> Dynamic Programming
        vector<int> change(amount + 1);
        change[0] = 0;
        for(int m = 1;m<=amount; ++m){
            change[m] = 1e9;
            for(int i = 0;i<coins.size(); ++i){
                if(m >= coins[i]){
                    int t = change[m-i] + 1;
                    if(t < change[m])   
                        change[m] = t;
                }
            }

        }
        return change[amount];
    }
};
