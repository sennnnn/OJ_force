#include <vector>
#include <iostream>

using namespace std;

int dp[35][35];

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        for(int i = 0; i < 35; i++) {
            for(int j = 0; j < 35; j++) {
                dp[i][j] = 0;
            }
        }
        dp[1][1] = 1;
        vector<int> temp;
        int i, j;
        for(i = 2; i <= rowIndex+1; i++) {
            for(j = 1; j <= i; j++) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                if(i == rowIndex+1) {
                    temp.push_back(dp[i][j]);
                }
            }
        }
        return temp;
    }
};