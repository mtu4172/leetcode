// Link : https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for (int iter : nums)
            maxHeap.push(iter);
        for (; k > 1; k--)
            maxHeap.pop();
        return maxHeap.top();
    }
};