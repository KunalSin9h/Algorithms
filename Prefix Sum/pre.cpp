#include <iostream>
using namespace std;

typedef long long ll;

const int N = 1e3 + 10 ;
int arr[N][N];
int pre[N][N];


int main(){

    int n;
    cin >> n;

    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<= n; ++j){
            cin >> arr[i][j];
            pre[i][j] = arr[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    cout << pre[d][c] - pre[a-1][c] - pre[d][b-1] + pre[a-1][b-1] << endl;

    return 0;
}