// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int max = 0;
        while (right < prices.size()) {
            if (prices[left] > prices[right]) {
                left++;
                right = left + 1;
                continue;
            }
            if (prices[right] - prices[left] > max) {
                max = prices[right] - prices[left];
            }
            right++;
        }
        return max;
    }
};