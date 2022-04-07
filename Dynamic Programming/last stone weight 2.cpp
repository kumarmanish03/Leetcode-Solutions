// Manish Kumar, IIIT Allahabad
// Medium, Hard if you dont know that it is minimum subset sum difference

https://leetcode.com/problems/last-stone-weight-ii/submissions/

// https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10

// Try to identify this dp problem
// This problem is same as finding minimum subset sum difference


class Solution {
public:
    
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = 0;
        int n = stones.size();
        for(auto i:stones)
            totalSum+=i;
        bool dp[n+1][totalSum+1];
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < totalSum+1; j++){
                if(j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(i == 0 && j!=0){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(stones[i-1] <= j){
                    dp[i][j] = dp[i-1][j-stones[i-1]] || dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        int mn = INT_MAX;
        for(int i = 0; i <= totalSum/2; i++){
            if(dp[n][i] == true){
                mn = min(mn, totalSum - 2*i);
            }
        }
        return mn;
        
    }
};