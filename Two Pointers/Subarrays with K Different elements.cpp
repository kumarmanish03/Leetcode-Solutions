// Manish Kumar, IIIT Allahabad
// Medium, Tricky
// Time Complexity : O(n)
// Space Complexity : O(n)

https://leetcode.com/problems/subarrays-with-k-different-integers/submissions/
https://www.interviewbit.com/problems/subarrays-with-distinct-integers/

// This question is simple if we have to calculate subaarays with atmost k Distinct elements
// Hence we make a function of it and subtract to get answer for exactly k Distinct elements
// Ex : return atMostKDistict(nums, k) - atMostKDistict(nums, k-1);

class Solution {
public:
    int atMostKDistict(vector<int> &A, int B){
        unordered_map<int, int> m;
        int cnt = 0;
        int i = 0;
        for(int j = 0; j < A.size(); j++){
            m[A[j]]++;

            while(m.size() > B){
                if(m[A[i]] > 1)
                    m[A[i]]--;
                else
                    m.erase(A[i]);
                i++;
            }

            cnt += j - i + 1;
        }

        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistict(nums, k) - atMostKDistict(nums, k-1); 
    }
};