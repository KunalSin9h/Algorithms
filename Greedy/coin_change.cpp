#include <iostream>
using namespace std;

typedef long long ll;

int GreedyChange(int coins[], int n, int money){
    int change = 0;
    while(money > 0){
        int coin = 0;
        int i = 0;
        for(i;i<n; ++i){
            if(coins[i] <= money){
                coin = coins[i];
                break;
            }
        }
        if( i == n ){
            return -1;
        }
        change++;
        money -= coin;
    }
    return change;
}


int main(){
    int a[] = {20};
    int money = 40 ;
    int n = sizeof(a)/sizeof(a[0]);
    int ans = GreedyChange(a, n,money );
    cout << ans << endl;
    return 0;
}