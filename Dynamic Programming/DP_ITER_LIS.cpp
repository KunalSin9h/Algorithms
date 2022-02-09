#include <bits/stdc++.h>
using namespace std;

// Bottom-Up DP are mainly iterative

int main(){
    int n;cin >> n;
    vector<int> a(n), dp(n);
    for(int &i: a)cin >> i;

    dp[0] = 1; // Lenght of LIS ending with 0'th element of the array
    for(int i = 1;i<n; ++i){
        bool ch = false;
        for(int j = i-1; j>=0; --j){
            if(a[j] < a[i]){
                dp[i] = 1 + dp[j];
                ch = true;
                break;
            }
        }
        if(!ch)dp[i] = 1;
    }
    cout << *max_element(begin(dp), end(dp)) << '\n';
    return 0;
}