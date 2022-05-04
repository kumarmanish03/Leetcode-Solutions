/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://leetcode.com/problems/house-robber-ii/
* @desc: dp1 has first element & dp2 haven't
*
*/

class Solution {
public:
    int maxRob(vector<int> &amt){
        int n = amt.size();
        if(n == 1){
            return amt[0];
        }

        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        dp1[0] = amt[0];
        dp2[0] = 0;
        dp1[1] = max(amt[0], amt[1]);
        dp2[1] = amt[1];
        for(int i = 2; i < n; i++){
            if(i == n-1){
                dp2[i] = max(dp2[i-1], amt[i] + dp2[i-2]);
                dp1[i] = dp1[i-1];
                continue;
            }
            dp1[i] = max(dp1[i-1], amt[i] + dp1[i-2]);
            dp2[i] = max(dp2[i-1], amt[i] + dp2[i-2]);
        }

        return max(dp1[n-1], dp2[n-1]);
    }

    int rob(vector<int>& nums) {
        return maxRob(nums);
    }
};