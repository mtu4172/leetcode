// Link : https://leetcode.com/problems/smallest-range-i/

#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int iter : nums) {
            mini = min(iter, mini);
            maxi = max(iter, maxi);
        }
        if (maxi - mini - 2 * k <= 0)
            return 0;
        return maxi - mini - 2 * k;
    }
};