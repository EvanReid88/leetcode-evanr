
// https://leetcode.com/problems/palindrome-linked-list/

// stack solution
// O(len * 2) time
// O(n) space
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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        int len = 0;
        
        auto a = head;
        while(a) {
            len++;
            s.push(a->val);
            a = a->next;
        }
        
        for (int i = 0; i < len / 2; i++) {
            if (head->val != s.top()) return false;
            
            s.pop();
            head = head->next;
        }
        
        return true;
    }
};

// recursive solution
// O(n) time
// O(n) space
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
    
    ListNode* left;
    bool isPalindrome(ListNode* head) {
        left = head;
        
        bool result = palindromeHelper(head);
        return result;
    }
    
    bool palindromeHelper(ListNode* right) {
        if (right == NULL) {
            return true;
        }
        
        // if sub-list is not palindrome, return false
        bool x = palindromeHelper(right->next);
        
        if (!x) return false;
        
        // current left and right
        bool y = left->val == right->val;
        
        // move left to next
        left = left->next;
        
        return y;
    }
};