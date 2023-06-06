// Link : https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int dist = abs(arr[1] - arr[0]);
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] != dist)
                return false;
        }
        return true;
    }
};