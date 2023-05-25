// Link: https://leetcode.com/problems/jump-game/

using namespace std;
#include <vector>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> jump(n, false);
        jump[n-1] = true;
        for (int i = n-2; i >= 0; i--) {
            for (int j = i + 1; j <= i + nums[i]; j++) {
                if (jump[j]) {
                    jump[i] = true;
                    break;
                }
            }
        }
        return jump[0];
    }
};
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        int i;
        for (i = n-1; i >= 0; i--) {
            if (i + nums[i] >= n)
                n = i;
        }
        return n == 0;
    }
};