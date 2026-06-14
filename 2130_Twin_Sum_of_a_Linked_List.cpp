/*
 * LeetCode 2130. Maximum Twin Sum of a Linked List
 * Difficulty: Medium
 * Topics: Linked List, Two pointers
 *
 * Time Complexity: O(n.2^n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    int pairSum(ListNode* head) {
        struct ListNode* temp = head, *temp1 = head;
        
        int n = 1;
        while(temp->next != NULL) {
            temp = temp->next;
            n++;
        }
        
        temp = head;

        for(int i=0; i<n/2 - 1; i++) {
            temp1 = temp1->next;
        }
        
        struct ListNode *temp2 = temp1->next;
        temp1->next = nullptr;
        struct ListNode *prev = nullptr;

        while(temp != nullptr) {
            struct ListNode *nextnode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextnode;
        }
        
        int sum = INT_MIN;
        for(int i=0; i<n/2; i++) {
            int current = prev->val + temp2->val;

            if(current > sum) sum = current;

            prev = prev->next;
            temp2 = temp2->next;
        }

        return sum;
    }
};
