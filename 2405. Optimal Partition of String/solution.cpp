// Link: https://leetcode.com/problems/optimal-partition-of-string/

#include <set>
#include <string>
using namespace std;
class Solution {
public:
    int partitionString(string s) {
        set<char> letters;
        int count = 1;
        for (char c : s) {
            if (letters.insert(c).second)
                continue;
            count++;
            letters.clear();
            letters.insert(c);
        }
        return count;
    }
};