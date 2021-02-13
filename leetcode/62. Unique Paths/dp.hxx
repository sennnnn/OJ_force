int dp[101][101];

int max(int a, int b) {
    return a > b ? a : b;
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        dp[1][1] = 1;
        dp[1][2] = 1;
        dp[2][1] = 1;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(dp[i][j] != 0) continue;
                if(i == 1) {
                    dp[i][j] = dp[i][j-1];
                }else if(j == 1) {
                    dp[i][j] = dp[i-1][j];
                }else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};