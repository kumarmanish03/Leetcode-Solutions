// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(n)
// Space Complexity : O(1)

// Strategy :
// we reverse the list after midpoint and then check from starting node and reversed list node
// Remember the below written reverse() function [standard]

https://leetcode.com/problems/palindrome-linked-list/submissions/
https://www.interviewbit.com/problems/palindrome-list/

ListNode *reverse(ListNode *head){
        ListNode *pre = NULL, *post = NULL;
        while(head){
            post = head->next;
            head->next = pre;
            pre = head;
            head = post;
        }
        return pre;
    }
    
bool isPalindrome(ListNode* head) {
  ListNode *slow = head, *fast = head;
  while(fast->next && fast->next->next){
    slow = slow->next;
    fast = fast->next->next;
  }
        
  slow = reverse(slow->next);
        
  while(slow && head){
    if(slow->val != head->val)
      return false;
    slow = slow->next;
    head = head->next;
  }
  return true;
}