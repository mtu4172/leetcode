// Link : https://leetcode.com/problems/number-of-provinces/

#include <vector>
#include <queue>
using namespace std;
class SolutionBFS {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int p = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            p++;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                visited[cur] = true;
                for (int j = 0; j < n; j++) {
                    if (isConnected[cur][j] == 1 && !visited[j])
                        q.push(j);
                }
            }
        }
        return p;
    }
};

class SolutionDFS {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int p = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            traverse(isConnected, visited, i);
            p++;
        }
        return p;
    }
    void traverse (vector<vector<int>>& ic, vector<bool>& visited, int c) {
        for (int i = 0; i < ic[c].size(); i++) {
            if (ic[c][i] == 1 && !visited[i]) {
                visited[i] = true;
                traverse(ic, visited, i);
            }
        }
    }
};