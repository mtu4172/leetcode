// Link: https://leetcode.com/problems/unique-paths-ii/

#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> paths (m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                break;
            paths[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1)
                break;
            paths[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                paths[i][j] = 0;
                if (obstacleGrid[i][j] == 1)
                    continue;
                if (obstacleGrid[i-1][j] == 0)
                    paths[i][j] += paths[i-1][j];
                if (obstacleGrid[i][j-1] == 0)
                    paths[i][j] += paths[i][j-1];
            }
        }
        return paths[m-1][n-1];
    }
};