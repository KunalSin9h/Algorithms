#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int N = 10;
    for(int i = 0;i<N; ++i){
        int t = N - i;
        pq.push(t);
    }

    while(!pq.empty()){
        int t = pq.top();
        pq.pop();
        cout << t << ' ';
    }
    cout << '\n';


    return 0;
}