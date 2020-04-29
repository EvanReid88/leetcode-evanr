// https://leetcode.com/problems/linked-list-cycle/

// one pointer solution
// O(n) Time
// O(n) Space
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
    bool hasCycle(ListNode *head) {   
        unordered_set<ListNode*> set;

        while (head != NULL) {
            // if we have see this node before,
            // we have a cycle
            if (set.find(head) != set.end()) {
                return true;
            }
            
            // else add node to hashset
            set.insert(head);
            
            // next node
            head = head->next;

        }
        
        return false;
    }
};

// two pointer solution
// No Cycle: O(n) Time
// Cycle: O(# of iterations + cyclic length) ~ O(n)
// O(1) Space

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
    bool hasCycle(ListNode *head) {   
        if (head == NULL || head->next == NULL) {
            return false;
        }
        
        // create slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (slow != fast) {
            // if either pointer is null,
            // the pointers have not met and no possible cycle
            if (fast == NULL || fast->next == NULL) {
                return false;
            }
            // traverse slow by one
            slow = slow->next;
            // traverse fast by two
            fast = fast->next->next;
        }
        
        // if slow pointer meets fast pointer, we have cycle
        return true;
    }
};