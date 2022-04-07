// Manish Kumar, IIIT Allahabad
// Easy

https://leetcode.com/contest/biweekly-contest-55/problems/maximum-alternating-subsequence-sum/


class Solution {
public:
    vector<int> v;
    long long dp[100001][2];
    
    long long find(int i, bool c){
        if(i == v.size())
            return 0;
        
        if(dp[i][c] != -1){
            return dp[i][c];
        }
        
        if(c)
            dp[i][c] = max(find(i+1, !c) - (long long)v[i], find(i+1, c));
        else
            dp[i][c] = max(find(i+1, !c) + (long long)v[i], find(i+1, c));
        
        return dp[i][c];
    }
    
    long long maxAlternatingSum(vector<int>& A) {
        v.clear();
        v = A;
        memset(dp, -1, sizeof(dp));
        // 0 for even & 1 for odd
        return find(0, 0);
    }
};