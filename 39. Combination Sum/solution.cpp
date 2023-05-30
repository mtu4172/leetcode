// Link : https://leetcode.com/problems/combination-sum/

#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> combos;
        traverse(candidates, target, {}, combos, 0);
        vector<vector<int>> vombo(combos.begin(), combos.end());
        return vombo;
    }
    void traverse(vector<int>& candidates, int target, map<int, int> current, set<vector<int>>& combos, int sum) {
        if (sum == target) {
            vector<int> c;
            for (auto iter : current) {
                for (int i = 0; i < iter.second; i++) {
                    c.push_back(iter.first);
                }
            }
            combos.insert(c);
            return;
        }
        for (int iter : candidates) {
            if (sum + iter <= target) {
                sum += iter;
                current[iter]++;
                traverse(candidates, target, current, combos, sum);
                sum -= iter;
                current[iter]--;
            }
        }
    }
};