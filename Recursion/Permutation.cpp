#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;

using std::cout;

void Permutation(vector<int> &A){
    static vector<int> B; // Static is not Good for Multiple Test Case
    static vector<bool> used(4, false);

    if(B.size() == 4){
        for(int &e: B)cout << e << ' ';
        cout << '\n';
    } 

    else{
        for(int i = 0; i<4; ++i){
            if(used[i])continue;
            used[i] = true;
            B.push_back(A[i]);
            Permutation(A);
            used[i] = false;
            B.pop_back();
        }
    }

}

int main(){

    vector<int> A{4, 3, 2, 1};

    Permutation(A);

    return 0;
}