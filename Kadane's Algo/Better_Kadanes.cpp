/**
  * Better Implementation to Handle both negative and positive/negative elements;
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<int> V{-100, -1, -1, -1, -1, 1};
    int n = V.size();

    auto empty_sub_allowed = [&]()->int{
        int max_sum = V[0];
        int curr = V[0];
        for(int i = 1;i<n; ++i){
            curr = max(curr + V[i], 0); // Empty subarray allowed so 0
            max_sum = max(max_sum, curr);
        }
        cout << max_sum << '\n';
    };

    auto empty_sub_not_allowed = [&]()->int{
        int max_sum = V[0];
        int curr = V[0];
        for(int i = 1;i<n; ++i){
            curr = max(curr + V[i], V[i]); // Empty subarray not allowed so V[i]
            max_sum = max(max_sum, curr);
        }
        cout << max_sum << '\n';
    };

    int best_sum_start = 1;
    int best_sum_end = 1;
    auto max_sum_with_pos = [&]()->int{
        int max_sum = V[0];
        int curr =  V[0];
        for(int i = 1;i<n; ++i){
            int curr_start;
            if(curr <= 0){
                curr_start = i;
                curr += V[i];
            }
            else{
                curr += V[i];
            }
            if(curr > max_sum){
                max_sum = curr;
                best_sum_start = curr_start;
                best_sum_end = i + 1;
            }
        }
    };



    return 0;
}



