https://leetcode.com/contest/weekly-contest-178/problems/linked-list-in-binary-tree/

// Efficient soln below

// Solution 1 (But uses extra memory)
// Strategy :
// v vector of vectors store all possible nodes from root to leaf
// Then, check for any possible subarray from any of the vectors of v 

class Solution {
public:
    // Function to check subarray
    bool isSubArray(vector<int> A, vector<int> B)
    {
        int i = 0, j = 0;

        while (i < A.size() && j < B.size()) {

            if (A[i] == B[j]) {

                i++;
                j++;

                if (j == B.size())
                    return true;
            }
            else {
                i = i - j + 1;
                j = 0;
            }
        }

        return false;
    }
    
    // Store all possible nodes from root to leaf in v
    void recur(vector<vector<int>> &v, TreeNode* root, vector<int> temp){
        if(root->left == NULL && root->right == NULL){
            temp.push_back(root->val);
            v.push_back(temp);
            return;
        }
        
        temp.push_back(root->val);
        if(root->left != NULL)
            recur(v, root->left, temp);
        if(root->right != NULL)
            recur(v, root->right, temp);
        temp.pop_back();
    }
    
    // check if linked list elements is subarray of any of v
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<vector<int> > v;
        vector<int> temp;
        recur(v, root, temp);
        while(head){
            temp.push_back(head->val);
            head = head->next;
        }
        for(auto i:v){
            if(isSubArray(i,temp))
                return true;
        }
        return false;
    }
};


// Efficient solution (2 Dfs)
// dfs() go through all nodes and start dfs2() from each
// dfs2() checks if, from that node linked list elements are matching

class Solution {
public:
    bool dfs2(TreeNode* root, ListNode* head){
        if(!head)
            return 1;
        if(!root || root->val != head->val)
            return 0;
        return dfs2(root->left, head->next) || dfs2(root->right, head->next);
    }
    
    bool dfs(TreeNode* root, ListNode* head){
        if(!root)
            return 0;
        
        if(dfs2(root, head)){
            return true;
        }
        else{
            return dfs(root->left, head) || dfs(root->right, head);
        }
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(root, head);
    }
};