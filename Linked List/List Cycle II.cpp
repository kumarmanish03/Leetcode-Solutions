// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(n)
// Space Complexity : O(1)

// Using Floyd and Tortoise method

https://leetcode.com/problems/linked-list-cycle-ii/submissions/
https://www.interviewbit.com/old/problems/list-cycle/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool check = false;

        do{
            if(fast == NULL || fast->next == NULL){
                check = true;
                break;   
            }
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);
        
        if(check)
            return NULL;

        slow = head;
        while(slow != fast){
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
        }
};