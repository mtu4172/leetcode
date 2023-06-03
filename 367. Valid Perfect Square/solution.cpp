// Link : https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 0; i < 46341; i++) {
            if (i * i == num)
                return true;
            if (i * i > num)
                return false;
        }
        return false;
    }
};