/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto p = head;
        int len = 0;
        
        // get linked list length
        while(p) {
            len++;
            p = p->next;
        }
        
        // iterate to middle node from head
        p = head;
        for (int i = 0; i < len / 2; i++) {
            p = p->next;
        }
        
        return p;
    }
};