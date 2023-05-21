// Link: https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int min = 999999999;
        int minList = -1;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == nullptr)
                continue;
            if (lists[i]->val < min) {
                min = lists[i]->val;
                minList = i;
            }
        }
        if (minList == -1) 
            return nullptr;
        ListNode* head = lists[minList];
        lists[minList] = lists[minList]->next;
        head->next = mergeKLists(lists);
        return head;
    }
};