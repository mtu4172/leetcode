// Link: https://leetcode.com/problems/swap-nodes-in-pairs/description/

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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        node1->next = node2->next;
        node2->next = node1;
        head = node2;
        while (node1->next != nullptr) {
            ListNode* prev = node1;
            node1 = node1->next;
            if (node1->next != nullptr)
                node2 = node1->next;
            else 
                return head;
            node1->next = node2->next;
            node2->next = node1;
            prev->next = node2;
        }
        return head;

    }
};