#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: 
 * Given an array of n integers a(i). Let's say that a segment of this array a[l..r] (1≤l≤r≤n) is good if the GCD of all 
 * numbers on this segment is 1. Your task is to find the shortest good segment.
 **/

template<typename T>
struct gqueue{
private:
    std::array<std::stack<T>, 2> left, right;
    void push_(std::array<std::stack<T>, 2> &S, T x){
        S[0].push(x);
        T gcd = S[1].empty() ? x : std::__gcd(x, S[1].top());
        S[1].push(gcd);
    }
    void pop_(std::array<std::stack<T>, 2> &S){
        S[0].pop();S[1].pop();
    }
    void refill(){
        if(left[0].empty()){
            while(!right[0].empty()){
                push_(left, right[0].top());
                pop_(right);
            }
        }
    }
public:
    void push(T x){push_(right, x);}
    void push_front(T x){
        push_(left, x);
    }
    T pop(){
        refill();
        T el = left[0].top();
        pop_(left);
        return el;
    }
    T gcd(){
        T a = left[0].empty() ? 0 : left[1].top();
        T b = right[0].empty() ? 0 : right[1].top();
        return std::__gcd(a, b);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;cin >> N;
    vector<int64_t> A(N);for(auto &a: A)cin >> a;

    gqueue<int64_t> gq;
    
    int ans = INT_MAX;
    for(int i = 0, j = 0; j < N; ++j){
        gq.push(A[j]);
        while(true){
            int64_t el = gq.pop();
            if(gq.gcd() == 1)i++;
            else{
                gq.push_front(el);
                break;
            }
        }
        if(gq.gcd() == 1)ans = min(ans, j - i + 1); 
    }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
    return 0;
}
