// Manish Kumar, IIIT Allahabad
// Hard

// Question of matrix chain multiplication

https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int dp[510][510];
    vector<int> v;
    
    int mcm(int st, int en){
        if(st > en)
            return 0;
        
        if(dp[st][en] != -1)
            return dp[st][en];
        
        int mx = INT_MIN;
        for(int k = st; k <= en; k++){
            int cost = v[st-1]*v[k]*v[en+1];
            int left = mcm(st, k-1);
            int right = mcm(k+1, en);
            mx = max(cost+left+right, mx);
        }
        dp[st][en] = mx;
        
        return dp[st][en];
    }
    
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        v.clear();
        v.push_back(1);
        for(auto i:nums)
            v.push_back(i);
        v.push_back(1);
        return mcm(1, v.size()-2);
    }
};