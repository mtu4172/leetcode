// Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int count[n];
        vector<int> solution;
        for (int i = 0; i < n; i++) {
            count[i] = 0;
        }
        for (vector<int> i : edges) {
            count[i.at(1)]++;
        }
        for (int i = 0; i < n; i++) {
            if (count[i] == 0) 
                solution.push_back(i);
        }
        return solution;
    }
};