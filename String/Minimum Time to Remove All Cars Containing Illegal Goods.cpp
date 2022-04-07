// Manish Kumar, IIIT Allahabad
// Hard-Medium, Greedy

https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/

// count min steps from left and right, then count final ans

class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> left(n, 0), right(n, 0);
        int one = 0;
        
        if(s[0] == '0') right[0] = 0;
        else right[0] = 1, one++;
        for(int i = 1; i < n; i++){
            if(s[i] == '1'){
                one++;
                right[i] = min(one*2, min(i+1, right[i-1]+2));
            }
            else{
                right[i] = right[i-1];
            }
        }
        one = 0;
        if(s[n-1] == '0') left[n-1] = 0;
        else left[n-1] = 1, one++;
        for(int i = n-2; i >= 0; i--){
            if(s[i] == '1'){
                one++;
                left[i] = min(one*2, min(n-i, left[i+1]+2));
            }
            else{
                left[i] = left[i+1];
            }
        }
        
        int mn = n;
        for(int i = 0; i < n-1; i++){
            mn = min(mn, right[i] + left[i+1]);
        }
        mn = min(mn, right[n-1]);
        mn = min(mn, left[0]);
        // cout << ans << mn;
        return mn;
    }
};
