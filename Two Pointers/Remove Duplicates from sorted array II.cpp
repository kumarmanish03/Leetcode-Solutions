// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        if(A.size() <= 2)
            return A.size();
        int i = 0;
        int j;
        if(A[0] == A[1]){
            j = 2;
            i = 1;
        }
        else j = 1;

        for(; j < A.size(); j++){
            if(A[j] != A[i]){
                i++;
                A[i] = A[j];
            }
            else if(A[j] == A[i] && A[j] != A[i-1]){
                i++;
                A[i] = A[j];
            }
        }
        return i+1;
    }
};