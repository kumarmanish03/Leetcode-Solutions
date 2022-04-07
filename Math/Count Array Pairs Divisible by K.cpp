// Manish Kumar, IIIT Allahabad
// TC: O(n*sqrt(n))

// Idea:
// If (gcd(a,k) * gcd(b,k)) % k == 0 then (a * b) % k == 0

https://leetcode.com/problems/count-array-pairs-divisible-by-k/

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        vector<int> divisors(1e5+1, 0);
        long long ans = 0;
        for(int n: nums){
            // m is the no. multiplied by n so that it is divisble by k
            int m = k / __gcd(n, k);
            
            ans += (long long)divisors[m];
            
            // updating divisors of n
            for(int i = 1; i*i <= n; i++){
                if(n % i == 0){
                    divisors[i]++;
                    if(i * i != n) divisors[n/i]++;
                }
            }
        }
        
        return ans;
    }
};
