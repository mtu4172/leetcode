// Link : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include <vector>
#include <queue>
using namespace std;
class Solution {
    struct compare {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return (a.first < b.first) || ((a.first == b.first) && (a.second > b.second));
        }
    };
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxHeap;
        for (int i = 0; i < mat.size(); i++) {
            int civs = 0;
            for (auto iter : mat.at(i)) {
                if (iter == 0)
                    civs++;
            }
            maxHeap.push(make_pair(civs, i));
        }
        vector<int> ans;
        for (; k > 0; k--) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans; 
    }
};