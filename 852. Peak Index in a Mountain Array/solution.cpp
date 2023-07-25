// Link : https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <vector>
using namespace std;
class Solution1 {
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

class Solution2 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        while (l < r) {
            int m = (l + r) / 2;
            if (m == 0 || m == arr.size()-1)
                return m;
            if (arr[m-1] < arr[m] && arr[m+1] < arr[m])
                return m;
            if (arr[m-1] > arr[m])
                r = m;
            else if (arr[m+1] > arr[m])
                l = m;
        }
        return -1;
    }
};