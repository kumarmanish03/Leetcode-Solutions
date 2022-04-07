// Manish Kumar, IIIT Allahabad
// TC: O(2^(2*numSlots) * numSlots)

// DP with Bitmask
// When we have to make a vector as states then we use bitmask

// Refer:
https://www.youtube.com/watch?v=tk5rwYgBWZc

https://leetcode.com/problems/maximum-and-sum-of-array/

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        // making size of nums = 2*numSlots, adding 0 wont affect answer
        while(nums.size() < 2 * numSlots)
            nums.push_back(0);
        
        int n = nums.size();
        // Bitmask
        int k = (1 << n) - 1;
        vector<int> dp(k+1, 0);
        for(int i = 1; i <= k; i++){
            // No. of elements in bitmask
            int slot = (__builtin_popcount(i)+1) / 2;
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j)){
                    dp[i] = max(dp[i], dp[i ^ (1 << j)] + (nums[j] & slot));
                }
            }
        }
        return dp[k];
    }
};
