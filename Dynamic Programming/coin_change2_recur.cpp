#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
* Find the number of ways to make the amount using coins
*/

int d, a;
vector<int> coins;

int memo[100005][105];

int dfs(int amount, int ind){
    if(amount == 0)return 1;
    if(ind == d) return 0;
    if(memo[amount][ind] != -1)return memo[amount][ind];
    int ways = 0; // number of ways 

    for(int coin_amount = 0;coin_amount <= amount; coin_amount += coins[ind]){
        ways += dfs(amount - coin_amount, ind + 1);
    }
    
    return  memo[amount][ind] = ways;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    memset(memo, -1, sizeof(memo));
    cin >> d >> a;
    coins.resize(d);
    for(int &i: coins)cin >> i;
    cout << dfs(a, 0) << '\n';
    return 0;
}