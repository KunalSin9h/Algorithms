#include <bits/stdc++.h>
using namespace std;


void generateParentheses(string &b, int n, int op, int cl){
    //cout << b << '\n';
    if(op + cl == n<<1){
        cout << b << " ";
        return;
    }
    if(op < n){
        b.push_back('(');
        generateParentheses(b, n, op+1, cl);
        b.pop_back(); // Back Track
    }
    if(cl < n && op > cl){
        b.push_back(')');
        generateParentheses(b, n, op, cl+1);
        b.pop_back(); // Back Track
    }
}

int main(){
    int n;cin >> n;
    string b;
    generateParentheses(b, n, 0, 0);
    cout << '\n';
    return 0;
}