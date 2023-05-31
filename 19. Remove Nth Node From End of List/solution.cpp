// Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
#include <stack>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        stack<ListNode*> s;
        ListNode* temp = head;
        while (temp != nullptr) {
            s.push(temp);
            temp = temp->next;
        }
        for (; n > 0; n--) {
            s.pop();
            if (s.empty())
                return head->next;
            temp = s.top();
        }
        temp->next = temp->next->next;
        return head;
    }
};