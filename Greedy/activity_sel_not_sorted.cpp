/*You are given n activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time. */

// This type of question are called as  Activity Selection Problem 

// Finish time is not sorted

#include <bits/stdc++.h>
using namespace std;

bool sec_sort(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> time(n);
    for(int i = 0;i<n; ++i){
        cin >> time[i].first;
    }
    for(int i =0;i<n; ++i){
        cin >> time[i].second;
    }

    sort(time.begin(), time.end(), sec_sort); 

    int ans = 0;
    int pre = -1;
    for(auto &p: time){
       if(p.first >= pre){
           ans++;
           pre = p.second;
       } 
    }

    cout << ans << endl;
}




int main(){
    solve();
    return 0;
}