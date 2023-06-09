// Link : https://leetcode.com/problems/find-smallest-letter-greater-than-target/

using namespace std;
#include <vector>;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid == 0 && letters[mid] > target)
                return letters[0];
            if (letters[mid] > target && letters[mid-1] <= target) {
                return letters[mid];
            }
            if (letters[mid] <= target) {
                left = mid + 1;
            }
            if (letters[mid] > target) {
                right = mid - 1;
            }
        }
        return letters[0];
    }
};