// Link: https://leetcode.com/problems/the-kth-factor-of-n/

#include <vector>
using namespace std;
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (factors.size() == k) {
                    return factors.at(factors.size()-1);
                }
            }
        }
        return -1;
    }
};