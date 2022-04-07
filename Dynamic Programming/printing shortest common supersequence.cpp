// Manish Kumar, IIIT Allahabad
// Medium

https://leetcode.com/problems/shortest-common-supersequence/

// Watch this video for explanation
// https://www.youtube.com/watch?v=VDhRg-ZJTuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=29

class Solution {
public:
    int dp[1001][1001];
    
    // standard LCS dp[i][j] function to calculate longest common subsequence length
    int LCS(string &A, string &B, int n, int m){
        if(n== 0 || m == 0)
            return 0;
         if(dp[n][m] != -1)
               return dp[n][m];
        
        if(A[n-1] == B[m-1])
            dp[n][m] = 1 + LCS(A, B, n-1, m-1);
        else
            dp[n][m] = max(LCS(A, B, n-1, m), LCS(A, B, n, m-1));
        
       return dp[n][m];
    }
    
    string shortestCommonSupersequence(string A, string B) {
        // LCS
        int n = A.size();
        int m = B.size();
        memset(dp, -1, sizeof(dp));
        // LCS() calculate length of longest common subsequence and store all its values in dp[n][m]
        LCS(A, B, n, m);
        int i = n;
        int j = m;
        string res;
        // If A[n-1] == B[m-1] then strings are equal Hence add only one
        // else push that which is maximum
        while(i > 0 && j > 0){
            if(A[i-1] == B[j-1]){
                res.push_back(A[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    res.push_back(A[i-1]);
                    i--;
                }else{
                    res.push_back(B[j-1]);
                    j--;
                }
            }
        }
       
       // If one of them i, j left without zero then add rest strings in res
        while(j>0){
            res.push_back(B[j-1]);
            j--;
        }
         while(i>0){
            res.push_back(A[i-1]);
            i--;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};