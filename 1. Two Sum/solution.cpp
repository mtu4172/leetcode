// Link: https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_ind;
        for (int i = 0; i < nums.size(); i++) {
            if (num_ind.find(target - nums.at(i)) != num_ind.end())
                return {i, num_ind[target - nums.at(i)]};
            num_ind[nums.at(i)] = i;
        }
        return {};
    }
};