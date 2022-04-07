// Manish Kumar, IIIT Allahabad
// TC: O(nlogn)

https://leetcode.com/problems/count-good-triplets-in-an-array/

// Idea :-
// We start with middle element, find its occurance in the second array lets say that is j. now our answer contribute by this element would be :-
// Number of overlapping elements in n1 from 0 to i and in n2 from 0 to j. lets say this is pref[i]
// and multiply this with number of overlapping elements in n1 from i + 1 to n and in n2 from j + 1 to n lets say this suff[i]
// Now answer is simply multiplication of these two.

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n, 0), pre(n, 0), suf(n, 0);
        
        for(int i = 0; i < n; i++){
            pos[nums2[i]] = i;
        }
        
        ordered_set s1, s2;
        for(int i = 0; i < n; i++){
            pre[i] = s1.order_of_key(pos[nums1[i]]);
            s1.insert(pos[nums1[i]]);
        }
        for(int i = n-1; i >= 0; i--){
            suf[i] = s2.order_of_key(-pos[nums1[i]]);
            s2.insert(-pos[nums1[i]]);
        }
        
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += 1LL * pre[i] * suf[i];
        }
        
        return ans;
    }
};
