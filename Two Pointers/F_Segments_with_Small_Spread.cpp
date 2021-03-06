#include <bits/stdc++.h>
using namespace std;

/**
 * Question: Good Segment is [l...r] -> max([l...r]) - min([l...r]) <= K
 **/

template<typename T>
class M_queue{
private:
    typedef std::array<std::stack<T> , 3> AST;
    AST left, right;
    void push_3(AST &A, T x){
        A[0].push(x);
        if(A[1].empty())A[1].push(x);
        else A[1].push(std::min<T>(x, A[1].top()));
        if(A[2].empty())A[2].push(x);
        else A[2].push(std::max<T>(x, A[2].top()));
    }
    void pop_3(AST &A){
        A[0].pop(); 
        A[1].pop(); 
        A[2].pop(); 
    }
    void refill(){
        if(left[0].empty()){
            while(!right[0].empty()){
                push_3(left, right[0].top());
                pop_3(right);
            }
        }
    }
public:
    void push(T x){
        push_3(right, x);
    }
    void pop(){
        refill();
        pop_3(left);
    }

    T front(){
        assert(left[0].size() != 0 && "Left Stack is Empty !!");
        return left[0].top();
    }
    T min(){
        T a = left[1].empty()?LLONG_MAX:left[1].top();
        T b = right[1].empty()?LLONG_MAX:right[1].top();
        return std::min<T>(a, b);
    }

    T max(){
        T a = left[2].empty()?LLONG_MIN:left[2].top();
        T b = right[2].empty()?LLONG_MIN:right[2].top();
        return std::max<T>(a, b);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;cin >> N;
    int64_t K;cin >> K;
    vector<int64_t> A(N);for(auto &a: A)cin >> a;

    M_queue<int64_t> q;

    int64_t ans = 0;
    for(int i = 0, j = 0; j < N; ++j){
        q.push(A[j]);
        while((q.max() - q.min()) > K){
            q.pop();
            i++;
        }
        ans += j - i + 1;
    }
    cout << ans << '\n';
    return 0;
}