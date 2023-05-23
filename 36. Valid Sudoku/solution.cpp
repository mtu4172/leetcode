// Link: https://leetcode.com/problems/valid-sudoku/

#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> chars;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (!chars.insert(board[i][j]).second)
                    return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            unordered_set<char> chars;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.')
                    continue;
                if (!chars.insert(board[j][i]).second)
                    return false;
            }
        }
        for (int i = 0; i < 7; i += 3) {
            for (int j = 0; j < 7; j += 3) {
                if (!box(board, i, j))
                    return false;
            }
        }
        return true;
    }
    bool box(vector<vector<char>>& board, int x, int y) {
        unordered_set<char> chars;
        for (int i = x; i < x+3; i++) {
            for (int j = y; j < y+3; j++) {
                if (board[i][j] == '.')
                    continue;
                if (!chars.insert(board[i][j]).second)
                    return false;
            }
        }
        return true;
    }
};
