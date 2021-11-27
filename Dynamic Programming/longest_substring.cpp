#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int DP(string a, string b){
    int la = a.size();
    int lb = b.size();

    int cell[la+1][lb+1];
    int ans = 0;
    if(a[0] == b[0]){
        cell[0][0] = 1;
        ans++;
    }
    cout << ans << endl;
    cout << cell[0][0] << endl;
    for(int i = 0;i<la; ++i){
        for(int j = 0;j<lb; ++j){
            if(a[i] == b[j] && i != 0 && j != 0){
                cell[i][j] = cell[i-1][j-1] + 1;
                ans = max(ans, cell[i][j]);
            }
            else{
                cell[i][j] = 0;
            }
        }
    }
    for(int i = 0;i<la; ++i){
        for(int m = 0; m<lb; ++m){
            cout << cell[i][m] << " " ;
        }
        cout << endl;
    }
    return ans; 
} 


int main(){
    string a = "kunal";
    string b = "kunal";
    cout << a << " "  << b << endl;
    int ans = DP(a, b);
    cout << ans << endl;
    return 0;
}