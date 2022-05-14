// Manish Kumat, IIIT Allahabad
// Medium, DFS

https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/

class Solution {
public:
    
    const int dx[4] = {1, 0};
    const int dy[4] = {0, 1};
    
    bool isValid(int i, int j, int n, int m){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    int dp[105][105][210];
    
    bool func(int i, int j, int sz, vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        
        if(i == n-1 && j == m-1){
            if(grid[i][j] == '(') sz++;
            else sz--;
            if(sz == 0)
                return true;
            else
                return false;
        }
        
        if(dp[i][j][sz] != -1)
            return dp[i][j][sz];
        
        char curr = grid[i][j];
        bool ans = false;
        if(curr == '('){
            for(int k = 0; k < 2; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(!isValid(ni, nj, n, m))
                    continue;
                ans |= func(ni, nj, sz+1, grid);
                if(ans) return dp[i][j][sz] = ans;
            }
        }
        else{
            if(sz == 0)
                return dp[i][j][sz] = false;
            for(int k = 0; k < 2; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(!isValid(ni, nj, n, m))
                    continue;

                ans |= func(ni, nj, sz-1, grid);
                if(ans) return dp[i][j][sz] = ans;
            }
        }
        
        return dp[i][j][sz] = ans;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {   
        memset(dp, -1, sizeof(dp));
        return func(0, 0, 0, grid);
    }
};