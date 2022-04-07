// Manish Kumar, IIIT Allahabad
// Medium
// TC: O(nlogk)

https://leetcode.com/contest/weekly-contest-287/problems/maximum-candies-allocated-to-k-children/

class Solution {
public:
    bool check(long long c, vector<int> &v, long long &k){
        long long res = 0;
        for(int i:v){
            res += (long long)(i / c);
        }
        return (res >= k);
    }
    
    int maximumCandies(vector<int>& v, long long k) {
        long long sum = 0, ans = 0;
        int n = v.size();
        
        sort(v.begin(), v.end());
        
        long long r = (long long)v.back();
        long long l = 1;
        while(r-l > 1){
            long long mid = l + (r - l) / 2;
            if(check(mid, v, k)){
                l = mid;
            }
            else{
                r = mid-1;
            }
        }
        if(check(r, v, k))
            return r;
        else if(check(l, v, k))
            return l;
        else
            return 0;
    }
};
