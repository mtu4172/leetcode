// Link : https://leetcode.com/problems/majority-element/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int iter : nums) {
            m[iter]++;
            if (m[iter] > n/2)
                return iter;
        }
        return -1;
    }
};