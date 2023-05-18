// Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
using namespace std;
class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    int pairSum(ListNode* head) {
        vector<int> list;
        list.push_back(head->val);
        while (head->next != nullptr) {
            head = head->next;
            list.push_back(head->val);
        }
        int n = list.size();
        int max = -1;
        for (int i = 0; i < (n / 2); i++) {
            if (list.at(i) + list.at(n-1-i) > max) {
                max = list.at(i) + list.at(n-1-i);
            }
        }
        return max;
    }
};