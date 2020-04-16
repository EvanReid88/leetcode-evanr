// https://leetcode.com/problems/merge-two-sorted-lists

// O((l1 length + l2 length))
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto head = new ListNode(0);
        auto merged = head;
        
        auto p1 = l1;
        auto p2 = l2;
        while (p1 && p2) {
            // if p1 value less than p2 value
            if (p1->val < p2->val) {
                // insert p1 to end of merged list
                merged->next = p1;
                // iterate to next value in l1
                p1 = p1->next;
            }
            else {
                // insert p2 to end of merged list
                merged->next = p2;
                // iterate to next value in l2
                p2 = p2->next;
            }
            
            merged = merged->next;
        }
        
        // if we are not at end of l1, 
        // rest of values in p1 are greater than 
        // values in merged.
        // insert p1 to end of merged list
        if (p1) merged->next = p1;
        
        // same for l2
        if (p2) merged->next = p2;
        
        // return first node in merged list
        return head->next;
    }
};