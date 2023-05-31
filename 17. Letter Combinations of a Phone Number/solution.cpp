// Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
    vector<string> letters;
    map<char, vector<char>> maps;
public:
    vector<string> letterCombinations(string digits) {
        maps['2'] = {'a', 'b', 'c'};
        maps['3'] = {'d', 'e', 'f'};
        maps['4'] = {'g', 'h', 'i'};
        maps['5'] = {'j', 'k', 'l'};
        maps['6'] = {'m', 'n', 'o'};
        maps['7'] = {'p', 'q', 'r', 's'};
        maps['8'] = {'t', 'u', 'v'};
        maps['9'] = {'w', 'x', 'y', 'z'};
        traverse(digits, "");
        return letters;
    }
    void traverse(string digits, string cur) {
        if (digits.size() == 0 && cur.size() != 0) {
            letters.push_back(cur);
            return;
        }
        for (char iter : maps[digits[0]]) {
            traverse(digits.substr(1), cur + iter);
        }
    }
};