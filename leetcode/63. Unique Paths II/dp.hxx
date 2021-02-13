#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        // Special situation
        if(obstacleGrid[0][0] == 1) return 0;
        if(obstacleGrid[r-1][c-1] == 1) return 0;
        if(r == 1 && c == 1) return 1;
        // Init
        int dp[101][101];
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        if(r == 1) dp[1][0] = 0;
        else dp[1][0] = obstacleGrid[1][0] == 1 ? 0 : 1;
        if(c == 1) dp[0][1] = 0;
        else dp[0][1] = obstacleGrid[0][1] == 1 ? 0 : 1;
        // Dp search
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(dp[i][j] != 0 || obstacleGrid[i][j] != 0) continue;
                if(i == 0) {
                    dp[i][j] = dp[i][j-1];
                }else if(j == 0) {
                    dp[i][j] = dp[i-1][j];
                }else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[r-1][c-1];
    }
};