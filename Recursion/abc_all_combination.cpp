#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<vector<int>> store;
vector<int> given;

int op = 0;

void all_combinations(vector<int> &b, int n, int cnt){
    op++;
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
    int op2 = 0;
    for(auto &v: store){
        cout << "[ ";
        for(int &i: v){
            op2++;
            cout << i << " ";
        }
        cout << "]" << '\n';
    }

    cout <<"Operations 1 -> " << op << '\n';
    cout <<"Operations 2 -> " << op2 << '\n';
    return 0;
}

/*
* Time -> O(2^n + 2^n*n) -> O(2^n*n)
*
*/