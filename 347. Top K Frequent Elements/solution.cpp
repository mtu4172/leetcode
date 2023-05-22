// Link: https://leetcode.com/problems/top-k-frequent-elements/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int i : nums)
            count[i]++;
        priority_queue<pair<int, int>> pq;
        for (auto iter : count)
            pq.push(make_pair(iter.second, iter.first));
        vector<int> topK;
        for (int i = 0; i < k; i++) {
            topK.push_back(pq.top().second);
            pq.pop();
        }
        return topK;
    }
};