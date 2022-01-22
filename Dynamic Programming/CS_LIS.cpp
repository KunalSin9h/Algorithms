#include <iostream>
#include <vector>

bool validate(std::vector<int> &s){
    bool ch = true;
    int n = s.size();
    for(int i = 0;i<n-1; ++i){
        if(s[i] >  s[i+1]){
            ch = false;
            break;
        }
    }
    return ch;
}

std::vector<int> given, ans, subset;
int curr = -1, last = -1;
int cnt = 0;
// Time -> O(2^n * n) :( not the best approch
void brut(std::vector<int> &subset, int n, int i){
    if(i == n){
        if(validate(subset)){
            int nc = subset.size();
            if(nc > curr){
                ans = subset;
                curr = nc;
            }
        }
        cnt++;
        return;
    }
    if(given[i] < last){
        brut(subset, n, i+1);
    }else{
        last = given[i];
        subset.push_back(given[i]);
        brut(subset, n, i+1);
        subset.pop_back();
        last = -1;
        brut(subset, n, i+1);
    }
}

signed main(void){
    std::freopen("input.in", "r", stdin);

    int n;std::cin >> n;
    given.resize(n);
    for(int i = 0;i<n; ++i){
        std::cin >> given[i];
    }

    brut(subset, n ,0);
    for(int &i: ans){
        std::cout << i << ' ';
    }
    std::cout << '\n';
    std::cout << cnt << '\n'; 
    return 0;
}