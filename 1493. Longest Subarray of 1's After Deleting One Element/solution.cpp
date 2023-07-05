// Link : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include<vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int count = 0;
        int max = 0;
        if (nums[left] != 1) count++;
        while (right < nums.size()-1) {
            right++;
            if (nums[right] != 1){
                count++;
            }
            while (count > 1) {
                if (nums[left] != 1) {
                    count--;
                }
                left++;
            }
            if (right - left > max)
                max = right - left;
        }
        return max;
    }
};