class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(begin(coins), end(coins), greater<int>());
        int n = coins.size();
        int change = 0;
        while(amount > 0){
            int coin = 0;
            int i = 0;
            for(i; i<n; ++i){
                if(coins[i] <= money){
                    coin = coins[i];
                    break;
                }
            }
            if(i ==n){
                return -1;
            }
            chagne++;
            money -= coin;
        }
        return change;
    }
};