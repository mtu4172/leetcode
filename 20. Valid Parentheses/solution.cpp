// Link : https://leetcode.com/problems/valid-parentheses/

#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string str) {
        if (str.size() < 2)
            return false;
        stack<char> s;
        s.push('-');
        for (char c : str) {
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else if ((c == ')' && s.top() == '(') || 
                (c == '}' && s.top() == '{') || 
                (c == ']' && s.top() == '[')) {
                    s.pop();
            } else 
                return false;
        }
        s.pop();
        return s.empty();
    }
};