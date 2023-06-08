// Link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

#include <vector>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0 ; i < m; i++) {
            int left = 0;
            int right = n-1;
            int mid = -1;
            int temp = 0;
            while (left <= right) {
                mid = (left + right) / 2;
                if (grid[i][mid] < 0) {
                    temp = n - mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            count += temp;
        }
        return count;
    }
};
