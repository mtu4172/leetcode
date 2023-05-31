// Link : https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/

#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    double average(vector<int>& salary) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int total = 0;
        for (int iter : salary) {
            mini = min(mini, iter);
            maxi = max(maxi, iter);
            total += iter;
        }
        return (double) (total - mini - maxi) / (salary.size() - 2);
    }
};