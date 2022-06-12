/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://leetcode.com/problems/reorder-list/
* @desc: Using slow and fast problem
*
*/


class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 
        ListNode *second = slow->next;
        slow->next = NULL;
        
        // reverse second part
        ListNode *prev = NULL;
        while(second){
            ListNode *temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        second = prev;
        
        // merging two lists
        while(second){
            ListNode *temp1 =  head->next;
            ListNode *temp2 =  second->next;
            
            head->next = second;
            second->next = temp1;
            
            second = temp2;
            head = temp1;
        }
    }
};