// Link : https://leetcode.com/problems/valid-anagram/description/

#include <string>
#include <map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        map<char, int> smap;
        map<char, int> tmap;
        for (char iter : s)
            smap[iter]++;
        for (char iter : t)
            tmap[iter]++;
        for (char iter : s)
            if (smap[iter] != tmap[iter])
                return false;
        return true;
    }
};