#include "bits/stdc++.h"
using namespace std;

constexpr int mx = int(1e5) + 10;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    vector<array<int, 4>> A(mx);

    for(int i = 0, sz; i < 4; ++i){
        cin >> sz;
        for(int j = 0, x; j < sz; ++j){
            cin >> x;
            int t = x;
            x--;
            A[x][i] = t;
        }
    }

    int cnt_a = 0, cnt_b = 0, cnt_c = 0, cnt_d = 0;
    set<int> a, b, c, d;

    auto add = [&](int pos)->void{
        if(A[pos][0]){
            cnt_a++;
            a.insert(A[pos][0]);
        }
        if(A[pos][1]){
            cnt_b++;
            b.insert(A[pos][1]);
        }
        if(A[pos][2]){
            cnt_c++;
            c.insert(A[pos][2]);
        }
        if(A[pos][3]){
            cnt_d++;
            d.insert(A[pos][3]);
        }
    };

    auto rem = [&](int pos)->void{
        if(A[pos][0]){
            cnt_a--;
            a.erase(A[pos][0]);
        }
        if(A[pos][1]){
            cnt_b--;
            b.erase(A[pos][1]);
        }
        if(A[pos][2]){
            cnt_c--;
            c.erase(A[pos][2]);
        }
        if(A[pos][3]){
            cnt_d--;
            d.erase(A[pos][3]);
        }
    };

    auto good = [&]()->bool{
        return (cnt_a && cnt_b && cnt_c && cnt_d);
    };

    int len =  INT_MAX;
    int ans_a = 0, ans_b = 0, ans_c = 0, ans_d = 0;
    for(int i = 0, j = 0; j < mx; ++j){
        add(j);
        while(true){
            rem(i);
            if(!good()){
                add(i);
                break;
            }
            i++;
        }
        if(good() && len > (j - i + 1)){
            len = j - i + 1;
            ans_a = *a.begin();
            ans_b = *b.begin();
            ans_c = *c.begin();
            ans_d = *d.begin();
        }
    }

    cout << ans_a << ' ' << ans_b << ' ' << ans_c << ' ' << ans_d << '\n';

    return 0;
}