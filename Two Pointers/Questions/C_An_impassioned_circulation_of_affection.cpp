#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;cin >> N;
    string S;cin >> S;

    auto max_seg = [&](string s, char c){
        int n, ans, j;
        n = s.size();ans = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] != c)continue;
            j = i + 1;
            while(j < n && s[j] == c)j++;
            ans = max(ans, j - i);
            i = j;
        }
        return ans;
    };


    int Q;cin >> Q;
    while(Q--){
        int x;cin >> x;
        char c;cin >> c;
    }
    return 0;
}