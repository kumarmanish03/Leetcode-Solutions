// Manish Kumar, IIIT Allahabad
// Medium

https://leetcode.com/problems/target-sum/
// https://www.youtube.com/watch?v=ot_XBHyqpFc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11

// Please read comment line 26

// Strategy:
// watch youtube video for correct explanation
// this question is same as 'count target sum' or 'count subset sum with given diff'

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        int n = nums.size();
        for(auto i:nums)
            totalSum+=i;
        int sum = (target+totalSum)/2;
        
        if(totalSum < target || (target+totalSum)%2 == 1)
            return 0;
        
        int dp[n+1][sum+1];
        // First initialize base conditions before calculation actual dp
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<sum+1; j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;
            }
        }

        // calculate from j = 0 and i = 1(becoz dp[i-1] for i = 0 create error)
        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};