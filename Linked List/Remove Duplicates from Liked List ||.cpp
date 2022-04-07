// Manish Kumar, IIIT Allahabad
// Medium

// Tricky to handle corner cases

https://www.interviewbit.com/old/problems/remove-duplicates-from-sorted-list-ii/
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* A) {
        ListNode* dummy = new ListNode(-101);
        ListNode *curr = A, *pre = dummy;
        dummy->next = A;
        while(curr){
            if(curr->next == NULL or curr->val != curr->next->val){
                pre->next = curr;
                pre = curr;
                curr = curr->next;
            }else{
                int val = curr->val;
                while(curr != NULL and curr->val == val){
                    curr = curr->next;
                }

                if(curr == NULL){
                    pre->next = curr;
                }
            }
        }
        return dummy->next;
    }
};