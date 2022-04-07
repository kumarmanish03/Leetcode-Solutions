// By Manish Kumar (IEC2019068), IIIT Allahabad
// Medium
// https://leetcode.com/problems/number-of-different-subsequences-gcds/
// https://www.youtube.com/watch?v=ZYJDCcKnwag
// We iterate all values in range and check for every number if it a gcd of possible subsequence
// For having gcd, 1. no. should be present or 2. the gcd of its multipliers (which is present in given array) is no. itself, then it is possible gcd of subsequence 

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        vector<bool> a(200002, false);
        
        for(auto i: nums) {
            a[i] = true;
        }
        int ans = 0;
        for(int i = 1; i < 200002; i++){
            if(a[i]) ans++;
            else {
                int ok = -1;
                for(int j = 2; j*i < 200002; j++){
                    if(a[i*j]) {
                        if(ok == -1) ok = j*i;
                        else ok = __gcd(ok, j*i);
                    }   
                }
                if(ok == i) ans++;
            }
        }
        
        return ans;
    }
};