// Manish Kumar, IIIT Allahabad
// @logic: if sum is constant and we have to maximize product then, their diff should be minimum

class Solution {
public:
    #define ll long long
    ll totalSum;
    ll minDiff;
    ll sumOfMinDiff;
    
    void dfs2(TreeNode* root){
        if(!root)
            return;
        
        totalSum += root->val;
        dfs2(root->left);
        dfs2(root->right);
    }
    
    ll dfs(TreeNode* root){
        if(!root)
            return 0;
        
        ll left = dfs(root->left);
        ll right = dfs(root->right);
        
        if(abs(totalSum - 2 * left) < minDiff){
            minDiff = abs(totalSum - 2 * left);
            sumOfMinDiff = left;
        }
        
        if(abs(totalSum - 2 * right) < minDiff){
            minDiff = abs(totalSum - 2 * right);
            sumOfMinDiff = right;
        }
        
        return left + right + root->val;
    }
    
    int maxProduct(TreeNode* root) {
        minDiff = INT_MAX;
        sumOfMinDiff = 0;
        totalSum = 0;
        dfs2(root);
        dfs(root);
        ll sum2 = totalSum - sumOfMinDiff;
        return sum2 * sumOfMinDiff % 1000000007;
    }
};