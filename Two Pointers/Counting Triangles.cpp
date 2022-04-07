// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/counting-triangles/
https://leetcode.com/problems/valid-triangle-number/

class Solution {
public:
    int triangleNumber(vector<int>& A) {
        long long int cnt = 0;
        sort(A.begin(), A.end());
        int n = A.size();
        for(int k = n-1; k >= 2; k--){
            int i = 0;
            int j = k-1;
            while(i < j){
                if(A[i] + A[j] > A[k]){
                    cnt += j-i;
                    j--;
                }
                else {
                    i++;
                }
            }
        }
        
        return cnt;
    }
};