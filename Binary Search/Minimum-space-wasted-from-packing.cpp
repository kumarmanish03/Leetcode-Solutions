// Manish Kumar, IIIT ALlahabad
// Hard

https://leetcode.com/problems/minimum-space-wasted-from-packaging/


class Solution {
public:
    
    int countBox(vector<int>& pack, int b){
        int lo = 0;
        int hi = pack.size()-1;
        
        while(hi - lo > 1){
            int mid = lo + (hi - lo) / 2;
            if(pack[mid] <= b){
                lo = mid;
            }else{
                hi = mid-1;
            }
        }
        if(pack[hi] <= b)
            return hi + 1;
        else if(pack[lo] <= b)
            return lo + 1;
        return 0;
    }
    
    int minWastedSpace(vector<int>& pack, vector<vector<int>>& boxes) {
        
        long long ans = LLONG_MAX;

        sort(pack.begin(), pack.end());
        
        //presum of packages
        vector<long long> presum(pack.size());
        presum[0] = (long long)pack[0];
        for(int i = 1; i < pack.size(); i++){
            presum[i] = (long long)pack[i] + presum[i-1];
        }
        
        for(auto box : boxes){
            sort(box.begin(), box.end());
            
            long long space = 0;
            int totalPicked = 0;
            
            for(auto b : box){
                // total package hold by box b
                int cnt = countBox(pack, b);
                
                // package hold by curr box
                int pickedByCurr = cnt - totalPicked;
                
                totalPicked += pickedByCurr;
                
                if(totalPicked == 0)
                    continue;
                
                // Calculating space
                if(totalPicked == pickedByCurr){
                    space -= presum[totalPicked-1];
                }else{
                    space -= presum[totalPicked-1] - presum[totalPicked - pickedByCurr - 1];
                }
                
                space += (long long)pickedByCurr * b;
            }
            
            if(totalPicked == pack.size())
                ans = min(ans, space);
        }
        if(ans == LLONG_MAX)
            return -1;
        return ans % 1000000007;
    }
};