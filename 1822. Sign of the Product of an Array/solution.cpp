// Link : https://leetcode.com/problems/sign-of-the-product-of-an-array/

#include <vector>
using namespace std;
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countNeg = 0;
        for (int iter : nums) {
            if (iter == 0)
                return 0;
            if (iter < 0)
                countNeg++;
        }
        if (countNeg % 2 == 0) 
            return 1;
        return -1;
    }
};