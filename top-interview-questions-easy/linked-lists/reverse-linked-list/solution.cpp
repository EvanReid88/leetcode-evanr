// https://leetcode.com/problems/reverse-linked-list

// iterative solution
// O(n)
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
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* following = head;
        
        while (current != NULL) {
            // set following node to next node
            following = following->next;
            
            // set current node next pointer to previous
            // swapping the list direction
            current->next = previous;
            
            // set previous node to current
            previous = current;
            
            // set current node to following
            current = following;
        }
        
        return previous;
    }
};

// recursive solution
// O(n)
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = reverseList(head->next);

        // reverse node order
        //n -> n2 -> n
        //n -> null
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};