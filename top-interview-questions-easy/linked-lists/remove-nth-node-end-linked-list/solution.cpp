// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// two pass solution
// O(length)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // get length of linked list
        auto p = head;
        int len = 0;
        while(p) {
            len++;
            p = p->next;
        }
        int startLen = len - n + 1;
        
        // remove node if first in list
        if (startLen == 1) return head->next;
        
        // remove node
        p = head;
        int i = 0;
        while (p) {
            if (++i == startLen - 1) {
                p->next = p->next->next;
            }
            p = p->next;
        }
        return head;
    }
};

// one pass solution
// O(length)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto front = head;
        auto back = head;
        while (front) {
            front = front->next;
            if (n < 0) {
                back = back->next;
            }
            n--;
        }
        
        if (n) {
            back->next = back->next->next;
        } 
        else {
            head = head->next;
        }

        return head;
    }
};

// one pass fast/slow pointer solution
// O(length)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto fast = head;
        auto slow = head;
        
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // remove node if first in list
        if (fast == NULL) {
            head = head->next;
            return head;
        }
        
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        // point to previous element of the target element
        slow->next = slow->next->next;
        
        return head;
    }
};