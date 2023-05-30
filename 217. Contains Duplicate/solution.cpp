// Link : https://leetcode.com/problems/contains-duplicate/

#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> noDup(nums.begin(), nums.end());
        return noDup.size() != nums.size();
    }
};