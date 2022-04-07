// Manish Kumar, IIIT Allahabad
// Medium

// Strategy: Range Queries

https://leetcode.com/contest/biweekly-contest-57/problems/describe-the-painting/

class Solution {
public:
    #define ll long long
    vector<vector<long long>> splitPainting(vector<vector<int>>& seg) {
        ll dp[100001] = {0};
        bool h[100001] = {0};
        for(auto e : seg){
            dp[e[0]] += 1LL*e[2];
            dp[e[1]] -= 1LL*e[2];
            h[e[0]] = h[e[1]] = true;
        }
        for(int i = 1; i < 100001; i++){
            dp[i] += dp[i-1];
        }
        vector<vector<long long>> res;
        
        int start = 0;
        ll key;
        for(int i = 0; i < 100001; i++){
            if(start == 0 && (dp[i] || h[i])){
                start = i;
                key = dp[i];
            }
            else if(start != 0 && (key != dp[i] || h[i] == true)){
                res.push_back({start, i, key});
                if(dp[i]){
                    start = i;
                    key = dp[i];
                }else {
                    start = 0;
                }
            }
        }
        return res;
    }
};