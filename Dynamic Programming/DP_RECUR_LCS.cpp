#include <bits/stdc++.h>
using namespace std;
/*
* You are given strings s and t. Find one longest string that is a subsequence of both s and t.
*
*   SUBSEQUENCE -
*   A subsequence of a string x is the string obtained by removing zero or more characters from x 
    and concatenating the remaining characters without changing the order
*/

/* RECURSIVE */

string S, T; // Max lenght is upto 1e3;

int memo[int(1e3)][int(1e3)];

int dfs(int ss, int st){
    if(ss < 0)return 0;
    if(st < 0)return 0;
    if(memo[ss][st] != -1)return memo[ss][st];
    if(S[ss] == T[st]){
        return memo[ss][st] = 1 + dfs(ss-1, st-1);
    }
    return memo[ss][st] = max(
        dfs(ss, st-1),
        dfs(ss-1, st)
    );
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    memset(memo, -1, sizeof(memo));
    cin >> S >> T;
    int a = S.size() - 1;
    int b = T.size() - 1;
    cout << dfs(a, b) << '\n';
    return 0;
}