// Manish Kumar, IIIT Allahabad
// Medium

https://leetcode.com/contest/weekly-contest-245/problems/maximum-number-of-removable-characters/

// This is Binary Search problem beco'z we have to check for valid k on a range
// We binary search on value of k in remove vector, and find largest k for which isSub() is true

class Solution {
public:
    vector<int> remove;
    bool isSub(string s, string p, int k){
        for(int i = 0; i <= k; i++){
            s[remove[i]] = ' ';
        }
        
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(j < p.size() && p[j] == s[i])
                j++;
        }
        if(j == p.size())
            return true;
        else
            return false;
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        remove.clear();
        remove = removable;
        int lo = 0;
        int hi = removable.size()-1;
        while(hi - lo > 1){
            int mid = (hi + lo) / 2;
            if(isSub(s, p, mid)){
                lo = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        if(isSub(s, p, hi))
            return hi+1;
        else if(isSub(s, p, lo))
            return lo+1;
        else
            return 0;
    }
};