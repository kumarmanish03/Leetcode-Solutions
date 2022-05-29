/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
* @desc: 0-1 BFS
*
*/


class Solution {
public:
    int dx[4] = {-1, +1, 0, 0};
    int dy[4] = {0, 0, -1, +1};
    
    bool isValid(int i, int j, int n, int m){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>cost(n, vector<int> (m, INT_MAX));
        
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        cost[0][0] = grid[0][0];
        while(!dq.empty()){
            auto [i, j] = dq.front();
            dq.pop_front();
            
            for(int k = 0; k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(!isValid(ni, nj, n, m)) continue;
                if(cost[ni][nj] > cost[i][j] + grid[ni][nj]){
                    cost[ni][nj] = cost[i][j] + grid[ni][nj];
                    if(grid[ni][nj] == 1){
                        dq.push_back({ni, nj});
                    }
                    else{
                        dq.push_front({ni, nj});
                    }
                }
            }
        }
        return cost[n-1][m-1];
    }
};