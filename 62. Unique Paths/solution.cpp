// Link: https://leetcode.com/problems/unique-paths/

#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths (m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            paths[i][0] = 1;
        }
        paths[0] = vector<int>(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[m-1][n-1];
    }
};