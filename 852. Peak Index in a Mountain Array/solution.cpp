// Link : https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int peakInd = -1;
        int peakVal = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > peakVal) {
                peakVal = arr[i];
                peakInd = i;
            }
        }
        return peakInd;
    }
};