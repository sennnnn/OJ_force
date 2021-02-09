#include <vector>

using namespace std;


class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int dp[40000];
        if(arr.size() == 1) return 1;
        dp[0] = 1;
        int flag = -1;
        int last_flag = -1;
        int max_length = -1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] == arr[i-1]) {
                dp[i] = 1; 
            }else{
                flag = arr[i] > arr[i-1];
                if(flag != last_flag){
                    dp[i] = dp[i-1] + 1;
                }else{
                    dp[i] = 2;
                }
                last_flag = flag;
            }
            if(dp[i] > max_length){
                max_length = dp[i];
            }
        }
        return max_length;
    }
};