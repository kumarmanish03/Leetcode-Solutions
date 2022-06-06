// O(n): using dp and sliding window

class Solution {
public:
  
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> dp(n);
        dq.push_front(0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(nums[i], nums[i] + dp[dq.back()]);
            while(!dq.empty() && dp[dq.front()] < dp[i]){
                dq.pop_front();
            }
            dq.push_front(i);
            if(i >= k){
                while(!dq.empty() && i-k >= dq.back()){
                    dq.pop_back();
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};