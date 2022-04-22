#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;cin >> N;
    string S;cin >> S;
    
    int u = set<char>(S.begin(), S.end()).size();

    vector<int> sm(26), lar(26);
    auto uniq = [&]()->int{
        int t = 0;
        for(int &i : sm)t += i >= 1;
        for(int &i : lar)t += i >= 1;
        return t;
    };

    int ans = int(2e9);
    for(int i = 0, j = 0; j < N; ++j){
        (islower(S[j]) ? sm[(S[j] - 97)] : lar[(S[j] - 65)])++;
        while(true){
            (islower(S[i]) ? sm[(S[i] - 97)] : lar[(S[i] - 65)])--;
            if(uniq() == u){
                i++;
            }
            else{
                (islower(S[i]) ? sm[(S[i] - 97)] : lar[(S[i] - 65)])++;
                break;
            }
        }
        if(uniq() == u)ans = min(ans, j - i + 1);
    }
    cout << ans << '\n';
    return 0;
}
/**
 * Good Segment[l...r]: Segment with all species
 * we want to minimize the size of this good segment
 **/