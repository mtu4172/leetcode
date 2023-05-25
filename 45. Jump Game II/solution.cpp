// Link: https://leetcode.com/problems/jump-game-ii/

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> steps(n+1, 999999999);
        steps[n] = 0;
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] == 0)
                continue;
            priority_queue<int, vector<int>, greater<int>> minHeap;
            for (int j = i+1; j <= i + nums[i] && j < nums.size(); j++) {
                minHeap.push(steps[j]);
            }
            steps[i] = minHeap.top()+1;
        }
        return steps[0];
    }
};