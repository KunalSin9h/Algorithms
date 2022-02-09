#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<vector<int>> store;
vector<int> given;


void all_combinations(vector<int> &b, int n, int cnt){
    if(cnt == n){
        store.push_back(b);
        return;
    } 
    b.push_back(given[cnt]);
    all_combinations(b, n, cnt+1);
    b.pop_back();
    all_combinations(b, n, cnt+1);
}

int main(){
    int N;cin >> N;
    given.resize(N);
    for(int i = 0;i<N; ++i){
        cin >> given[i];
    }
    vector<int> b;
    all_combinations(b, N, 0);
    for(auto &v: store){
        cout << "[ ";
        for(int &i: v){
            cout << i << " ";
        }
        cout << "]" << '\n';
    }
    return 0;
}

/*
* Time -> O(2^n + 2^n*n) -> O(2^n*n)
*
*/