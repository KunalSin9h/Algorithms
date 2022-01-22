#include <bits/stdc++.h>
using namespace std;

/*
* Find the number of ways of making the total amount through given denominations
*/

int d, a;
vector<int> coins;
/*
int dfs(int amount){
    if(amount == 0){
        return 1;
    }
    int ways = 0;
    for(int &j: coins){
        if(j <= amount)
            ways += dfs(amount - j);
    }
    return ways;
}
*/
// 1, 2, 5
int dfs(int ind, int amount){
    if(amount == 0){
        return 1;
    }
    if(ind == d){
        return 0;
    }
    int ways = 0;
    for(int i = 0;coins[ind]*i <= amount; i++){
        ways += dfs(ind + 1, amount - coins[ind]*i);
    }
    return ways;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> d >> a;
    coins.resize(d);
    for(int &i: coins)cin >> i;
    cout << dfs(0, a) << '\n';
    return 0;
}

